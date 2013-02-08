#ifndef _SBFMESH_H_
#define _SBFMESH_H_

#include <cstddef>
#include <cstdlib>
#include <typeinfo>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>

#include "sbfDeclspec.h"

//	TODO - serious problem! sizeof(sbfElement) > 38 !!! because of ind is a std::vector

//	TODO - change internal int type to size_t

namespace sbf{

class sbfNode;
class sbfElement;
class sbfSELevel;
class sbfSELevelList;
class sbfGroupFilter;
class sbfGroup;
class sbfNodeGroup;
class sbfElementGroup;
class sbfMesh;
template < class ArrayType, int numComp = 3> class NodesData;
template < class ArrayType, int numArrays = 20> class SolutionBundle;

enum FileVersion {
	OLD_FORMAT = 0,
	NEW_FORMAT = 1,
	AUTO_FORMAT = 10,//try to determine file format during file reading
	NOT_DEFINED_FORMAT = -1
};
enum ElementType {
	//This enumeration type holds types of elements.
	/*1D elements*/
	BEAM_LINEAR_3DOF = 0, BEAM_QUADRATIC_3DOF = 1, BEAM_LINEAR_6DOF = 2, BEAM_QUADRATIC_6DOF = 3,
	/*2D elements*/
	RECTANGLE_LINEAR = 10, RECTANGLE_QUADRATIC = 11, TRIANGLE_LINEAR = 12, TRIANGLE_QUADRATIC = 13,
	/*3D elements*/
	HEXAHEDRON_LINEAR = 20, HEXAHEDRON_QUADRATIC = 21, TRIANGLE_PRISM_LINEAR = 22, TRIANGLE_PRISM_QUADRATIC = 23, TETRAHEDRON_LINEAR = 24, TETRAHEDRON_QUADRATIC = 25,
	/*Unknown element*/
	NO_DEFINED_ELEMENT = -1
};
enum NumberOptType {
	SIMPLE = 0,
	FIND_FIRST_NODE = 1
};

class DECLSPEC sbfMesh
//sbfMesh class stores all information abaut FE mesh
{
public:
	//Default constructor
	sbfMesh();
	//sbfMesh(const char* indName, const char* crdName, const char* mtrName);
	//Copy constructor
	sbfMesh(sbfMesh & mesh);
	//Destructor
	~sbfMesh();

private:
	int nNodes_;//Normally number of nodes can be geted by numNodes()
	int nElements_;//Normally number of nodes can be geted by numElements()
	int kort_;//Number of coordinates, stored in mesh (X, Y, Z)

	std::vector <sbfNode> nodes_;
	std::vector <sbfElement> elems_;
	std::vector < int > mtr_;
	std::vector < sbfElementGroup *> elemGroups_;
	std::vector < sbfNodeGroup *> nodeGroups_;
	std::vector < NodesData<double, 3> * > nodesDVDataList_;
	std::vector < NodesData<double, 1> * > nodesDSDataList_;
	std::vector < NodesData<float, 3> * > nodesFVDataList_;
	std::vector < NodesData<float, 1> * > nodesFSDataList_;
	std::vector < SolutionBundle<double> * > solutionBundleList_;

	//Mesh read/write
public:
	int readCrdFromFile(const char* crdName = "crd.sba");
	int readIndFromFile(const char* indName = "ind.sba", FileVersion version = AUTO_FORMAT);
	int readMtrFromFile(const char* mtrName = "mtr001.sba");
	int readMeshFromFiles(const char* indName = "ind.sba", const char* crdName = "crd.sba", const char* mtrName = "mtr001.sba", FileVersion version = AUTO_FORMAT);
	int writeCrdToFile(const char* crdName = "crd.sba");
	int writeIndToFile(const char* indName = "ind.sba", const FileVersion version = NEW_FORMAT);
	int writeMtrToFile(const char* mtrName = "mtr001.sba", const FileVersion version = NEW_FORMAT);
	int writeMeshToFiles(const char* indName = "ind.sba", const char* crdName = "crd.sba", const char* mtrName = "mtr001.sba", const FileVersion version = NEW_FORMAT);

	int writeToVTKFile(const char* baseName);

	//Access to members
public:
	sbfNode & node(const int seqNumber);//Returns reference to specific node
	sbfElement & elem(const int seqNumber);//Returns reference to specific element
	sbfElement * elemPtr(const int sequenceNumber);//Returns pointer to specific element

	//Mesh information
public:
	int numElements();
	int numNodes();
	int numGroups();
	int numNodeGroups();
	void printInfo();
	float max(const int kort);
	float min(const int kort);
	float maxX();
	float maxY();
	float maxZ();
	float minX();
	float minY();
	float minZ();
	//Returns index of node (first found) near point (x, y, z) with tolerance tol
	int nodeAt(float x, float y, float z, float tol = 0.001);

	//Mesh modifications
public:
	int addElement(const sbfElement & elem);
	//Add node (x, y, z) to mesh. If flag checkExisted = true the mesh will be scaned for existed node with tolerance tol. Returns index of new or existed node.
	void insertElement(const sbfElement & elem, int position);
	int addNode(float x, float y, float z, bool checkExisted = true, float tol = 0.001);
	//Add sbfNode node to mesh. Similar as previous.
	int addNode(sbfNode & node, bool checkExisted = true, float tol = 0.001);
	//Delete node with index nodeIndex from mesh and optionally make renumbering of elements indexes
	void deleteNode(int nodeIndex, bool renumberElemIndexes = true);
	//Merge and renumber nodes in mesh. Coinsident nodes with tolerance tol will be dropped.
	//!!!!!!!!!!!!!!!!! not working now !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int mergeNodes(float tol = 0.001);
	//Renumber nodes in mesh, newIndexes represents new indexes of existing nodes after renumbering.
	void renumberNodes(int * newIndexes);
	//Add empty group to mesh
	sbfElementGroup * addElementGroup();
	//Add group with specific filter to mesh
	sbfElementGroup * addElementGroup(sbfGroupFilter filter);
	//Add empty group to mesh
	sbfNodeGroup * addNodeGroup();
	//Add group with specific filter to mesh
	sbfNodeGroup * addNodeGroup(sbfGroupFilter filter);
	//Add mesh by reference. If passGroups = true, existed groups will be added to current mesh. If checkExisted = true new nodes will be checked for coinsidential with tolerance tol.
	void addMesh(sbfMesh & mesh, bool passGroups = true, bool checkExisted = true, float tol = 0.001);
	//Add mesh by pointer. Similar as previous.
	void addMesh(sbfMesh * mesh, bool passGroups = true, bool checkExisted = true, float tol = 0.001);
	//Reserve memory
	void reserveNodesNumber(const int newNodesNumber);
	void reserveElementsNumber(const int newElementNumber);
	void optimizeNodesNumbering(NumberOptType type = SIMPLE);//Make nodes numbering optimization

	void addDVData(NodesData<double, 3> * data) {nodesDVDataList_.push_back(data);}
	NodesData<double, 3> * dVData(const int seqNumber) {return nodesDVDataList_[seqNumber];}
	void addDSData(NodesData<double, 1> * data) {nodesDSDataList_.push_back(data);}
	NodesData<double, 1> * dSData(const int seqNumber) {return nodesDSDataList_[seqNumber];}
	void addFVData(NodesData<float, 3> * data) {nodesFVDataList_.push_back(data);}
	NodesData<float, 3> * fVData(const int seqNumber) {return nodesFVDataList_[seqNumber];}
	void addFSData(NodesData<float, 1> * data) {nodesFSDataList_.push_back(data);}
	NodesData<float, 1> * fSData(const int seqNumber) {return nodesFSDataList_[seqNumber];}
	void addSolutionBundle(SolutionBundle<double> * bundle) {solutionBundleList_.push_back(bundle);}
	SolutionBundle<double> * solutionBundle(const int seqNumber) {return solutionBundleList_[seqNumber];}

	//Geometry modifications
public:
	void scale(float scaleX, float scaleY, float scaleZ);
	void scale(float scale);
	void translate(float transX, float transY, float transZ);
	//Rotate nodes in mesh arround origin arround vector (rotX, rotY, rotZ) by angle = length of rotation vector (in radianes).
	void rotate(float rotX, float rotY, float rotZ);

	//Groups
public:
	//Returns pointer to a specific group of elements
	sbfElementGroup * group(const int sequenceNumber);
	//Process all groups - evaluetes indexes of elements in groups.
	void processGroups();
	//Process specific group
	void processGroup(const int sequenceNumber);
	//Returns pointer to a specific group of nodes
	sbfNodeGroup * nodeGroup(const int sequenceNumber);
	//Process all groups - evaluetes indexes of nodes in groups.
	void processNodeGroups();
	//Process specific group
	void processNodeGroup(const int sequenceNumber);
	//Clear list of groups. To clear information of elements in group without deleting group use sbfElementGroup::clearGroup() method.
	void clearGroups();
	void clearNodeGroups();
	void clearAllGroups();

	//Make some standard meshes
public:
	static sbfMesh * makeBlock(std::vector<float> & crdX, std::vector<float> & crdY, std::vector<float> & crdZ, ElementType type = HEXAHEDRON_LINEAR);//General nonuniform block
	static sbfMesh * makeBlock(float xSide, float ySide, float zSide, int xPart, int yPart, int zPart, ElementType type = HEXAHEDRON_LINEAR);//Uniform block
};

class DECLSPEC sbfNode
//Holds information abaut node coordinates
{
public:
	sbfNode();
	//Construct node with certain coordinates
	sbfNode(float x, float y, float z);
	//Copy constructor
	sbfNode(const sbfNode & node);
	~sbfNode();

private:
	//std::vector <float> crd_;
	float crd_[3];

public:
	//Set/get coordinates
	void setX(const float x = 0.0);
	void setY(const float y = 0.0);
	void setZ(const float z = 0.0);
	float x();
	float y();
	float z();
	float & crdAtKort(int kort);
	//Check if all coordinates of nodes are equal with tolerance
	bool isSame(sbfNode & node, const float tolerance = 0.001);
	//Check if spesific coordinate of nodes is equal with tolerance
	bool isSameX(sbfNode & node, const float tolerance = 0.001);
	bool isSameY(sbfNode & node, const float tolerance = 0.001);
	bool isSameZ(sbfNode & node, const float tolerance = 0.001);
	//Returns the distance between nodes
	float distance(sbfNode & node);
	void rotate(float rotX, float rotY, float rotZ);
};

class DECLSPEC sbfElement
{
public:
	sbfElement();
	//Construct sbfElement by number of nodes
	sbfElement(const int numNodes);
	//Construct sbfElement by type and node indexes
	sbfElement(const ElementType type, std::vector <int> indexes);
	~sbfElement();

private:
	std::vector <int> ind_;
	//int *inds_;
	int mtr_;
	ElementType type_;
	sbfMesh *mesh_;//Maybe it should be excluded from class

public:
	//Set element information
	void setNumNodes(const int nNodes = 8);
	void setNode(const int sequenceNumber, const int nodeNumber);
	void addNode(const int nodeNumber);
	void setNodes(const int nodeNumber, int first, ...);
	void setNodes(const std::vector <int> indexes);
	void setMtr(const int material = 1);
	void setType(const ElementType & type);
	//Set/get pointer to mesh, associated with this element
	void setMesh(sbfMesh * mesh);
	sbfMesh * mesh();

