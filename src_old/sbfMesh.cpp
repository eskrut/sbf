#include "sbfMesh.h"

using namespace std;
using namespace sbf;

void quickSortCrd(vector <float> & crd, vector <int> & ind, int left, int right);
void quickSortIntDown(vector <int> & ind, int left, int right);
void quickSortIntUp(vector <int> & ind, int left, int right);
void quickSortIntUp(vector <int> & ind1, vector <int> & ind2, int left, int right);
//template <class TypeToSort, class AssociatedType> void quickAssociatedSortUp(TypeToSort * arrayToSort, AssociatedType * associatedArray, int left, int right);
void quickSortNodes(sbfNode * nodes, int * ind, int left, int right);

void computeGraph(sbfMesh * mesh, int *** graph);
void computeGraphAlter(sbfMesh * mesh, int *** graph);
size_t computeProfileSize(int ** graph, int numNodes, bool * flagOwerFlow = NULL);
int computeBandwidth(int ** graph, int numNodes);
void findUnnumberedNeighbors(int ** graph, int * mask, int * tmp, /*I do not know better name*/ int & temp, int * deg, int nodeCt);
void makeRCM(int ** graph, int numNodes, int startNode, int * newToOld, int *oldToNew);
int findStartNode(int ** graph, int numNodes);

sbfMesh::sbfMesh()
{
	kort_ = 3;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	reserveNodesNumber(1000);
	reserveElementsNumber(1000);
}
sbfMesh::sbfMesh(sbfMesh & mesh)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	reserveNodesNumber(1000);
	reserveElementsNumber(1000);
	kort_ = mesh.kort_;
	int nnode = mesh.numNodes();
	for(int ct = 0; ct < nnode; ct++)
		addNode(mesh.node(ct), false);
	int nelem = mesh.numElements();
	for(int ct = 0; ct < nelem; ct++)
		addElement(mesh.elems_[ct]);
	mtr_ = mesh.mtr_;
	int ngrelem = mesh.numGroups();
	for(int ct = 0; ct < ngrelem; ct++)
	{
		//Not implemented yet!!!
	}
}
sbfMesh::~sbfMesh()
{
	clearAllGroups();
	mtr_.clear();
}

int sbfMesh::readCrdFromFile(const char* crdName)
{
	nodes_.clear();
	ifstream crdFile(crdName, fstream::binary);
	if(!crdFile.good())
	{
		cout << "Error! Can't read crd file " << crdName << endl;
		return 1;
	}

	int temp;
	crdFile.read((char *)&temp, sizeof(temp));
	crdFile.read((char *)&kort_, sizeof(kort_));
	nNodes_ = temp/kort_;

	nodes_.reserve(nNodes_);

	float *tempF;
	tempF = new float [kort_*nNodes_];
	crdFile.read((char *)tempF, kort_*nNodes_*sizeof(tempF[0]));

	for(int ct = 0; ct < nNodes_; ct++)
		nodes_.push_back(sbfNode(tempF[0*nNodes_+ct], tempF[1*nNodes_+ct], tempF[2*nNodes_+ct]));
	delete [] tempF;

	crdFile.close();
	//cout << "Crd file read OK" << endl;
	return 0;
}

int sbfMesh::readIndFromFile(const char* indName, FileVersion fileFormatVersion)
{
	elems_.clear();
	ifstream indFile(indName, fstream::binary);
	if(!indFile.good()){
		cout << "Error! Can't read ind file " << indName << endl;
		return 1;
	}

	if(fileFormatVersion == AUTO_FORMAT){
		indFile.seekg(0, ios_base::end);
		int fileBytesLength = indFile.tellg();
		indFile.seekg(0, ios_base::beg);
		int oldNElem, newNTypes;
		indFile.read((char *)&oldNElem, sizeof(int)); newNTypes = oldNElem;
		int /*oldIndLen, */newIndLen;
		int oldNumNodes;
		indFile.read((char *)&oldNumNodes, sizeof(oldNumNodes));
		if(oldNumNodes) oldNElem /= oldNumNodes;
		else oldNElem = 0;
		if((int)((1+2*newNTypes)*sizeof(int)) < fileBytesLength){
			indFile.seekg((1+2*newNTypes)*sizeof(int), ios_base::beg);
			indFile.read((char *)&newIndLen, sizeof(newIndLen));
		}
		else newIndLen = 0;
		if(fileBytesLength == (int)((2 + oldNElem*oldNumNodes)*sizeof(int)))
			fileFormatVersion = OLD_FORMAT;
		else if(fileBytesLength == (int)((1 + 2*newNTypes + 1 + newIndLen)*sizeof(int)))
			fileFormatVersion = NEW_FORMAT;
		else fileFormatVersion = NOT_DEFINED_FORMAT;
		indFile.seekg(0, ios_base::beg);
	}

	if(fileFormatVersion == OLD_FORMAT){
		int temp;
		indFile.read((char *)&nElements_, sizeof(nElements_));
		indFile.read((char *)&temp, sizeof(temp));
		nElements_ /= temp;
		elems_.reserve(nElements_);
		for(int ct = 0; ct < nElements_; ct++)
		{
			elems_.push_back(sbfElement());
			elems_.back().setNumNodes(temp);
			elems_.back().setMesh(this);
			elems_.back().setType(tryToResolveTypeByNumNodes(temp));
			for(int ct1 = 0; ct1 < temp; ct1++)
			{
				int tempi;
				indFile.read((char *)&tempi, sizeof(tempi));
				tempi--;
				elems_.back().setNode(ct1, tempi);
			}
		}
	}
	else if(fileFormatVersion == NEW_FORMAT){
		int nTypes;
		vector <int> types;
		vector <int> nElem;
		int indLength;
		int numAllElem = 0;
		indFile.read((char *)&nTypes, sizeof(nTypes));
		types.resize(nTypes, -1);
		nElem.resize(nTypes, -1);
		for(int ct = 0; ct < nTypes; ct++){
			indFile.read((char *)&types[ct], sizeof(types[ct]));
			indFile.read((char *)&nElem[ct], sizeof(types[ct]));
			numAllElem += nElem[ct];
		}
		indFile.read((char *)&indLength, sizeof(indLength));
		elems_.reserve(numAllElem);
		for(int ct = 0; ct < nTypes; ct++){
			ElementType type_ = typesFileToLib(types[ct]);
			int temp_i = numNodesInElement(type_);
			for(int ct1 = 0; ct1 < nElem[ct]; ct1++){
				elems_.push_back(sbfElement(temp_i));
				elems_.back().setType(type_);
				elems_.back().setMesh(this);
				for(int ct2 = 0; ct2 < temp_i; ct2++)
				{
					int temp_i2;
					indFile.read((char *)&temp_i2, sizeof(temp_i2));
					//indFile.read((char *)&elems_.back().nodeIndex(ct2), sizeof(elems_.back().nodeIndex(ct2)));
					elems_.back().setNode(ct2, --temp_i2);
				}
			}
		}
	}
	else {cout << "Ind file version error" << endl; return 1;}
	indFile.close();
	//cout << "Ind file read OK" << endl;
	return 0;
}

int sbfMesh::readMtrFromFile(const char* mtrName)
{
	mtr_.clear();
	ifstream mtrFile(mtrName, fstream::binary);
	if(!mtrFile.good())
	{
		cout << "Error! Can't read mtr file " << mtrName << endl;
		return 1;
	}

	int temp;
	int nelems = numElements();
	for(int ct = 0; ct < nelems; ct++)
	{
		mtrFile.read((char *)&temp, sizeof(temp));
		elems_[ct].setMtr(temp);
	}

	mtrFile.close();
	//cout << "Mtr file read OK" << endl;
	return 0;
}
int sbfMesh::readMeshFromFiles(const char* indName, const char* crdName, const char* mtrName, FileVersion fileFormatVersion)
{
	if(readIndFromFile(indName, fileFormatVersion) != 0)
		return 1;
	if(readCrdFromFile(crdName) != 0)
		return 2;
	if(readMtrFromFile(mtrName) != 0)
		return 3;
	return 0;
}

int sbfMesh::writeCrdToFile(const char* crdName)
{
	ofstream crdFile(crdName, fstream::binary);
	if(!crdFile.good())
	{
		cout << "Error! Can't open crd file " << crdName << " for writing" << endl;
		return 1;
	}

	int temp = numNodes()*kort_;
	crdFile.write((char *)&temp, sizeof(temp));
	crdFile.write((char *)&kort_, sizeof(kort_));

	for(int ct = 0; ct < kort_; ct++)
		for(int ct1 = 0; ct1 < numNodes(); ct1++)
			crdFile.write((char *)&(nodes_[ct1].crdAtKort(ct)), sizeof(nodes_[ct1].x()));
	crdFile.close();
	//cout << "Crd file write OK" << endl;
	return 0;
}

int sbfMesh::writeIndToFile(const char* indName, const FileVersion fileFormatVersion)
{
	ofstream indFile(indName, fstream::binary);
	if(!indFile.good())
	{
		cout << "Error! Can't open ind file " << indName << " for writing" << endl;
		return 1;
	}

	if(fileFormatVersion == OLD_FORMAT){
		int temp = (int) elems_.size() * elems_[0].numNodes();
		indFile.write((char *)&temp, sizeof(temp));
		temp = elems_[0].numNodes();
		indFile.write((char *)&temp, sizeof(temp));

		for(int ct = 0; ct < numElements(); ct++)
			for(int ct1 = 0; ct1 < elems_[ct].numNodes(); ct1++)
			{
				int tempi = elems_[ct].nodeIndex(ct1) + 1;
				indFile.write((char *)&(tempi), sizeof(tempi));
			}
	}
	else if(fileFormatVersion == NEW_FORMAT){
		bool autoGeneratedGroups = false;
		if(numGroups() == 0){
			//Automatic groups generation based on elemType
			autoGeneratedGroups = true;
			map<ElementType, sbfElementGroup *> typeGroups;
			for(int ct = 0; ct < numElements(); ct++){
				sbfElement *elem = elemPtr(ct);
				if(typeGroups.find(elem->type()) == typeGroups.end()) typeGroups[elem->type()] = addElementGroup();
				typeGroups[elem->type()]->addElement(ct, false);
			}
		}

		int nTypes = numGroups();
		ElementType typeL;
		int typeF;
		int nElem;
		int indLength = 0;
		indFile.write((char *)&nTypes, sizeof(nTypes));
		for(int ct = 0; ct < nTypes; ct++){
			typeL = elemGroups_[ct]->type();
			nElem = elemGroups_[ct]->numElems();
			indLength += nElem*numNodesInElement(typeL);
			typeF = typesLibToFile(typeL);
			indFile.write((char *)&typeF, sizeof(typeF));
			indFile.write((char *)&nElem, sizeof(nElem));
		}
		indFile.write((char *)&indLength, sizeof(indLength));
		for(int ct = 0; ct < nTypes; ct++){
			typeL = elemGroups_[ct]->type();
			for(int ct1 = 0; ct1 < elemGroups_[ct]->numElems(); ct1++){
				int temp_i = numNodesInElement(typeL);
				for(int ct2 = 0; ct2 < temp_i; ct2++)
				{
					int tempi = elems_[elemGroups_[ct]->element(ct1)].nodeIndex(ct2) + 1;
					indFile.write((char *)&tempi, sizeof(tempi));
				}
			}
		}

		if(autoGeneratedGroups) clearGroups();
	}
	indFile.close();
	//cout << "Ind file write OK" << endl;
	return 0;
}

