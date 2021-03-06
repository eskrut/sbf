#include "sbfMatrix.h"

#ifdef USE_UNROLLED_FUNCTIONS//Include manual force unrolled functions (-funroll-loops should be specified)
#include "unrolledFunctions.hpp"
#endif

/*typedef */struct indexes2{
	int i, j;
};
bool operator< (const indexes2 & left, const indexes2 & right)
{
	bool rez;
	if(left.i > right.i)
		rez = false;
	else if(left.i < right.i)
			rez = true;
	else{
		if (left.j < right.j) rez = true;
		else rez = false;
	}
	return rez;
}
bool operator== (const indexes2 & left, const indexes2 & right) { bool rez; left.i == right.i ? left.j == right.j ? rez = true : rez = false : rez = false; return rez; }

using namespace sbf;

const double intCrd1[] = {0.0};
const double intWgh1[] = {2.0};
const double intCrd2[] = {-5.773502691896257645e-01, 5.773502691896257645e-01};
const double intWgh2[] = {1.0, 1.0};
const double intCrd3[] = {-7.745966692414833771e-01, 0.0, 7.745966692414833771e-01};
const double intWgh3[] = {5.555555555555555556e-01, 8.888888888888888889e-01, 5.555555555555555556e-01};
const double intCrd4[] = {-0.861136311594953, -0.339981043584856, 0.339981043584856, 0.861136311594953};
const double intWgh4[] = {0.347854845137454, 0.652145154862546, 0.652145154862546, 0.347854845137454};

double const * intCrd[] = {intCrd1, intCrd2, intCrd3, intCrd4};
double const * intWgh[] = {intWgh1, intWgh2, intWgh3, intWgh4};

bool compareIndListEntrySort(std::vector<int> first, std::vector<int> second);
bool compareIndListEntryMerge(std::vector<int> first, std::vector<int> second);

static void makeStiffMatrixBlock3x3Multiplication(void *data);
static void makeStiffMatrixBlock3x3MultiplicationLoop(void *data);//Looped version

static void StiffMatrixBlock3x3ComputeThread(void * data);
struct StiffMatrixBlock3x3ComputeThreadData
{
	StiffMatrixBlock3x3 *stiffMatrix;
	ThreadType thread;
	EventType *signalsUnlock, threadReady;
	int threadID;
	int startElem, stopElem;
	int *elemIndexes; int elemIndexesLength;//For indexed based enumeration
};

//extern "C" typedef void *(*pthread_callback)(void *);

StiffBlock3x3::StiffBlock3x3()
{
	length_ = 9;
	data_ = new double [length_];
	type_ = NO_DEFINED_BLOCK;
	indI_ = indJ_ = -1;
}
StiffBlock3x3::StiffBlock3x3(const StiffBlock3x3 & block)
{
	if(data_ == NULL)
		data_ = new double [length_];
	if(block.data_ != NULL)
		for(int ct = 0; ct < length_; ct++)
			data_[ct] = block.data_[ct];
	indI_ = block.indI_;
	indJ_ = block.indJ_;
	type_ = block.type_;
}
StiffBlock3x3::~StiffBlock3x3()
{
	if(data_ != NULL)
		delete [] data_;
}

double * StiffBlock3x3::data()
{return data_;}

void StiffBlock3x3::setType(BlockType type)
{type_ = type;}

BlockType StiffBlock3x3::type()
{return type_;}

int StiffBlock3x3::indI()
{return indI_;}

int StiffBlock3x3::indJ()
{return indJ_;}

void StiffBlock3x3::setIndI(int ind)
{indI_ = ind;}

void StiffBlock3x3::setIndJ(int ind)
{indJ_ = ind;}

int StiffBlock3x3::dataLength()
{return length_;}


