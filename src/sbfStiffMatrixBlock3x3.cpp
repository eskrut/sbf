#include "sbfStiffMatrixBlock3x3.h"

#include <cmath>
#include "sbfElement.h"
#include "sbfMesh.h"
#include "sbfElemStiffMatrixHexa8.h"
#include "sbfReporter.h"
#include "sbfStiffMatrixBlock3x3Iterator.h"
#include <memory>

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


static void makeStiffMatrixBlock3x3Multiplication(void *data);
static void makeStiffMatrixBlock3x3MultiplicationLoop(void *data);//Looped version

static void StiffMatrixBlock3x3ComputeThread(void * data);
struct StiffMatrixBlock3x3ComputeThreadData
{
    sbfStiffMatrixBlock3x3 *stiffMatrix;
    ThreadType thread;
    EventType *signalsUnlock, threadReady;
    int threadID;
    int startElem, stopElem;
    int *elemIndexes; int elemIndexesLength;//For indexed based enumeration
};

sbfStiffMatrixBlock3x3::sbfStiffMatrixBlock3x3()
{
    init();
}
sbfStiffMatrixBlock3x3::sbfStiffMatrixBlock3x3(int numBlocks, int numNodes)
{
    init();
    setNumBlocksNodes(numBlocks, numNodes);
}
//StiffMatrixBlock3x3::StiffMatrixBlock3x3(const StiffMatrixBlock3x3 & matrix)
//{}
sbfStiffMatrixBlock3x3::~sbfStiffMatrixBlock3x3()
{
    clean();
}
void sbfStiffMatrixBlock3x3::init()
{
    type_ = NO_DEFINED_MATRIX;
    numNodes_ = 0;
    numBlocks_ = 0;
    numBlocksAlter_ = 0;
    data_ = nullptr;
    indJ_ = nullptr;
    shiftInd_ = nullptr;
    indJAlter_ = nullptr;
    shiftIndAlter_ = nullptr;
    ptrDataAlter_ = nullptr;
    flagInitialized_ = nullptr;
    isDOFMerged_ = true;
    //threadsData_ = nullptr;
    mesh_ = nullptr;
    propSet_ = nullptr;
}
void sbfStiffMatrixBlock3x3::clean()
{
    if(data_ != nullptr)
    {delete [] data_; data_ = nullptr;}
    if(indJ_ != nullptr)
    {delete [] indJ_; indJ_ = nullptr;}
    if(shiftInd_ != nullptr)
    {delete [] shiftInd_; shiftInd_ = nullptr;}
    if(indJAlter_ != nullptr)
    {delete [] indJAlter_; indJAlter_ = nullptr;}
    if(shiftIndAlter_ != nullptr)
    {delete [] shiftIndAlter_; shiftIndAlter_ = nullptr;}
    if(ptrDataAlter_ != nullptr)
    {delete [] ptrDataAlter_; ptrDataAlter_ = nullptr;}
    if(flagInitialized_ != nullptr)
    {delete [] flagInitialized_; flagInitialized_ = nullptr;}
    //if(threadsData_ != nullptr)
    //{delete [] threadsData_; threadsData_ = nullptr;}
}
void sbfStiffMatrixBlock3x3::allocate()
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
void sbfStiffMatrixBlock3x3::setNumBlocksNodes(int numBlocks, int numNodes, int numBlocksAlter)
{
    clean();
    numBlocks_ = numBlocks;
    numBlocksAlter_ = numBlocksAlter;
    numNodes_ = numNodes;
    allocate();
}
void sbfStiffMatrixBlock3x3::setIndData(int numNodes, int numBlocks, int * indJ, int * shiftInd, int numBlocksAlter, int * indJAlter, int * shiftIndAlter)
{
    numBlocks_ = numBlocks;
    numBlocksAlter_ = numBlocksAlter;
    numNodes_ = numNodes;
    allocate();
    for(int ct = 0; ct < numBlocks_; ct++)
        indJ_[ct] = indJ[ct];
    for(int ct = 0; ct < numNodes_+1; ct++)
        shiftInd_[ct] = shiftInd[ct];
    if(numBlocksAlter_ > 0){
        for(int ct = 0; ct < numBlocksAlter_; ct++)
            indJAlter_[ct] = indJAlter[ct];
        for(int ct = 0; ct < numNodes_+1; ct++)
            shiftIndAlter_[ct] = shiftIndAlter[ct];
        updataAlterPtr();
    }
}
void sbfStiffMatrixBlock3x3::updateIndexesFromMesh(int *elemIndexes, int elemIndexesLength, MatrixType type, bool merge)
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

    if(mesh_ == nullptr){/*Throw an exception*/}
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
                    else {indJAlter_[ctAlter] = band[ctColumn]; ptrDataAlter_[ctAlter] = nullptr; ctAlter++;}
                }//Loop over indexes in row
                shiftInd_[countNorm++] = ctNorm;
                shiftIndAlter_[countAlter++] = ctAlter;
            }//Loop over rows
        else// type_ == DOWN_TREANGLE_MATRIX
            for(int ctNodes = 0; ctNodes < numNodes; ctNodes++){//Loop over rows
                int length = indBandLength[ctNodes], * band = indBandInd[ctNodes];
                for(int ctColumn = 0; ctColumn < length; ctColumn++){//Loop over indexes in row
                    if(band[ctColumn] <= ctNodes) indJ_[ctNorm++] = band[ctColumn];
                    else {indJAlter_[ctAlter] = band[ctColumn]; ptrDataAlter_[ctAlter] = nullptr; ctAlter++;}
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
void sbfStiffMatrixBlock3x3::updateIndexesFromMesh(int startElemIndex, int stopElemIndex, MatrixType type, bool merge)
{
    std::vector <int> elemIndexes;
    elemIndexes.resize(stopElemIndex - startElemIndex);
    for(int ct = 0; ct < stopElemIndex - startElemIndex; ct++)
        elemIndexes[ct] = startElemIndex + ct;
    updateIndexesFromMesh(&elemIndexes[0], (int)elemIndexes.size(), type, merge);
}
void sbfStiffMatrixBlock3x3::updateIndexesFromMesh(MatrixType type, bool merge)
{
    if(mesh_ == nullptr){/*Throw an exception*/}
    updateIndexesFromMesh(0, mesh_->numElements(), type, merge);
}
void sbfStiffMatrixBlock3x3::updataAlterPtr()
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
double * sbfStiffMatrixBlock3x3::blockPtr(int indI, int indJ)
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

    return nullptr;
}
double * sbfStiffMatrixBlock3x3::data(int indI, int indJ, bool *isDirect)
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

    return nullptr;
}
double * sbfStiffMatrixBlock3x3::addBlockData(double * data, int indI, int indJ)
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
    else base = nullptr;
    return base;
}
const double * sbfStiffMatrixBlock3x3::data()
{return data_;}
const int * sbfStiffMatrixBlock3x3::indData()
{return indJ_;}
const int * sbfStiffMatrixBlock3x3::shiftIndData()
{return shiftInd_;}
double ** sbfStiffMatrixBlock3x3::ptrDataAlter()
{return ptrDataAlter_;}
const int * sbfStiffMatrixBlock3x3::indDataAlter()
{return indJAlter_;}
const int * sbfStiffMatrixBlock3x3::shiftIndDataAlter()
{return shiftIndAlter_;}
int sbfStiffMatrixBlock3x3::numNodes()
{return numNodes_;}
int sbfStiffMatrixBlock3x3::numBlocks()
{return numBlocks_;}
void sbfStiffMatrixBlock3x3::setType(MatrixType type)
{type_=type;}
MatrixType sbfStiffMatrixBlock3x3::type()
{return type_;}
void sbfStiffMatrixBlock3x3::null()
{
    int length = 9*numBlocks_;
    for(int ct = 0; ct < length; data_[ct++] = 0);
    for(int ct = 0; ct < numBlocks_; flagInitialized_[ct++] = false);
}
void sbfStiffMatrixBlock3x3::null(int indI, int indJ)
{
    double * data = blockPtr(indI, indJ);
    if(data != nullptr)
        for(int ct = 0; ct < 9; *(data + ct++) = 0);
    flagInitialized_[(data-data_)/9] = false;
}
int sbfStiffMatrixBlock3x3::checkNulls()
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

