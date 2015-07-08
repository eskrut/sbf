#ifndef SBFMESH_H
#define SBFMESH_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <iomanip>
#include <limits>
#include <functional>

#include "sbfReporter.h"

class sbfNode;
class sbfElement;
class sbfElementGroup;
class sbfNodeGroup;
class sbfGroupFilter;

using DefaultWorkDataType = double;
using DefaultStorageDataType = float;
template < class ArrayType = DefaultWorkDataType, int numComp = 3> class NodesData;
template < class ArrayType = DefaultWorkDataType, int numArrays = 20> class SolutionBundle;

#include "sbfEnums.h"
#include "sbfDeclspec.h"

class DECLSPEC sbfMesh
//sbfMesh class stores all information abaut FE mesh
{
public:
    //Default constructor
    sbfMesh();
    //sbfMesh(const char* indName, const char* crdName, const char* mtrName);
    //Copy constructor
    sbfMesh(const sbfMesh &mesh);
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
    std::vector < SolutionBundle<double> * > solutionBundleDList_;
    std::vector < SolutionBundle<float> * > solutionBundleFList_;

    //Mesh read/write
public:
    int readCrdFromFile(const char* crdName = "crd.sba");
    int readIndFromFile(const char* indName = "ind.sba", FileVersion version = FileVersion::AUTO_FORMAT);
    int readMtrFromFile(const char* mtrName = "mtr001.sba");
    int readMeshFromFiles(const char* indName = "ind.sba", const char* crdName = "crd.sba", const char* mtrName = "mtr001.sba", FileVersion version = FileVersion::AUTO_FORMAT);
    int writeCrdToFile(const char* crdName = "crd.sba");
    int writeIndToFile(const char* indName = "ind.sba", const FileVersion version = FileVersion::NEW_FORMAT);
    int writeMtrToFile(const char* mtrName = "mtr001.sba", const FileVersion version = FileVersion::NEW_FORMAT) const;
    int writeMeshToFiles(const char* indName = "ind.sba", const char* crdName = "crd.sba", const char* mtrName = "mtr001.sba", const FileVersion version = FileVersion::NEW_FORMAT);

    int writeToVTKFile(const char* baseName);

    //Access to members
public:
    sbfNode & node(const int seqNumber);//Returns reference to specific node
    const sbfNode &node(const int seqNumber) const;
    //! Returns reference to specific element
    sbfElement &elem(const int seqNumber);
    const sbfElement &elem(const int seqNumber) const;
    //Returns pointer to specific element
    sbfElement * elemPtr(const int sequenceNumber);
    const sbfElement * elemPtr(const int sequenceNumber) const;

    //Mesh information
public:
    int numElements() const;
    int numNodes() const;
    int numGroups() const;
    int numNodeGroups() const;
    void printInfo() const;
    float max(const int kort) const;
    float min(const int kort) const;
    float maxX() const;
    float maxY() const;
    float maxZ() const;
    float minX() const;
    float minY() const;
    float minZ() const;
    //Returns index of node (first found) near point (x, y, z) with tolerance tol
    int nodeAt(float x, float y, float z, float tol = 0.001) const;

    //Mesh modifications
public:
    int addElement(const sbfElement & elem);
    void insertElement(const sbfElement & elem, int position);
    void deleteElement(int elemID);
    //Add node (x, y, z) to mesh. If flag checkExisted = true the mesh will be scaned for existed node with tolerance tol. Returns index of new or existed node.
    int addNode(float x, float y, float z, bool checkExisted = true, float tol = 0.001);
    //Add sbfNode node to mesh. Similar as previous.
    int addNode(const sbfNode &node, bool checkExisted = true, float tol = 0.001);
    //Delete node with index nodeIndex from mesh and optionally make renumbering of elements indexes
    void deleteNode(int nodeIndex, bool renumberElemIndexes = true);
    //Merge and renumber nodes in mesh. Coinsident nodes with tolerance tol will be dropped.
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
    void addMesh(const sbfMesh *mesh, bool passGroups = true, bool checkExisted = true, float tol = 0.001);
    //! Set material for all elements
    void setMtr(int mtr);
    //! Increase material number for all elements
    void increaseMtr(int shift);
    //Reserve memory
    void reserveNodesNumber(const int newNodesNumber);
    void reserveElementsNumber(const int newElementNumber);
    void optimizeNodesNumbering(RenumberOptimizationType type = RenumberOptimizationType::SIMPLE, bool makeReport = true);//Make nodes numbering optimization

    void applyToAllNodes(std::function<void (sbfNode &)> lambda);
    void applyToAllElements(std::function<void (sbfElement &)> lambda);
    void applyToAllElements(std::function<void (const sbfElement &)> lambda) const;

    int numDVData() const { return static_cast<int>(nodesDVDataList_.size()); }
    void addDVData(NodesData<double, 3> * data) {nodesDVDataList_.push_back(data);}
    NodesData<double, 3> * dVData(const int seqNumber) {return nodesDVDataList_[seqNumber];}
    int numDSData() const { return static_cast<int>(nodesDSDataList_.size()); }
    void addDSData(NodesData<double, 1> * data) {nodesDSDataList_.push_back(data);}
    NodesData<double, 1> * dSData(const int seqNumber) {return nodesDSDataList_[seqNumber];}
    int numFVData() const { return static_cast<int>(nodesFVDataList_.size()); }
    void addFVData(NodesData<float, 3> * data) {nodesFVDataList_.push_back(data);}
    NodesData<float, 3> * fVData(const int seqNumber) {return nodesFVDataList_[seqNumber];}
    int numFSData() const { return static_cast<int>(nodesFSDataList_.size()); }
    void addFSData(NodesData<float, 1> * data) {nodesFSDataList_.push_back(data);}
    NodesData<float, 1> * fSData(const int seqNumber) {return nodesFSDataList_[seqNumber];}
    int numSolDData() const { return static_cast<int>(solutionBundleDList_.size()); }
    void addSolutionBundle(SolutionBundle<double> * bundle) {solutionBundleDList_.push_back(bundle);}
    SolutionBundle<double> * solutionBundleD(const int seqNumber) {return solutionBundleDList_[seqNumber];}
    int numSolFData() const { return static_cast<int>(solutionBundleFList_.size()); }
    void addSolutionBundle(SolutionBundle<float> * bundle) {solutionBundleFList_.push_back(bundle);}
    SolutionBundle<float> * solutionBundleF(const int seqNumber) {return solutionBundleFList_[seqNumber];}

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
    sbfElementGroup * group(const int sequenceNumber) const;
    //Process all groups - evaluetes indexes of elements in groups.
    void processGroups();
    //Process specific group
    void processGroup(const int sequenceNumber);
    //Returns pointer to a specific group of nodes
    sbfNodeGroup * nodeGroup(const int sequenceNumber) const;
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
    static sbfMesh * makeBlock(std::vector<float> & crdX, std::vector<float> & crdY, std::vector<float> & crdZ, ElementType type = ElementType::HEXAHEDRON_LINEAR);//General nonuniform block
    static sbfMesh * makeBlock(float xSide, float ySide, float zSide, int xPart, int yPart, int zPart, ElementType type = ElementType::HEXAHEDRON_LINEAR);//Uniform block
    static sbfMesh * makeCylinderPart(float rInner, float rOuter, float phiStart, float phiStop, float zStart, float zStop, int rPart, int phiPart, int zPart, ElementType type = ElementType::HEXAHEDRON_LINEAR);//Uniform part of cylinder
    static sbfMesh * makeCylinderPart(std::vector<float> &radiuses, std::vector<float> &angles, std::vector<float> &zCrds, ElementType type = ElementType::HEXAHEDRON_LINEAR);//Nonniform part of cylinder
};