StiffMatrixBlock3x3::StiffMatrixBlock3x3()
{
	init();
}
StiffMatrixBlock3x3::StiffMatrixBlock3x3(int numBlocks, int numNodes)
{
	init();
	setNumBlocksNodes(numBlocks, numNodes);
}
//StiffMatrixBlock3x3::StiffMatrixBlock3x3(const StiffMatrixBlock3x3 & matrix)
//{}
StiffMatrixBlock3x3::~StiffMatrixBlock3x3()
{
	clean();
}
void StiffMatrixBlock3x3::init()
{
	type_ = NO_DEFINED_MATRIX;
	numNodes_ = 0;
	numBlocks_ = 0;
	numBlocksAlter_ = 0;
	data_ = NULL;
	indJ_ = NULL;
	shiftInd_ = NULL;
	indJAlter_ = NULL;
	shiftIndAlter_ = NULL;
	ptrDataAlter_ = NULL;
	flagInitialized_ = NULL;
	isDOFMerged_ = true;
	//threadsData_ = NULL;
	mesh_ = NULL;
	propSet_ = NULL;
}
void StiffMatrixBlock3x3::clean()
{
	if(data_ != NULL)
	{delete [] data_; data_ = NULL;}
	if(indJ_ != NULL)
	{delete [] indJ_; indJ_ = NULL;}
	if(shiftInd_ != NULL)
	{delete [] shiftInd_; shiftInd_ = NULL;}
	if(indJAlter_ != NULL)
	{delete [] indJAlter_; indJAlter_ = NULL;}
	if(shiftIndAlter_ != NULL)
	{delete [] shiftIndAlter_; shiftIndAlter_ = NULL;}
	if(ptrDataAlter_ != NULL)
	{delete [] ptrDataAlter_; ptrDataAlter_ = NULL;}
	if(flagInitialized_ != NULL)
	{delete [] flagInitialized_; flagInitialized_ = NULL;}
	//if(threadsData_ != NULL)
	//{delete [] threadsData_; threadsData_ = NULL;}
}
void StiffMatrixBlock3x3::allocate()
{
	clean();
	data_ = new double [9*numBlocks_];
	flagInitialized_ = new bool [numBlocks_];
	null();
	indJ_ = new int [numBlocks_];
	shiftInd_ = new int [numNodes_+1];//+1 to allow unique iteration through rows, i.e. from shiftInd_[ct] to shiftInd_[ct+1]
	if(numBlocksAlter_ > 0){
		indJAlter_ = new int [numBlocksAlter_];
		shiftIndAlter_ = new int [numNodes_+1];
		ptrDataAlter_ = new double * [numBlocksAlter_];
	}
}
void StiffMatrixBlock3x3::setNumBlocksNodes(int numBlocks, int numNodes, int numBlocksAlter)
{
	clean();
	numBlocks_ = numBlocks;
	numBlocksAlter_ = numBlocksAlter;
	numNodes_ = numNodes;
	allocate();
}
void StiffMatrixBlock3x3::setIndData(int numNodes, int numBlocks, int * indJ, int * shiftInd, int numBlocksAlter, int * indJAlter, int * shiftIndAlter)
{
	clean();
	numBlocks_ = numBlocks;
	numBlocksAlter_ = numBlocksAlter;
	numNodes_ = numNodes;
	data_ = new double [9*numBlocks_];
	flagInitialized_ = new bool [numBlocks_];
	null();
	indJ_ = indJ;
	shiftInd_ = shiftInd;
	if(numBlocksAlter_ > 0){
		indJAlter_ = indJAlter;
		shiftIndAlter_ = shiftIndAlter;
		ptrDataAlter_ = new double * [numBlocksAlter_];
	}
}
void StiffMatrixBlock3x3::updateIndexesFromMesh(int *elemIndexes, int elemIndexesLength, MatrixType type, bool merge)
{
	/*
	 * Calculate indexes and shift arrays by sbfMesh mesh topology and target matrix topology
	 * Calculation only for elements in elemIndexes[elemIndexesLength]
	 * If merge == false equal indexes pares will not be removed from index list.
	 */
	if(type == NO_DEFINED_MATRIX)
		type_ = FULL_MATRIX;
	else
		type_ = type;

	if(mesh_ == NULL){/*Throw an exception*/}
	int numNodes = mesh_->numNodes();

	isDOFMerged_ = merge;

	//Compute all stiff indexes in mesh
	int * indBandLength = new int [numNodes];for(int ct = 0; ct < numNodes; indBandLength[ct++] = 0);//Length of all blocks in row (with duplicated indexes)
	int * indBandCount = new int [numNodes];for(int ct = 0; ct < numNodes; indBandCount[ct++] = 0);//Counters of indexes in row for indexes storage
	int ** indBandInd = new int* [numNodes];//Indexes (second parts) in row with duplicates
	std::vector<int> indexes;
	for(int ct = 0; ct < elemIndexesLength; ct++){//Loop over elements in mesh
		indexes = mesh_->elemPtr(elemIndexes[ct])->indexes();
		int length = (int)indexes.size();
		for(int ct1 = 0; ct1 < length; ct1++){//Compute indexes bands length
			for(int ct2 = 0; ct2 < length; ct2++){
				indBandLength[indexes[ct1]]++;
			}
		}//Add all stiff indexes of element to indList
	}//Loop over elements in mesh
	for(int ct = 0; ct < numNodes; ct++)indBandInd[ct] = new int [indBandLength[ct]];
	for(int ct = 0; ct < elemIndexesLength; ct++){//Loop over elements in mesh
		indexes = mesh_->elemPtr(elemIndexes[ct])->indexes();
		int length = (int)indexes.size();
		for(int ct1 = 0; ct1 < length; ct1++){//Add all stiff indexes of element to indBandInd
			int * band = indBandInd[indexes[ct1]];
			int count = indBandCount[indexes[ct1]];
			for(int ct2 = 0; ct2 < length; ct2++){
				band[count++] = indexes[ct2];
			}
			indBandCount[indexes[ct1]] = count;
		}//Add all stiff indexes of element to indBandInd
	}//Loop over elements in mesh

	//Sort indexes in rows. Rows are already sorted
	for(int ct = 0; ct < numNodes; ct++){//Loop over rows (nodes)
		int * band = indBandInd[ct];
		int length = indBandLength[ct];
		int lengthM1 = length-1;
		//Simple bubble sort
		for(int ct1 = 0; ct1 < lengthM1; ct1++){	for(int ct2 = ct1 + 1; ct2 < length; ct2++){
			if(band[ct1] > band[ct2])
			{int tempI = band[ct1]; band[ct1] = band[ct2]; band[ct2] = tempI;}
		}	}
	}//Loop over rows (nodes)

	if(isDOFMerged_ == true){//Merge indexes in rows
		for(int ct = 0; ct < numNodes; ct++){//Loop over rows (nodes)
			int * band = indBandInd[ct];
			int length = indBandLength[ct];
			int * newBand = new int [length];
			int newLength = 0;
			for(int ct1 = 0; ct1 < length; ct1++){//Loop over indexes in row
				bool flag = true;//index should be added
				int index = band[ct1];
				for(int ct2 = 0; ct2 < newLength; ct2++){
					if(index == newBand[ct2])
					{flag = false; break;}//index should not be added
				}
				if(flag)
					newBand[newLength++] = index;
			}//Loop over indexes in row
			for(int ct1 = 0; ct1 < newLength; ct1++) band[ct1] = newBand[ct1];
			indBandLength[ct] = newLength;
			delete [] newBand;
		}//Loop over rows (nodes)
	}//Merge indexes in rows
	int indLength = 0; for(int ct = 0; ct < numNodes; indLength += indBandLength[ct++]);

	//Store to internal variables
	if(type_ == FULL_MATRIX){
		setNumBlocksNodes(indLength, numNodes);
		int count = 0;
		int ct = 0;
		shiftInd_[count++] = ct;
		for(int ctNodes = 0; ctNodes < numNodes; ctNodes++){//Loop over rows
			int length = indBandLength[ctNodes];
			int * band = indBandInd[ctNodes];
			for(int ctColumn = 0; ctColumn < length; ctColumn++){//Loop over indexes in row
				indJ_[ct++] = band[ctColumn];
			}//Loop over indexes in row
			shiftInd_[count++] = ct;
		}//Loop over rows
	}//FULL_MATRIX
	else if(type_ == UP_TREANGLE_MATRIX || type_ == DOWN_TREANGLE_MATRIX){
		int * indBandLengthNorm;
		int ** indBandIndNorm;
		int * indBandLengthAlter;
		int ** indBandIndAlter;

		indBandLengthNorm = new int [numNodes];
		indBandLengthAlter = new int [numNodes];
		indBandIndNorm = new int* [numNodes];
		indBandIndAlter = new int* [numNodes];
		for(int ct = 0; ct < numNodes; ct++){
			indBandIndNorm[ct] = new int [indBandLength[ct]];
			indBandIndAlter[ct] = new int [indBandLength[ct]];
		}

		int numBlocksNorm = 0, numBlocksAlter = 0;
		if(type_ == UP_TREANGLE_MATRIX)
			for(int ctNodes = 0; ctNodes < numNodes; ctNodes++){//Loop over rows
				int length = indBandLength[ctNodes], * band = indBandInd[ctNodes];
				for(int ctColumn = 0; ctColumn < length; ctColumn++){//Loop over indexes in row
					if(band[ctColumn] >= ctNodes) numBlocksNorm++;
					else numBlocksAlter++;
				}//Loop over indexes in row
			}//Loop over rows
		else// type_ == DOWN_TREANGLE_MATRIX
			for(int ctNodes = 0; ctNodes < numNodes; ctNodes++){//Loop over rows
				int length = indBandLength[ctNodes], * band = indBandInd[ctNodes];
				for(int ctColumn = 0; ctColumn < length; ctColumn++){//Loop over indexes in row
					if(band[ctColumn] <= ctNodes) numBlocksNorm++;
					else numBlocksAlter++;
				}//Loop over indexes in row
			}//Loop over rows

		setNumBlocksNodes(numBlocksNorm, numNodes, numBlocksAlter);

		int countNorm = 0;
		int ctNorm = 0;
		int countAlter = 0;
		int ctAlter = 0;
		shiftInd_[countNorm++] = ctNorm;
		shiftIndAlter_[countAlter++] = ctAlter;
		if(type_ == UP_TREANGLE_MATRIX)
			for(int ctNodes = 0; ctNodes < numNodes; ctNodes++){//Loop over rows
				int length = indBandLength[ctNodes], * band = indBandInd[ctNodes];
				for(int ctColumn = 0; ctColumn < length; ctColumn++){//Loop over indexes in row
					if(band[ctColumn] >= ctNodes) indJ_[ctNorm++] = band[ctColumn];
					else {indJAlter_[ctAlter] = band[ctColumn]; ptrDataAlter_[ctAlter] = NULL; ctAlter++;}
				}//Loop over indexes in row
				shiftInd_[countNorm++] = ctNorm;
				shiftIndAlter_[countAlter++] = ctAlter;
			}//Loop over rows
		else// type_ == DOWN_TREANGLE_MATRIX
			for(int ctNodes = 0; ctNodes < numNodes; ctNodes++){//Loop over rows
				int length = indBandLength[ctNodes], * band = indBandInd[ctNodes];
				for(int ctColumn = 0; ctColumn < length; ctColumn++){//Loop over indexes in row
					if(band[ctColumn] <= ctNodes) indJ_[ctNorm++] = band[ctColumn];
					else {indJAlter_[ctAlter] = band[ctColumn]; ptrDataAlter_[ctAlter] = NULL; ctAlter++;}
				}//Loop over indexes in row
				shiftInd_[countNorm++] = ctNorm;
				shiftIndAlter_[countAlter++] = ctAlter;
			}//Loop over rows

		int count = 0;
		for(int ctIndI = 0; ctIndI < numNodes; ctIndI++){
			for(int shift = shiftIndAlter_[ctIndI]; shift < shiftIndAlter_[ctIndI+1]; shift++)
				ptrDataAlter_[count++] = this->blockPtr(indJAlter_[shift], ctIndI);
		}

		for(int ct = 0; ct < numNodes; ct++){delete [] indBandIndNorm[ct]; delete [] indBandIndAlter[ct];}
		delete [] indBandIndNorm;
		delete [] indBandIndAlter;
		delete [] indBandLengthNorm;
		delete [] indBandLengthAlter;
	}
	else{
		/*Throw an exception*/
	}

	for(int ct = 0; ct < numNodes; ct++) delete [] indBandInd[ct];
	delete [] indBandInd;
	delete [] indBandCount;
	delete [] indBandLength;
}
void StiffMatrixBlock3x3::updateIndexesFromMesh(int startElemIndex, int stopElemIndex, MatrixType type, bool merge)
{
	std::vector <int> elemIndexes;
	elemIndexes.resize(stopElemIndex - startElemIndex);
	for(int ct = 0; ct < stopElemIndex - startElemIndex; ct++)
		elemIndexes[ct] = startElemIndex + ct;
	updateIndexesFromMesh(&elemIndexes[0], (int)elemIndexes.size(), type, merge);
}
void StiffMatrixBlock3x3::updateIndexesFromMesh(MatrixType type, bool merge)
{
	if(mesh_ == NULL){/*Throw an exception*/}
	updateIndexesFromMesh(0, mesh_->numElements(), type, merge);
}
void StiffMatrixBlock3x3::updataAlterPtr()
{
	if((type_ == UP_TREANGLE_MATRIX || type_ == DOWN_TREANGLE_MATRIX) && numBlocksAlter_ > 0){
		int count = 0;
		for(int ctIndI = 0; ctIndI < numNodes_; ctIndI++){
			for(int shift = shiftIndAlter_[ctIndI]; shift < shiftIndAlter_[ctIndI+1]; shift++)
				ptrDataAlter_[count++] = this->blockPtr(indJAlter_[shift], ctIndI);
		}
	}
}
bool compareIndListEntrySort(std::vector<int> first, std::vector<int> second)
{
	if(first[0] < second[0])
		return true;
	else if(first[0] == second[0]){
		if(first[1] < second[1])
			return true;}
	//	else
	return false;
}
bool compareIndListEntryMerge(std::vector<int> first, std::vector<int> second)
{
	if(first[0] != second[0])
		return false;
	else if(first[1] == second[1])
		return true;
	//	else
	return false;
}
double * StiffMatrixBlock3x3::blockPtr(int indI, int indJ)
{
	//Returns pointer to stiffness block with indexes indI, indJ.

	//Search in regular storage ONLY
	int shift = shiftInd_[indI];
	double * base = data_ + shift*9;
	int searchLength = shiftInd_[indI+1] - shift;
	for(int ct = 0; ct < searchLength; ct++){//Search through row indI for column indJ
		if(indJ_[shift+ct] == indJ)
			return base;
		base += 9;
	}

	return NULL;
}
double * StiffMatrixBlock3x3::data(int indI, int indJ, bool *isDirect)
{
	//Returns pointer to stiffness block with indexes indI, indJ.

	//Search in regular storage
	int shift = shiftInd_[indI];
	double * base = data_ + shift*9;
	int searchLength = shiftInd_[indI+1] - shift;
	if(isDirect) *isDirect = true;
	for(int ct = 0; ct < searchLength; ct++){//Search through row indI for column indJ
		if(indJ_[shift+ct] == indJ)
			return base;
		base += 9;
	}

	//Search in alternative storage
	shift = shiftIndAlter_[indI];
	searchLength = shiftIndAlter_[indI+1] - shift;

	if(isDirect) *isDirect = false;
	for(int ct = 0; ct < searchLength; ct++){//Search through row indI for column indJ
		if(indJAlter_[shift+ct] == indJ)
			return ptrDataAlter_[ct];
	}

	return NULL;
}
double * StiffMatrixBlock3x3::addBlockData(double * data, int indI, int indJ)
{
	bool flagFound = false;
	//Code from StiffMatrixBlock3x3::blockPtr(int indI, int indJ)
	int shift = shiftInd_[indI];
	double * base = data_ + shift*9;
	int searchLength = shiftInd_[indI+1] - shift;
	int ct;
	for(ct = 0; ct < searchLength; ct++){//Search through row indI for column indJ
		if(indJ_[shift+ct] == indJ){
			if(isDOFMerged_){
				flagFound = true;
				break;
			}
			else{
				if(!flagInitialized_[shift+ct]){
					flagFound = true;
					break;
				}
			}
		}
		base += 9;
	}
	if(flagFound){
		double * dataIter = base;
		for(int count = 0; count < 9; count++) dataIter[count] += data[count];
		flagInitialized_[shift+ct] = true;
	}
	else base = NULL;
	return base;
}
const double * StiffMatrixBlock3x3::data()
{return data_;}
const int * StiffMatrixBlock3x3::indData()
{return indJ_;}
const int * StiffMatrixBlock3x3::shiftIndData()
{return shiftInd_;}
double ** StiffMatrixBlock3x3::ptrDataAlter()
{return ptrDataAlter_;}
const int * StiffMatrixBlock3x3::indDataAlter()
{return indJAlter_;}
const int * StiffMatrixBlock3x3::shiftIndDataAlter()
{return shiftIndAlter_;}
int StiffMatrixBlock3x3::numNodes()
{return numNodes_;}
int StiffMatrixBlock3x3::numBlocks()
{return numBlocks_;}
void StiffMatrixBlock3x3::setType(MatrixType type)
{type_=type;}
MatrixType StiffMatrixBlock3x3::type()
{return type_;}
void StiffMatrixBlock3x3::null()
{
	int length = 9*numBlocks_;
	for(int ct = 0; ct < length; data_[ct++] = 0);
	for(int ct = 0; ct < numBlocks_; flagInitialized_[ct++] = false);
}
void StiffMatrixBlock3x3::null(int indI, int indJ)
{
	double * data = blockPtr(indI, indJ);
	if(data != NULL)
		for(int ct = 0; ct < 9; *(data + ct++) = 0);
	flagInitialized_[(data-data_)/9] = false;
}
int StiffMatrixBlock3x3::checkNulls()
{
	bool flagNull = false;
	bool flagNotNull = false;
	for(int ct = 0; ct < numBlocks_; ct++){
		if(flagInitialized_[ct] == false) flagNull = true;
		else flagNotNull = true;
	}
	if(flagNull && !flagNotNull)
		return 0;//All are nulls
	if(!flagNull && flagNotNull)
		return 2;//All are not nulls
	return 1;//Some are nulls
}

//TODO merge versions () and (int *elemIndexes, int elemIndexesLength) by using (int *elemIndexes = NULL, int elemIndexesLength = NULL)