	//Get element information
	int numNodes();
	int nodeIndex(const int sequenceNumber);
	//Returns a vector (copy) of nodes indexes
	std::vector<int> indexes();
	int mtr();
	ElementType type();
	//Returns nodes indexes on all element faces
	std::vector< std::vector<int> > facesNodesIndexes();
	//Returns average coordinate of all nodes
	sbfNode centreOfMass();
	//Get information about max/min coordinates of element nodes
	float max(const int kort);
	float min(const int kort);
	float maxX();
	float maxY();
	float maxZ();
	float minX();
	float minY();
	float minZ();
	float volume();//Returns element volume if exist

};

class DECLSPEC sbfSELevel
//Holds information about indexes of elements in super element
{
public:
	sbfSELevel();
	~sbfSELevel();
private:
	std::vector <int> ind_;//Indexes of elements in SE layer
	int level_;//Layer index
	sbfSELevel *prevLayer_, *nextLayer_;
	sbfMesh *mesh_;
public:
	void setSize(int size);//Sets size of indexes vector should be same as number of elements at previous level
	int size();//Returns indexes vector size
	void setLevelIndex(int index);//Sets index of this level
	int levelIndex();
	void setIndex(int seqNumber, int index);//Sets index of SE in this level
	int index(int seqNumber);
	int numSE();//Returns number of SE at this level
	std::vector<int> indexesOfSE(int seqNumber);//Returns vector of element indexes which belonges to SE seqNumber in this level
	void setMesh(sbfMesh * mesh);//Sets base mesh
	sbfSELevel * prev();//Returns pointer to previous SE layer
	sbfSELevel * next();//Returns pointer to next SE layer
	void writeToFile(const char * baseName = "level", int levelIndex = -1, int numDigits = 3);
	int readFromFile(const char * baseName = "level", int levelIndex = -1, int numDigits = 3);
};

class DECLSPEC sbfSELevelList
//Holds information about super element layers
{
public:
	sbfSELevelList();
	~sbfSELevelList();
private:
	std::list<sbfSELevel> list_;
	sbfMesh * mesh_;
public:
	int numLevels();//Returns number of SE layers
	sbfSELevel & level(int seqNumber);
	void writeToFiles(const char * baseName = "level", int numDigits = 3);
	int readFromFiles(const char * baseName = "level", int numDigits = 3);
	void setMesh(sbfMesh * mesh);//Sets base mesh
};

class DECLSPEC sbfGroup
//Base class for grouping
{
public:
	sbfGroup();
	virtual ~sbfGroup();
private:
	std::vector <sbfGroupFilter> filters_;
public:
	void addFilter(const sbfGroupFilter & filter);
	void clearFilters();
	int numFilters();
	sbfGroupFilter & filter(int count);
};

class DECLSPEC sbfElementGroup : public sbfGroup
//Holds information abaut elements group
{
public:
	sbfElementGroup();
	virtual ~sbfElementGroup();

private:
	std::vector <int> list_;
	sbfMesh *mesh_;

public:
	void clearGroup();
	void reserve(int newSize);
	void addElement(const int elementInd, bool checkDuplicate = true);
	int element(const int sequenceNumber);
	int numElems();
	ElementType type();
	void setMesh(sbfMesh * mesh);
	void setMtr(const int mtr);
	std::vector <int> elemIndList();
	std::vector <int> nodeIndList();
};

class DECLSPEC sbfNodeGroup : public sbfGroup
//Holds information abaut nodes group
{
public:
	sbfNodeGroup();
	virtual ~sbfNodeGroup();

private:
	std::vector <int> list_;
	sbfMesh *mesh_;

public:
	void clearGroup();
	void addNode(const int nodeInd);
	int node(const int sequenceNumber);
	int numNodes();
	void setMesh(sbfMesh * mesh);
	std::vector <int> nodeIndList();
};

class DECLSPEC sbfGroupFilter
//Holds information abaut filter used for grouping
{
public:
	sbfGroupFilter();
	~sbfGroupFilter();
private:
	bool mtrF_;
	bool xMaxF_, xMinF_, yMaxF_, yMinF_, zMaxF_, zMinF_;
	float xMax_, xMin_, yMax_, yMin_, zMax_, zMin_;
	bool typeF_;
	int mtr_;
	ElementType type_;
	sbfMesh *mesh_;
public:
	void setMtrF(int mtr);
	void unsetMtrF();
	void setTypeF(ElementType type);
	void unsetTypeF();
	void setCrdF(float xMin = -std::numeric_limits<float>::max(), float xMax = std::numeric_limits<float>::max(), float yMin = -std::numeric_limits<float>::max(), float yMax = std::numeric_limits<float>::max(), float zMin = -std::numeric_limits<float>::max(), float zMax = std::numeric_limits<float>::max());
	void setCrdXF(float xMin = -std::numeric_limits<float>::max(), float xMax = std::numeric_limits<float>::max());
	void setCrdYF(float yMin = -std::numeric_limits<float>::max(), float yMax = std::numeric_limits<float>::max());
	void setCrdZF(float zMin = -std::numeric_limits<float>::max(), float zMax = std::numeric_limits<float>::max());
	void unsetCrdF();
	void setMesh(sbfMesh *mesh);
	bool isPass(sbfElement & elem);
	bool isPass(sbfNode & node);
};

DECLSPEC bool crdcmp(float crd1, float crd2, float eps = 1.0e-3);
DECLSPEC int numNodesInElement(ElementType type);
//Convert library element type to element type of sbf ind file format
DECLSPEC int typesLibToFile(const ElementType & type);
//Convert sbf ind file element type to library type
DECLSPEC ElementType typesFileToLib(const int type);
DECLSPEC ElementType tryToResolveTypeByNumNodes(int numNodes, int kort = 3);

template <class TypeToSort, class AssociatedType> void quickAssociatedSortUp(TypeToSort * arrayToSort, AssociatedType * associatedArray, int left, int right){
	int i = left, j = right;
	TypeToSort tmpTypeToSort;
	AssociatedType tmpAssociatedType;
	TypeToSort pivot = arrayToSort[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arrayToSort[i] < pivot)
			i++;
		while (arrayToSort[j] > pivot)
			j--;
		if (i <= j) {
			tmpTypeToSort = arrayToSort[i];
			arrayToSort[i] = arrayToSort[j];
			arrayToSort[j] = tmpTypeToSort;
			tmpAssociatedType = associatedArray[i];
			associatedArray[i] = associatedArray[j];
			associatedArray[j] = tmpAssociatedType;
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickAssociatedSortUp<TypeToSort, AssociatedType>(arrayToSort, associatedArray, left, j);
	if (i < right)
		quickAssociatedSortUp<TypeToSort, AssociatedType>(arrayToSort, associatedArray, i, right);
}

template < class ArrayType, int numComp> class NodesData
//template holder for nodes data
{
public:
	NodesData(std::string name, sbfMesh* mesh);
	NodesData(std::string name, int numNodes);
	NodesData(sbfMesh* mesh);
	NodesData(int numNodes);
	~NodesData();
	enum Type{ // Note that file writing is always store data by kort, while during solution data usually stored by nodes.
		ByNodes,	// Store information in sequence by nodes i.e. XYZXYZ...XYZ
		ByKort		// Store information in sequence by kort i.e. XX...XXYY...YYZZ...ZZ
	};
private:
	ArrayType *data_;
	int numNodes_;
	std::string name_;
	sbfMesh *mesh_;
	std::string extension_;
	int numDigits_;
	int stepToProceed_;
	Type type_;
	void init();
	void free();
public:
	ArrayType * data(); // Return pointer to data
	ArrayType & data(int nodeIndex, int compIndex); // Return  reference to value of specific component in specific node
	void null(){if( data_ != NULL) for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = 0.0; }
	void copyData(ArrayType * data) { if( !data_ ) init(); for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = data[ct];}
	void copyData(/*const */NodesData<ArrayType, numComp> & nodesData) { if(!data_) init(); ArrayType * srcData = nodesData.data(); if(srcData) for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = srcData[ct]; }
	//void setNumNodes(int numNodes);
	int numNodes();
	int numComponents();
	std::string & name();
	void setStep(int step) {stepToProceed_ = step;}
	int step() {return stepToProceed_;}
	void setName(const char * name) {name_ = name;}
	void setNumDigits(int numDigits) {numDigits_ = numDigits;}
	Type type() {return type_;}
	void setType(Type type) {type_ = type;}
	template <class StorageType> int writeToFile(const char *name, int step, const char * extension = ".sba", int numDigits = 4);
	template <class StorageType> int readFromFile(const char * name, int step, const char * extension = ".sba", int numDigits = 4);
	template <class StorageType> int writeToFile();//Short forms
	template <class StorageType> int readFromFile();
	bool exist();//Check if file with current step exists

	//Useful mathematics functions
	NodesData<ArrayType, numComp> operator+(/*const */NodesData<ArrayType, numComp> & right)
	{NodesData<ArrayType, numComp> result(this->numNodes()); ArrayType *srcDataLeft = this->data(), *srcDataRight = right.data(), *trgData = result.data(); if(srcDataLeft && srcDataRight) for(int ct = 0; ct < numNodes_*numComp; ct++) trgData[ct] = srcDataLeft[ct] + srcDataRight[ct]; return result;}
	NodesData<ArrayType, numComp> operator-(/*const */NodesData<ArrayType, numComp> & right)
	{NodesData<ArrayType, numComp> result(this->numNodes()); ArrayType *srcDataLeft = this->data(), *srcDataRight = right.data(), *trgData = result.data(); if(srcDataLeft && srcDataRight) for(int ct = 0; ct < numNodes_*numComp; ct++) trgData[ct] = srcDataLeft[ct] - srcDataRight[ct]; return result;}
	NodesData<ArrayType, numComp> operator*(const ArrayType & mult)
	{NodesData<ArrayType, numComp> result(this->numNodes()); ArrayType *srcDataLeft = this->data(), *trgData = result.data(); if(srcDataLeft) for(int ct = 0; ct < numNodes_*numComp; ct++) trgData[ct] = srcDataLeft[ct]*mult; return result;}
	ArrayType scalMul(/*const */NodesData<ArrayType, numComp> & nodesData)
	{ ArrayType sum = std::numeric_limits<ArrayType>::quiet_NaN(); ArrayType * srcData = nodesData.data(), * thisData = this->data(); if(srcData && thisData) {sum = 0; for(int ct = 0; ct < numNodes_*numComp; ct++) sum += thisData[ct]*srcData[ct];} return sum; }
};

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(std::string name, sbfMesh* mesh) : data_(NULL), numNodes_(0) , name_(name), mesh_(mesh), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { numNodes_ = mesh ? mesh->numNodes() : 0; init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(std::string name, int numNodes) : data_(NULL), numNodes_(numNodes) , name_(name), mesh_(NULL), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(sbfMesh* mesh) : data_(NULL), numNodes_(0) , name_("data"), mesh_(mesh), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { numNodes_ = mesh ? mesh->numNodes() : 0; init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(int numNodes) : data_(NULL), numNodes_(numNodes) , name_("data"), mesh_(NULL), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::~NodesData() { free(); }

template < class ArrayType, int numComp>
void NodesData<ArrayType, numComp>::init() { free(); data_ = new ArrayType [numComp*numNodes_]; }

template < class ArrayType, int numComp>
void NodesData<ArrayType, numComp>::free() { if(data_ != NULL) delete [] data_; }

template < class ArrayType, int numComp>
ArrayType * NodesData<ArrayType, numComp>::data() { return data_; }

template < class ArrayType, int numComp>
ArrayType & NodesData<ArrayType, numComp>::data(int nodeIndex, int compIndex) { if(type_ == ByNodes) return data_[nodeIndex*numComp+compIndex]; else /*if(type_ == ByKort)*/ return data_[compIndex*numNodes_+nodeIndex]; }

template < class ArrayType, int numComp>
int NodesData<ArrayType, numComp>::numNodes() { return numNodes_; }

template < class ArrayType, int numComp>
int NodesData<ArrayType, numComp>::numComponents() { return numComp; }

template < class ArrayType, int numComp>
std::string & NodesData<ArrayType, numComp>::name() { return name_; }

template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::writeToFile(const char * name, int step, const char * extension, int numDigits)
{
	name_ = name; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
	std::stringstream sstr;
	sstr << name << std::setw(numDigits) << std::setfill('0') << step << extension;
	std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
	if(!out.good()) {std::cout << "Error while writing file \"" << sstr.str().c_str() << "\"" << sstr.str() << std::endl; return 1;}
	//TODO implement compile time ArrayType comparison
	if(typeid(StorageType) == typeid(ArrayType)){
		if(type_ == ByNodes){
			ArrayType * storageData = new ArrayType [numNodes_*numComp];
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) storageData[ct*numNodes_+ct1] = data_[ct1*numComp+ct];
			out.write((const char *)storageData, sizeof(ArrayType)*numNodes_*numComp);
			delete [] storageData;
		}
		else if(type_ == ByKort)
			out.write((const char *)data_, sizeof(ArrayType)*numNodes_*numComp);
	}
	else{
		StorageType * storageData = new StorageType [numNodes_*numComp];
		if(type_ == ByNodes)
			for(int ct = 0; ct < numNodes_*numComp; ct++) storageData[ct] = static_cast<StorageType>(data_[ct]);
		else if(type_ == ByKort)
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) storageData[ct*numNodes_+ct1] = static_cast<StorageType>(data_[ct1*numComp+ct]);
		out.write((const char *)storageData, sizeof(StorageType)*numNodes_*numComp);
		delete [] storageData;
	}
	out.close();
	stepToProceed_++;
	return 0;
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::readFromFile(const char * name, int step, const char * extension, int numDigits)
{
	name_ = name; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
	std::stringstream sstr;
	sstr << name << std::setw(numDigits) << std::setfill('0') << step << extension;
	std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
	if(!in.good()) {std::cout << "Error while reading file \"" << sstr.str().c_str() << "\"" << sstr.str() << std::endl; return 1;}
	in.seekg(0, std::ios_base::end);
	size_t length = in.tellg();
	if(length != sizeof(StorageType)*numNodes_*numComp) {std::cout << "Error! Data in file \"" << sstr.str().c_str() << "\" not corresponds to data type and nodes number" << sstr.str() << std::endl; return 2;}
	in.seekg(0, std::ios_base::beg);
	//TODO implement compile time comparison
	if(typeid(StorageType) == typeid(ArrayType)){
		if(type_ == ByNodes){
			ArrayType * storageData = new ArrayType [numNodes_*numComp];
			in.read((char *)storageData, sizeof(ArrayType)*numNodes_*numComp);
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) data_[ct1*numComp+ct] = storageData[ct*numNodes_+ct1];
			delete [] storageData;
		}
		else if(type_ == ByKort)
			in.read((char *)data_, sizeof(ArrayType)*numNodes_*numComp);
	}
	else{
		StorageType * storageData = new StorageType [numNodes_*numComp];
		in.read((char *)storageData, sizeof(StorageType)*numNodes_*numComp);
		if(type_ == ByNodes)
			for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = static_cast<ArrayType>(storageData[ct]);
		else if(type_ == ByKort)
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) data_[ct1*numComp+ct] = static_cast<ArrayType>(storageData[ct*numNodes_+ct1]);
		delete [] storageData;
	}
	in.close();
	stepToProceed_++;
	return 0;
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::writeToFile()
{
	std::stringstream sstr;
	sstr << name_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
	std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
	if(!out.good()) {std::cout << "Error while writing file \"" << sstr.str().c_str() << "\" " << sstr.str() << std::endl; return 1;}
	//TODO implement compile time comparison
	if(typeid(StorageType) == typeid(ArrayType)){
		if(type_ == ByNodes){
			ArrayType * storageData = new ArrayType [numNodes_*numComp];
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) storageData[ct*numNodes_+ct1] = data_[ct1*numComp+ct];
			out.write((const char *)storageData, sizeof(ArrayType)*numNodes_*numComp);
			delete [] storageData;
		}
		else if(type_ == ByKort)
			out.write((const char *)data_, sizeof(ArrayType)*numNodes_*numComp);
	}
	else{
		StorageType * storageData = new StorageType [numNodes_*numComp];
		if(type_ == ByNodes)
			for(int ct = 0; ct < numNodes_*numComp; ct++) storageData[ct] = static_cast<StorageType>(data_[ct]);
		else if(type_ == ByKort)
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) storageData[ct*numNodes_+ct1] = static_cast<StorageType>(data_[ct1*numComp+ct]);
		out.write((const char *)storageData, sizeof(StorageType)*numNodes_*numComp);
		delete [] storageData;
	}
	out.close();
	stepToProceed_++;
	return 0;
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::readFromFile()
{
	std::stringstream sstr;
	sstr << name_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
	std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
	if(!in.good()) {std::cout << "Error while reading file \"" << sstr.str().c_str() << "\"" << sstr.str() << std::endl; return 1;}
	in.seekg(0, std::ios_base::end);
	size_t length = in.tellg();
	if(length != sizeof(ArrayType)*numNodes_*numComp) {std::cout << "Error! Data in file \"" << sstr.str().c_str() << "\" not corresponds to data type and nodes number" << sstr.str() << std::endl; return 2;}
	in.seekg(0, std::ios_base::beg);
	//TODO implement compile time comparison
	if(typeid(StorageType) == typeid(ArrayType)){
		if(type_ == ByNodes){
			ArrayType * storageData = new ArrayType [numNodes_*numComp];
			in.read((char *)storageData, sizeof(ArrayType)*numNodes_*numComp);
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) data_[ct1*numComp+ct] = storageData[ct*numNodes_+ct1];
			delete [] storageData;
		}
		else if(type_ == ByKort)
			in.read((char *)data_, sizeof(ArrayType)*numNodes_*numComp);
	}
	else{
		StorageType * storageData = new StorageType [numNodes_*numComp];
		in.read((char *)storageData, sizeof(StorageType)*numNodes_*numComp);
		if(type_ == ByNodes)
			for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = static_cast<ArrayType>(storageData[ct]);
		else if(type_ == ByKort)
			for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) data_[ct1*numComp+ct] = static_cast<ArrayType>(storageData[ct*numNodes_+ct1]);
		delete [] storageData;
	}
	in.close();
	stepToProceed_++;
	return 0;
}
template < class ArrayType, int numComp>
bool NodesData<ArrayType, numComp>::exist()
{
	bool exist = false;
	std::stringstream sstr;
	sstr << name_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
	std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
	if(in.good()) exist = true;
	in.close();
	return exist;
}