template < class ArrayType, int numComp> class NodesData
//template holder for nodes data
{
public:
    NodesData(std::string name, const sbfMesh* mesh);
    NodesData(std::string name, int numNodes);
    NodesData(const sbfMesh *mesh);
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
    const sbfMesh *mesh_;
    std::string extension_;
    int numDigits_;
    int stepToProceed_;
    Type type_;
    void init();
    void free();
public:
    ArrayType * data(); // Return pointer to data
    ArrayType *data() const;
    ArrayType & data(int nodeIndex, int compIndex); // Return  reference to value of specific component in specific node
    //! Return data assuming type_ == ByNodes
    ArrayType operator()(int nodeIndex, int compIndex) const;
    ArrayType &operator()(int nodeIndex, int compIndex);
    void null(){if( data_ != nullptr) for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = 0.0; }
    void copyData(ArrayType * data) { if( !data_ ) init(); for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = data[ct];}
    void copyData(const NodesData<ArrayType, numComp> & nodesData) { if(!data_) init(); ArrayType * srcData = nodesData.data(); if(srcData) for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = srcData[ct]; }
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
    template <class StorageType = DefaultStorageDataType> int writeToFile(const char *name, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int readFromFile(const char * name, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int writeToFile();//Short forms
    template <class StorageType = DefaultStorageDataType> int readFromFile();
    template <class StorageType = DefaultStorageDataType, int numInOneFile> int writeToFileSplited();
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
NodesData<ArrayType, numComp>::NodesData(std::string name, const sbfMesh *mesh) : data_(nullptr), numNodes_(0) , name_(name), mesh_(mesh), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { numNodes_ = mesh ? mesh->numNodes() : 0; init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(std::string name, int numNodes) : data_(nullptr), numNodes_(numNodes) , name_(name), mesh_(nullptr), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(const sbfMesh* mesh) : data_(nullptr), numNodes_(0) , name_("data"), mesh_(mesh), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { numNodes_ = mesh ? mesh->numNodes() : 0; init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(int numNodes) : data_(nullptr), numNodes_(numNodes) , name_("data"), mesh_(nullptr), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::~NodesData() { free(); }

template < class ArrayType, int numComp>
void NodesData<ArrayType, numComp>::init() { free(); data_ = new ArrayType [numComp*numNodes_]; }

template < class ArrayType, int numComp>
void NodesData<ArrayType, numComp>::free() { if(data_ != nullptr) delete [] data_; }

template < class ArrayType, int numComp>
ArrayType * NodesData<ArrayType, numComp>::data() { return data_; }

template < class ArrayType, int numComp>
ArrayType * NodesData<ArrayType, numComp>::data() const { return data_; }

template < class ArrayType, int numComp>
ArrayType & NodesData<ArrayType, numComp>::data(int nodeIndex, int compIndex) { if(type_ == ByNodes) return data_[nodeIndex*numComp+compIndex]; else /*if(type_ == ByKort)*/ return data_[compIndex*numNodes_+nodeIndex]; }

template < class ArrayType, int numComp>
ArrayType NodesData<ArrayType, numComp>::operator()(int nodeIndex, int compIndex) const { return *(data_ + numComp*nodeIndex + compIndex); }

template < class ArrayType, int numComp>
ArrayType &NodesData<ArrayType, numComp>::operator()(int nodeIndex, int compIndex) { return *(data_ + numComp*nodeIndex + compIndex); }

template < class ArrayType, int numComp>
int NodesData<ArrayType, numComp>::numNodes() { return numNodes_; }

template < class ArrayType, int numComp>
int NodesData<ArrayType, numComp>::numComponents() { return numComp; }

template < class ArrayType, int numComp>
std::string & NodesData<ArrayType, numComp>::name() { return name_; }

template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::writeToFile(const char * name, int step, const char * extension, int numDigits, const char *catalog)
{
    name_ = name; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << name << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
    if(!out.good()) {
        report.error("Error while writing file \"", sstr.str(), "\"");
        return 1;
    }
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
            for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) storageData[ct*numNodes_+ct1] = static_cast<StorageType>(data_[ct1*numComp+ct]);
        else if(type_ == ByKort)
            for(int ct = 0; ct < numNodes_*numComp; ct++) storageData[ct] = static_cast<StorageType>(data_[ct]);
        out.write((const char *)storageData, sizeof(StorageType)*numNodes_*numComp);
        delete [] storageData;
    }
    out.close();
    stepToProceed_++;
    return 0;
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::readFromFile(const char * name, int step, const char * extension, int numDigits, const char *catalog)
{
    name_ = name; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << name << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
    if(!in.good()) {
        report.error("Error while reading file \"", sstr.str(), "\"");
        return 1;
    }
    in.seekg(0, std::ios_base::end);
    size_t length = in.tellg();
    if(length != sizeof(StorageType)*numNodes_*numComp) {report.error("Error! Data in file \"", sstr.str().c_str(), "\" not corresponds to data type and nodes number", sstr.str()); return 2;}
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
            for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) data_[ct1*numComp+ct] = static_cast<ArrayType>(storageData[ct*numNodes_+ct1]);
        else if(type_ == ByKort)
            for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = static_cast<ArrayType>(storageData[ct]);
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
    return writeToFile<StorageType>(name_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::readFromFile()
{
    return readFromFile<StorageType>(name_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
}
template < class ArrayType, int numComp>
template <class StorageType, int numInOneFile>
int NodesData<ArrayType, numComp>::writeToFileSplited()
{
    NodesData<ArrayType, numInOneFile> tmp(name_+std::to_string(1), mesh_);
    tmp.setStep(step());
    for(int ct = 0;ct < numInOneFile; ct++)
        for(int ct1 = 0; ct1 < numNodes_; ct1++) tmp.data(ct1, ct) = data(ct1, ct);
    tmp.writeToFile();
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
    template <class StorageType = DefaultStorageDataType> int writeToFile(const char * baseName, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int readFromFile(const char * baseName, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int writeToFile();//Short forms
    template <class StorageType = DefaultStorageDataType> int readFromFile();
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
    for(int ct = 0; ct < numArrays; ct++) arrays_[ct] = nullptr;
}
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::free() { for(int ct = 0; ct < numArrays; ct++) if(arrays_[ct]) {delete arrays_[ct]; arrays_[ct] = nullptr;} }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::free(int index) { if(arrays_[index]) {delete arrays_[index]; arrays_[index] = nullptr;} }
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
int SolutionBundle<ArrayType, numArrays>::writeToFile(const char * baseName, int step, const char * extension, int numDigits, const char *catalog)
{
    baseName_ = baseName; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << baseName << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
    if(!out.good()) {report.error("Error while opening file to write ", sstr.str()); return 1;}
    int flags[numArrays];
    for(int ct = 0; ct < numArrays; ct++) flags[ct] = arrays_[ct] ? 1 : 0;
    out.write((const char *)flags, sizeof(int)*numArrays);
    for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
        //TODO implement compile time comparison
        if(typeid(StorageType) == typeid(ArrayType))
            out.write((const char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
        else{
            StorageType * storageData = new StorageType [numNodes_];
            for(int ctNode = 0; ctNode < numNodes_; ctNode++) storageData[ctNode] = static_cast<StorageType>(arrays_[ct]->data()[ctNode]);
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
int SolutionBundle<ArrayType, numArrays>::readFromFile(const char * baseName, int step, const char * extension, int numDigits, const char *catalog)
{
    free();
    baseName_ = baseName; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << baseName << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
    if(!in.good()) {report.error("Error while reading file ", sstr.str()); return 1;}
    int flags[numArrays];
    in.read((char *)flags, sizeof(int)*numArrays);
    int numValidArrays = 0;
    for(int ct = 0; ct < numArrays; ++ct) if(flags[ct]) ++numValidArrays;
    in.seekg(0, std::ios_base::end);
    size_t length = in.tellg();
    if(length != sizeof(int)*numArrays + sizeof(StorageType)*numNodes_*numValidArrays) {
        report.error("Error! Data in file \"", sstr.str().c_str(), "\" not corresponds to data type, nodes number or array number", sstr.str());
        return 2;
    }
    in.seekg(0, std::ios_base::beg);
    in.read((char *)flags, sizeof(int)*numArrays);
    for(int ct = 0; ct < numArrays; ct++) if(flags[ct]) allocate(ct);
    for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
        //TODO implement compile time comparison
        if(typeid(StorageType) == typeid(ArrayType))
            in.read((char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
        else{
            StorageType * storageData = new StorageType [numNodes_];
            in.read((char *)storageData, sizeof(StorageType)*numNodes_);
            for(int ctNode = 0; ctNode < numNodes_; ctNode++) arrays_[ct]->data()[ctNode] = static_cast<ArrayType>(storageData[ctNode]);
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
    return writeToFile<StorageType>(baseName_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
}
template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::readFromFile()
{
    return readFromFile<StorageType>(baseName_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
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
#endif // SBFMESH_H