void StiffMatrixBlock3x3::compute()
{
	/*
	 * Compute stiffnesses of elements in mesh_ and assembly them to this
	 */
	if(mesh_ == NULL){/*Throw an exception*/}
	if(propSet_ == NULL){/*Throw an exception*/}
	int numElements = mesh_->numElements();
	sbfElement * elem;
	std::vector<int> indexes;
	indexes.reserve(20);

	//forward preparation of matrixes
	ElemStiffMatrixHexa8 *stiffHexa8 = new ElemStiffMatrixHexa8();
	stiffHexa8->setPropSet(propSet_);

	double * blockData = new double [9];
	double * pBlock;

	for(int ct = 0; ct < numElements; ct++){//Loop over elements
		elem = mesh_->elemPtr(ct);
		switch(elem->type()){
		case HEXAHEDRON_LINEAR:{
			stiffHexa8->setElem(elem);
			stiffHexa8->computeSM();
			indexes = elem->indexes();
			for(int ctI = 0; ctI < 8; ctI++)
				for(int ctJ = 0; ctJ < 8; ctJ++){
					if(type_ == UP_TREANGLE_MATRIX && indexes[ctI] > indexes[ctJ]) continue;
					else if(type_ == DOWN_TREANGLE_MATRIX && indexes[ctI] < indexes[ctJ]) continue;
					stiffHexa8->getBlockDataLoc(blockData, ctI, ctJ);//Store current block from element stiffness matrix to temporary array
					pBlock = addBlockData(blockData, indexes[ctI], indexes[ctJ]);
					if(pBlock == NULL) std::cout << "Error while processing local indexes " << ctI << ", " << ctJ << " of element " << ct << ". Can't find appropriate block in stiffness matrix" << std::endl;
				}
			break;
		}
		default:
			/*Throw an exception*/
			break;
		}
	}//Loop over elements

	delete [] blockData;
	delete stiffHexa8;
}
void StiffMatrixBlock3x3::compute(int *elemIndexes, int elemIndexesLength)
{
	/*
	 * Compute stiffnesses of elements in mesh_ and assembly them to this
	 */
	if(mesh_ == NULL){/*Throw an exception*/}
	if(propSet_ == NULL){/*Throw an exception*/}
	//int numElements = mesh_->numElements();
	sbfElement * elem;
	std::vector<int> indexes;
	indexes.reserve(20);

	//forward preparation of matrixes
	ElemStiffMatrixHexa8 *stiffHexa8 = new ElemStiffMatrixHexa8();
	stiffHexa8->setPropSet(propSet_);

	double * blockData = new double [9];
	double * pBlock;

	for(int ctID = 0; ctID < elemIndexesLength; ctID++){//Loop over elements
		int ct = elemIndexes[ctID];
		elem = mesh_->elemPtr(ct);
		switch(elem->type()){
		case HEXAHEDRON_LINEAR:{
			stiffHexa8->setElem(elem);
			stiffHexa8->computeSM();
			indexes = elem->indexes();
			for(int ctI = 0; ctI < 8; ctI++)
				for(int ctJ = 0; ctJ < 8; ctJ++){
					if(type_ == UP_TREANGLE_MATRIX && indexes[ctI] > indexes[ctJ]) continue;
					else if(type_ == DOWN_TREANGLE_MATRIX && indexes[ctI] < indexes[ctJ]) continue;
					stiffHexa8->getBlockDataLoc(blockData, ctI, ctJ);//Store current block from element stiffness matrix to temporary array
					pBlock = addBlockData(blockData, indexes[ctI], indexes[ctJ]);
					if(pBlock == NULL) std::cout << "Error while processing local indexes " << ctI << ", " << ctJ << " of element " << ct << ". Can't find appropriate block in stiffness matrix" << std::endl;
				}
			break;
		}
		default:
			/*Throw an exception*/
			break;
		}
	}//Loop over elements

	delete [] blockData;
	delete stiffHexa8;
}
void StiffMatrixBlock3x3::computeParallel()
{
	StiffMatrixBlock3x3ComputeThreadData data[SBF_NUM_THREADS];
	EventType signalsUnlock[SBF_NUM_THREADS];
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++) event_init(&(signalsUnlock[ct]));
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++){
		data[ct].signalsUnlock = signalsUnlock;
		data[ct].startElem = ct*mesh_->numElements()/SBF_NUM_THREADS;
		data[ct].stopElem = ((ct+1)*mesh_->numElements())/SBF_NUM_THREADS;
		data[ct].stiffMatrix = this;
		data[ct].threadID = ct;
		data[ct].elemIndexes = NULL;
		event_init(&(data[ct].threadReady));
		createNewThread(&(data[ct].thread), StiffMatrixBlock3x3ComputeThread, &data[ct]);
		event_wait(&(data[ct].threadReady));
		event_set(&(signalsUnlock[ct]));
	}
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++) waitThreadDone(data[ct].thread);
}
void StiffMatrixBlock3x3::computeParallel(int *elemIndexes, int elemIndexesLength)
{
	StiffMatrixBlock3x3ComputeThreadData data[SBF_NUM_THREADS];
	EventType signalsUnlock[SBF_NUM_THREADS];
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++) event_init(&(signalsUnlock[ct]));
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++){
		data[ct].signalsUnlock = signalsUnlock;
		data[ct].startElem = ct*elemIndexesLength/SBF_NUM_THREADS;
		data[ct].stopElem = ((ct+1)*elemIndexesLength)/SBF_NUM_THREADS;
		data[ct].stiffMatrix = this;
		data[ct].threadID = ct;
		data[ct].elemIndexes = elemIndexes;
		data[ct].elemIndexesLength = elemIndexesLength;
		event_init(&(data[ct].threadReady));
		createNewThread(&(data[ct].thread), StiffMatrixBlock3x3ComputeThread, &data[ct]);
		event_wait(&(data[ct].threadReady));
		event_set(&(signalsUnlock[ct]));
	}
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++) waitThreadDone(data[ct].thread);
}
static void StiffMatrixBlock3x3ComputeThread(void * rawData)
{
	StiffMatrixBlock3x3ComputeThreadData * data = reinterpret_cast<StiffMatrixBlock3x3ComputeThreadData *>(rawData);

	if(data->stiffMatrix->mesh() == NULL){/*Throw an exception*/}
	if(data->stiffMatrix->propSet() == NULL){/*Throw an exception*/}
	sbfElement * elem;
	std::vector<int> indexes;
	indexes.reserve(20);

	//forward preparation of matrixes
	ElemStiffMatrixHexa8 *stiffHexa8 = new ElemStiffMatrixHexa8();
	stiffHexa8->setPropSet(data->stiffMatrix->propSet());

	double * blockData = new double [9];
	double * pBlock;
	sbfMesh * mesh = data->stiffMatrix->mesh();
	int startElem = data->startElem, stopElem = data->stopElem;
	int stiffnessPart, coeff = mesh->numNodes()/SBF_NUM_THREADS;
	int *elemIndexes = data->elemIndexes;
	//int elemIndexesLength = data->elemIndexesLength;
	EventType *signalsUnlock = data->signalsUnlock;
	event_set(&data->threadReady);
	for(int ctID = startElem; ctID < stopElem; ctID++){//Loop over elements
		int ct = elemIndexes ? elemIndexes[ctID] : ctID;
		elem = mesh->elemPtr(ct);
		switch(elem->type()){
		case HEXAHEDRON_LINEAR:{
			//std::cout << "Tread " << data->threadID << " computing element " << ct << std::endl;
			stiffHexa8->setElem(elem);
			stiffHexa8->computeSM();
			indexes = elem->indexes();
			for(int ctI = 0; ctI < 8; ctI++)
				for(int ctJ = 0; ctJ < 8; ctJ++){
					if(data->stiffMatrix->type() == UP_TREANGLE_MATRIX && indexes[ctI] > indexes[ctJ]) continue;
					else if(data->stiffMatrix->type() == DOWN_TREANGLE_MATRIX && indexes[ctI] < indexes[ctJ]) continue;
					stiffHexa8->getBlockDataLoc(blockData, ctI, ctJ);//Store current block from element stiffness matrix to temporary array
					stiffnessPart = indexes[ctI]/coeff;
					if(stiffnessPart > SBF_NUM_THREADS-1) stiffnessPart = SBF_NUM_THREADS-1;
					//std::cout << "Tread " << data->threadID << " waiting to access to part " << stiffnessPart << std::endl;
					event_wait(&signalsUnlock[stiffnessPart]);//Wait for access to row in certain part of stiffness matrix
					pBlock = data->stiffMatrix->addBlockData(blockData, indexes[ctI], indexes[ctJ]);
					if(pBlock == NULL) std::cout << "Error while processing local indexes " << ctI << ", " << ctJ << " (" << indexes[ctI] << ", " << indexes[ctJ] << ") of element " << ct << ". Can't find block ptr" << std::endl;
					event_set(&signalsUnlock[stiffnessPart]);
				}
			break;
		}
		default:
			/*Throw an exception*/
			break;
		}
	}//Loop over elements

	delete [] blockData;
	delete stiffHexa8;
	//std::cout << "Tread " << data->threadID << " done" << std::endl;
	return;
}
void StiffMatrixBlock3x3::lockKort(int indI, int kort, double val, double * force, LockType lockType)
{
	if(lockType == APPROXIMATE_LOCK_TYPE){
		double * targetBlock = blockPtr(indI, indI);
		if (targetBlock == NULL) return;
		int shift;
		if(kort == 0) shift = 0;
		else if(kort == 1) shift = 4;
		else shift = 8;
		double great = 1.0e10;
		targetBlock[shift] *= great;
		if(force != NULL) force[indI*3 + kort] = targetBlock[shift]*val;
	}
	else{
		for(int colCt = shiftInd_[indI]; colCt < shiftInd_[indI+1]; colCt++){
			int curJ = indJ_[colCt];
			double * blockPtr = data_ + 9*colCt;
			if(force){
				force[3*curJ+0] -= blockPtr[3*kort + 0]*val;
				blockPtr[3*kort + 0] = 0.0;
				force[3*curJ+1] -= blockPtr[3*kort + 1]*val;
				blockPtr[3*kort + 1] = 0.0;
				force[3*curJ+2] -= blockPtr[3*kort + 2]*val;
				blockPtr[3*kort + 2] = 0.0;
			}
		}
		for(int rowCt = 0; rowCt < numNodes_; rowCt++){
			double * blockPtr = this->blockPtr(rowCt, indI);
			if(blockPtr){
				blockPtr[kort] = blockPtr[kort+3] = blockPtr[kort+6] = 0.0;
				if(rowCt == indI) blockPtr[kort*3 + kort] = 1;
			}
		}
		force[indI*3+kort] = val;
	}
}
void StiffMatrixBlock3x3::multiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength)
{
	/*
	 * Multiply this matrix by vector and store result (memory should be allocated for result)
	 * ind_ indexes should be sorted
	 * version with specified rows to process
	 */

	//	if(type_ != FULL_MATRIX)
	//		return;

	StiffMatrixBlock3x3MultiplicationData tData[SBF_NUM_THREADS];
	ThreadType handles[SBF_NUM_THREADS];
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++){
		tData[ct].result = result;
		tData[ct].vector = vector;
		tData[ct].stiffMatrix = this;
		tData[ct].startRow = ct*rowIndexesLength/SBF_NUM_THREADS;
		tData[ct].stopRow = ((ct+1)*rowIndexesLength)/SBF_NUM_THREADS;
		tData[ct].rowIndexes = rowIndexes;
		tData[ct].rowIndexesLength = rowIndexesLength;
		createNewThread(&handles[ct], makeStiffMatrixBlock3x3Multiplication, &tData[ct]);
	}
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++)
		waitThreadDone(handles[ct]);
}
void StiffMatrixBlock3x3::multiplyByVector(double * vector, double * result)
{
	/*
	 * Multiply this matrix by vector and store result (memory should be allocated for result)
	 * ind_ indexes should be sorted
	 */

	StiffMatrixBlock3x3MultiplicationData tData[SBF_NUM_THREADS];
	ThreadType handles[SBF_NUM_THREADS];
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++){
		tData[ct].result = result;
		tData[ct].vector = vector;
		tData[ct].stiffMatrix = this;
		tData[ct].startRow = ct*numNodes_/SBF_NUM_THREADS;
		tData[ct].stopRow = ((ct+1)*numNodes_)/SBF_NUM_THREADS;
		tData[ct].rowIndexes = NULL;
		tData[ct].rowIndexesLength = 0;
		createNewThread(&handles[ct], makeStiffMatrixBlock3x3Multiplication, &tData[ct]);
	}
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++)
		waitThreadDone(handles[ct]);
}

void StiffMatrixBlock3x3::prepareParallelMultiplyByVector(double * vector, double * result)
{
	//Possible loss of previous threadsData_ data, if initilized some threads will hang
	// TODO clear data and stop threads (if exist)
	//threadsData_ = new StiffMatrixBlock3x3MultiplicationData [SBF_NUM_THREADS];
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++){
		threadsData_[ct].result = result;
		threadsData_[ct].vector = vector;
		threadsData_[ct].stiffMatrix = this;
		threadsData_[ct].startRow = ct*numNodes_/SBF_NUM_THREADS;
		threadsData_[ct].stopRow = ((ct+1)*numNodes_)/SBF_NUM_THREADS;
		threadsData_[ct].rowIndexes = NULL;
		threadsData_[ct].rowIndexesLength = 0;
		threadsData_[ct].threadID = ct;
		threadsData_[ct].flagCancel = false;
		event_init(&threadsData_[ct].start);
		event_init(&threadsData_[ct].stop);
		createNewThread(&(threadsData_[ct].thread), makeStiffMatrixBlock3x3MultiplicationLoop, &threadsData_[ct]);
		event_wait(&threadsData_[ct].stop);
	}
}
void StiffMatrixBlock3x3::prepareParallelMultiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength)
{
	//Possible loss of previous threadsData_ data, if initilized some threads will hang
	// TODO clear data and stop threads (if exist)
	//threadsData_ = new StiffMatrixBlock3x3MultiplicationData [SBF_NUM_THREADS];
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++){
		threadsData_[ct].result = result;
		threadsData_[ct].vector = vector;
		threadsData_[ct].stiffMatrix = this;
		threadsData_[ct].startRow = ct*rowIndexesLength/SBF_NUM_THREADS;
		threadsData_[ct].stopRow = ((ct+1)*rowIndexesLength)/SBF_NUM_THREADS;
		threadsData_[ct].rowIndexes = rowIndexes;
		threadsData_[ct].rowIndexesLength = rowIndexesLength;
		threadsData_[ct].threadID = ct;
		threadsData_[ct].flagCancel = false;
		event_init(&threadsData_[ct].start);
		event_init(&threadsData_[ct].stop);
		createNewThread(&(threadsData_[ct].thread), makeStiffMatrixBlock3x3MultiplicationLoop, &threadsData_[ct]);
		event_wait(&threadsData_[ct].stop);
	}
}

void StiffMatrixBlock3x3::makeParallelMultiplyByVector()
{
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++) event_set(&threadsData_[ct].start);
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++) event_wait(&threadsData_[ct].stop);
}

void StiffMatrixBlock3x3::clearParallelMultiplyByVector()
{
	for(int ct = 0; ct < SBF_NUM_THREADS; ct++){
		cancelThread(threadsData_[ct].thread);//Pthread version do not stops a thread, it asks to stop at next cancelation point. To reach this point "event_set(&threadsData_[ct].start);" is used
		event_set(&threadsData_[ct].start);
		event_destroy(&threadsData_[ct].start);
		event_destroy(&threadsData_[ct].stop);
		waitThreadDone(threadsData_[ct].thread);
	}
}