int sbfMesh::writeMtrToFile(const char* mtrName, const FileVersion fileFormatVersion)
{
	ofstream mtrFile(mtrName, fstream::binary);
	if(!mtrFile.good())
	{
		cout << "Error! Can't open mtr file " << mtrName << " for writing" << endl;
		return 1;
	}
	if(fileFormatVersion == OLD_FORMAT){
		for(int ct = 0; ct < numElements(); ct++){
			int mtr_ = elems_[ct].mtr();
			mtrFile.write((char *)&mtr_, sizeof(mtr_));
		}
	}
	else if(fileFormatVersion == NEW_FORMAT){
		if(numGroups() == 0)
			cout << "Mtr file write failed! No groups!" << endl;
		else{
			int nTypes = numGroups();
			for(int ct = 0; ct < nTypes; ct++){
				for(int ct1 = 0; ct1 < elemGroups_[ct]->numElems(); ct1++){
					int temp_i = elems_[elemGroups_[ct]->element(ct1)].mtr();
					mtrFile.write((char *)&temp_i, sizeof(temp_i));
				}
			}
		}
	}
	mtrFile.close();
	//cout << "Mtr file write OK" << endl;
	return 0;
}
int sbfMesh::writeMeshToFiles(const char* indName, const char* crdName, const char* mtrName, const FileVersion fileFormatVersion)
{
	bool autoGeneratedGroups = false;
	if(fileFormatVersion == NEW_FORMAT){
		if(numGroups() == 0){
			//Automatic groups generation based on elemType
			autoGeneratedGroups = true;
			map<ElementType, sbfElementGroup *> typeGroups;
			for(int ct = 0; ct < numElements(); ct++){
				sbfElement *elem = elemPtr(ct);
				if(typeGroups.find(elem->type()) == typeGroups.end()) typeGroups[elem->type()] = addElementGroup();
				typeGroups[elem->type()]->addElement(ct, false);
			}
		}
	}
	if(writeIndToFile(indName, fileFormatVersion) != 0)
		return 1;
	if(writeCrdToFile(crdName) != 0)
		return 2;
	if(writeMtrToFile(mtrName, fileFormatVersion) != 0)
		return 3;
	if(autoGeneratedGroups) clearGroups();
	return 0;
}

sbfNode & sbfMesh::node(const int seqNumber)
{return nodes_[seqNumber];}
sbfElement & sbfMesh::elem(const int seqNumber)
{return elems_[seqNumber];}
sbfElement * sbfMesh::elemPtr(const int sequenceNumber)
{
	if(sequenceNumber >= (int)elems_.size())
		return NULL;
	return & elems_[sequenceNumber];
}

int sbfMesh::numElements()
{return (int) elems_.size();}

int sbfMesh::numNodes()
{return (int) nodes_.size();}

int sbfMesh::numGroups()
{return (int) elemGroups_.size();}

int sbfMesh::numNodeGroups()
{return (int) nodeGroups_.size();}

void sbfMesh::printInfo()
{
	cout << "Number of elements " << numElements() << endl;
	cout << "Number of nodes " << nodes_.size() << endl;
	std::map<sbf::ElementType, size_t> numElementsMap;
	numElementsMap[sbf::BEAM_LINEAR_3DOF] = 0;
	numElementsMap[sbf::BEAM_QUADRATIC_3DOF] = 0;
	numElementsMap[sbf::BEAM_LINEAR_6DOF] = 0;
	numElementsMap[sbf::BEAM_QUADRATIC_6DOF] = 0;
	numElementsMap[sbf::RECTANGLE_LINEAR] = 0;
	numElementsMap[sbf::RECTANGLE_QUADRATIC] = 0;
	numElementsMap[sbf::TRIANGLE_LINEAR] = 0;
	numElementsMap[sbf::TRIANGLE_QUADRATIC] = 0;
	numElementsMap[sbf::HEXAHEDRON_LINEAR] = 0;
	numElementsMap[sbf::HEXAHEDRON_QUADRATIC] = 0;
	numElementsMap[sbf::TRIANGLE_PRISM_LINEAR] = 0;
	numElementsMap[sbf::TRIANGLE_PRISM_QUADRATIC] = 0;
	numElementsMap[sbf::TETRAHEDRON_LINEAR] = 0;
	numElementsMap[sbf::TETRAHEDRON_QUADRATIC] = 0;
	numElementsMap[sbf::NO_DEFINED_ELEMENT] = 0;
	for(int ct = 0; ct < numElements(); ct++)
		numElementsMap[elemPtr(ct)->type()]++;
	cout << "Elements in mesh:" << endl;
	cout << "Beam 3 DOF linear\t\t" << numElementsMap[sbf::BEAM_LINEAR_3DOF] << endl;
	cout << "Beam 3 DOF quadratic\t\t" << numElementsMap[sbf::BEAM_QUADRATIC_3DOF] << endl;
	cout << "Beam 6 DOF linear\t\t" << numElementsMap[sbf::BEAM_LINEAR_6DOF] << endl;
	cout << "Beam 6 DOF quadratic\t\t" << numElementsMap[sbf::BEAM_QUADRATIC_6DOF] << endl;
	cout << "Hexahedron linear\t\t" << numElementsMap[sbf::HEXAHEDRON_LINEAR] << endl;
	cout << "Hexahedron quadratic\t\t" << numElementsMap[sbf::HEXAHEDRON_QUADRATIC] << endl;
	cout << "Tetrahedron linear\t\t" << numElementsMap[sbf::TETRAHEDRON_LINEAR] << endl;
	cout << "Tetrahedron quadratic\t\t" << numElementsMap[sbf::TETRAHEDRON_QUADRATIC] << endl;
	cout << "Undefined elements\t\t" << numElementsMap[sbf::NO_DEFINED_ELEMENT] << endl;
	cout << "Number of elements groups " << this->numGroups() << endl;
	cout << "Number of nodes groups " << this->numNodeGroups() << endl;
	cout << "Bounding box:" << endl << "xMin = " << minX() << "\txMax = " << maxX() << endl << "yMin = " << minY() << "\tyMax = " << maxY() << endl << "zMin = " << minZ() << "\tzMax = " << maxZ() << endl;
}
float sbfMesh::max(const int kort)
{
	int nNode = numNodes();
	if(nNode == 0)
		return -std::numeric_limits<float>::max();
	float max = nodes_[0].crdAtKort(kort), tempF;
	for(int ct = 1; ct < nNode; ct++){
		tempF = nodes_[ct].crdAtKort(kort);
		if(max < tempF)
			max = tempF;
	}
	return max;
}
float sbfMesh::min(const int kort)
{
	int nNode = numNodes();
	if(nNode == 0)
		return std::numeric_limits<float>::max();
	float min = nodes_[0].crdAtKort(kort), tempF;
	for(int ct = 1; ct < nNode; ct++){
		tempF = nodes_[ct].crdAtKort(kort);
		if(min > tempF)
			min = tempF;
	}
	return min;
}
float sbfMesh::maxX()
{return max(0);}
float sbfMesh::maxY()
{return max(1);}
float sbfMesh::maxZ()
{return max(2);}
float sbfMesh::minX()
{return min(0);}
float sbfMesh::minY()
{return min(1);}
float sbfMesh::minZ()
{return min(2);}

int sbfMesh::addElement(const sbfElement & elem)
{
	/*	return index of new added element	*/
	elems_.push_back(elem);
	elems_.back().setMesh(this);
	return (int)elems_.size()-1;
}
void sbfMesh::insertElement(const sbfElement & elem, int position)
{
	//	elems_.push_back(elem);
	//	elems_.back().setMesh(this);
	if(position < (int)elems_.size()){
		elems_.insert(elems_.begin() + position, elem);
		elems_[position].setMesh(this);
	}
	else{/*throw exception*/}
}