template <class ArrayType, int numArrays> class SolutionBundle
{
public:
	SolutionBundle(std::string baseName, int numNodes);
	~SolutionBundle();
private:
	NodesData<ArrayType, 1> * arrays_[numArrays];
	std::string names_[numArrays];
	std::string baseName_;
	std::string extension_;
	int numDigits_;
	int stepToProceed_;
	int numNodes_;
	void init();

public:
	NodesData<ArrayType, 1> * array(int index);
	std::string & name(int index);
	std::string & baseName();
	void setStep(int step);
	int step();
	void setNumDigits(int numDigits);
	void free();
	void free(int index);
	void allocate();
	void allocate(int index);
	template <class StorageType> int writeToFile(const char * baseName, int step, const char * extension = ".sba", int numDigits = 4);
	template <class StorageType> int readFromFile(const char * baseName, int step, const char * extension = ".sba", int numDigits = 4);
	template <class StorageType> int writeToFile();//Short forms
	template <class StorageType> int readFromFile();
	int writeNames();
	int readNames();
	bool exist();//Check if file with current step exists
};
template <class ArrayType, int numArrays>
SolutionBundle<ArrayType, numArrays>::SolutionBundle(std::string baseName, int numNodes) : baseName_(baseName), extension_(".sba"), numDigits_(4), stepToProceed_(1), numNodes_(numNodes) { init(); }
template <class ArrayType, int numArrays>
SolutionBundle<ArrayType, numArrays>::~SolutionBundle() { free(); }