static void makeStiffMatrixBlock3x3Multiplication(void *data_)
{
	StiffMatrixBlock3x3MultiplicationData * tData = (StiffMatrixBlock3x3MultiplicationData *) data_;

	int startRow, stopRow;
	int *rowIndexes;//, rowIndexesLength;
	startRow = tData->startRow;
	stopRow = tData->stopRow;
	rowIndexes = tData->rowIndexes;
	//rowIndexesLength = tData->rowIndexesLength;
	double *result = tData->result;
	double *vector = tData->vector;

	double *data = (double*)tData->stiffMatrix->data();
	int *ind = (int*)tData->stiffMatrix->indData(), *shiftInd = (int*)tData->stiffMatrix->shiftIndData();
	double ** ptrDataAlter = (double **)tData->stiffMatrix->ptrDataAlter();
	int *indAlter = (int*)tData->stiffMatrix->indDataAlter(), *shiftIndAlter = (int*)tData->stiffMatrix->shiftIndDataAlter();
	int ct;
	double *rezPtr, *stifPtr, *vectPtr;
	double vectTmp1, vectTmp2, vectTmp3;
	int blockBandLength;
	int *shiftBase;
	double tmpRez1, tmpRez2, tmpRez3;

	//	makeMulRowFuncPtrType *rowMulFunctions = new makeMulRowFuncPtrType [stopRow - startRow];
	//	rowMulFunctions[0] = makeMulRowFunctions[0];

	MatrixType type = tData->stiffMatrix->type();

	if(rowIndexes == NULL){//Version with sequenced rows
		for(ct = startRow; ct < stopRow; ct++){//Loop over rows.
			//Each row can be evaluated separately
			rezPtr = result + 3*ct;
			tmpRez1 = 0; tmpRez2 = 0; tmpRez3 = 0;

			//Process normal blocks
			blockBandLength = shiftInd[ct+1]-shiftInd[ct];
			shiftBase = ind + shiftInd[ct];//Pointer to index of current vector part
			stifPtr = data + shiftInd[ct]*9;//Pointer to current stiffness block
			for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
				vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

				vectTmp1 = *vectPtr++;//Variables for further access
				vectTmp2 = *vectPtr++;
				vectTmp3 = *vectPtr;
				tmpRez1 += *stifPtr++*vectTmp1;
				tmpRez1 += *stifPtr++*vectTmp2;
				tmpRez1 += *stifPtr++*vectTmp3;
				tmpRez2 += *stifPtr++*vectTmp1;
				tmpRez2 += *stifPtr++*vectTmp2;
				tmpRez2 += *stifPtr++*vectTmp3;
				tmpRez3 += *stifPtr++*vectTmp1;
				tmpRez3 += *stifPtr++*vectTmp2;
				tmpRez3 += *stifPtr++*vectTmp3;

				shiftBase++;
			}//Loop over blocks in row

			if(type == UP_TREANGLE_MATRIX || type == DOWN_TREANGLE_MATRIX){
				//Process blocks with alternative storage
				blockBandLength = shiftIndAlter[ct+1]-shiftIndAlter[ct];
				shiftBase = indAlter + shiftIndAlter[ct];//Pointer to index of current vector part
				for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
					stifPtr = ptrDataAlter[shiftIndAlter[ct] + ct1];//Pointer to current stiffness block
					vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

					vectTmp1 = *vectPtr++;//Variables for further access
					vectTmp2 = *vectPtr++;
					vectTmp3 = *vectPtr;
					tmpRez1 += *stifPtr++*vectTmp1;
					tmpRez2 += *stifPtr++*vectTmp1;
					tmpRez3 += *stifPtr++*vectTmp1;
					tmpRez1 += *stifPtr++*vectTmp2;
					tmpRez2 += *stifPtr++*vectTmp2;
					tmpRez3 += *stifPtr++*vectTmp2;
					tmpRez1 += *stifPtr++*vectTmp3;
					tmpRez2 += *stifPtr++*vectTmp3;
					tmpRez3 += *stifPtr*vectTmp3;

					shiftBase++;
				}//Loop over blocks in row
			}//(type == UP_TREANGLE_MATRIX || type == DOWN_TREANGLE_MATRIX)

			*rezPtr++ = tmpRez1;
			*rezPtr++ = tmpRez2;
			*rezPtr = tmpRez3;

		}//Loop over rows.
	}//Version with sequenced rows
	else{//Version with indexed rows
		//Nulling result
		//int length = stopRow-startRow;
		int curRow;
		//for(int ct = startRow; ct < stopRow; ct++) {curRow = rowIndexes[ct]; result[3*curRow]=result[3*curRow+1]=result[3*curRow+2]=0.0;}//Is nulling necessary? rezPtr[0] = tmpRez1; ... ??????
		for(ct = startRow; ct < stopRow; ct++){//Loop over rows.
			//Each row can be evaluated separately?
			curRow = rowIndexes[ct];
			rezPtr = result + 3*curRow;
			tmpRez1 = 0; tmpRez2 = 0; tmpRez3 = 0;

			//Process normal blocks
			blockBandLength = shiftInd[curRow+1]-shiftInd[curRow];
			shiftBase = ind + shiftInd[curRow];//Pointer to index of current vector part
			stifPtr = data + shiftInd[curRow]*9;//Pointer to current stiffness block
			for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
				vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

				vectTmp1 = *vectPtr++;//Variables for further access
				vectTmp2 = *vectPtr++;
				vectTmp3 = *vectPtr;
				tmpRez1 += *stifPtr++*vectTmp1;
				tmpRez1 += *stifPtr++*vectTmp2;
				tmpRez1 += *stifPtr++*vectTmp3;
				tmpRez2 += *stifPtr++*vectTmp1;
				tmpRez2 += *stifPtr++*vectTmp2;
				tmpRez2 += *stifPtr++*vectTmp3;
				tmpRez3 += *stifPtr++*vectTmp1;
				tmpRez3 += *stifPtr++*vectTmp2;
				tmpRez3 += *stifPtr++*vectTmp3;

				shiftBase++;
			}//Loop over blocks in row

			if(type == UP_TREANGLE_MATRIX || type == DOWN_TREANGLE_MATRIX){
				//Process blocks with alternative storage
				blockBandLength = shiftIndAlter[curRow+1]-shiftIndAlter[curRow];
				shiftBase = indAlter + shiftIndAlter[curRow];//Pointer to index of current vector part
				for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
					stifPtr = ptrDataAlter[shiftIndAlter[curRow] + ct1];//Pointer to current stiffness block
					vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

					vectTmp1 = *vectPtr++;//Variables for further access
					vectTmp2 = *vectPtr++;
					vectTmp3 = *vectPtr;
					tmpRez1 += *stifPtr++*vectTmp1;
					tmpRez2 += *stifPtr++*vectTmp1;
					tmpRez3 += *stifPtr++*vectTmp1;
					tmpRez1 += *stifPtr++*vectTmp2;
					tmpRez2 += *stifPtr++*vectTmp2;
					tmpRez3 += *stifPtr++*vectTmp2;
					tmpRez1 += *stifPtr++*vectTmp3;
					tmpRez2 += *stifPtr++*vectTmp3;
					tmpRez3 += *stifPtr*vectTmp3;

					shiftBase++;
				}//Loop over blocks in row
			}//(type == UP_TREANGLE_MATRIX || type == DOWN_TREANGLE_MATRIX)

			*rezPtr++ = tmpRez1;
			*rezPtr++ = tmpRez2;
			*rezPtr = tmpRez3;
		}//Loop over rows.
	}//Version with indexed rows
}