int sbfMesh::addNode(float x, float y, float z, bool checkExisted, float tol)
{
	/*	return index of new created node or already existed node with tolerance	*/
	sbfNode node(x, y, z);
	return addNode(node, checkExisted, tol);
}
int sbfMesh::addNode(sbfNode & node, bool checkExisted, float tol)
{
	/*	return index of new created node or already existed node with tolerance	*/
	int nNodes = numNodes();
	if(checkExisted){
		for(int ct = nNodes-1; ct >= 0; ct--)
		{
			if(nodes_[ct].isSame(node, tol))
				return ct;
		}
		nodes_.push_back(node);
		return nNodes;
	}
	else{
		nodes_.push_back(node);
		return nNodes;
	}
}
void sbfMesh::deleteNode(int nodeIndex, bool renumberElemIndexes)
{
	if(nodeIndex < static_cast<int>(nodes_.size())){
		if(renumberElemIndexes){
			//Process elements indexes
			vector<int> indexes;
			for(size_t elemCt = 0; elemCt < static_cast<size_t>(numElements()); elemCt++){
				indexes = elems_[elemCt].indexes();
				for(size_t nodeCt = 0; nodeCt < indexes.size(); nodeCt++)
					if(indexes[nodeCt] >= nodeIndex)
						indexes[nodeCt]--;
			}
		}
		vector<sbfNode>::iterator eraceIterator = nodes_.begin() + nodeIndex;
		nodes_.erase(eraceIterator);
	}
}
int sbfMesh::nodeAt(float x, float y, float z, float tol)
{
	/*	return index of node at specified coordinates with tolerance
		or -1 otherwise	*/
	int nNodes = numNodes();
	sbfNode node(x, y, z);
	for(int ct = 0; ct < nNodes; ct++)
	{
		if(nodes_[ct].isSame(node, tol))
			return ct;
	}
	return -1;
}
int sbfMesh::mergeNodes(float tol)
{
	//clock_t start, stop;
	vector <int> newInd, oldInd, shiftInd;
	vector <int> toDelete;
	vector <int> sortX, newSortX;
	vector <bool> isMerged;
	newInd.resize(numNodes(), -1);
	shiftInd.resize(numNodes(), 0);
	toDelete.reserve(numNodes());
	isMerged.resize(numNodes(), false);
	int nnodes = numNodes();
	for(int ct = 0; ct < nnodes; ct++)
		newInd[ct] = ct;
	oldInd = newInd;
	sortX = oldInd;

	int numMergedNodes = 0;

	//start = clock();
	vector <float> crdX;
	crdX.resize(nnodes, 0.0);
	for(int ct = 0; ct < nnodes; ct++) crdX[ct] = nodes_[ct].x();
	quickSortCrd(crdX, sortX, 0, nnodes-1);
	newSortX = sortX;

	//stop = clock();
	//cout << "dt = " << stop - start << endl;
	//start = clock();

	//int shiftSumm;
	//shiftSumm = 0;
	//start = clock();
	vector <int> equalInd;
	equalInd.reserve(nnodes);
	for(int ct1 = 0; ct1 < nnodes-1; ct1++){
		//cout << "\r" << ct1+1 << " / " << nnodes;
		int ind1, ind2;
		ind1 = sortX[ct1];
		if(isMerged[ind1])
			continue;
		equalInd.clear();
		equalInd.push_back(ind1);
		for(int ct2 = ct1 + 1; ct2 < nnodes; ct2++){
			ind2 = sortX[ct2];
			if(isMerged[ind2])
				continue;
			if(crdX[ct2] - crdX[ct1] > tol)
				break;
			sbfNode n1, n2;
			n1 = nodes_[ind1];
			n2 = nodes_[ind2];
			if(fabs(n1.y() - n2.y()) <  tol){
				if(fabs(n1.z() - n2.z()) <  tol){
					if(n1.distance(n2) < tol)
						equalInd.push_back(ind2);
				}
			}
		}
		if(equalInd.size() > 1)
		{
			int minInd = equalInd[0], len = (int) equalInd.size();
			for(int ct = 1; ct < len; ct++)
				if(minInd > equalInd[ct])
					minInd = equalInd[ct];
			for(int ct = 0; ct < len; ct++){
				int tempI = equalInd[ct];
				if(tempI != minInd){
					toDelete.push_back(tempI);
					newInd[tempI] = minInd;
					isMerged[tempI] = true;
				}
			}
		}
	}

	renumberNodes(&newInd[0]);

	quickSortIntDown(toDelete, 0, (int)toDelete.size()-1);
	for(int ct = 0; ct < (int)toDelete.size(); ct++){//Loop on indexes of nodes to delete
		vector<sbfNode>::iterator it = nodes_.begin();
		for(int ct1 = 0; ct1 < toDelete[ct]; ct1++) it++;
		nodes_.erase(it);
	}//Loop on indexes of nodes to delete

	//Evaluate shiftInd
	for(vector<int>::iterator it = newInd.begin(), itShift = shiftInd.begin(); it != newInd.end(); it++, itShift++){
		for(vector<int>::iterator itDel = toDelete.begin(); itDel != toDelete.end(); itDel++){
			if((*it) > (*itDel)) (*itShift)--;
		}
	}
	numMergedNodes = (int)toDelete.size();

	for(vector<sbfElement>::iterator it = elems_.begin(); it != elems_.end(); it++){//Loop on elements to reduce nodes indexes
		vector<int> indexes = (*it).indexes();
		for(vector<int>::iterator itInd = indexes.begin(); itInd != indexes.end(); itInd++)
			(*itInd) += shiftInd[*itInd];
	}

	//	stop = clock();
	//	//cout << "dt = " << stop - start << endl;
	//	start = clock();
	//	for(int ct = 0; ct < nnodes; ct++){
	//		shiftInd[ct] = shiftSumm;
	//		if(oldInd[ct] > newInd[ct]){
	//			shiftSumm++;
	//			shiftInd[ct] = shiftInd[newInd[ct]];
	//		}
	//	}
	//	stop = clock();
	//	//cout << "dt = " << stop - start << endl;
	//	start = clock();
	//	int nelems = numElements();
	//	for(int ct = 0; ct < nelems; ct++){
	//		int nnodes = elems_[ct].numNodes();
	//		for(int ct1 = 0; ct1 < nnodes; ct1++){
	//			int temp_i = elems_[ct].nodeIndex(ct1);
	//			elems_[ct].setNode(ct1, newInd[temp_i] - shiftInd[temp_i]);
	//		}
	//	}
	//	stop = clock();
	//	//cout << "dt = " << stop - start << endl;
	//	start = clock();
	//	int deleteLen = (int) toDelete.size();
	//	quickSortIntUp(toDelete, 0, deleteLen-1);
	//	stop = clock();
	//	//cout << "dt = " << stop - start << endl;
	//	start = clock();
	//	int countDelete = 0, countStore = 0;
	////	for(int ct = 0; ct < deleteLen; ct++)
	////		nodes.erase(nodes.begin() + toDelete[ct]);
	//	for(int ct = 0; ct < nnodes; ct++)
	//		if(ct != toDelete[countDelete])
	//			nodes_[countStore++] = nodes_[ct];
	//		else
	//			countDelete++;
	//	nodes_.resize(countStore+1);
	//	stop = clock();
	//	//cout << "dt = " << stop - start << endl;
	//	return shiftSumm;
	return numMergedNodes;
}
void sbfMesh::renumberNodes(int * newIndexes)
{
	vector <sbfNode> newNodes;
	newNodes.resize(numNodes());
	for(int ct = 0; ct < numNodes(); ct++)
		newNodes[ct] = nodes_[newIndexes[ct]];
	for(int ct = 0; ct < numNodes(); ct++)
		nodes_[ct] = newNodes[ct];
	newNodes.clear();
	vector <int> indexesMap1, indexesMap2;
	indexesMap1.resize(numNodes());
	indexesMap2.resize(numNodes());
	for(int ct = 0; ct < numNodes(); ct++){
		indexesMap1[ct] = newIndexes[ct];
		indexesMap2[ct] = ct;
	}
	quickSortIntUp(indexesMap1, indexesMap2, 0, numNodes()-1);
	for(vector<sbfElement>::iterator it = elems_.begin(); it != elems_.end(); it++){//Loop on elements in mesh
		int nnodes = (*it).numNodes();
		for(int ct = 0; ct < nnodes; ct++)
			(*it).setNode(ct, indexesMap2[(*it).nodeIndex(ct)]);
	}//Loop on elements in mesh
	indexesMap1.clear();
	indexesMap2.clear();
}
sbfElementGroup * sbfMesh::addElementGroup()
{
	sbfElementGroup * gr = new sbfElementGroup();
	gr->setMesh(this);
	elemGroups_.push_back(gr);
	return gr;
}
sbfElementGroup * sbfMesh::addElementGroup(sbfGroupFilter filter)
{
	sbfElementGroup * gr = new sbfElementGroup();
	gr->setMesh(this);
	filter.setMesh(this);
	gr->addFilter(filter);
	elemGroups_.push_back(gr);
	return gr;
}
sbfNodeGroup * sbfMesh::addNodeGroup()
{
	sbfNodeGroup * gr = new sbfNodeGroup();
	gr->setMesh(this);
	nodeGroups_.push_back(gr);
	return gr;
}
sbfNodeGroup * sbfMesh::addNodeGroup(sbfGroupFilter filter)
{
	sbfNodeGroup * gr = new sbfNodeGroup();
	gr->setMesh(this);
	filter.setMesh(this);
	gr->addFilter(filter);
	nodeGroups_.push_back(gr);
	return gr;
}
void sbfMesh::processGroups()
{
	for(int ct = 0; ct < numGroups(); ct++)
	{
		elemGroups_[ct]->clearGroup();
		for(int ct1 = 0; ct1 < elemGroups_[ct]->numFilters(); ct1++)
		{
			sbfGroupFilter filter = elemGroups_[ct]->filter(ct1);
			filter.setMesh(this);
			for(int ct2 = 0; ct2 < numElements(); ct2++)
				if(filter.isPass(elems_[ct2]))
					elemGroups_[ct]->addElement(ct2, false);
		}
	}
}
void sbfMesh::processGroup(const int sequenceNumber)
{
	elemGroups_[sequenceNumber]->clearGroup();
	for(int ct1 = 0; ct1 < elemGroups_[sequenceNumber]->numFilters(); ct1++)
	{
		sbfGroupFilter filter = elemGroups_[sequenceNumber]->filter(ct1);
		filter.setMesh(this);
		for(int ct2 = 0; ct2 < numElements(); ct2++)
			if(filter.isPass(elems_[ct2]))
				elemGroups_[sequenceNumber]->addElement(ct2);
	}
}
void sbfMesh::processNodeGroups()
{
	for(int ct = 0; ct < numNodeGroups(); ct++)
		processNodeGroup(ct);
}
void sbfMesh::processNodeGroup(const int sequenceNumber)
{
	nodeGroups_[sequenceNumber]->clearGroup();
	for(int ct1 = 0; ct1 < nodeGroups_[sequenceNumber]->numFilters(); ct1++)
	{
		sbfGroupFilter filter = nodeGroups_[sequenceNumber]->filter(ct1);
		filter.setMesh(this);
		for(int ct2 = 0; ct2 < numNodes(); ct2++)
			if(filter.isPass(nodes_[ct2]))
				nodeGroups_[sequenceNumber]->addNode(ct2);
	}
}
void sbfMesh::clearGroups()
{
	for(size_t ct = 0; ct < elemGroups_.size(); ct++) delete elemGroups_[ct];
	elemGroups_.clear();
}
void sbfMesh::clearNodeGroups()
{
	for(size_t ct = 0; ct < nodeGroups_.size(); ct++) delete nodeGroups_[ct];
	nodeGroups_.clear();
}
void sbfMesh::clearAllGroups()
{
	for(size_t ct = 0; ct < elemGroups_.size(); ct++) delete elemGroups_[ct];
	elemGroups_.clear();
	for(size_t ct = 0; ct < nodeGroups_.size(); ct++) delete nodeGroups_[ct];
	nodeGroups_.clear();
}
void sbfMesh::addMesh(sbfMesh & mesh, bool passGroups, bool checkExisted, float tol)
{
	//Add existed mesh content [and pass] groups to current mesh

	int nnodes = mesh.numNodes();
	vector <int> newInd;
	newInd.resize(nnodes, -1);
	for(int ct = 0; ct < nnodes; ct++)
		newInd[ct] = addNode(mesh.node(ct), checkExisted, tol);
	int nelem = mesh.numElements();
	for(int ct = 0; ct < nelem; ct++){
		sbfElement el = mesh.elem(ct);
		for(int ct1 = 0; ct1 < el.numNodes(); ct1++)
			el.setNode(ct1, newInd[el.nodeIndex(ct1)]);
		addElement(el);
	}
	if(passGroups)
	{
		//TODO Not implemented yet!!!!
	}
}
void sbfMesh::addMesh(sbfMesh * mesh, bool passGroups, bool checkExisted, float tol)
{
	//Add existed mesh content [and pass] groups to current mesh

	int nnodes = mesh->numNodes();
	vector <int> newInd;
	newInd.resize(nnodes, -1);
	for(int ct = 0; ct < nnodes; ct++)
		newInd[ct] = addNode(mesh->node(ct), checkExisted, tol);
	int nelem = mesh->numElements();
	for(int ct = 0; ct < nelem; ct++){
		sbfElement el = mesh->elem(ct);
		for(int ct1 = 0; ct1 < el.numNodes(); ct1++)
			el.setNode(ct1, newInd[el.nodeIndex(ct1)]);
		addElement(el);
	}
	if(passGroups)
	{
		//TODO Not implemented yet!!!!
	}
}