template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::init()
{
	names_[0]="Temperature";names_[1]="SigmaXX";names_[2]="SigmaYY";names_[3]="SigmaZZ";names_[4]="SigmaXY";names_[5]="SigmaYZ";names_[6]="SigmaXZ";names_[7]="SigmaI";names_[8]="EXX";names_[9]="EYY";
    names_[10]="EZZ";names_[11]="EXY";names_[12]="EYZ";names_[13]="EXZ";names_[14]="EI";names_[15]="EIPL";names_[16]="16";names_[17]="17";names_[18]="18";names_[19]="19";
	for(int ct = 0; ct < numArrays; ct++) arrays_[ct] = NULL;
}
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::free() { for(int ct = 0; ct < numArrays; ct++) if(arrays_[ct]) {delete arrays_[ct]; arrays_[ct] = NULL;} }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::free(int index) { if(arrays_[index]) {delete arrays_[index]; arrays_[index] = NULL;} }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::allocate() { free(); for(int ct = 0; ct < numArrays; ct++)  arrays_[ct] = new NodesData<ArrayType, 1>(numNodes_); }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::allocate(int index) { free(index); arrays_[index] = new NodesData<ArrayType, 1>(numNodes_); }

template <class ArrayType, int numArrays>
NodesData<ArrayType, 1> * SolutionBundle<ArrayType, numArrays>::array(int index) { return arrays_[index]; }
template <class ArrayType, int numArrays>
std::string & SolutionBundle<ArrayType, numArrays>::name(int index) { return names_[index]; }
template <class ArrayType, int numArrays>
std::string & SolutionBundle<ArrayType, numArrays>::baseName() { return baseName_; }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::setStep(int step) { stepToProceed_ = step; }
template <class ArrayType, int numArrays>
int SolutionBundle<ArrayType, numArrays>::step() { return stepToProceed_; }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::setNumDigits(int numDigits) { numDigits_ = numDigits; }