static void makeStiffMatrixBlock3x3MultiplicationLoop(void *data_)
{
	StiffMatrixBlock3x3MultiplicationData * tData = (StiffMatrixBlock3x3MultiplicationData *) data_;

	int startRow, stopRow;
	int *rowIndexes;//, rowIndexesLength;
	startRow = tData->startRow;
	stopRow = tData->stopRow;
	rowIndexes = tData->rowIndexes;
	//rowIndexesLength = tData->rowIndexesLength;
	double *result = tData->result;
	double *vector = tData->vector;

	double *data = (double*)tData->stiffMatrix->data();
	int *ind = (int*)tData->stiffMatrix->indData(), *shiftInd = (int*)tData->stiffMatrix->shiftIndData();
	double ** ptrDataAlter = (double **)tData->stiffMatrix->ptrDataAlter();
	int *indAlter = (int*)tData->stiffMatrix->indDataAlter(), *shiftIndAlter = (int*)tData->stiffMatrix->shiftIndDataAlter();
	int ct;
	double *rezPtr, *stifPtr, *vectPtr;
	double vectTmp1, vectTmp2, vectTmp3;
	int blockBandLength;
	int *shiftBase;
	double tmpRez1, tmpRez2, tmpRez3;

	//Signal stop
	event_set(& tData->stop);

	if(tData->stiffMatrix->type() == FULL_MATRIX){//Code for normal storage of matrix
		if(rowIndexes == NULL){//Version with sequenced rows
			for(;;){//Ever loop
				//Wait for start
				event_wait(& tData->start);

				for(ct = startRow; ct < stopRow; ct++){//Loop over rows.
					//Each row can be evaluated separately
					rezPtr = result + 3*ct;
					tmpRez1 = 0; tmpRez2 = 0; tmpRez3 = 0;
					blockBandLength = shiftInd[ct+1]-shiftInd[ct];
					shiftBase = ind + shiftInd[ct];//Pointer to index of current vector part
					stifPtr = data + shiftInd[ct]*9;//Pointer to current stiffness block

#ifndef USE_MATMUL_UNROLL//Do not use manual unrolled functions in matrix multiplication
					//Following loop should be replaced by calling of functions with unrolled row processing
					for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
						vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

						//						vectTmp1 = *vectPtr++;//Variables for further access
						//						vectTmp2 = *vectPtr++;
						//						vectTmp3 = *vectPtr;
						//						tmpRez1 += *stifPtr++*vectTmp1;
						//						tmpRez1 += *stifPtr++*vectTmp2;
						//						tmpRez1 += *stifPtr++*vectTmp3;
						//						tmpRez2 += *stifPtr++*vectTmp1;
						//						tmpRez2 += *stifPtr++*vectTmp2;
						//						tmpRez2 += *stifPtr++*vectTmp3;
						//						tmpRez3 += *stifPtr++*vectTmp1;
						//						tmpRez3 += *stifPtr++*vectTmp2;
						//						tmpRez3 += *stifPtr++*vectTmp3;

						//Trying to optimize

						vectTmp1 = vectPtr[0];//Variables for further access
						vectTmp2 = vectPtr[1];
						vectTmp3 = vectPtr[2];
						tmpRez1 += stifPtr[0]*vectTmp1;
						tmpRez1 += stifPtr[1]*vectTmp2;
						tmpRez1 += stifPtr[2]*vectTmp3;
						tmpRez2 += stifPtr[3]*vectTmp1;
						tmpRez2 += stifPtr[4]*vectTmp2;
						tmpRez2 += stifPtr[5]*vectTmp3;
						tmpRez3 += stifPtr[6]*vectTmp1;
						tmpRez3 += stifPtr[7]*vectTmp2;
						tmpRez3 += stifPtr[8]*vectTmp3;
						stifPtr += 9;

						shiftBase++;
					}//Loop over blocks in row

					*rezPtr++ = tmpRez1;
					*rezPtr++ = tmpRez2;
					*rezPtr = tmpRez3;
#else//Use manual unrolled functions in matrix multiplication
					//pre-unrolled functions
					makeMulRowFunctions[blockBandLength](vector, stifPtr, rezPtr, shiftBase);
#endif//USE_MATMUL_UNROLL
				}//Loop over rows.

				//Signal stop
				event_set(& tData->stop);

			}//Ever loop
		}//Version with sequenced rows
		else{//Version with indexed rows

			for(;;){//Ever loop
				//Wait for start
				event_wait(& tData->start);

				int curRow;
				for(ct = startRow; ct < stopRow; ct++){//Loop over rows.
					//Each row can be evaluated separately
					curRow = rowIndexes[ct];
					rezPtr = result + 3*curRow;
					tmpRez1 = 0; tmpRez2 = 0; tmpRez3 = 0;
					blockBandLength = shiftInd[curRow+1]-shiftInd[curRow];
					shiftBase = ind + shiftInd[curRow];//Pointer to index of current vector part
					stifPtr = data + shiftInd[curRow]*9;//Pointer to current stiffness block

#ifndef USE_MATMUL_UNROLL//Do not use manual unrolled functions in matrix multiplication
					//Following loop should be replaced by calling of functions with unrolled row processing
					for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
						vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

						vectTmp1 = *vectPtr++;//Variables for further access
						vectTmp2 = *vectPtr++;
						vectTmp3 = *vectPtr;
						tmpRez1 += *stifPtr++*vectTmp1;
						tmpRez1 += *stifPtr++*vectTmp2;
						tmpRez1 += *stifPtr++*vectTmp3;
						tmpRez2 += *stifPtr++*vectTmp1;
						tmpRez2 += *stifPtr++*vectTmp2;
						tmpRez2 += *stifPtr++*vectTmp3;
						tmpRez3 += *stifPtr++*vectTmp1;
						tmpRez3 += *stifPtr++*vectTmp2;
						tmpRez3 += *stifPtr++*vectTmp3;

						shiftBase++;
					}//Loop over blocks in row

					*rezPtr++ = tmpRez1;
					*rezPtr++ = tmpRez2;
					*rezPtr = tmpRez3;

#else//Use manual unrolled functions in matrix multiplication
					//pre-unrolled functions
					makeMulRowFunctions[blockBandLength](vector, stifPtr, rezPtr, shiftBase);
#endif//USE_MATMUL_UNROLL

				}//Loop over rows.

				//Signal stop
				event_set(& tData->stop);

			}//Ever loop
		}//Version with indexed rows
	}//Code for normal storage of matrix

	else{//Code for alternative storage of matrix
		if(rowIndexes == NULL){//Version with sequenced rows
			for(;;){//Ever loop
				//Wait for start
				event_wait(& tData->start);

				for(ct = startRow; ct < stopRow; ct++){//Loop over rows.
					//Each row can be evaluated separately
					rezPtr = result + 3*ct;
					tmpRez1 = 0; tmpRez2 = 0; tmpRez3 = 0;
					blockBandLength = shiftInd[ct+1]-shiftInd[ct];
					shiftBase = ind + shiftInd[ct];//Pointer to index of current vector part
					stifPtr = data + shiftInd[ct]*9;//Pointer to current stiffness block

#ifndef USE_MATMUL_UNROLL//Do not use manual unrolled functions in matrix multiplication
					for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
						vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

						vectTmp1 = *vectPtr++;//Variables for further access
						vectTmp2 = *vectPtr++;
						vectTmp3 = *vectPtr;
						tmpRez1 += *stifPtr++*vectTmp1;
						tmpRez1 += *stifPtr++*vectTmp2;
						tmpRez1 += *stifPtr++*vectTmp3;
						tmpRez2 += *stifPtr++*vectTmp1;
						tmpRez2 += *stifPtr++*vectTmp2;
						tmpRez2 += *stifPtr++*vectTmp3;
						tmpRez3 += *stifPtr++*vectTmp1;
						tmpRez3 += *stifPtr++*vectTmp2;
						tmpRez3 += *stifPtr++*vectTmp3;

						shiftBase++;
					}//Loop over blocks in row
#else//Use manual unrolled functions in matrix multiplication
					//pre-unrolled functions
					makeMulRowFunctions[blockBandLength](vector, stifPtr, rezPtr, shiftBase);
#endif//USE_MATMUL_UNROLL

					//Process blocks with alternative storage
					blockBandLength = shiftIndAlter[ct+1]-shiftIndAlter[ct];
					shiftBase = indAlter + shiftIndAlter[ct];//Pointer to index of current vector part
#ifndef USE_MATMUL_UNROLL//Do not use manual unrolled functions in matrix multiplication
					for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
						stifPtr = ptrDataAlter[shiftIndAlter[ct] + ct1];//Pointer to current stiffness block
						vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

						vectTmp1 = *vectPtr++;//Variables for further access
						vectTmp2 = *vectPtr++;
						vectTmp3 = *vectPtr;
						tmpRez1 += *stifPtr++*vectTmp1;
						tmpRez2 += *stifPtr++*vectTmp1;
						tmpRez3 += *stifPtr++*vectTmp1;
						tmpRez1 += *stifPtr++*vectTmp2;
						tmpRez2 += *stifPtr++*vectTmp2;
						tmpRez3 += *stifPtr++*vectTmp2;
						tmpRez1 += *stifPtr++*vectTmp3;
						tmpRez2 += *stifPtr++*vectTmp3;
						tmpRez3 += *stifPtr*vectTmp3;

						shiftBase++;
					}//Loop over blocks in row

					*rezPtr++ = tmpRez1;
					*rezPtr++ = tmpRez2;
					*rezPtr = tmpRez3;

#else//Use manual unrolled functions in matrix multiplication
					//pre-unrolled functions
					makeMulRowAlterFunctions[blockBandLength](vector, &ptrDataAlter[shiftIndAlter[ct]], rezPtr, shiftBase);
#endif//USE_MATMUL_UNROLL

				}//Loop over rows.

				//Signal stop
				event_set(& tData->stop);

			}//Ever loop
		}//Version with sequenced rows
		else{//Version with indexed rows

			for(;;){//Ever loop
				//Wait for start
				event_wait(& tData->start);

				int curRow;
				for(ct = startRow; ct < stopRow; ct++){//Loop over rows.
					//Each row can be evaluated separately
					curRow = rowIndexes[ct];
					rezPtr = result + 3*curRow;
					tmpRez1 = 0; tmpRez2 = 0; tmpRez3 = 0;
					blockBandLength = shiftInd[curRow+1]-shiftInd[curRow];
					shiftBase = ind + shiftInd[curRow];//Pointer to index of current vector part
					stifPtr = data + shiftInd[curRow]*9;//Pointer to current stiffness block

#ifndef USE_MATMUL_UNROLL//Do not use manual unrolled functions in matrix multiplication
					for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
						vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

						vectTmp1 = *vectPtr++;//Variables for further access
						vectTmp2 = *vectPtr++;
						vectTmp3 = *vectPtr;
						tmpRez1 += *stifPtr++*vectTmp1;
						tmpRez1 += *stifPtr++*vectTmp2;
						tmpRez1 += *stifPtr++*vectTmp3;
						tmpRez2 += *stifPtr++*vectTmp1;
						tmpRez2 += *stifPtr++*vectTmp2;
						tmpRez2 += *stifPtr++*vectTmp3;
						tmpRez3 += *stifPtr++*vectTmp1;
						tmpRez3 += *stifPtr++*vectTmp2;
						tmpRez3 += *stifPtr++*vectTmp3;

						shiftBase++;
					}//Loop over blocks in row
#else//Use manual unrolled functions in matrix multiplication
					//pre-unrolled functions
					makeMulRowFunctions[blockBandLength](vector, stifPtr, rezPtr, shiftBase);
#endif//USE_MATMUL_UNROLL

					//Process blocks with alternative storage
					blockBandLength = shiftIndAlter[curRow+1]-shiftIndAlter[curRow];
					shiftBase = indAlter + shiftIndAlter[curRow];//Pointer to index of current vector part

#ifndef USE_MATMUL_UNROLL//Do not use manual unrolled functions in matrix multiplication
					for(int ct1 = 0; ct1 < blockBandLength; ct1++){//Loop over blocks in row
						stifPtr = ptrDataAlter[shiftIndAlter[curRow] + ct1];//Pointer to current stiffness block
						vectPtr = vector + 3**shiftBase;//Pointer to vector components corresponded to current stiff block

						vectTmp1 = *vectPtr++;//Variables for further access
						vectTmp2 = *vectPtr++;
						vectTmp3 = *vectPtr;
						tmpRez1 += *stifPtr++*vectTmp1;
						tmpRez2 += *stifPtr++*vectTmp1;
						tmpRez3 += *stifPtr++*vectTmp1;
						tmpRez1 += *stifPtr++*vectTmp2;
						tmpRez2 += *stifPtr++*vectTmp2;
						tmpRez3 += *stifPtr++*vectTmp2;
						tmpRez1 += *stifPtr++*vectTmp3;
						tmpRez2 += *stifPtr++*vectTmp3;
						tmpRez3 += *stifPtr*vectTmp3;

						shiftBase++;
					}//Loop over blocks in row

					*rezPtr++ = tmpRez1;
					*rezPtr++ = tmpRez2;
					*rezPtr = tmpRez3;
#else//Use manual unrolled functions in matrix multiplication
					//pre-unrolled functions
					makeMulRowAlterFunctions[blockBandLength](vector, &ptrDataAlter[shiftIndAlter[ct]], rezPtr, shiftBase);
#endif//USE_MATMUL_UNROLL
				}//Loop over rows.

				//Signal stop
				event_set(& tData->stop);
			}//Ever loop
		}//Version with indexed rows
	}//Code for alternative storage of matrix
}

//TODO - improve versions for UP_TREANGLE_MATRIX and DOWN_TREANGLE_MATRIX

void StiffMatrixBlock3x3::write(std::ofstream &out)
{
	out.write((char *)&type_, sizeof(type_));
	out.write((char *)&numNodes_, sizeof(numNodes_));
	out.write((char *)&numBlocks_, sizeof(numBlocks_));

	if(type_ == UP_TREANGLE_MATRIX || type_ == DOWN_TREANGLE_MATRIX)
		out.write((char *)&numBlocksAlter_, sizeof(numBlocksAlter_));

	out.write((char *)indJ_, 2*numBlocks_*sizeof(indJ_[0]));
	out.write((char *)shiftInd_, (numNodes_+1)*sizeof(shiftInd_[0]));
	out.write((char *)data_, numBlocks_*9*sizeof(data_[0]));
	if(type_ == UP_TREANGLE_MATRIX || type_ == DOWN_TREANGLE_MATRIX){//Alternate information
		out.write((char *)indJAlter_, 2*numBlocksAlter_*sizeof(indJAlter_[0]));
		out.write((char *)shiftIndAlter_, (numNodes_+1)*sizeof(shiftIndAlter_[0]));
		std::vector<int> shiftPtrDataAlter;
		shiftPtrDataAlter.resize(numBlocksAlter_);
		for(int ct = 0; ct < numBlocksAlter_; ct++)
			shiftPtrDataAlter[ct] = (int)(ptrDataAlter_[ct] - data_);
		out.write((char *)&(shiftPtrDataAlter[0]), numBlocksAlter_*sizeof(shiftPtrDataAlter[0]));
	}//Alternate information
}
void StiffMatrixBlock3x3::read(std::ifstream &in)
{
	in.read((char *)&type_, sizeof(type_));
	in.read((char *)&numNodes_, sizeof(numNodes_));
	in.read((char *)&numBlocks_, sizeof(numBlocks_));

	if(type_ == UP_TREANGLE_MATRIX || type_ == DOWN_TREANGLE_MATRIX)
		in.read((char *)&numBlocksAlter_, sizeof(numBlocksAlter_));

	if(type_ == FULL_MATRIX)
		setNumBlocksNodes(numBlocks_, numNodes_);
	if(type_ == UP_TREANGLE_MATRIX || type_ == DOWN_TREANGLE_MATRIX)
		setNumBlocksNodes(numBlocks_, numNodes_, numBlocksAlter_);

	in.read((char *)indJ_, 2*numBlocks_*sizeof(indJ_[0]));
	in.read((char *)shiftInd_, (numNodes_+1)*sizeof(shiftInd_[0]));
	in.read((char *)data_, numBlocks_*9*sizeof(data_[0]));
	if(type_ == UP_TREANGLE_MATRIX || type_ == DOWN_TREANGLE_MATRIX){//Alternate information
		in.read((char *)indJAlter_, 2*numBlocksAlter_*sizeof(indJAlter_[0]));
		in.read((char *)shiftIndAlter_, (numNodes_+1)*sizeof(shiftIndAlter_[0]));
		std::vector<int> shiftPtrDataAlter;
		shiftPtrDataAlter.resize(numBlocksAlter_);
		in.read((char *)&(shiftPtrDataAlter[0]), numBlocksAlter_*sizeof(shiftPtrDataAlter[0]));
		for(int ct = 0; ct < numBlocksAlter_; ct++)
			ptrDataAlter_[ct] = data_ + shiftPtrDataAlter[ct];
	}//Alternate information
}
void StiffMatrixBlock3x3::printTopology(const char * name)
{
	std::ofstream out(name);
	if(out.good())
	{
		for(int ct = 0; ct < numNodes_; ct++)
		{
			int bandLength = shiftInd_[ct+1] - shiftInd_[ct];
			for(int ct1 = 0; ct1 < bandLength; ct1++)
				out << ct << "\t" << indJ_[shiftInd_[ct] + ct1] << std::endl;
		}
	}
	out.close();
}
void StiffMatrixBlock3x3::printTopology2(const char * name, int plotRate)
{
	std::ofstream out(name);
	if(out.good())
	{
		for(int ct = 0; ct < numNodes_; ct += plotRate)
		{
			//int bandLength = shiftInd_[ct+1] - shiftInd_[ct];
			out << indJ_[shiftInd_[ct]] << "\t" << -ct << std::endl;
			out << indJ_[shiftInd_[ct+1]-1] << "\t" << -ct << std::endl;
		}
	}
	out.close();
}
void StiffMatrixBlock3x3::setMesh(sbfMesh * mesh)
{mesh_ = mesh;}
sbfMesh * StiffMatrixBlock3x3::mesh()
{return mesh_;}
void StiffMatrixBlock3x3::setPropSet(sbfPropertiesSet * propSet)
{propSet_ = propSet;}
sbfPropertiesSet * StiffMatrixBlock3x3::propSet()
{return propSet_;}