//Geometry modifications
void sbfMesh::scale(float scaleX, float scaleY, float scaleZ)
{
	int nnode = numNodes();
	//TODO parallelize this
	for(int ct = 0; ct < nnode; ct++){
		nodes_[ct].setX(nodes_[ct].x()*scaleX);
		nodes_[ct].setY(nodes_[ct].y()*scaleY);
		nodes_[ct].setZ(nodes_[ct].z()*scaleZ);
	}
}
void sbfMesh::scale(float scale_)
{scale(scale_, scale_, scale_);}
void sbfMesh::translate(float transX, float transY, float transZ)
{
	int nnode = numNodes();
	//TODO parallelize this
	for(int ct = 0; ct < nnode; ct++){
		nodes_[ct].setX(nodes_[ct].x() + transX);
		nodes_[ct].setY(nodes_[ct].y() + transY);
		nodes_[ct].setZ(nodes_[ct].z() + transZ);
	}
}
void sbfMesh::rotate(float rotX, float rotY, float rotZ)
{
	//Rotate around vector (rotX, rotY, rotZ) to angle |(rotX, rotY, rotZ)|

	//Generate rotate matrix.
	float angle, dirx, diry, dirz, cs, sn;
	angle = sqrt(pow(rotX, (float)2.0) + pow(rotY, (float)2.0) + pow(rotZ, (float)2.0));
	if(angle == 0) return;
	dirx = rotX/angle;
	diry = rotY/angle;
	dirz = rotZ/angle;
	cs = cos(angle);
	sn = sin(angle);
	float L[3][3];

	L[0][0] = cs + dirx*dirx*(1.0f - cs);
	L[0][1] = dirx*diry*(1.0f - cs) - dirz*sn;
	L[0][2] = dirx*dirz*(1.0f - cs) + diry*sn;

	L[1][0] = dirx*diry*(1.0f - cs) + dirz*sn;
	L[1][1] = cs + diry*diry*(1.0f - cs);
	L[1][2] = diry*dirz*(1.0f - cs) - dirx*sn;

	L[2][0] = dirx*dirz*(1.0f - cs) - diry*sn;
	L[2][1] = diry*dirz*(1.0f - cs) + dirx*sn;
	L[2][2] = cs + dirz*dirz*(1.0f - cs);

	int nnode = numNodes();
	//TODO parallelize this
	for(int ct = 0; ct < nnode; ct++){
		float crd_[3];
		crd_[0] = nodes_[ct].x();
		crd_[1] = nodes_[ct].y();
		crd_[2] = nodes_[ct].z();
		nodes_[ct].setX(L[0][0]*crd_[0] + L[0][1]*crd_[1] + L[0][2]*crd_[2]);
		nodes_[ct].setY(L[1][0]*crd_[0] + L[1][1]*crd_[1] + L[1][2]*crd_[2]);
		nodes_[ct].setZ(L[2][0]*crd_[0] + L[2][1]*crd_[1] + L[2][2]*crd_[2]);
	}
}

sbfElementGroup * sbfMesh::group(const int sequenceNumber)
{return elemGroups_[sequenceNumber];}
sbfNodeGroup * sbfMesh::nodeGroup(const int sequenceNumber)
{return nodeGroups_[sequenceNumber];}
void sbfMesh::reserveNodesNumber(const int newNodesNumber)
{nodes_.reserve(newNodesNumber);}
void sbfMesh::reserveElementsNumber(const int newElemsNumber)
{elems_.reserve(newElemsNumber);}

void sbfMesh::optimizeNodesNumbering(NumberOptType type)
{
	/*
	 * This code based on procedures from RCMW2.cpp of sbfv_2011
	 */

	int numNodes = this->numNodes();
	size_t size = 0;
	int startNode = 0;
	int *newToOld, *oldToNew;
	int ** graph;

	newToOld = new int [numNodes];
	oldToNew = new int [numNodes];

	graph = NULL;
	computeGraphAlter(this, &graph);
	size = computeProfileSize(graph, numNodes);
	cout << "Until number optimization: size = " << size << " bandwidth = " << computeBandwidth(graph, numNodes) << endl;

	switch(type){
	default:
	case SIMPLE:
		startNode = 0;
		break;
	case FIND_FIRST_NODE:
		startNode = findStartNode(graph, numNodes);
		break;
	}

	makeRCM(graph, numNodes, startNode, newToOld, oldToNew);
	renumberNodes(newToOld);

	for(int ct = 0; ct < numNodes; ct++) delete [] graph[ct];
	delete [] graph;

	computeGraphAlter(this, &graph);
	size = computeProfileSize(graph, numNodes);
	cout << "After number optimization: size = " << size << " bandwidth = " << computeBandwidth(graph, numNodes) << endl;

	for(int ct = 0; ct < numNodes; ct++) delete [] graph[ct];
	delete [] graph;

	delete [] newToOld;
	delete [] oldToNew;
}
void computeGraph(sbfMesh * mesh, int *** graph)
{
	list<int> neighbors;
	int * mask;
	int numMask;
	int numNodes = mesh->numNodes();
	int numElems = mesh->numElements();
	int **localGraph;

	localGraph = new int * [numNodes]; //!!!!!!!!!!!!!!!!!! Possible leak of memory !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	mask = new int [numNodes];
	numMask = 0;

	//Graph computing
	cout << "Computing graph:" << endl;
	for(int curNode = 0; curNode < numNodes; curNode++){//Loop on nodes
		if(curNode % (numNodes/20 > 0 ? numNodes/20 : 1) == 0)
			cout << "\r" << curNode << " of " << numNodes << " (" << (curNode+1)*100/numNodes << "%)";
		numMask = 0;
		//Find elements which contains node "curNode"
		for(int curElem = 0; curElem < numElems; curElem++){//Loop on elements
			sbfElement * elem = mesh->elemPtr(curElem);
			vector<int> indexes = elem->indexes();
			int numElemNodes = (int)indexes.size();
			for(int ct = 0; ct < numElemNodes; ct++){//Loop on nodes in element
				if(indexes[ct] == curNode){
					mask[numMask++] = curElem;
					break;
				}
			}//Loop on nodes in element
		}//Loop on elements
		//Find neighbors for node "curNode"
		neighbors.clear();
		for(int elemCt = 0; elemCt < numMask; elemCt++){//Loop on elements
			int curElem = mask[elemCt];
			//numNeighborsOld = numNeighbors;
			sbfElement * elem = mesh->elemPtr(curElem);
			vector<int> indexes = elem->indexes();
			int numElemNodes = (int)indexes.size();
			for(int ct = 0; ct < numElemNodes; ct++){//Loop on nodes in element
				neighbors.push_back(indexes[ct]);
			}//Loop on nodes in element
		}//Loop on elements
		neighbors.sort();
		neighbors.unique();
		neighbors.remove(curNode);
		localGraph[curNode] = new int [neighbors.size()+1];
		localGraph[curNode][0] = (int)neighbors.size();
		int count = 1;
		for(list<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) localGraph[curNode][count++] = *it;
	}//Loop on nodes
	cout  << "DONE" << endl;

	neighbors.clear();
	delete [] mask;
	*graph = localGraph;
}
void computeGraphAlter(sbfMesh * mesh, int *** graph)
{
	list<int> neighbors;
	vector < list<int> > elemInd;
	int * mask;
	//int numNeighbors, numMask;//, numNeighborsOld;
	int numNodes = mesh->numNodes();
	int numElems = mesh->numElements();
	int **localGraph;

	elemInd.resize(numNodes);
	localGraph = new int * [numNodes]; //!!!!!!!!!!!!!!!!!! Possible leak of memory !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	mask = new int [numNodes];
	//numMask = 0;
	//numNeighbors = 0;

	//Graph computing
	cout << "Computing graph:" << endl;
	cout << "Pass I: ";
	int curElem;
	for(curElem = 0; curElem < numElems; curElem++){//Loop on elements
		if(curElem % (numElems/20 > 0 ? numElems/20 : 1) == 0)
			cout << "\rPass I: " << curElem << " of " << numElems << " (" << ((curElem+1)*100)/numElems << "%)";
		sbfElement * elem = mesh->elemPtr(curElem);
		vector<int> indexes = elem->indexes();
		int numElemNodes = (int)indexes.size();
		for(int ct = 0; ct < numElemNodes; ct++){//Loop on nodes in element
			elemInd[indexes[ct]].push_back(curElem);
		}//Loop on nodes in element
	}//Loop on elements
	cout << "\rPass I: " << curElem << " of " << numElems << " (" << ((curElem+1)*100)/numElems << "%)";
	cout << endl << "Pass II: ";
	int curNode;
	for(curNode = 0; curNode < numNodes; curNode++){//Loop on nodes
		if(curNode % (numNodes/20 > 0 ? numNodes/20 : 1) == 0)
			cout << "\rPass II: " << curNode << " of " << numNodes << " (" << ((curNode+1)*100)/numNodes << "%)";
		neighbors.clear();
		list <int>::iterator it, itStart, itStop;
		itStart = elemInd[curNode].begin();
		itStop = elemInd[curNode].end();
		for(it = itStart; it != itStop; it++){//Loop on elements which contain curNode
			sbfElement * elem = mesh->elemPtr(*it);
			vector<int> indexes = elem->indexes();
			int numElemNodes = (int)indexes.size();
			for(int ct = 0; ct < numElemNodes; ct++)
				neighbors.push_back(indexes[ct]);
		}//Loop on elements which contain curNode
		neighbors.sort();
		neighbors.unique();
		neighbors.remove(curNode);
		localGraph[curNode] = new int [neighbors.size()+1];
		localGraph[curNode][0] = (int)neighbors.size();
		int count = 1;
		for(list<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) localGraph[curNode][count++] = *it;
	}//Loop on nodes
	cout << "\rPass II: " << curNode << " of " << numNodes << " (" << ((curNode+1)*100)/numNodes << "%)";
	cout << "DONE" << endl;

	neighbors.clear();
	delete [] mask;
	*graph = localGraph;
}
size_t computeProfileSize(int ** graph, int numNodes, bool * flagOverFlow)
{
	size_t size = 0, threthold = numeric_limits<size_t>::max()/100*99;
	bool flagOF = false;
	for(int ct = 0; ct < numNodes; ct++){
		int bandwidth = graph[ct][1] < ct ? ct - graph[ct][1] : 0;
		size += bandwidth*9;
		size++;
		if(size > threthold)
			flagOF = true;
	}
	if(flagOverFlow)
	 *flagOverFlow = flagOF;
	return size;
}
int computeBandwidth(int ** graph, int numNodes)
{
	int bandwidth = 0;
	for(int ct = 0; ct < numNodes; ct++)
		bandwidth = ct - graph[ct][1] > bandwidth ? ct - graph[ct][1] : bandwidth;
	return bandwidth*3;
}
void findUnnumberedNeighbors(int ** graph, int * mask, int * tmp, /*I do not know better name*/ int & count, int * deg, int nodeCt)
{
	count = 0;
	for(int ct = 1; ct <= graph[nodeCt][0]; ct++){
		if(mask[graph[nodeCt][ct]] != 1){
			tmp[count] = graph[nodeCt][ct];
			deg[count] = graph[tmp[count]][0];
			count++;
		}
	}
	quickAssociatedSortUp<int, int>(deg, tmp, 0, count-1);
}
void makeRCM(int ** graph, int numNodes, int startNode, int * newToOld, int *oldToNew)
{
	int *mask, *unnumberedNeighbors, *tmp, *deg;
	int numUnnumberedNeighbors, count;
	mask = new int [numNodes];
	unnumberedNeighbors = new int [numNodes];
	tmp = new int [numNodes];
	deg = new int [numNodes];

	for(int ct = 0; ct < numNodes; ct++){mask[ct] = 0; unnumberedNeighbors[ct] = -1; tmp[ct] = deg[ct] = -1;}
	newToOld[0] = startNode;
	mask[startNode] = 1;
	numUnnumberedNeighbors = 0;

	int curNode;
	for(curNode = 0; curNode < numNodes - 1; curNode++){//Loop on nodes
		findUnnumberedNeighbors(graph, mask, tmp, count, deg, newToOld[curNode]);
		for(int ct = 0; ct < count; ct++){
			unnumberedNeighbors[numUnnumberedNeighbors] = tmp[ct];
			mask[tmp[ct]] = 1;
			numUnnumberedNeighbors++;
		}
		newToOld[curNode + 1] = unnumberedNeighbors[curNode];
		if(newToOld[curNode + 1] == -1){
			cout << "makeRCM error newToOld[" << curNode + 1 << "] == -1, tmp = " << count << endl;
			break;
		}
	}//Loop on nodes
	if(curNode < numNodes - 1)
		for(int ct = 0; ct < numNodes; ct++)
			newToOld[ct] = ct;

	int ct1 = 0, ct2 = numNodes-1;
	while(ct1 < ct2){
		int temp = newToOld[ct1];
		newToOld[ct1] = newToOld[ct2];
		newToOld[ct2] = temp;
		ct1++; ct2--;
	}

	for(int ct = 0; ct < numNodes; ct++) oldToNew[newToOld[ct]] = ct;

	delete [] mask;
	delete [] unnumberedNeighbors;
	delete [] tmp;
	delete [] deg;
}
int findStartNode(int ** graph, int numNodes)
{
	int index, minNumNeighbors;
	index = 0; minNumNeighbors = graph[index][0];
	for(int ct = 1; ct < numNodes; ct++){
		if(minNumNeighbors > graph[ct][0]){
			minNumNeighbors = graph[ct][0];
			index = ct;
		}
	}
	return index;
}