std::vector<std::vector<int> > sbfStiffMatrixBlock3x3::columnsInRows()
{
    /*
     *return indexes of columns for each row
     */
    std::vector<std::vector<int> > colsInRows;
    colsInRows.resize(numNodes());
    int ctRow = 0;
    while(true){
        if ( shiftInd_[ctRow+1] == shiftInd_[ctRow] )
            ctRow++;
        else
            break;
    }
    for ( int ct = ctRow; ct < numBlocks_; ct++ ) {
        if ( shiftInd_[ctRow+1] == ct ) ctRow++;
        colsInRows[ctRow].push_back(indJ_[ct]);
    }
    return colsInRows;
}

std::vector<std::vector<int> > sbfStiffMatrixBlock3x3::rowsInColumns()
{
    /*
     *return indexes of rows for each column
     */
    std::vector<std::vector<int> > rowsInCols;
    rowsInCols.resize(numNodes());
    int ctRow = 0;
    while(true){
        if ( shiftInd_[ctRow+1] == shiftInd_[ctRow] )
            ctRow++;
        else
            break;
    }
    for ( int ct = ctRow; ct < numBlocks_; ct++ ) {
        if ( shiftInd_[ctRow+1] == ct ) ctRow++;
        rowsInCols[indJ_[ct]].push_back(ctRow);
    }
    return rowsInCols;
}