StiffMatrixBlock3x3 * StiffMatrixBlock3x3::makeIncompleteChol(double thresholdAmp)
{
	if(this->isDOFMerged_ == false) return NULL;

	StiffMatrixBlock3x3 * cholFactor = new StiffMatrixBlock3x3();

	cholFactor->setType(DOWN_TREANGLE_MATRIX);
	int /*numOriginBlocks, */numOriginNodes;
	int numTargetBlocks, numTargetNodes;
	const int *originIndJ, *originShiftInd;
	int *targetIndJ, *targetShiftInd;
	int numTargetBlocksAlter, *targetIndJAlter, *targetShiftIndAlter;

//	numOriginBlocks = this->numBlocks();
	numOriginNodes = this->numNodes();
	numTargetBlocks = 0;
	numTargetNodes = numOriginNodes;

	originIndJ = this->indData();
	originShiftInd = this->shiftIndData();

	//Use STL to get indexing to low triangle
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! it may lead to performance lowering (or not :) ) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	std::list<indexes2> downIndexes;
	std::list<indexes2> upIndexes;
	for(int ctNode = 0; ctNode < numOriginNodes; ctNode++) for(int ctIndJ = originShiftInd[ctNode]; ctIndJ < originShiftInd[ctNode+1]; ctIndJ++) {
		int indI = ctNode, indJ = originIndJ[ctIndJ];
		indexes2 ind2;
		if(indI >= indJ) {ind2.i = indI; ind2.j = indJ;} else {ind2.i = indJ; ind2.j = indI;}
		downIndexes.push_back(ind2);
		if(indI != indJ){
			if(indI < indJ) {ind2.i = indI; ind2.j = indJ;} else {ind2.i = indJ; ind2.j = indI;}
			upIndexes.push_back(ind2);
		}
	}
	downIndexes.sort();
	downIndexes.unique();//indexes sorted and contains only low triangle
	upIndexes.sort();
	upIndexes.unique();//indexes sorted and contains only upper triangle

	numTargetBlocks = static_cast<int>(downIndexes.size());
	targetIndJ = new int [numTargetBlocks];
	targetShiftInd = new int [numTargetNodes+1];

	numTargetBlocksAlter = static_cast<int>(upIndexes.size());
	targetIndJAlter = new int [numTargetBlocksAlter];
	targetShiftIndAlter = new int [numTargetNodes+1];

	int count = 0;
	for(int siftCount = 0; siftCount < numOriginNodes+1; targetShiftInd[siftCount++] = 0);
	for(std::list<indexes2>::iterator it = downIndexes.begin(); it != downIndexes.end(); it++){
		targetIndJ[count] = (*it).j;
		targetShiftInd[(*it).i+1] = count+1;
		count++;
	}
	count = 0;
	for(int siftCount = 0; siftCount < numOriginNodes+1; targetShiftIndAlter[siftCount++] = 0);
	for(std::list<indexes2>::iterator it = upIndexes.begin(); it != upIndexes.end(); it++){
		targetIndJAlter[count] = (*it).j;
		targetShiftIndAlter[(*it).i+1] = count+1;
		count++;
	}
	targetShiftIndAlter[numTargetNodes] = numTargetBlocksAlter;

	cholFactor->setIndData(numTargetNodes, numTargetBlocks, targetIndJ, targetShiftInd, numTargetBlocksAlter, targetIndJAlter, targetShiftIndAlter);
	cholFactor->updataAlterPtr();
	cholFactor->null();

	//Serial code of incomplete chol fill

	double * blockDiag, * blockCt, * blockCt1, *block;
	double * blockDiagTarget, * blockTarget;
	bool isDirect;
	for(int diagCt = 0; diagCt < numTargetNodes; diagCt++){//Loop on block rows
		//Process diagonal block
		//if(diagCt % (numTargetNodes/1000) == 0) std::cout << "\r" << diagCt << "\t/" << numTargetNodes;
		blockDiag = this->data(diagCt, diagCt, NULL);//Diagonal block is always at normal storage
		blockDiagTarget = cholFactor->blockPtr(diagCt, diagCt);//Look only in normal storage
		blockDiagTarget[1] = 0;//Nulling above diagonal elements
		blockDiagTarget[2] = 0;
		blockDiagTarget[5] = 0;
		double sum[6];// 00 11 22 01 02 12 - regular and cross sums
		sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;
		for(int colCt = 0; colCt < diagCt; colCt++){//Loop on blocks in row
			blockCt = cholFactor->blockPtr(diagCt, colCt);
			if(!blockCt) continue;
			sum[0] += blockCt[0]*blockCt[0] + blockCt[1]*blockCt[1] + blockCt[2]*blockCt[2];
			sum[1] += blockCt[3]*blockCt[3] + blockCt[4]*blockCt[4] + blockCt[5]*blockCt[5];
			sum[2] += blockCt[6]*blockCt[6] + blockCt[7]*blockCt[7] + blockCt[8]*blockCt[8];
			sum[3] += blockCt[0]*blockCt[3] + blockCt[1]*blockCt[4] + blockCt[2]*blockCt[5];
			sum[4] += blockCt[0]*blockCt[6] + blockCt[1]*blockCt[7] + blockCt[2]*blockCt[8];
			sum[5] += blockCt[3]*blockCt[6] + blockCt[4]*blockCt[7] + blockCt[5]*blockCt[8];
		}//Loop on blocks in row
		blockDiagTarget[0] = std::sqrt(blockDiag[0] - sum[0]);
		blockDiagTarget[3] = blockDiag[3] != 0.0 ? (blockDiag[3] - sum[3]) / blockDiagTarget[0] : 0.0;
		blockDiagTarget[6] = blockDiag[6] != 0.0 ? (blockDiag[6] - sum[4]) / blockDiagTarget[0] : 0.0;
		sum[1] += blockDiagTarget[3]*blockDiagTarget[3];
		sum[2] += blockDiagTarget[6]*blockDiagTarget[6];
		sum[5] += blockDiagTarget[3]*blockDiagTarget[6];
		blockDiagTarget[4] = std::sqrt(blockDiag[4] - sum[1]);
		blockDiagTarget[7] = blockDiag[7] != 0.0 ? (blockDiag[7] - sum[5]) / blockDiagTarget[4] : 0.0;
		sum[2] += blockDiagTarget[7]*blockDiagTarget[7];
		blockDiagTarget[8] = std::sqrt(blockDiag[8] - sum[2]);
		//Process diagonal block - END

		//Process blocks under diagonal

		double rowSum[9];// 00 01 02 10 11 12 20 21 22
		double blockData[9];//
		for(int rowCt = diagCt + 1; rowCt < numTargetNodes; rowCt++){//Loop on blocks under current diagonal block
			blockTarget = cholFactor->blockPtr(rowCt, diagCt);//Look only in normal storage
			if(!blockTarget) continue;
			block = this->data(rowCt, diagCt, &isDirect);//May be at alternative storage
			if(isDirect) for(int ct = 0; ct < 9; ct++) blockData[ct] = block[ct];
			else for(int ctI = 0; ctI < 3; ctI++) for(int ctJ = 0; ctJ < 3; ctJ++) blockData[ctI*3+ctJ] = block[ctJ*3+ctI];
			rowSum[0] = rowSum[1] = rowSum[2] = rowSum[3] = rowSum[4] = rowSum[5] = rowSum[6] = rowSum[7] = rowSum[8] = 0.0;
			for(int colCt = 0; colCt < diagCt; colCt++){//Loop on blocks in row
				blockCt = cholFactor->blockPtr(rowCt, colCt);
				if(!blockCt) continue;
				blockCt1 = cholFactor->blockPtr(diagCt, colCt);
				if(!blockCt1) continue;
				//collect sums
				rowSum[0] += blockCt[0]*blockCt1[0] + blockCt[1]*blockCt1[1] + blockCt[2]*blockCt1[2];
				rowSum[1] += blockCt[0]*blockCt1[3] + blockCt[1]*blockCt1[4] + blockCt[2]*blockCt1[5];
				rowSum[2] += blockCt[0]*blockCt1[6] + blockCt[1]*blockCt1[7] + blockCt[2]*blockCt1[8];
				rowSum[3] += blockCt[3]*blockCt1[0] + blockCt[4]*blockCt1[1] + blockCt[5]*blockCt1[2];
				rowSum[4] += blockCt[3]*blockCt1[3] + blockCt[4]*blockCt1[4] + blockCt[5]*blockCt1[5];
				rowSum[5] += blockCt[3]*blockCt1[6] + blockCt[4]*blockCt1[7] + blockCt[5]*blockCt1[8];
				rowSum[6] += blockCt[6]*blockCt1[0] + blockCt[7]*blockCt1[1] + blockCt[8]*blockCt1[2];
				rowSum[7] += blockCt[6]*blockCt1[3] + blockCt[7]*blockCt1[4] + blockCt[8]*blockCt1[5];
				rowSum[8] += blockCt[6]*blockCt1[6] + blockCt[7]*blockCt1[7] + blockCt[8]*blockCt1[8];
			}//Loop on blocks in row
			blockTarget[0] = blockData[0] != 0.0 ? (blockData[0] - rowSum[0]) / blockDiagTarget[0] : 0.0;
			blockTarget[3] = blockData[3] != 0.0 ? (blockData[3] - rowSum[3]) / blockDiagTarget[0] : 0.0;
			blockTarget[6] = blockData[6] != 0.0 ? (blockData[6] - rowSum[6]) / blockDiagTarget[0] : 0.0;
			rowSum[1] += blockTarget[0]*blockDiagTarget[3];
			rowSum[4] += blockTarget[3]*blockDiagTarget[3];
			rowSum[7] += blockTarget[6]*blockDiagTarget[3];
			blockTarget[1] = blockData[1] != 0.0 ? (blockData[1] - rowSum[1]) / blockDiagTarget[4] : 0.0;
			blockTarget[4] = blockData[4] != 0.0 ? (blockData[4] - rowSum[4]) / blockDiagTarget[4] : 0.0;
			blockTarget[7] = blockData[7] != 0.0 ? (blockData[7] - rowSum[7]) / blockDiagTarget[4] : 0.0;
			rowSum[2] += blockTarget[0]*blockDiagTarget[6] + blockTarget[1]*blockDiagTarget[7];
			rowSum[5] += blockTarget[3]*blockDiagTarget[6] + blockTarget[4]*blockDiagTarget[7];
			rowSum[8] += blockTarget[6]*blockDiagTarget[6] + blockTarget[7]*blockDiagTarget[7];
			blockTarget[2] = blockData[2] != 0.0 ? (blockData[2] - rowSum[2]) / blockDiagTarget[8] : 0.0;
			blockTarget[5] = blockData[5] != 0.0 ? (blockData[5] - rowSum[5]) / blockDiagTarget[8] : 0.0;
			blockTarget[8] = blockData[8] != 0.0 ? (blockData[8] - rowSum[8]) / blockDiagTarget[8] : 0.0;
		}//Loop on blocks under current diagonal block

		//Process blocks under diagonal - END
	}//Loop on block rows

	return cholFactor;
}