sbfMesh * sbfMesh::makeBlock(std::vector<float> & crdX, std::vector<float> & crdY, std::vector<float> & crdZ, ElementType type)
{
	sbfMesh * block = new sbfMesh();

	switch(type){
	case HEXAHEDRON_LINEAR:
	{
		block->reserveNodesNumber((int)(crdX.size()*crdY.size()*crdZ.size()));
		int xNum = (int)(crdX.size()-1);
		int yNum = (int)(crdY.size()-1);
		int zNum = (int)(crdZ.size()-1);
		int allNum = xNum*yNum*zNum;
		block->reserveElementsNumber(allNum);
		for(vector<float>::iterator itZ = crdZ.begin(); itZ != crdZ.end(); itZ++)
			for(vector<float>::iterator itY = crdY.begin(); itY != crdY.end(); itY++)
				for(vector<float>::iterator itX = crdX.begin(); itX != crdX.end(); itX++)
					block->addNode(*itX, *itY, *itZ, false);
		sbfElement elem;
		elem.setMtr(1);
		elem.setType(HEXAHEDRON_LINEAR);
		for(int ctz = 0; ctz < zNum; ctz++){
			for(int cty = 0; cty < yNum; cty++){
				for(int ctx = 0; ctx < xNum; ctx++){
					//create one element
					int temp0 = xNum+1;
					int temp1 = ctz*(yNum+1)*temp0;
					int temp2 = (ctz+1)*(yNum+1)*temp0;
					elem.setNode(0, temp1 + cty*temp0 + ctx);
					elem.setNode(1, temp1 + cty*temp0 + ctx+1);
					elem.setNode(2, temp1 + (cty+1)*temp0 + ctx+1);
					elem.setNode(3, temp1 + (cty+1)*temp0 + ctx);
					elem.setNode(4, temp2 + cty*temp0 + ctx);
					elem.setNode(5, temp2 + cty*temp0 + ctx+1);
					elem.setNode(6, temp2 + (cty+1)*temp0 + ctx+1);
					elem.setNode(7, temp2 + (cty+1)*temp0 + ctx);
					block->addElement(elem);
				}
			}
		}
		break;
	}
	case HEXAHEDRON_QUADRATIC:
		break;
	default :
		break;
	}

	return block;
}
sbfMesh * sbfMesh::makeBlock(float xSide, float ySide, float zSide, int xPart, int yPart, int zPart, ElementType type)
{
	vector<float> crdX, crdY, crdZ;
	crdX.reserve(xPart+1);
	crdY.reserve(yPart+1);
	crdZ.reserve(zPart+1);
	float step;
	step = xSide/xPart;
	for(int ct = 0; ct <= xPart; ct++)
		crdX.push_back(step*ct);
	step = ySide/yPart;
	for(int ct = 0; ct <= yPart; ct++)
		crdY.push_back(step*ct);
	step = zSide/zPart;
	for(int ct = 0; ct <= zPart; ct++)
		crdZ.push_back(step*ct);
	return sbfMesh::makeBlock(crdX, crdY, crdZ, type);
}


sbfNode::sbfNode()
{//crd_.resize(3, 0.0);
	//crds_ = new float [3];
}
sbfNode::sbfNode(float x, float y, float z)
{//crd_.resize(3, 0.0);
	setX(x);setY(y);setZ(z);}
sbfNode::sbfNode(const sbfNode &node)
{//crd_ = node.crd_;
	crd_[0] = node.crd_[0];
	crd_[1] = node.crd_[1];
	crd_[2] = node.crd_[2];
}
sbfNode::~sbfNode()
{//crd_.clear();
}

void sbfNode::setX(const float x)
{crd_[0] = x;}
void sbfNode::setY(const float y)
{crd_[1] = y;}
void sbfNode::setZ(const float z)
{crd_[2] = z;}
float sbfNode::x()
{return crd_[0];}
float sbfNode::y()
{return crd_[1];}
float sbfNode::z()
{return crd_[2];}
float & sbfNode::crdAtKort(int kort)
{return crd_[kort];}
bool sbfNode::isSame(sbfNode & node, const float tolerance)
{
	//return sqrt(pow(x()-node.x(), 2) + pow(y()-node.y(), 2) + pow(z()-node.z(), 2)) < tolerance ? true : false;
	if(!isSameX(node, tolerance))
		return false;
	else if(!isSameY(node, tolerance))
		return false;
	else if(!isSameZ(node, tolerance))
		return false;
	else
		//Distance check should be here!!!!!!!!!!!!!!!!!
		return true;
}
bool sbfNode::isSameX(sbfNode & node, const float tolerance)
{return fabs(x()-node.x()) < tolerance ? true : false;}
bool sbfNode::isSameY(sbfNode & node, const float tolerance)
{return fabs(y()-node.y()) < tolerance ? true : false;}
bool sbfNode::isSameZ(sbfNode & node, const float tolerance)
{return fabs(z()-node.z()) < tolerance ? true : false;}
float sbfNode::distance(sbfNode & node)
{return sqrt(pow(x()-node.x(), 2) + pow(y()-node.y(), 2) + pow(z()-node.z(), 2));}
void sbfNode::rotate(float rotX, float rotY, float rotZ)
{
	//Rotate around vector (rotX, rotY, rotZ) to angle |(rotX, rotY, rotZ)|

	//Generate rotate matrix.
	float angle, dirx, diry, dirz, cs, sn;
	angle = sqrt(pow(rotX, (float)2.0) + pow(rotY, (float)2.0) + pow(rotZ, (float)2.0));
	dirx = rotX/angle;
	diry = rotY/angle;
	dirz = rotZ/angle;
	cs = cos(angle);
	sn = sin(angle);
	float L[3][3];

	L[0][0] = cs + dirx*dirx*(1.0f - cs);
	L[0][1] = dirx*diry*(1.0f - cs) - dirz*sn;
	L[0][2] = dirx*dirz*(1.0f - cs) + diry*sn;

	L[1][0] = dirx*diry*(1.0f - cs) + dirz*sn;
	L[1][1] = cs + diry*diry*(1.0f - cs);
	L[1][2] = diry*dirz*(1.0f - cs) - dirx*sn;

	L[2][0] = dirx*dirz*(1.0f - cs) - diry*sn;
	L[2][1] = diry*dirz*(1.0f - cs) + dirx*sn;
	L[2][2] = cs + dirz*dirz*(1.0f - cs);

	float oldCrd_[3];
	oldCrd_[0] = x();
	oldCrd_[1] = y();
	oldCrd_[2] = z();
	setX(L[0][0]*oldCrd_[0] + L[0][1]*oldCrd_[1] + L[0][2]*oldCrd_[2]);
	setY(L[1][0]*oldCrd_[0] + L[1][1]*oldCrd_[1] + L[1][2]*oldCrd_[2]);
	setZ(L[2][0]*oldCrd_[0] + L[2][1]*oldCrd_[1] + L[2][2]*oldCrd_[2]);
}

sbfElement::sbfElement()
{}
sbfElement::sbfElement(const int numNodes)
{ind_.resize(numNodes, -1);}
sbfElement::sbfElement(const ElementType type, vector <int> indexes)
{type_ = type; setNodes(indexes);}
sbfElement::~sbfElement()
{ind_.clear();}