template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::writeToFile(const char * baseName, int step, const char * extension, int numDigits)
{
	baseName_ = baseName; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
	std::stringstream sstr;
	sstr << baseName << std::setw(numDigits) << std::setfill('0') << step << extension;
	std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
	if(!out.good()) {std::cout << "Error while opening file to write " << sstr.str() << std::endl; return 1;}
	int flags[numArrays];
	for(int ct = 0; ct < numArrays; ct++) flags[ct] = arrays_[ct] ? 1 : 0;
	out.write((const char *)flags, sizeof(int)*numArrays);
	for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
		//TODO implement compile time comparison
		if(typeid(StorageType) == typeid(ArrayType))
			out.write((const char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
		else{
			StorageType * storageData = new StorageType [numNodes_];
			for(int ct = 0; ct < numNodes_; ct++) storageData[ct] = static_cast<StorageType>(arrays_[ct]->data()[ct]);
			out.write((const char *)storageData, sizeof(StorageType)*numNodes_);
			delete [] storageData;
		}
	}
	out.close();
	stepToProceed_++;
	return 0;
}
template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::readFromFile(const char * baseName, int step, const char * extension, int numDigits)
{
	free();
	baseName_ = baseName; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
	std::stringstream sstr;
	sstr << baseName << std::setw(numDigits) << std::setfill('0') << step << extension;
	std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
	if(!in.good()) {std::cout << "Error while reading file " << sstr.str() << std::endl; return 1;}
	int flags[numArrays];
	in.read((char *)flags, sizeof(int)*numArrays);
	for(int ct = 0; ct < numArrays; ct++) if(flags[ct]) allocate(ct);
	for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
		//TODO implement compile time comparison
		if(typeid(StorageType) == typeid(ArrayType))
			in.read((char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
		else{
			StorageType * storageData = new StorageType [numNodes_];
			in.read((char *)storageData, sizeof(StorageType)*numNodes_);
			for(int ct = 0; ct < numNodes_; ct++) arrays_[ct]->data()[ct] = static_cast<ArrayType>(storageData[ct]);
			delete [] storageData;
		}
	}
	in.close();
	stepToProceed_++;
	return 0;
}
template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::writeToFile()
{
	std::stringstream sstr;
	sstr << baseName_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
	std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
	if(!out.good()) {std::cout << "Error while writing file " << sstr.str() << std::endl; return 1;}
	int flags[numArrays];
	for(int ct = 0; ct < numArrays; ct++) flags[ct] = arrays_[ct] ? 1 : 0;
	out.write((const char *)flags, sizeof(int)*numArrays);
	for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
		//TODO implement compile time comparison
		if(typeid(StorageType) == typeid(ArrayType))
			out.write((const char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
		else{
			StorageType * storageData = new StorageType [numNodes_];
			for(int ct = 0; ct < numNodes_; ct++) storageData[ct] = static_cast<StorageType>(arrays_[ct]->data()[ct]);
			out.write((const char *)storageData, sizeof(StorageType)*numNodes_);
			delete [] storageData;
		}
	}
	out.close();
	stepToProceed_++;
	return 0;
}
template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::readFromFile()
{
	free();
	std::stringstream sstr;
	sstr << baseName_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
	std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
	if(!in.good()) {std::cout << "Error while reading file " << sstr.str() << std::endl; return 1;}
	int flags[numArrays];
	in.read((char *)flags, sizeof(int)*numArrays);
	for(int ct = 0; ct < numArrays; ct++) if(flags[ct]) allocate(ct);
	for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
		//TODO implement compile time comparison
		if(typeid(StorageType) == typeid(ArrayType))
			in.read((char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
		else{
			StorageType * storageData = new StorageType [numNodes_];
			in.read((char *)storageData, sizeof(StorageType)*numNodes_);
			for(int ct = 0; ct < numNodes_; ct++) arrays_[ct]->data()[ct] = static_cast<ArrayType>(storageData[ct]);
			delete [] storageData;
		}
	}
	in.close();
	stepToProceed_++;
	return 0;
}
template <class ArrayType, int numArrays>
bool SolutionBundle<ArrayType, numArrays>::exist()
{
	bool exist = false;
	std::stringstream sstr;
	sstr << baseName_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
	std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
	if(in.good()) exist = true;
	in.close();
	return exist;
}
template <class ArrayType, int numArrays>
int SolutionBundle<ArrayType, numArrays>::readNames()
{
	std::stringstream sstr;
	sstr << baseName_ << "_Names" << extension_;
	std::ifstream in(sstr.str().c_str());
	if(!in.good()){return 1;}
	for(int ct = 0; ct < numArrays; ct++){
		if(in.eof()){return 2;}
		in >> names_[ct];
	}
	in.close();
	return 0;
}
template <class ArrayType, int numArrays>
int SolutionBundle<ArrayType, numArrays>::writeNames()
{
	std::stringstream sstr;
	sstr << baseName_ << "_Names" << extension_;
	std::ofstream out(sstr.str().c_str());
	if(!out.good()){return 1;}
	for(int ct = 0; ct < numArrays; ct++)
		out << names_[ct];
	out.close();
	return 0;
}

}//end namespace sbf

#endif// _SBFMESH_H_