ElemStiffMatrixHexa8::ElemStiffMatrixHexa8()
{
	data_ = new double [8*8*9];
	elem_ = NULL;
	numIntPoints_ = 2;
	propSet_ = NULL;
}
ElemStiffMatrixHexa8::ElemStiffMatrixHexa8(sbfElement * elem)
{
	data_ = new double [8*8*9];
	numIntPoints_ = 2;
	setElem(elem);
	propSet_ = NULL;
}
ElemStiffMatrixHexa8::~ElemStiffMatrixHexa8()
{
	if(data_ != NULL)
		delete [] data_;
}
void ElemStiffMatrixHexa8::setElem(sbfElement * elem)
{
	if(elem->type() != HEXAHEDRON_LINEAR)
	{
		elem_ = NULL;
		return;
	}
	elem_ = elem;
	sbfMesh *mesh = elem->mesh();
	sbfNode node;
	std::vector<int> indexes = elem->indexes();
	for(int ct = 0; ct < 8; ct++)
	{
		ind_[ct] = indexes[ct];
		node = mesh->node(indexes[ct]);
		crd_[ct] = node.x();
		crd_[ct+8] = node.y();
		crd_[ct+8*2] = node.z();
	}
}
sbfElement & ElemStiffMatrixHexa8::elem()
{return *elem_;}
void ElemStiffMatrixHexa8::setNumIntPoints(int numIntPoints)
{numIntPoints_ = numIntPoints;}
int ElemStiffMatrixHexa8::numIntPoints()
{return numIntPoints_;}
void ElemStiffMatrixHexa8::computeH(double r, double s, double t)
{
	/*
	 *Compute values of form functions at specific point in natural coordinates
	 *H_[0] = h0(r, s, t), H_[1] = h1(r, s, t), etc.
	 */
	double onePlusR = (1.+r);
	double oneMinusR = (1.-r);
	double onePlusS = (1.+s);
	double oneMinusS = (1.-s);
	double onePlusT = (1.+t);
	double oneMinusT = (1.-t);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ERROR in nodes numeration. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//Solved
	H_[0] = onePlusR*onePlusS*onePlusT/8.0;
	H_[3] = oneMinusR*onePlusS*onePlusT/8.0;
	H_[2] = oneMinusR*oneMinusS*onePlusT/8.0;
	H_[1] = onePlusR*oneMinusS*onePlusT/8.0;
	H_[4] = onePlusR*onePlusS*oneMinusT/8.0;
	H_[7] = oneMinusR*onePlusS*oneMinusT/8.0;
	H_[6] = oneMinusR*oneMinusS*oneMinusT/8.0;
	H_[5] = onePlusR*oneMinusS*oneMinusT/8.0;
}
void ElemStiffMatrixHexa8::computeDHDN(double r, double s, double t)
{
	/*
	 * Compute values of form functions derivatives over natural coordinates at specific point in natural coordinates
	 * DHDN_[0*3 + 0] = d h0 / d r, DHDN_[0*3 + 1] = d h0 / d s, DHDN_[0*3 + 2] = d h0 / d t, DHDN_[1*3 + 0] = d h1 / d r, etc.
	 */
	double onePlusR = (1.+r);
	double oneMinusR = (1.-r);
	double onePlusS = (1.+s);
	double oneMinusS = (1.-s);
	double onePlusT = (1.+t);
	double oneMinusT = (1.-t);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ERROR in nodes numeration. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//Solved
	DHDN_[0] = onePlusS*onePlusT/8.0;//d h0 / d r
	DHDN_[1] = onePlusR*onePlusT/8.0;//d h0 / d s
	DHDN_[2] = onePlusR*onePlusS/8.0;//d h0 / d t
	DHDN_[9] = -onePlusS*onePlusT/8.0;//d h1 / d r
	DHDN_[10] = oneMinusR*onePlusT/8.0;
	DHDN_[11] = oneMinusR*onePlusS/8.0;
	DHDN_[6] = -oneMinusS*onePlusT/8.0;//d h2 / d r
	DHDN_[7] = -oneMinusR*onePlusT/8.0;
	DHDN_[8] = oneMinusR*oneMinusS/8.0;
	DHDN_[3] = oneMinusS*onePlusT/8.0;//d h3 / d r
	DHDN_[4] = -onePlusR*onePlusT/8.0;
	DHDN_[5] = onePlusR*oneMinusS/8.0;
	DHDN_[12] = onePlusS*oneMinusT/8.0;//d h4 / d r
	DHDN_[13] = onePlusR*oneMinusT/8.0;
	DHDN_[14] = -onePlusR*onePlusS/8.0;
	DHDN_[21] = -onePlusS*oneMinusT/8.0;//d h5 / d r
	DHDN_[22] = oneMinusR*oneMinusT/8.0;
	DHDN_[23] = -oneMinusR*onePlusS/8.0;
	DHDN_[18] = -oneMinusS*oneMinusT/8.0;//d h6 / d r
	DHDN_[19] = -oneMinusR*oneMinusT/8.0;
	DHDN_[20] = -oneMinusR*oneMinusS/8.0;
	DHDN_[15] = oneMinusS*oneMinusT/8.0;//d h7 / d r
	DHDN_[16] = -onePlusR*oneMinusT/8.0;
	DHDN_[17] = -onePlusR*oneMinusS/8.0;
}
void ElemStiffMatrixHexa8::computeJ()
{
	/*
	 * Compute Jacobian and its determinant. computeDHDN(r, s, t) should be performed before !
	 * J_[0] = d x / d r = d h_i / d r * x_i, J_[1] = d h_i / d r * y_i, J_[2] = d h_i / d r * z_i, J_[3] = d h_i / d s * x_i
	 */
	J_[0] = DHDN_[0]*crd_[0] + DHDN_[3]*crd_[1] + DHDN_[6]*crd_[2] + DHDN_[9]*crd_[3] + DHDN_[12]*crd_[4] + DHDN_[15]*crd_[5] + DHDN_[18]*crd_[6] + DHDN_[21]*crd_[7];
	J_[1] = DHDN_[0]*crd_[8] + DHDN_[3]*crd_[9] + DHDN_[6]*crd_[10] + DHDN_[9]*crd_[11] + DHDN_[12]*crd_[12] + DHDN_[15]*crd_[13] + DHDN_[18]*crd_[14] + DHDN_[21]*crd_[15];
	J_[2] = DHDN_[0]*crd_[16] + DHDN_[3]*crd_[17] + DHDN_[6]*crd_[18] + DHDN_[9]*crd_[19] + DHDN_[12]*crd_[20] + DHDN_[15]*crd_[21] + DHDN_[18]*crd_[22] + DHDN_[21]*crd_[23];
	J_[3] = DHDN_[1]*crd_[0] + DHDN_[4]*crd_[1] + DHDN_[7]*crd_[2] + DHDN_[10]*crd_[3] + DHDN_[13]*crd_[4] + DHDN_[16]*crd_[5] + DHDN_[19]*crd_[6] + DHDN_[22]*crd_[7];
	J_[4] = DHDN_[1]*crd_[8] + DHDN_[4]*crd_[9] + DHDN_[7]*crd_[10] + DHDN_[10]*crd_[11] + DHDN_[13]*crd_[12] + DHDN_[16]*crd_[13] + DHDN_[19]*crd_[14] + DHDN_[22]*crd_[15];
	J_[5] = DHDN_[1]*crd_[16] + DHDN_[4]*crd_[17] + DHDN_[7]*crd_[18] + DHDN_[10]*crd_[19] + DHDN_[13]*crd_[20] + DHDN_[16]*crd_[21] + DHDN_[19]*crd_[22] + DHDN_[22]*crd_[23];
	J_[6] = DHDN_[2]*crd_[0] + DHDN_[5]*crd_[1] + DHDN_[8]*crd_[2] + DHDN_[11]*crd_[3] + DHDN_[14]*crd_[4] + DHDN_[17]*crd_[5] + DHDN_[20]*crd_[6] + DHDN_[23]*crd_[7];
	J_[7] = DHDN_[2]*crd_[8] + DHDN_[5]*crd_[9] + DHDN_[8]*crd_[10] + DHDN_[11]*crd_[11] + DHDN_[14]*crd_[12] + DHDN_[17]*crd_[13] + DHDN_[20]*crd_[14] + DHDN_[23]*crd_[15];
	J_[8] = DHDN_[2]*crd_[16] + DHDN_[5]*crd_[17] + DHDN_[8]*crd_[18] + DHDN_[11]*crd_[19] + DHDN_[14]*crd_[20] + DHDN_[17]*crd_[21] + DHDN_[20]*crd_[22] + DHDN_[23]*crd_[23];
	detJ_ = J_[0]*J_[4]*J_[8] + J_[1]*J_[5]*J_[6] + J_[2]*J_[3]*J_[7] - J_[2]*J_[4]*J_[6] - J_[0]*J_[5]*J_[7] - J_[1]*J_[3]*J_[8];
	invJ_[0] = (J_[4]*J_[8] - J_[5]*J_[7])/detJ_;
	invJ_[1] = (J_[2]*J_[7] - J_[1]*J_[8])/detJ_;
	invJ_[2] = (J_[1]*J_[5] - J_[2]*J_[4])/detJ_;
	invJ_[3] = (J_[5]*J_[6] - J_[3]*J_[8])/detJ_;
	invJ_[4] = (J_[0]*J_[8] - J_[2]*J_[6])/detJ_;
	invJ_[5] = (J_[2]*J_[3] - J_[0]*J_[5])/detJ_;
	invJ_[6] = (J_[3]*J_[7] - J_[4]*J_[6])/detJ_;
	invJ_[7] = (J_[1]*J_[6] - J_[0]*J_[7])/detJ_;
	invJ_[8] = (J_[0]*J_[4] - J_[1]*J_[3])/detJ_;
}
void ElemStiffMatrixHexa8::computeDHDG(double r, double s, double t)
{
	/*
	 * Compute values of form functions derivatives over global coordinates at specific point in natural coordinates
	 * DHDG[0*3+0] = d h0 / d x = invJ_[0] * d h0 / d r + invJ_[1] * d h0 / d s + invJ_[2] * d h0 / d t.
	 * DHDG[0*3+1] = d h0 / d y. etc.
	 */
	DHDG_[0] = invJ_[0]*DHDN_[0] + invJ_[1]*DHDN_[1] + invJ_[2]*DHDN_[2];//d h0 / d x
	DHDG_[1] = invJ_[3]*DHDN_[0] + invJ_[4]*DHDN_[1] + invJ_[5]*DHDN_[2];//d h0 / d y
	DHDG_[2] = invJ_[6]*DHDN_[0] + invJ_[7]*DHDN_[1] + invJ_[8]*DHDN_[2];//d h0 / d z
	DHDG_[3] = invJ_[0]*DHDN_[3] + invJ_[1]*DHDN_[4] + invJ_[2]*DHDN_[5];//d h1 / d x
	DHDG_[4] = invJ_[3]*DHDN_[3] + invJ_[4]*DHDN_[4] + invJ_[5]*DHDN_[5];
	DHDG_[5] = invJ_[6]*DHDN_[3] + invJ_[7]*DHDN_[4] + invJ_[8]*DHDN_[5];
	DHDG_[6] = invJ_[0]*DHDN_[6] + invJ_[1]*DHDN_[7] + invJ_[2]*DHDN_[8];//d h2 / d x
	DHDG_[7] = invJ_[3]*DHDN_[6] + invJ_[4]*DHDN_[7] + invJ_[5]*DHDN_[8];
	DHDG_[8] = invJ_[6]*DHDN_[6] + invJ_[7]*DHDN_[7] + invJ_[8]*DHDN_[8];
	DHDG_[9] = invJ_[0]*DHDN_[9] + invJ_[1]*DHDN_[10] + invJ_[2]*DHDN_[11];//d h3 / d x
	DHDG_[10] = invJ_[3]*DHDN_[9] + invJ_[4]*DHDN_[10] + invJ_[5]*DHDN_[11];
	DHDG_[11] = invJ_[6]*DHDN_[9] + invJ_[7]*DHDN_[10] + invJ_[8]*DHDN_[11];
	DHDG_[12] = invJ_[0]*DHDN_[12] + invJ_[1]*DHDN_[13] + invJ_[2]*DHDN_[14];//d h4 / d x
	DHDG_[13] = invJ_[3]*DHDN_[12] + invJ_[4]*DHDN_[13] + invJ_[5]*DHDN_[14];
	DHDG_[14] = invJ_[6]*DHDN_[12] + invJ_[7]*DHDN_[13] + invJ_[8]*DHDN_[14];
	DHDG_[15] = invJ_[0]*DHDN_[15] + invJ_[1]*DHDN_[16] + invJ_[2]*DHDN_[17];//d h5 / d x
	DHDG_[16] = invJ_[3]*DHDN_[15] + invJ_[4]*DHDN_[16] + invJ_[5]*DHDN_[17];
	DHDG_[17] = invJ_[6]*DHDN_[15] + invJ_[7]*DHDN_[16] + invJ_[8]*DHDN_[17];
	DHDG_[18] = invJ_[0]*DHDN_[18] + invJ_[1]*DHDN_[19] + invJ_[2]*DHDN_[20];//d h6 / d x
	DHDG_[19] = invJ_[3]*DHDN_[18] + invJ_[4]*DHDN_[19] + invJ_[5]*DHDN_[20];
	DHDG_[20] = invJ_[6]*DHDN_[18] + invJ_[7]*DHDN_[19] + invJ_[8]*DHDN_[20];
	DHDG_[21] = invJ_[0]*DHDN_[21] + invJ_[1]*DHDN_[22] + invJ_[2]*DHDN_[23];//d h7 / d x
	DHDG_[22] = invJ_[3]*DHDN_[21] + invJ_[4]*DHDN_[22] + invJ_[5]*DHDN_[23];
	DHDG_[23] = invJ_[6]*DHDN_[21] + invJ_[7]*DHDN_[22] + invJ_[8]*DHDN_[23];
}