void sbfElement::setNumNodes(const int nNodes)
{ind_.resize(nNodes, -1);}
int sbfElement::numNodes()
{return (int) ind_.size();}
void sbfElement::setNode(const int sequenceNumber, const int nodeNumber)
{ind_[sequenceNumber] = nodeNumber;}
void sbfElement::addNode(const int nodeNumber)
{ind_.push_back(nodeNumber);}
int sbfElement::nodeIndex(const int sequenceNumber)
{return ind_[sequenceNumber];}
vector<int> sbfElement::indexes()
{return ind_;}
//inline vector<int> & sbfElement::nodeIndexs()
//{return ind_;}
void sbfElement::setNodes(const int nodeNumber, int first, ...)
{for(int ct = 0; ct < nodeNumber; ct++) ind_[ct] = *(&first + ct);}
void sbfElement::setNodes(const vector <int> indexes)
{ind_.clear(); ind_ = indexes;}
void sbfElement::setMtr(const int material)
{mtr_ = material;}
int sbfElement::mtr()
{return mtr_;}
void sbfElement::setType(const ElementType & type)
{type_ = type;
setNumNodes(numNodesInElement(type));}
ElementType sbfElement::type()
{return type_;}
std::vector<std::vector<int> > sbfElement::facesNodesIndexes() {
	std::vector<std::vector<int> > facesNodes;
	switch (type()){
	case TETRAHEDRON_LINEAR : {
		facesNodes.push_back(std::vector<int>{ind_[0], ind_[1], ind_[2]});
		facesNodes.push_back(std::vector<int>{ind_[0], ind_[3], ind_[1]});
		facesNodes.push_back(std::vector<int>{ind_[1], ind_[3], ind_[2]});
		facesNodes.push_back(std::vector<int>{ind_[2], ind_[3], ind_[0]});
		break;
	}
	case TETRAHEDRON_QUADRATIC : {
		facesNodes.push_back(std::vector<int>{ind_[0], ind_[4], ind_[1], ind_[5], ind_[2], ind_[6]});
		facesNodes.push_back(std::vector<int>{ind_[0], ind_[7], ind_[3], ind_[8], ind_[1], ind_[4]});
		facesNodes.push_back(std::vector<int>{ind_[1], ind_[8], ind_[3], ind_[9], ind_[2], ind_[5]});
		facesNodes.push_back(std::vector<int>{ind_[2], ind_[9], ind_[3], ind_[7], ind_[0], ind_[6]});
		break;
	}
	case HEXAHEDRON_LINEAR : {
		facesNodes.push_back(std::vector<int>{ind_[0], ind_[1], ind_[2], ind_[3]});
		facesNodes.push_back(std::vector<int>{ind_[4], ind_[7], ind_[6], ind_[5]});
		facesNodes.push_back(std::vector<int>{ind_[0], ind_[4], ind_[5], ind_[1]});
		facesNodes.push_back(std::vector<int>{ind_[1], ind_[5], ind_[6], ind_[2]});
		facesNodes.push_back(std::vector<int>{ind_[2], ind_[6], ind_[7], ind_[3]});
		facesNodes.push_back(std::vector<int>{ind_[3], ind_[7], ind_[4], ind_[0]});
		break;
	}
	case HEXAHEDRON_QUADRATIC : {
		facesNodes.push_back(std::vector<int>{ind_[ 0], ind_[ 8], ind_[ 1], ind_[ 9], ind_[ 2], ind_[10], ind_[ 3], ind_[11]});
		facesNodes.push_back(std::vector<int>{ind_[ 4], ind_[19], ind_[ 7], ind_[18], ind_[ 6], ind_[17], ind_[ 5], ind_[16]});
		facesNodes.push_back(std::vector<int>{ind_[ 0], ind_[12], ind_[ 4], ind_[16], ind_[ 5], ind_[13], ind_[ 1], ind_[ 8]});
		facesNodes.push_back(std::vector<int>{ind_[ 1], ind_[13], ind_[ 5], ind_[17], ind_[ 6], ind_[14], ind_[ 2], ind_[ 9]});
		facesNodes.push_back(std::vector<int>{ind_[ 2], ind_[14], ind_[ 6], ind_[18], ind_[ 7], ind_[15], ind_[ 3], ind_[10]});
		facesNodes.push_back(std::vector<int>{ind_[ 3], ind_[15], ind_[ 7], ind_[19], ind_[ 4], ind_[12], ind_[ 0], ind_[11]});
		break;
	}
	default:
		break;
	}
	return facesNodes;
}
sbfNode sbfElement::centreOfMass()
{
	int nNode = numNodes();
	float x, y, z;
	z = y = x = 0.0;
	sbfNode node;
	for(int ct = 0; ct < nNode; ct++){
		node = mesh_->node(ind_[ct]);
		x += node.x();
		y += node.y();
		z += node.z();
	}
	return sbfNode(x/nNode, y/nNode, z/nNode);
}
void sbfElement::setMesh(sbfMesh * mesh)
{mesh_ = mesh;}
float sbfElement::max(const int kort)
{
	int nNode = numNodes();
	if(nNode == 0)
		return -std::numeric_limits<float>::max();
	float max = mesh_->node(nodeIndex(0)).crdAtKort(kort);
	for(int ct = 1; ct < nNode; ct++)
		if(max < mesh_->node(nodeIndex(ct)).crdAtKort(kort))
			max = mesh_->node(nodeIndex(ct)).crdAtKort(kort);
	return max;
}
float sbfElement::min(const int kort)
{
	int nNode = numNodes();
	if(nNode == 0)
		return std::numeric_limits<float>::max();
	float min = mesh_->node(nodeIndex(0)).crdAtKort(kort);
	for(int ct = 1; ct < nNode; ct++)
		if(min > mesh_->node(nodeIndex(ct)).crdAtKort(kort))
			min = mesh_->node(nodeIndex(ct)).crdAtKort(kort);
	return min;
}
float sbfElement::maxX()
{return max(0);}
float sbfElement::maxY()
{return max(1);}
float sbfElement::maxZ()
{return max(2);}
float sbfElement::minX()
{return min(0);}
float sbfElement::minY()
{return min(1);}
float sbfElement::minZ()
{return min(2);}
sbfMesh * sbfElement::mesh()
{return mesh_;}
float sbfElement::volume()
{
	double vol;
	switch (type()) {
	case HEXAHEDRON_LINEAR :
	{
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ERROR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		double v1[3], v2[3], v3[3];
		v1[0] = mesh_->node(ind_[1]).x() - mesh_->node(ind_[0]).x();
		v1[1] = mesh_->node(ind_[1]).y() - mesh_->node(ind_[0]).y();
		v1[2] = mesh_->node(ind_[1]).z() - mesh_->node(ind_[0]).z();
		v2[0] = mesh_->node(ind_[4]).x() - mesh_->node(ind_[0]).x();
		v2[1] = mesh_->node(ind_[4]).y() - mesh_->node(ind_[0]).y();
		v2[2] = mesh_->node(ind_[4]).z() - mesh_->node(ind_[0]).z();
		v3[0] = mesh_->node(ind_[3]).x() - mesh_->node(ind_[0]).x();
		v3[1] = mesh_->node(ind_[3]).y() - mesh_->node(ind_[0]).y();
		v3[2] = mesh_->node(ind_[3]).z() - mesh_->node(ind_[0]).z();
		vol = v1[0]*v2[1]*v3[2] + v1[1]*v2[2]*v3[0] + v2[0]*v3[1]*v1[2] - v3[0]*v2[1]*v1[2] - v3[1]*v2[2]*v1[0] - v3[2]*v2[0]*v1[2];
		break;
	}
	default :
		vol = 0;
		break;
	}
	return (float)vol;
}

sbfSElement::sbfSElement()
{initialize();}
sbfSElement::sbfSElement(sbfMesh * mesh, int index)
{
	initialize();
	mesh_ = mesh;
	seIndex_ = index;
}
void sbfSElement::initialize()
{
	numChildren_ = 0;
	seIndex_ = -1;
	mesh_ = NULL;
	parent_ = NULL;
	childrens_ = NULL;
	regElemIndexes_ = NULL;
	nodesIds_ = NULL;
}
sbfSElement::~sbfSElement()
{
	if(childrens_ != NULL) {delete [] childrens_; childrens_ = NULL;}
	if(regElemIndexes_ != NULL) {delete [] regElemIndexes_; regElemIndexes_ = NULL;}
	if(nodesIds_ != NULL) {delete [] nodesIds_; nodesIds_ = NULL;}
}
std::vector<int> sbfSElement::regElemIndexes()
{
	//Collect regular elements indexes in all underlying (children) SE
	std::vector<int> indexes;

	if(numChildren_ && regElemIndexes_){//This is a lower level SE, containing only regular elements
		indexes.resize(numChildren_);
		for(int ct = 0; ct < numChildren_; ct++) indexes[ct] = regElemIndexes_[ct];
	}
	else if(numChildren_ && childrens_){
		for(int ct = 0; ct < numChildren_; ct++){//Loop on underlying SE's
			std::vector<int> indexesToAppend = childrens_[ct]->regElemIndexes();
			indexes.insert(indexes.end(), indexesToAppend.begin(), indexesToAppend.end());
		}
	}

	return indexes;
}
void sbfSElement::setRegElemIndexes (std::vector<int> regElemIndexes){
	//Since adding regular element, childrens_ should be void
	if(childrens_ != NULL) {delete [] childrens_; childrens_ = NULL;}
	if(regElemIndexes_ != NULL) {delete [] regElemIndexes_; regElemIndexes_ = NULL;}
	numChildren_ = regElemIndexes.size();
	regElemIndexes_ = new int [numChildren_];
	for(int ct = 0; ct < numChildren_; ct++) regElemIndexes_[ct] = regElemIndexes[ct];
}
void sbfSElement::setChildrens (std::vector<sbfSElement *> selems){
	//Since adding super elements, regElemIndexes_ should be void
	if(childrens_ != NULL) {delete [] childrens_; childrens_ = NULL;}
	if(regElemIndexes_ != NULL) {delete [] regElemIndexes_; regElemIndexes_ = NULL;}
	numChildren_ = selems.size();
	childrens_ = new sbfSElement * [numChildren_];
	for(int ct = 0; ct < numChildren_; ct++) childrens_[ct] = selems[ct];
}
void sbfSElement::addChildren(sbfSElement * selem){
	//Since adding super elements, regElemIndexes_ should be void
	if(regElemIndexes_ != NULL) {delete [] regElemIndexes_; regElemIndexes_ = NULL; numChildren_ = 0;}
	sbfSElement ** tmp = new sbfSElement * [numChildren_ + 1];
	if(childrens_ != NULL){
		for(int ct = 0; ct < numChildren_; ct++) tmp[ct] = childrens_[ct];
		delete [] childrens_;
	}
	tmp[numChildren_++] = selem;
	childrens_ = tmp;
}