//! Creates and returns new iterator instance. Client code should perform valid deleting after finishing usage of iterator.
sbfStiffMatrixBlock3x3Iterator *sbfStiffMatrixBlock3x3::createIterator()
{
    //Create new iterator instance.
    sbfStiffMatrixBlock3x3Iterator * iterator = new sbfStiffMatrixBlock3x3Iterator(this);
    return iterator;
}

//TODO merge versions () and (int *elemIndexes, int elemIndexesLength) by using (int *elemIndexes = nullptr, int elemIndexesLength = nullptr)

void sbfStiffMatrixBlock3x3::compute()
{
    /*
     * Compute stiffnesses of elements in mesh_ and assembly them to this
     */
    if(mesh_ == nullptr){/*Throw an exception*/}
    if(propSet_ == nullptr){/*Throw an exception*/}
    int numElements = mesh_->numElements();
    sbfElement * elem;
    std::vector<int> indexes;
    indexes.reserve(20);

    //forward preparation of matrixes
    sbfElemStiffMatrixHexa8 *stiffHexa8 = new sbfElemStiffMatrixHexa8();
    stiffHexa8->setPropSet(propSet_);

    double * blockData = new double [9];
    double * pBlock;

    for(int ct = 0; ct < numElements; ct++){//Loop over elements
        elem = mesh_->elemPtr(ct);
        switch(elem->type()){
        case ElementType::HEXAHEDRON_LINEAR:{
            stiffHexa8->setElem(elem);
            stiffHexa8->computeSM();
            indexes = elem->indexes();
            for(int ctI = 0; ctI < 8; ctI++)
                for(int ctJ = 0; ctJ < 8; ctJ++){
                    if(type_ == UP_TREANGLE_MATRIX && indexes[ctI] > indexes[ctJ]) continue;
                    else if(type_ == DOWN_TREANGLE_MATRIX && indexes[ctI] < indexes[ctJ]) continue;
                    stiffHexa8->getBlockDataLoc(blockData, ctI, ctJ);//Store current block from element stiffness matrix to temporary array
                    pBlock = addBlockData(blockData, indexes[ctI], indexes[ctJ]);
                    if(pBlock == nullptr) report.error("Error while processing local indexes ", ctI, ", ", ctJ, " of element ", ct, ". Can't find appropriate block in stiffness matrix");
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
void sbfStiffMatrixBlock3x3::compute(int *elemIndexes, int elemIndexesLength)
{
    /*
     * Compute stiffnesses of elements in mesh_ and assembly them to this
     */
    if(mesh_ == nullptr){/*Throw an exception*/}
    if(propSet_ == nullptr){/*Throw an exception*/}
    //int numElements = mesh_->numElements();
    sbfElement * elem;
    std::vector<int> indexes;
    indexes.reserve(20);

    //forward preparation of matrixes
    sbfElemStiffMatrixHexa8 *stiffHexa8 = new sbfElemStiffMatrixHexa8();
    stiffHexa8->setPropSet(propSet_);

    double * blockData = new double [9];
    double * pBlock;

    for(int ctID = 0; ctID < elemIndexesLength; ctID++){//Loop over elements
        int ct = elemIndexes[ctID];
        elem = mesh_->elemPtr(ct);
        switch(elem->type()){
        case ElementType::HEXAHEDRON_LINEAR:{
            stiffHexa8->setElem(elem);
            stiffHexa8->computeSM();
            indexes = elem->indexes();
            for(int ctI = 0; ctI < 8; ctI++)
                for(int ctJ = 0; ctJ < 8; ctJ++){
                    if(type_ == UP_TREANGLE_MATRIX && indexes[ctI] > indexes[ctJ]) continue;
                    else if(type_ == DOWN_TREANGLE_MATRIX && indexes[ctI] < indexes[ctJ]) continue;
                    stiffHexa8->getBlockDataLoc(blockData, ctI, ctJ);//Store current block from element stiffness matrix to temporary array
                    pBlock = addBlockData(blockData, indexes[ctI], indexes[ctJ]);
                    if(pBlock == nullptr) report.error("Error while processing local indexes ", ctI, ", ", ctJ, " of element ", ct, ". Can't find appropriate block in stiffness matrix");
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
void sbfStiffMatrixBlock3x3::computeParallel()
{
    StiffMatrixBlock3x3ComputeThreadData data[sbfNumThreads];
    EventType signalsUnlock[sbfNumThreads];
    for(int ct = 0; ct < sbfNumThreads; ct++) event_init(&(signalsUnlock[ct]));
    for(int ct = 0; ct < sbfNumThreads; ct++){
        data[ct].signalsUnlock = signalsUnlock;
        data[ct].startElem = ct*mesh_->numElements()/sbfNumThreads;
        data[ct].stopElem = ((ct+1)*mesh_->numElements())/sbfNumThreads;
        data[ct].stiffMatrix = this;
        data[ct].threadID = ct;
        data[ct].elemIndexes = nullptr;
        event_init(&(data[ct].threadReady));
        createNewThread(&(data[ct].thread), StiffMatrixBlock3x3ComputeThread, &data[ct]);
        event_wait(&(data[ct].threadReady));
        event_set(&(signalsUnlock[ct]));
    }
    for(int ct = 0; ct < sbfNumThreads; ct++) waitThreadDone(data[ct].thread);
}
void sbfStiffMatrixBlock3x3::computeParallel(int *elemIndexes, int elemIndexesLength)
{
    StiffMatrixBlock3x3ComputeThreadData data[sbfNumThreads];
    EventType signalsUnlock[sbfNumThreads];
    for(int ct = 0; ct < sbfNumThreads; ct++) event_init(&(signalsUnlock[ct]));
    for(int ct = 0; ct < sbfNumThreads; ct++){
        data[ct].signalsUnlock = signalsUnlock;
        data[ct].startElem = ct*elemIndexesLength/sbfNumThreads;
        data[ct].stopElem = ((ct+1)*elemIndexesLength)/sbfNumThreads;
        data[ct].stiffMatrix = this;
        data[ct].threadID = ct;
        data[ct].elemIndexes = elemIndexes;
        data[ct].elemIndexesLength = elemIndexesLength;
        event_init(&(data[ct].threadReady));
        createNewThread(&(data[ct].thread), StiffMatrixBlock3x3ComputeThread, &data[ct]);
        event_wait(&(data[ct].threadReady));
        event_set(&(signalsUnlock[ct]));
    }
    for(int ct = 0; ct < sbfNumThreads; ct++) waitThreadDone(data[ct].thread);
}
static void StiffMatrixBlock3x3ComputeThread(void * rawData)
{
    StiffMatrixBlock3x3ComputeThreadData * data = reinterpret_cast<StiffMatrixBlock3x3ComputeThreadData *>(rawData);

    if(data->stiffMatrix->mesh() == nullptr){/*Throw an exception*/}
    if(data->stiffMatrix->propSet() == nullptr){/*Throw an exception*/}
    sbfElement * elem;
    std::vector<int> indexes;
    indexes.reserve(20);

    //forward preparation of matrixes
    sbfElemStiffMatrixHexa8 *stiffHexa8 = new sbfElemStiffMatrixHexa8();
    stiffHexa8->setPropSet(data->stiffMatrix->propSet());

    double * blockData = new double [9];
    double * pBlock;
    sbfMesh * mesh = data->stiffMatrix->mesh();
    int startElem = data->startElem, stopElem = data->stopElem;
    int stiffnessPart, coeff = mesh->numNodes()/sbfNumThreads;
    int *elemIndexes = data->elemIndexes;
    //int elemIndexesLength = data->elemIndexesLength;
    EventType *signalsUnlock = data->signalsUnlock;
    event_set(&data->threadReady);
    for(int ctID = startElem; ctID < stopElem; ctID++){//Loop over elements
        int ct = elemIndexes ? elemIndexes[ctID] : ctID;
        elem = mesh->elemPtr(ct);
        switch(elem->type()){
        case ElementType::HEXAHEDRON_LINEAR:{
            stiffHexa8->setElem(elem);
            stiffHexa8->computeSM();
            indexes = elem->indexes();
            for(int ctI = 0; ctI < 8; ctI++)
                for(int ctJ = 0; ctJ < 8; ctJ++){
                    if(data->stiffMatrix->type() == UP_TREANGLE_MATRIX && indexes[ctI] > indexes[ctJ]) continue;
                    else if(data->stiffMatrix->type() == DOWN_TREANGLE_MATRIX && indexes[ctI] < indexes[ctJ]) continue;
                    stiffHexa8->getBlockDataLoc(blockData, ctI, ctJ);//Store current block from element stiffness matrix to temporary array
                    stiffnessPart = indexes[ctI]/coeff;
                    if(stiffnessPart > sbfNumThreads-1) stiffnessPart = sbfNumThreads-1;
                    event_wait(&signalsUnlock[stiffnessPart]);//Wait for access to row in certain part of stiffness matrix
                    pBlock = data->stiffMatrix->addBlockData(blockData, indexes[ctI], indexes[ctJ]);
                    if(pBlock == nullptr) report.error("Error while processing local indexes ", ctI, ", ", ctJ, " (", indexes[ctI], ", ", indexes[ctJ], ") of element ", ct, ". Can't find block ptr");
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
    return;
}
void sbfStiffMatrixBlock3x3::lockKort(int indI, int kort, double val, double * force, LockType lockType)
{
    if(lockType == APPROXIMATE_LOCK_TYPE){
        double * targetBlock = blockPtr(indI, indI);
        if (targetBlock == nullptr) return;
        int shift;
        if(kort == 0) shift = 0;
        else if(kort == 1) shift = 4;
        else shift = 8;
        double great = 1.0e10;
        targetBlock[shift] *= great;
        if(force != nullptr) force[indI*3 + kort] = targetBlock[shift]*val;
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
void sbfStiffMatrixBlock3x3::multiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength)
{
    /*
     * Multiply this matrix by vector and store result (memory should be allocated for result)
     * ind_ indexes should be sorted
     * version with specified rows to process
     */

    //	if(type_ != FULL_MATRIX)
    //		return;

    StiffMatrixBlock3x3MultiplicationData tData[sbfNumThreads];
    ThreadType handles[sbfNumThreads];
    for(int ct = 0; ct < sbfNumThreads; ct++){
        tData[ct].result = result;
        tData[ct].vector = vector;
        tData[ct].stiffMatrix = this;
        tData[ct].startRow = ct*rowIndexesLength/sbfNumThreads;
        tData[ct].stopRow = ((ct+1)*rowIndexesLength)/sbfNumThreads;
        tData[ct].rowIndexes = rowIndexes;
        tData[ct].rowIndexesLength = rowIndexesLength;
        createNewThread(&handles[ct], makeStiffMatrixBlock3x3Multiplication, &tData[ct]);
    }
    for(int ct = 0; ct < sbfNumThreads; ct++)
        waitThreadDone(handles[ct]);
}
void sbfStiffMatrixBlock3x3::multiplyByVector(double * vector, double * result)
{
    /*
     * Multiply this matrix by vector and store result (memory should be allocated for result)
     * ind_ indexes should be sorted
     */

    StiffMatrixBlock3x3MultiplicationData tData[sbfNumThreads];
    ThreadType handles[sbfNumThreads];
    for(int ct = 0; ct < sbfNumThreads; ct++){
        tData[ct].result = result;
        tData[ct].vector = vector;
        tData[ct].stiffMatrix = this;
        tData[ct].startRow = ct*numNodes_/sbfNumThreads;
        tData[ct].stopRow = ((ct+1)*numNodes_)/sbfNumThreads;
        tData[ct].rowIndexes = nullptr;
        tData[ct].rowIndexesLength = 0;
        createNewThread(&handles[ct], makeStiffMatrixBlock3x3Multiplication, &tData[ct]);
    }
    for(int ct = 0; ct < sbfNumThreads; ct++)
        waitThreadDone(handles[ct]);
}

void sbfStiffMatrixBlock3x3::prepareParallelMultiplyByVector(double * vector, double * result)
{
    //Possible loss of previous threadsData_ data, if initilized some threads will hang
    // TODO clear data and stop threads (if exist)
    //threadsData_ = new StiffMatrixBlock3x3MultiplicationData [sbfNumThreads];
    for(int ct = 0; ct < sbfNumThreads; ct++){
        threadsData_[ct].result = result;
        threadsData_[ct].vector = vector;
        threadsData_[ct].stiffMatrix = this;
        threadsData_[ct].startRow = ct*numNodes_/sbfNumThreads;
        threadsData_[ct].stopRow = ((ct+1)*numNodes_)/sbfNumThreads;
        threadsData_[ct].rowIndexes = nullptr;
        threadsData_[ct].rowIndexesLength = 0;
        threadsData_[ct].threadID = ct;
        threadsData_[ct].flagCancel = false;
        event_init(&threadsData_[ct].start);
        event_init(&threadsData_[ct].stop);
        createNewThread(&(threadsData_[ct].thread), makeStiffMatrixBlock3x3MultiplicationLoop, &threadsData_[ct]);
        event_wait(&threadsData_[ct].stop);
    }
}
void sbfStiffMatrixBlock3x3::prepareParallelMultiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength)
{
    //Possible loss of previous threadsData_ data, if initilized some threads will hang
    // TODO clear data and stop threads (if exist)
    //threadsData_ = new StiffMatrixBlock3x3MultiplicationData [sbfNumThreads];
    for(int ct = 0; ct < sbfNumThreads; ct++){
        threadsData_[ct].result = result;
        threadsData_[ct].vector = vector;
        threadsData_[ct].stiffMatrix = this;
        threadsData_[ct].startRow = ct*rowIndexesLength/sbfNumThreads;
        threadsData_[ct].stopRow = ((ct+1)*rowIndexesLength)/sbfNumThreads;
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

void sbfStiffMatrixBlock3x3::makeParallelMultiplyByVector()
{
    for(int ct = 0; ct < sbfNumThreads; ct++) event_set(&threadsData_[ct].start);
    for(int ct = 0; ct < sbfNumThreads; ct++) event_wait(&threadsData_[ct].stop);
}

void sbfStiffMatrixBlock3x3::clearParallelMultiplyByVector()
{
    for(int ct = 0; ct < sbfNumThreads; ct++){
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

    if(rowIndexes == nullptr){//Version with sequenced rows
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
        if(rowIndexes == nullptr){//Version with sequenced rows
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
        if(rowIndexes == nullptr){//Version with sequenced rows
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

void sbfStiffMatrixBlock3x3::write(std::ofstream &out)
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
void sbfStiffMatrixBlock3x3::read(std::ifstream &in)
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
void sbfStiffMatrixBlock3x3::printTopology(const char * name)
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
void sbfStiffMatrixBlock3x3::printTopology2(const char * name, int plotRate)
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
void sbfStiffMatrixBlock3x3::setMesh(sbfMesh * mesh)
{mesh_ = mesh;}
sbfMesh * sbfStiffMatrixBlock3x3::mesh()
{return mesh_;}
void sbfStiffMatrixBlock3x3::setPropSet(sbfPropertiesSet * propSet)
{propSet_ = propSet;}
sbfPropertiesSet * sbfStiffMatrixBlock3x3::propSet()
{return propSet_;}

sbfStiffMatrixBlock3x3 * sbfStiffMatrixBlock3x3::makeIncompleteChol(/*double thresholdAmp*/)
{
    if(this->isDOFMerged_ == false) return nullptr;

    report.createNewProgress("Compute incomplete cholesky");

    sbfStiffMatrixBlock3x3 * cholFactor = new sbfStiffMatrixBlock3x3();

    cholFactor->setType(DOWN_TREANGLE_MATRIX | INCOMPLETE_CHOL);
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
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! it may lead to performance lowering (or not :) ) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::list<indexes2> downIndexes;
    std::list<indexes2> upIndexes;
    for(int ctNode = 0; ctNode < numOriginNodes; ctNode++) for(int ctIndJ = originShiftInd[ctNode]; ctIndJ < originShiftInd[ctNode+1]; ctIndJ++) {
        int indI = ctNode, indJ = originIndJ[ctIndJ];
        //Make fake symmetry for iterators normal processing
        indexes2 indDown;
        if(indI >= indJ) {indDown.i = indI; indDown.j = indJ;} else {indDown.i = indJ; indDown.j = indI;}
        downIndexes.push_back(indDown);
        if(indI != indJ){
            std::swap(indDown.i, indDown.j);
            upIndexes.push_back(indDown);
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
//    cholFactor->updataAlterPtr();//Not needed
    cholFactor->null();

    //Serial code of incomplete chol fill

    //auto colsInRows = cholFactor->columnsInRows();
    //auto rowsInCols = cholFactor->rowsInColumns();

    std::unique_ptr<sbfMatrixIterator> iteratorThis(createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorChol(cholFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow0(cholFactor->createIterator());
    std::unique_ptr<sbfMatrixIterator> iteratorCholRow1(cholFactor->createIterator());

    double * blockDiag, * blockCt, * blockCt1, *block;
    double * blockDiagTarget, * blockTarget;
    bool isDirect;
    for(int diagCt = 0; diagCt < numTargetNodes; diagCt++){//Loop on block rows
        //Process diagonal block
        if(numTargetNodes > 100 && (diagCt % (numTargetNodes/100) == 0)) report.updateProgress(0, numTargetNodes, diagCt);

        //blockDiag = this->data(diagCt, diagCt, nullptr);//Diagonal block is always at normal storage
        //blockDiagTarget = cholFactor->blockPtr(diagCt, diagCt);//Look only in normal storage
        blockDiag = iteratorThis->diagonal(diagCt);
        blockDiagTarget = iteratorChol->diagonal(diagCt);

        blockDiagTarget[1] = 0;//Nulling above diagonal elements
        blockDiagTarget[2] = 0;
        blockDiagTarget[5] = 0;
        double sum[6];// 00 11 22 01 02 12 - regular and cross sums
        sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0.0;

        //for(int colCt = 0; colCt < diagCt; colCt++){//Loop on blocks in row

        //for(auto colCt : colsInRows[diagCt]){//Loop on blocks in row
        iteratorChol->setToRow(diagCt);
        while(iteratorChol->isValid()){
            if (iteratorChol->column() >= diagCt) break;
            //FIXME This is VERY slow!!!
            //blockCt = cholFactor->blockPtr(diagCt, colCt);
            blockCt = iteratorChol->data();
            //if(!blockCt) continue;
            sum[0] += blockCt[0]*blockCt[0] + blockCt[1]*blockCt[1] + blockCt[2]*blockCt[2];
            sum[1] += blockCt[3]*blockCt[3] + blockCt[4]*blockCt[4] + blockCt[5]*blockCt[5];
            sum[2] += blockCt[6]*blockCt[6] + blockCt[7]*blockCt[7] + blockCt[8]*blockCt[8];
            sum[3] += blockCt[0]*blockCt[3] + blockCt[1]*blockCt[4] + blockCt[2]*blockCt[5];
            sum[4] += blockCt[0]*blockCt[6] + blockCt[1]*blockCt[7] + blockCt[2]*blockCt[8];
            sum[5] += blockCt[3]*blockCt[6] + blockCt[4]*blockCt[7] + blockCt[5]*blockCt[8];
            iteratorChol->next();
        }//Loop on blocks in row
        blockDiagTarget[0] = std::sqrt(blockDiag[0] - sum[0]);
        //FIXME Why there are comparisions to zero???
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

        //Process blocks under current diagonal

        double rowSum[9];// 00 01 02 10 11 12 20 21 22
        double blockData[9];//

        //for(int rowCt = diagCt + 1; rowCt < numTargetNodes; rowCt++){//Loop on blocks under current diagonal block
        iteratorChol->setToColumn(diagCt);
        iteratorThis->setToColumn(diagCt);
        while(iteratorChol->isValid()){
            int rowCt = iteratorChol->row();
            if(rowCt <= diagCt){
                iteratorChol->next();
                iteratorThis->next();
                continue; //Skip abowe rows
            }

//            blockTarget = cholFactor->blockPtr(rowCt, diagCt);//Look only in normal storage
//            if(!blockTarget) continue;
            blockTarget = iteratorChol->data();

            //block = this->data(rowCt, diagCt, &isDirect);//May be at alternative storage
            block = iteratorThis->data(&isDirect);

            if(isDirect) for(int ct = 0; ct < 9; ct++) blockData[ct] = block[ct];
            else for(int ctI = 0; ctI < 3; ctI++) for(int ctJ = 0; ctJ < 3; ctJ++) blockData[ctI*3+ctJ] = block[ctJ*3+ctI];
            rowSum[0] = rowSum[1] = rowSum[2] = rowSum[3] = rowSum[4] = rowSum[5] = rowSum[6] = rowSum[7] = rowSum[8] = 0.0;

            //for(int colCt = 0; colCt < diagCt; colCt++){//Loop on blocks in row
            //for(auto colCt : colsInRows[diagCt]){//Loop on blocks in row
            iteratorCholRow0->setToRow(rowCt);
            iteratorCholRow1->setToRow(diagCt);
            int col0 = iteratorCholRow0->column();
            int col1 = iteratorCholRow1->column();
            while(iteratorCholRow0->isValid() && iteratorCholRow1->isValid()) {
                if (col0 >= diagCt) break;
                if (col0 < col1) {
                    iteratorCholRow0->next();
                    col0 = iteratorCholRow0->column();
                    continue;
                }
                if (col0 > col1) {
                    iteratorCholRow1->next();
                    col1 = iteratorCholRow1->column();
                    continue;
                }
                //OK, found equal columns ID
//                blockCt = cholFactor->blockPtr(rowCt, colCt);
//                if(!blockCt) continue;
//                blockCt1 = cholFactor->blockPtr(diagCt, colCt);
//                if(!blockCt1) continue;
                blockCt = iteratorCholRow0->data();
                blockCt1 = iteratorCholRow1->data();
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
                iteratorCholRow0->next();
                iteratorCholRow1->next();
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
            iteratorChol->next();
            iteratorThis->next();
        }//Loop on blocks under current diagonal block

        //Process blocks under diagonal - END
    }//Loop on block rows

    report.finalizeProgress();

    return cholFactor;
}

void sbfStiffMatrixBlock3x3::solve_L_LT_u_eq_f(double * u, double * f)
{
    //Solve L*L^T*u = f
    const int numNodes = numNodes_;
    double sum[3], vecPart[3];
    double * block = data_;
    sum[0] = sum[1] = sum[2] = 0.0;
    //FIXME It is bad idea to create iterator each time (or not :) )
    //std::unique_ptr<sbfMatrixIterator> iterPtr(createIterator());
    //sbfMatrixIterator * iter = iterPtr.get();
    sbfMatrixIterator * iter = createIterator();
    //L u' = f
    int ctRow = 0;
    int ctColumn = 0;
    for (int ctBlock = 0; ctBlock < numBlocks_; ctBlock++) {//Loop on blocks
        if( ctBlock == shiftInd_[ctRow+1] ) {
            ctRow++;
            sum[0] = sum[1] = sum[2] = 0.0;
        }
        ctColumn = indJ_[ctBlock];
        if( ctRow != ctColumn ){//process non diagonal block
            //TODO this is not fatal, but still it should be implemented with iterator
            block = blockPtr(ctRow, ctColumn);
            if (!block) continue;
            vecPart[0] = u[ctColumn*3 + 0];
            vecPart[1] = u[ctColumn*3 + 1];
            vecPart[2] = u[ctColumn*3 + 2];
            sum[0] += block[0]*vecPart[0] + block[1]*vecPart[1] + block[2]*vecPart[2];
            sum[1] += block[3]*vecPart[0] + block[4]*vecPart[1] + block[5]*vecPart[2];
            sum[2] += block[6]*vecPart[0] + block[7]*vecPart[1] + block[8]*vecPart[2];
        }//process non diagonal block
        else {
            vecPart[0] = (f[ctRow*3 + 0] - sum[0]) / block[0];
            sum[1] += block[3]*vecPart[0];
            sum[2] += block[6]*vecPart[0];
            vecPart[1] = (f[ctRow*3 + 1] - sum[1]) / block[4];
            sum[2] += block[7]*vecPart[1];
            vecPart[2] = (f[ctRow*3 + 2] - sum[2]) / block[8];
            u[ctRow*3 + 0] = vecPart[0];
            u[ctRow*3 + 1] = vecPart[1];
            u[ctRow*3 + 2] = vecPart[2];
        }
        block += 9;
    }//Loop on blocks
    //L^T u = u'
    for (int ctRow = numNodes_ - 1; ctRow >= 0; ctRow--) {//Loop on rows
        sum[0] = sum[1] = sum[2] = 0.0;
        iter->setToColumnInverse(ctRow);
        //for (int ctColumn = numNodes - 1; ctColumn > ctRow; ctColumn--){//Loop on non diaonal blocks
        while(!iter->isDiagonal()) {
//            block = blockPtr(ctColumn, ctRow);//swap row and column ndexes
//            if ( !block ) continue;
            block = iter->data();
            int ctColumn = iter->column();
            vecPart[0] = u[ctColumn*3 + 0];
            vecPart[1] = u[ctColumn*3 + 1];
            vecPart[2] = u[ctColumn*3 + 2];
            //transposed indexing to block
            sum[0] += block[0]*vecPart[0] + block[3]*vecPart[1] + block[6]*vecPart[2];
            sum[1] += block[1]*vecPart[0] + block[4]*vecPart[1] + block[7]*vecPart[2];
            sum[2] += block[2]*vecPart[0] + block[5]*vecPart[1] + block[8]*vecPart[2];
            iter->next();
        }//Loop on non diaonal blocks
        //block = blockPtr(ctRow, ctRow);
        block = iter->diagonal(ctRow);
        vecPart[2] = (u[ctRow*3 + 2] - sum[2]) / block[8];
        sum[0] += block[6]*vecPart[2];
        sum[1] += block[7]*vecPart[2];
        vecPart[1] = (u[ctRow*3 + 1] - sum[1]) / block[4];
        sum[0] += block[3]*vecPart[1];
        vecPart[0] = (u[ctRow*3 + 0] - sum[0]) / block[0];
        u[ctRow*3 + 0] = vecPart[0];
        u[ctRow*3 + 1] = vecPart[1];
        u[ctRow*3 + 2] = vecPart[2];
    }//Loop on rows

    delete iter;
}
