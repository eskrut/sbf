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
#include <assert.h>

#include "sbfReporter.h"
#include "sbfAdditions.h"

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
    int readMeshFromFiles(const std::string &indName, const std::string &crdName, const std::string &mtrName);
    int readMeshFromFilesWithPrefix(const std::string &prefix, const std::string &indName = "ind.sba", const std::string &crdName = "crd.sba", const std::string &mtrName = "mtr0001.sba");
    int writeCrdToFile(const char* crdName = "crd.sba");
    int writeIndToFile(const char* indName = "ind.sba", const FileVersion version = FileVersion::NEW_FORMAT);
    int writeMtrToFile(const char* mtrName = "mtr001.sba", const FileVersion version = FileVersion::NEW_FORMAT) const;
    int writeMeshToFiles(const char* indName = "ind.sba", const char* crdName = "crd.sba", const char* mtrName = "mtr001.sba", const FileVersion version = FileVersion::NEW_FORMAT);
    int writeMeshToFiles(const std::string &indName, const std::string &crdName, const std::string &mtrName);
    int writeMeshToFilesWithPrefix(const std::string &prefix);

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
    sbfElementGroup * elemGroup(const int sequenceNumber) const;
    //Process all groups - evaluetes indexes of elements in groups.
    void processElemGroups();
    //Process specific group
    void processElemGroup(const int sequenceNumber);
    //Returns pointer to a specific group of nodes
    sbfNodeGroup * nodeGroup(const int sequenceNumber) const;
    //Process all groups - evaluetes indexes of nodes in groups.
    void processNodeGroups();
    //Process specific group
    void processNodeGroup(const int sequenceNumber);
    //Clear list of groups. To clear information of elements in group without deleting group use sbfElementGroup::clearGroup() method.
    void clearElemGroups();
    void clearNodeGroups();
    void clearAllGroups();

    //Boundaries
public:
    struct sbfMeshBorderFace{
        unsigned int elemID, faceID;
        std::vector<int> nodeIDs;
        std::vector<sbfNode> norms;
    };
private :
    std::vector<std::list<sbfMeshBorderFace>> borderFaces_;
public:
    std::vector<std::list<sbfMeshBorderFace>> computeBorderFaces(float normalAngleThreashold);
};

#include "sbfNodesData.h"
#include "sbfSolutionBundle.h"

#endif // SBFMESH_H