sbfSELevel::sbfSELevel()
{
	prevLayer_ = NULL;
	nextLayer_ = NULL;
	level_ = -1;
	mesh_ = NULL;
}
sbfSELevel::~sbfSELevel()
{
	ind_.clear();
}
void sbfSELevel::setMesh(sbfMesh * mesh)
{mesh_ = mesh;}
void sbfSELevel::setSize(int size)
{ind_.resize(size, -1);}
int sbfSELevel::size()
{return (int) ind_.size();}
void sbfSELevel::setLevelIndex(int index)
{level_ = index;}
int sbfSELevel::levelIndex()
{return level_;}
void sbfSELevel::setIndex(int seqNumber, int index)
{ind_.at(seqNumber) = index;}
int sbfSELevel::index(int seqNumber)
{return ind_[seqNumber];}
int sbfSELevel::numSE()
{
	std::list<int> seList;
	for(vector<int>::iterator it = ind_.begin(); it != ind_.end(); it++)
	{
		int seInd = *it;
		bool flagExist = false;
		for(list<int>::iterator itL = seList.begin(); itL != seList.end(); itL++)
			if(seInd == *itL)
			{flagExist = true; break;}
		if(!flagExist)
			seList.push_back(seInd);
	}
	seList.sort();
	return (int) seList.size();
}
vector<int> sbfSELevel::indexesOfSE(int seqNumber)
{
	std::vector<int> indexes;
	if(seqNumber >= numSE())
		return indexes;
	indexes.reserve(ind_.size());
	int length = (int)ind_.size();
	for(int ct = 0; ct < length; ct++)
		if(ind_[ct] == seqNumber) indexes.push_back(ct);
	return indexes;
}
sbfSELevel * sbfSELevel::prev()
{return prevLayer_;}
sbfSELevel * sbfSELevel::next()
{return nextLayer_;}
void sbfSELevel::writeToFile(const char * baseName, int levelIndex, int numDigits)
{
	stringstream sStream;
	sStream << baseName;
	sStream.width(numDigits);
	sStream.fill('0');
	if(levelIndex != -1)
		sStream << levelIndex;
	else
		sStream << level_+1;
	sStream << ".sba";

	ofstream out(sStream.str().c_str(), ios::binary);
	for(vector<int>::iterator it = ind_.begin();it != ind_.end(); it++)
		(*it)++;
	out.write((const char *)&ind_[0], (int)ind_.size()*sizeof(ind_[0]));
	out.close();
}
int sbfSELevel::readFromFile(const char * baseName, int levelIndex, int numDigits)
{
	stringstream sStream;
	sStream << baseName;
	sStream.width(numDigits);
	sStream.fill('0');
	if(levelIndex != -1)
		sStream << levelIndex;
	else
		sStream << level_+1;
	sStream << ".sba";

	ifstream in(sStream.str().c_str(), ios::binary);
	if(!in.good())
		return 1;
	in.seekg(0, ios::end);
	setSize((int)in.tellg()/sizeof(ind_[0]));
	in.seekg(0, ios::beg);
	in.read((char *)&ind_[0], (int)ind_.size()*sizeof(ind_[0]));
	for(vector<int>::iterator it = ind_.begin();it != ind_.end(); it++)
		(*it)--;
	in.close();
	return 0;
}

sbfSELevelList::sbfSELevelList()
{mesh_ = NULL;}
sbfSELevelList::~sbfSELevelList()
{list_.clear();}
int sbfSELevelList::numLevels()
{return (int)list_.size();}
sbfSELevel & sbfSELevelList::level(int seqNumber)
{
	list<sbfSELevel>::iterator it = list_.begin();
	for(int ct = 0; ct < seqNumber; ct++) it++;
	return *it;
}
void sbfSELevelList::writeToFiles(const char * baseName, int numDigits)
{
	for(list<sbfSELevel>::iterator it = list_.begin(); it != list_.end(); it++)
		(*it).writeToFile(baseName, (*it).levelIndex(), numDigits);
}
int sbfSELevelList::readFromFiles(const char * baseName, int numDigits)
{
	for(int ct = 1, rez = 0; rez == 0;ct++)
	{
		sbfSELevel layer;
		rez = layer.readFromFile(baseName, ct, numDigits);
		if(rez == 0)//read OK
		{
			layer.setMesh(mesh_);
			layer.setLevelIndex(ct-1);
			list_.push_back(layer);
		}
		else
			break;
	}
	return 0;
}
void sbfSELevelList::setMesh(sbfMesh * mesh)
{mesh_ = mesh;}
std::vector< std::vector<sbfSElement *> > sbfSELevelList::selevels (std::vector<sbfSElement *> * fakeSEs)
{
	std::vector< std::vector<sbfSElement *> > selements;
	selements.resize(numLevels());

	for(int ctLevel = 0; ctLevel < numLevels(); ctLevel++){
		selements[ctLevel].reserve(level(ctLevel).numSE());
		for(int ctSe = 0; ctSe < level(ctLevel).numSE(); ctSe++) selements[ctLevel].push_back(new sbfSElement(mesh_, ctSe));
		std::vector< std::vector<int> > indexesPerSEs;
		indexesPerSEs.resize(level(ctLevel).numSE());
		for(int ctSe = 0; ctSe < level(ctLevel).numSE(); ctSe++) indexesPerSEs[ctSe] = level(ctLevel).indexesOfSE(ctSe);
		if(ctLevel == 0){
			for(int ctSe = 0; ctSe < level(ctLevel).numSE(); ctSe++)
				selements[ctLevel][ctSe]->setRegElemIndexes(indexesPerSEs[ctSe]);
			if(fakeSEs && mesh_){
				fakeSEs->reserve(mesh_->numElements());
				for(int ctElem = 0; ctElem < mesh_->numElements(); ctElem++)
					fakeSEs->push_back(new sbfSElement(mesh_, ctElem));
				for(int ctSe = 0; ctSe < level(0).numSE(); ctSe++)
					for(size_t ct = 0; ct < indexesPerSEs[ctSe].size(); ct++)
						(*fakeSEs)[indexesPerSEs[ctSe][ct]]->setParent(selements[ctLevel][ctSe]);
			}
		}
		else{
			for(int ctSe = 0; ctSe < level(ctLevel).numSE(); ctSe++){
				for(size_t ct = 0; ct < indexesPerSEs[ctSe].size(); ct++){
					selements[ctLevel][ctSe]->addChildren(selements[ctLevel-1][indexesPerSEs[ctSe][ct]]);
					selements[ctLevel-1][indexesPerSEs[ctSe][ct]]->setParent(selements[ctLevel][ctSe]);
				}
			}
		}
	}


	return selements;
}

sbfGroup::sbfGroup()
{}
sbfGroup::~sbfGroup()
{}

void sbfGroup::addFilter(const sbfGroupFilter &filter)
{filters_.push_back(filter);}
void sbfGroup::clearFilters()
{filters_.clear();}
int sbfGroup::numFilters()
{return (int)filters_.size();}
sbfGroupFilter & sbfGroup::filter(int count)
{return filters_[count];}

sbfElementGroup::sbfElementGroup() : sbfGroup()
{}
sbfElementGroup::~sbfElementGroup()
{}

void sbfElementGroup::clearGroup()
{list_.clear();}
void sbfElementGroup::reserve(int newSize)
{list_.reserve(newSize);}
void sbfElementGroup::addElement(const int element, bool checkDuplicate)
{
	if(checkDuplicate)
		for(unsigned int ct = 0; ct < list_.size(); ct++)
		{if(list_[ct] == element)
			return;}
	list_.push_back(element);
}

int sbfElementGroup::element(const int sequenceNumber)
{return list_[sequenceNumber];}
int sbfElementGroup::numElems()
{return (int)list_.size();}
ElementType sbfElementGroup::type()
{
	//Return element type of groupe; if many types or none return -1
	if(list_.empty())
		return NO_DEFINED_ELEMENT;
	ElementType type = mesh_->elem(list_[0]).type();
	for(int ct = 0; ct < numElems(); ct++)
	{
		if(type != mesh_->elem(list_[ct]).type())
			return NO_DEFINED_ELEMENT;
	}
	return type;
}
void sbfElementGroup::setMesh(sbfMesh *mesh)
{mesh_ = mesh;}
void sbfElementGroup::setMtr(const int mtr_)
{
	int nElem = numElems();
	for(int ct = 0; ct < nElem; ct++)
		mesh_->elem(list_[ct]).setMtr(mtr_);
}
vector <int> sbfElementGroup::elemIndList()
{return list_;}
vector <int> sbfElementGroup::nodeIndList()
{
	vector <int> nodeList;
	int allNodes = 0, nElem = numElems();
	for(int ct = 0; ct < nElem; ct++) allNodes += mesh_->elem(list_[ct]).numNodes();
	nodeList.reserve(allNodes*sizeof(int));
	for(int ct = 0; ct < nElem; ct++){
		sbfElement *el = mesh_->elemPtr(list_[ct]);
		int nNode = el->numNodes();
		for(int ct1 = 0; ct1 < nNode; ct1++){
			int node = el->nodeIndex(ct1);
			/*bool flag = false;
			int size = (int)nodeList.size();
			for(int ct2 = 0; ct2 < size; ct2++){
				if(nodeList[ct] == node){
					flag = true;
					break;
				}
			}
			if(!flag)*/
			nodeList.push_back(node);
		}
	}
	int nodeListSize = (int)nodeList.size();
	if(nodeListSize != 0)
		quickSortIntUp(nodeList, 0, nodeListSize-1);
	vector <int> nodeList_;
	if(nodeListSize > 0){
		nodeList_.reserve(nodeListSize*sizeof(int));
		nodeList_.push_back(nodeList.front());
		for(int ct = 1; ct < nodeListSize; ct++)
			if(nodeList_.back() != nodeList[ct])
				nodeList_.push_back(nodeList[ct]);
		nodeList.clear();
	}
	return nodeList_;
}

sbfNodeGroup::sbfNodeGroup() : sbfGroup()
{}
sbfNodeGroup::~sbfNodeGroup()
{}

void sbfNodeGroup::clearGroup()
{list_.clear();}
void sbfNodeGroup::addNode(const int nodeInd)
{
	for(unsigned int ct = 0; ct < list_.size(); ct++)
	{if(list_[ct] == nodeInd)
		return;}
	list_.push_back(nodeInd);
}

int sbfNodeGroup::node(const int sequenceNumber)
{return list_[sequenceNumber];}
int sbfNodeGroup::numNodes()
{return (int)list_.size();}
void sbfNodeGroup::setMesh(sbfMesh *mesh)
{mesh_ = mesh;}
vector <int> sbfNodeGroup::nodeIndList()
{return list_;}