void ElemStiffMatrixHexa8::computeSM()
{
	/*
	 * Compute stiffness matrix of element
	 */

	if(propSet_ == NULL)
	{/*Throw an exception*/debugMsg("ERROR!!! properties are not set correctly!!!")}

	MaterialProperties *mp = propSet_->material(elem_->mtr() - 1);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	double E = mp->propertyTable("elastic module")->curValue();
	double mu = mp->propertyTable("puasson ratio")->curValue();

	double c_mul = E/((1+mu)*(1-2*mu));//Additional multiplicator

	//Perform integration over volume of integral(BT*C*B*detJ dV)
	for(int ct = 0; ct < 8*8*9; data_[ct++] = 0);//Nulling
	for(int ct = 0; ct < 8*3*6; temp_[ct++] = 0);//Nulling
	//Loop over integration points
	for(int ctR = 0; ctR < numIntPoints_; ctR++){//Loop in r dir
		double r, s, t;
		double weigthR, weigthS, weigthT;
		r = intCrd[numIntPoints_-1][ctR];
		weigthR = intWgh[numIntPoints_-1][ctR];
		for(int ctS = 0; ctS < numIntPoints_; ctS++){//Loop in s dir
			s = intCrd[numIntPoints_-1][ctS];
			weigthS = intWgh[numIntPoints_-1][ctS];
			for(int ctT = 0; ctT < numIntPoints_; ctT++){//Loop in t dir
				t = intCrd[numIntPoints_-1][ctT];
				weigthT = intWgh[numIntPoints_-1][ctT];
				computeH(r, s, t);
				computeDHDN(r, s, t);
				computeJ();
				computeDHDG(r, s, t);
				for(int ct = 0; ct < 8; ct++){//Loop on form functions to obtain result of BT*C
					temp_[3*6*ct] = DHDG_[3*ct]*(1-mu)*c_mul;
					temp_[3*6*ct + 1] = temp_[3*6*ct + 2] = DHDG_[3*ct]*mu*c_mul;
					temp_[3*6*ct + 3] = DHDG_[3*ct+1]*((1-2.*mu)/2.)*c_mul;
					//temp_[3*6*ct + 4] = 0.;// - by matrix topology
					temp_[3*6*ct + 5] = DHDG_[3*ct+2]*((1-2.*mu)/2.)*c_mul;
					temp_[3*6*ct + 6] = DHDG_[3*ct+1]*mu*c_mul;
					temp_[3*6*ct + 7] = DHDG_[3*ct+1]*(1-mu)*c_mul;
					temp_[3*6*ct + 8] = temp_[3*6*ct + 6];
					temp_[3*6*ct + 9] = DHDG_[3*ct]*((1-2.*mu)/2.)*c_mul;
					temp_[3*6*ct + 10] = DHDG_[3*ct+2]*((1-2.*mu)/2.)*c_mul;
					//temp_[3*6*ct + 11] = 0.;// - by matrix topology
					temp_[3*6*ct + 12] = temp_[3*6*ct + 13] = DHDG_[3*ct+2]*mu*c_mul;
					temp_[3*6*ct + 14] = DHDG_[3*ct+2]*(1-mu)*c_mul;
					//temp_[3*6*ct + 15] = 0.;// - by matrix topology
					temp_[3*6*ct + 16] = DHDG_[3*ct+1]*((1-2.*mu)/2.)*c_mul;
					temp_[3*6*ct + 17] = DHDG_[3*ct]*((1-2.*mu)/2.)*c_mul;
				}//Loop on form functions to obtain result of BT*C
				//Compute matrix multiplication (BT*C)*B and add result to stiffness matrix with weights and determinant
				for(int ct1 = 0; ct1 < 8; ct1++){//Loop on rows blocks of matrix (BT*C) upper triangle
					for(int ct2 = ct1; ct2 < 8; ct2++){//Loop on rows blocks of matrix B upper triangle
						data_[(ct1*3)*3*8 + ct2*3] += (temp_[3*6*ct1]*DHDG_[3*ct2]+temp_[3*6*ct1+3]*DHDG_[3*ct2+1]+temp_[3*6*ct1+5]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;
						data_[(ct1*3)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+1]*DHDG_[3*ct2+1]+temp_[3*6*ct1+3]*DHDG_[3*ct2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+4] == 0;
						data_[(ct1*3)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+2]*DHDG_[3*ct2+2]+temp_[3*6*ct1+5]*DHDG_[3*ct2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+4] == 0;

						data_[(ct1*3+1)*3*8 + ct2*3] += (temp_[3*6*ct1+6]*DHDG_[3*ct2]+temp_[3*6*ct1+9]*DHDG_[3*ct2+1])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+11] == 0;
						data_[(ct1*3+1)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+7]*DHDG_[3*ct2+1]+temp_[3*6*ct1+9]*DHDG_[3*ct2]+temp_[3*6*ct1+10]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;
						data_[(ct1*3+1)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+8]*DHDG_[3*ct2+2]+temp_[3*6*ct1+10]*DHDG_[3*ct2+1])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+11] == 0;

						data_[(ct1*3+2)*3*8 + ct2*3] += (temp_[3*6*ct1+12]*DHDG_[3*ct2]+temp_[3*6*ct1+17]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+15] == 0;
						data_[(ct1*3+2)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+13]*DHDG_[3*ct2+1]+temp_[3*6*ct1+16]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+15] == 0;
						data_[(ct1*3+2)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+14]*DHDG_[3*ct2+2]+temp_[3*6*ct1+16]*DHDG_[3*ct2+1]+temp_[3*6*ct1+17]*DHDG_[3*ct2])*weigthR*weigthS*weigthT*detJ_;
					}//Loop on rows blocks of matrix B
				}//Loop on rows blocks of matrix (BT*C)

			}//Loop in t dir
		}//Loop in s dir
	}//Loop in r dir
	for(int ct1 = 0; ct1 < 8; ct1++){//Loop on rows blocks of matrix (BT*C) lower triangle
		for(int ct2 = 0; ct2 < ct1; ct2++){//Loop on rows blocks of matrix B lower triangle
			data_[(ct1*3)*3*8 + ct2*3] = data_[(ct2*3)*3*8 + ct1*3];
			data_[(ct1*3)*3*8 + ct2*3 + 1] = data_[(ct2*3+1)*3*8 + ct1*3];
			data_[(ct1*3)*3*8 + ct2*3 + 2] = data_[(ct2*3+2)*3*8 + ct1*3];

			data_[(ct1*3+1)*3*8 + ct2*3] = data_[(ct2*3)*3*8 + ct1*3 + 1];
			data_[(ct1*3+1)*3*8 + ct2*3 + 1] = data_[(ct2*3+1)*3*8 + ct1*3 + 1];
			data_[(ct1*3+1)*3*8 + ct2*3 + 2] = data_[(ct2*3+2)*3*8 + ct1*3 + 1];

			data_[(ct1*3+2)*3*8 + ct2*3] = data_[(ct2*3)*3*8 + ct1*3 + 2];
			data_[(ct1*3+2)*3*8 + ct2*3 + 1] = data_[(ct2*3+1)*3*8 + ct1*3 + 2];
			data_[(ct1*3+2)*3*8 + ct2*3 + 2] = data_[(ct2*3+2)*3*8 + ct1*3 + 2];
		}//Loop on rows blocks of matrix B
	}//Loop on rows blocks of matrix (BT*C)
}
double ElemStiffMatrixHexa8::computeVolume()
{
	double vol = 0;
	//Loop over integration points
	for(int ctR = 0; ctR < numIntPoints_; ctR++){//Loop in r dir
		double r, s, t;
		double weigthR, weigthS, weigthT;
		r = intCrd[numIntPoints_-1][ctR];
		weigthR = intWgh[numIntPoints_-1][ctR];
		for(int ctS = 0; ctS < numIntPoints_; ctS++){//Loop in s dir
			s = intCrd[numIntPoints_-1][ctS];
			weigthS = intWgh[numIntPoints_-1][ctS];
			for(int ctT = 0; ctT < numIntPoints_; ctT++){//Loop in t dir
				t = intCrd[numIntPoints_-1][ctT];
				weigthT = intWgh[numIntPoints_-1][ctT];
				computeH(r, s, t);
				computeDHDN(r, s, t);
				computeJ();
				vol += weigthR*weigthS*weigthT*detJ_;
			}//Loop in t dir
		}//Loop in s dir
	}//Loop in r dir
	return vol;
}
double ElemStiffMatrixHexa8::computeMass(double rho)
{return rho*computeVolume();}
double ElemStiffMatrixHexa8::computeMass()
{
	if(propSet_ == NULL)
	{/*Throw an exception*/debugMsg("ERROR!!! properties are not set correctly!!!")}

	MaterialProperties *mp = propSet_->material(elem_->mtr() - 1);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	double rho = mp->propertyTable("density")->curValue();
	return computeMass(rho);
}

void ElemStiffMatrixHexa8::getBlockDataLoc(double * data, int localIndI, int localIndJ)
{
	/*
	 * data - pointer to store stiffness block 3*3 with row index localIndI and column index localIndJ.
	 * local indexing.
	 * memory of data is not checked or allocated, it should be done before calling thise method
	 */
	if(localIndI > 7 || localIndJ > 7 || localIndI < 0 || localIndJ < 0 || data == NULL)
		return;
	double *pointer = data_+localIndI*3*3*8 + 3*localIndJ;
	data[0] = *pointer++;
	data[1] = *pointer++;
	data[2] = *pointer;
	pointer += 7*3+1;
	data[3] = *pointer++;
	data[4] = *pointer++;
	data[5] = *pointer;
	pointer += 7*3+1;
	data[6] = *pointer++;
	data[7] = *pointer++;
	data[8] = *pointer;
}
void ElemStiffMatrixHexa8::getBlockDataGlob(double * data, int indI, int indJ)
{
	/*
	 * data - pointer to store stiffness block 3*3.
	 * Row and column indexes of block are evaluated by mapping global indexes indI and indJ.
	 * memory of data is not checked or allocated, it should be done before calling thise method
	 */
	if(data == NULL)
		return;
	int localIndI = -1, localIndJ = -1;
	int ctFound = 0;
	for(int ct = 0; ct < 8; ct++){
		if(indI == ind_[ct])
		{localIndI = ct; ctFound++;}
		if(indJ == ind_[ct])
		{localIndJ = ct; ctFound++;}
		if(ctFound == 2) break;
	}
	getBlockDataLoc(data, localIndI, localIndJ);
}
void ElemStiffMatrixHexa8::addBlockDataLoc(double * data, int localIndI, int localIndJ)
{
	/*
	 * data - pointer to store stiffness block 3*3 with row index localIndI and column index localIndJ.
	 * local indexing.
	 * memory of data is not checked or allocated, it should be done before calling thise method
	 */
	if(localIndI > 7 || localIndJ > 7 || localIndI < 0 || localIndJ < 0 || data == NULL)
		return;
	double *pointer = data_+localIndI*3*3*8 + 3*localIndJ;
	data[0] += *pointer++;
	data[1] += *pointer++;
	data[2] += *pointer;
	pointer += 7*3+1;
	data[3] += *pointer++;
	data[4] += *pointer++;
	data[5] += *pointer;
	pointer += 7*3+1;
	data[6] += *pointer++;
	data[7] += *pointer++;
	data[8] += *pointer;
}
void ElemStiffMatrixHexa8::addBlockDataGlob(double * data, int indI, int indJ)
{
	/*
	 * data - pointer to store stiffness block 3*3.
	 * Row and column indexes of block are evaluated by mapping global indexes indI and indJ.
	 * memory of data is not checked or allocated, it should be done before calling thise method
	 */
	if(data == NULL)
		return;
	int localIndI = -1, localIndJ = -1;
	int ctFound = 0;
	for(int ct = 0; ct < 8; ct++){
		if(indI == ind_[ct])
		{localIndI = ct; ctFound++;}
		if(indJ == ind_[ct])
		{localIndJ = ct; ctFound++;}
		if(ctFound == 2) break;
	}
	addBlockDataLoc(data, localIndI, localIndJ);
}
double * ElemStiffMatrixHexa8::data()
{return data_;}
void ElemStiffMatrixHexa8::setPropSet(sbfPropertiesSet * propSet)
{propSet_ = propSet;}
sbfPropertiesSet * ElemStiffMatrixHexa8::propSet()
{return propSet_;}

void sbf::saveNodesDataFloat_NumNodesX3(double * data, int numNodes, const char * baseName, int count, const char * ext, const int numDigits)
{
	float * tempF = new float [numNodes*3];
	for(int ct = 0; ct < numNodes; ct++){
		tempF[ct] = (float)data[3*ct];
		tempF[numNodes + ct] = (float)data[3*ct + 1];
		tempF[2*numNodes + ct] = (float)data[3*ct + 2];
	}
	std::stringstream sstr;
	sstr << baseName;
	sstr.width(numDigits);
	sstr.fill('0');
	sstr << count;
	sstr << ext;
	std::ofstream out(sstr.str().c_str(), std::ios::binary);
	out.write((char *)tempF, numNodes*3*sizeof(float));
	out.close();
	delete [] tempF;
}
//template <class WhatToSaveType, class HowToSaveType, int kort> void sbf::saveNodesData(WhatToSaveType * data, int numNodes, const char * baseName, int count, const char * ext, const int numDigits)
//{
//	HowToSaveType * tempF = new HowToSaveType [numNodes*kort];
//	for(int ct = 0; ct < numNodes; ct++){
//		for(int ct1 = 0; ct1 < kort; ++ct1){
//			tempF[ct1*numNodes + ct] = (HowToSaveType)data[kort*ct + ct1];
//		}
//	}
//	std::stringstream sstr;
//	sstr << baseName;
//	sstr.width(numDigits);
//	sstr.fill('0');
//	sstr << count;
//	sstr << ext;
//	std::ofstream out(sstr.str().c_str(), std::ios::binary);
//	out.write((char *)tempF, numNodes*kort*sizeof(float));
//	out.close();
//	delete [] tempF;
//}