sbfGroupFilter::sbfGroupFilter()
{mtrF_ = xMaxF_ = xMinF_ = yMaxF_ = yMinF_ = zMaxF_ = zMinF_ = typeF_ = false;
xMin_ = yMin_ = zMin_ = -std::numeric_limits<float>::max();
xMax_ = yMax_ = zMax_ = std::numeric_limits<float>::max();
mesh_ = NULL;}
sbfGroupFilter::~sbfGroupFilter()
{}
void sbfGroupFilter::setMtrF(int mtr)
{
	mtrF_ = true;
	mtr_ = mtr;
}
void sbfGroupFilter::unsetMtrF()
{mtrF_ = false;}
void sbfGroupFilter::setTypeF(ElementType type)
{
	typeF_ = true;
	type_ = type;
}
void sbfGroupFilter::unsetTypeF()
{typeF_ = false;}
void sbfGroupFilter::setCrdF(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax)
{
	xMaxF_ = xMinF_ = yMaxF_ = yMinF_ = zMaxF_ = zMinF_ = true;
	xMin_ = xMin;
	xMax_ = xMax;
	yMin_ = yMin;
	yMax_ = yMax;
	zMin_ = zMin;
	zMax_ = zMax;
}
void sbfGroupFilter::setCrdXF(float xMin, float xMax)
{
	xMaxF_ = xMinF_ = true;
	xMin_ = xMin;
	xMax_ = xMax;
}
void sbfGroupFilter::setCrdYF(float yMin, float yMax)
{
	yMaxF_ = yMinF_ = true;
	yMin_ = yMin;
	yMax_ = yMax;
}
void sbfGroupFilter::setCrdZF(float zMin, float zMax)
{
	zMaxF_ = zMinF_ = true;
	zMin_ = zMin;
	zMax_ = zMax;
}
void sbfGroupFilter::unsetCrdF()
{
	xMaxF_ = xMinF_ = yMaxF_ = yMinF_ = zMaxF_ = zMinF_ = false;
	xMin_ = yMin_ = zMin_ = -std::numeric_limits<float>::max();
	xMax_ = yMax_ = zMax_ = std::numeric_limits<float>::max();
}
void sbfGroupFilter::setMesh(sbfMesh *mesh)
{mesh_ = mesh;}
bool sbfGroupFilter::isPass(sbfElement &elem)
{
	if(mesh_ == NULL)
		return false;
	if(mtrF_ && mtr_ == elem.mtr())
		return true;
	else if(typeF_ && type_ == elem.type())
		return true;
	else if(xMaxF_ || yMaxF_ || zMaxF_ || xMinF_ || yMinF_ || zMinF_){
		sbfNode node = elem.centreOfMass();
		if(xMaxF_)
			if(xMax_ <= node.x())
				return false;
		if(yMaxF_)
			if(yMax_ <= node.y())
				return false;
		if(zMaxF_)
			if(zMax_ <= node.z())
				return false;
		if(xMinF_)
			if(xMin_ >= node.x())
				return false;
		if(yMinF_)
			if(yMin_ >= node.y())
				return false;
		if(zMinF_)
			if(zMin_ >= node.z())
				return false;
		return true;
	}
	//else
		return false;
}
bool sbfGroupFilter::isPass(sbfNode &node)
{
	if(mesh_ == NULL)
		return false;
	{
		if(xMaxF_)
			if(xMax_ <= node.x())
				return false;
		if(yMaxF_)
			if(yMax_ <= node.y())
				return false;
		if(zMaxF_)
			if(zMax_ <= node.z())
				return false;
		if(xMinF_)
			if(xMin_ >= node.x())
				return false;
		if(yMinF_)
			if(yMin_ >= node.y())
				return false;
		if(zMinF_)
			if(zMin_ >= node.z())
				return false;
	}
	return true;
}

bool sbf::crdcmp(float crd1, float crd2, float eps)
{return (fabs(crd1 - crd2) < eps) ? true : false;}

int sbf::numNodesInElement(ElementType type)
{
	if( type == HEXAHEDRON_LINEAR )
		return 8;
	else if( type == HEXAHEDRON_QUADRATIC )
		return 20;
	else if( type == BEAM_LINEAR_3DOF )
		return 2;
	else if( type == BEAM_QUADRATIC_3DOF )
		return 3;
	else if( type == BEAM_LINEAR_6DOF )
		return 2;
	else if( type == BEAM_QUADRATIC_6DOF )
		return 3;
	else if( type == RECTANGLE_LINEAR )
		return 4;
	else if( type == TETRAHEDRON_LINEAR )
		return 4;
	else if( type == TETRAHEDRON_QUADRATIC )
		return 10;
	return -1;
}
int sbf::typesLibToFile(const ElementType & type)
{
	//Convert internal element type to sba ind file format
	if( type == BEAM_LINEAR_3DOF )
		return 10;
	else if( type == BEAM_QUADRATIC_3DOF )
		return 11;
	else if( type == BEAM_LINEAR_6DOF )
		return 8;
	else if( type == BEAM_QUADRATIC_6DOF )
		return 9;
	else if( type == RECTANGLE_LINEAR )
		return 6;
	else if( type == HEXAHEDRON_LINEAR )
		return 0;
	else if( type == HEXAHEDRON_QUADRATIC )
		return 1;
	else if( type == TETRAHEDRON_LINEAR )
		return 4;
	else if( type == TETRAHEDRON_QUADRATIC )
		return 5;
	return -1;
}
ElementType sbf::typesFileToLib(const int type)
{
	//Convert sba ind file type of element to internal library element type
	if( type == 10 )
		return BEAM_LINEAR_3DOF;
	else if( type == 11 )
		return BEAM_QUADRATIC_3DOF;
	else if( type == 8 )
		return BEAM_LINEAR_6DOF;
	else if( type == 9 )
		return BEAM_QUADRATIC_6DOF;
	else if( type == 6 )
		return RECTANGLE_LINEAR;
	else if( type == 0 )
		return HEXAHEDRON_LINEAR;
	else if( type == 1 )
		return HEXAHEDRON_QUADRATIC;
	else if( type == 4 )
		return TETRAHEDRON_LINEAR;
	else if( type == 5 )
		return TETRAHEDRON_QUADRATIC;
	return NO_DEFINED_ELEMENT;
}
ElementType sbf::tryToResolveTypeByNumNodes(int numNodes, int kort)
{
	ElementType type = NO_DEFINED_ELEMENT;
	if(numNodes == 8) type = HEXAHEDRON_LINEAR;
	else if(numNodes == 20) type = HEXAHEDRON_QUADRATIC;
	else if(numNodes == 4) type = TETRAHEDRON_LINEAR;
	else if(numNodes == 10) type = TETRAHEDRON_QUADRATIC;
	else if(numNodes == 2) type = BEAM_LINEAR_3DOF;
	else if(numNodes == 3) type = BEAM_QUADRATIC_3DOF;
	return type;
}
/*
// �������� �������� 8-�� ������� �������� ������� (�����)
		El_Nus[0] = 8;
		El_Ngr[0] = 4;
// ������������ �������� 20-�� ������� �������� ������� (�����)
		El_Nus[1] = 20;
		El_Ngr[1] = 8;
// �������� �������� 6-�� ������� �������� ������� (����������� ������)
		El_Nus[2] = 6;
		El_Ngr[2] = 4;
// ������������ �������� 15-�� ������� �������� ������� (����������� ������)
		El_Nus[3] = 15;
		El_Ngr[3] = 8;
// �������� �������� 4-� ������� �������� ������� (��������)
		El_Nus[4] = 4;
		El_Ngr[4] = 3;
// ������������ �������� 10-�� ������� �������� ������� (��������)
		El_Nus[5] = 10;
		El_Ngr[5] = 6;
// �������� ������� 4-� ������� �������� ������� 
		El_Nus[6] = 4;
		El_Ngr[6] = 4;
// ������������ �������� 8-�� ������� �������� �������
		El_Nus[7] = 8;
		El_Ngr[7] = 8;
// �������� ���������� 2-� ������� �������� ������� (6 �������� ������� � ����) 
		El_Nus[8] = 2;
		El_Ngr[8] = 0;
// ������������ ���������� 3-� ������� �������� ������� (6 �������� ������� � ����)
		El_Nus[9] = 3;
		El_Ngr[9] = 0;
// �������� ���������� 2-� ������� �������� ������� (3 ������� ������� � ����) 
		El_Nus[10] = 2;
		El_Ngr[10] = 0;
 */


void quickSortCrd(vector <float> & crd, vector <int> & ind, int left, int right){
	int i = left, j = right;
	float tmpF;
	int tmpI;
	float pivot = crd[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (crd[i] < pivot)
			i++;
		while (crd[j] > pivot)
			j--;
		if (i <= j) {
			tmpF = crd[i];
			crd[i] = crd[j];
			crd[j] = tmpF;
			tmpI = ind[i];
			ind[i] = ind[j];
			ind[j] = tmpI;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSortCrd(crd, ind, left, j);
	if (i < right)
		quickSortCrd(crd, ind, i, right);
}

void quickSortIntDown(vector <int> & ind, int left, int right){
	int i = left, j = right;
	int tmpI;
	int pivot = ind[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (ind[i] > pivot)
			i++;
		while (ind[j] < pivot)
			j--;
		if (i <= j) {
			tmpI = ind[i];
			ind[i] = ind[j];
			ind[j] = tmpI;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSortIntDown(ind, left, j);
	if (i < right)
		quickSortIntDown(ind, i, right);
}
void quickSortIntUp(vector <int> & ind1, int left, int right){
	int i = left, j = right;
	int tmpI;
	int pivot = ind1[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (ind1[i] < pivot)
			i++;
		while (ind1[j] > pivot)
			j--;
		if (i <= j) {
			tmpI = ind1[i];
			ind1[i] = ind1[j];
			ind1[j] = tmpI;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSortIntUp(ind1, left, j);
	if (i < right)
		quickSortIntUp(ind1, i, right);
}
void quickSortIntUp(vector <int> & ind1, vector <int> & ind2, int left, int right){
	int i = left, j = right;
	int tmpI;
	int pivot = ind1[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (ind1[i] < pivot)
			i++;
		while (ind1[j] > pivot)
			j--;
		if (i <= j) {
			tmpI = ind1[i];
			ind1[i] = ind1[j];
			ind1[j] = tmpI;
			tmpI = ind2[i];
			ind2[i] = ind2[j];
			ind2[j] = tmpI;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSortIntUp(ind1, ind2, left, j);
	if (i < right)
		quickSortIntUp(ind1, ind2, i, right);
}
//template <class TypeToSort, class AssociatedType> void quickAssociatedSortUp(TypeToSort * arrayToSort, AssociatedType * associatedArray, int left, int right){
//	int i = left, j = right;
//	TypeToSort tmpTypeToSort;
//	AssociatedType tmpAssociatedType;
//	TypeToSort pivot = arrayToSort[(left + right) / 2];
//	/* partition */
//	while (i <= j) {
//		while (arrayToSort[i] < pivot)
//			i++;
//		while (arrayToSort[j] > pivot)
//			j--;
//		if (i <= j) {
//			tmpTypeToSort = arrayToSort[i];
//			arrayToSort[i] = arrayToSort[j];
//			arrayToSort[j] = tmpTypeToSort;
//			tmpAssociatedType = associatedArray[i];
//			associatedArray[i] = associatedArray[j];
//			associatedArray[j] = tmpAssociatedType;
//			i++;
//			j--;
//		}
//	};
//	/* recursion */
//	if (left < j)
//		quickAssociatedSortUp<TypeToSort, AssociatedType>(arrayToSort, associatedArray, left, j);
//	if (i < right)
//		quickAssociatedSortUp<TypeToSort, AssociatedType>(arrayToSort, associatedArray, i, right);
//}

void quickSortNodes(sbfNode * nodes, int * ind, int left, int right){
	int i = left, j = right;
	sbfNode tmpNode;
	int tmpI;
	int pivot = ind[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (ind[i] < pivot)
			i++;
		while (ind[j] > pivot)
			j--;
		if (i <= j) {
			tmpNode = nodes[i];
			nodes[i] = nodes[j];
			nodes[j] = tmpNode;
			tmpI = ind[i];
			ind[i] = ind[j];
			ind[j] = tmpI;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSortNodes(nodes, ind, left, j);
	if (i < right)
		quickSortNodes(nodes, ind, i, right);
}
