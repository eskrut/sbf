#ifndef SBFELEMENT_H
#define SBFELEMENT_H

#include <vector>
#include <limits>
#include <initializer_list>

#include "sbfEnums.h"

class sbfMesh;
class sbfNode;

class /*DECLSPEC*/ sbfElement
{
public:
    sbfElement();
    //Construct sbfElement by number of nodes
    sbfElement(const int numNodes);
    //Construct sbfElement by type and node indexes
    sbfElement(const ElementType type, const std::vector<int> & indexes);
    sbfElement(const ElementType type, const std::initializer_list<int> & indexes);
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
    void setNode(const int sequenceNumber, const int nodeInd);
    void addNode(const int nodeInd);
    //TODO should be replaced to variadic or list initialization
    void setNodes(const int nodesNumber, int first, ...);
    void setNodes(const std::vector<int> & indexes);
    void setNodes(const int nodesNumber, const int * const firstNodeIndPtr);
    void setNodes(const std::initializer_list<int> & indexes);
    void setMtr(const int material = 1);
    void setType(const ElementType & type);
    //Set/get pointer to mesh, associated with this element
    void setMesh(sbfMesh * mesh);
    sbfMesh * mesh() const;

    //Get element information
    int numNodes() const;
    int nodeIndex(const int sequenceNumber) const;
    //Returns a vector (copy) of nodes indexes
    std::vector<int> indexes() const;
    int mtr() const;
    ElementType type() const;
    //Returns nodes indexes on all element faces
    using FacesNodesIndsContainer = std::vector<std::vector<int>>;
    FacesNodesIndsContainer facesNodesIndexes() const;
    //Returns average coordinate of all nodes
    sbfNode centreOfMass() const;
    //Get information about max/min coordinates of element nodes
    float max(const int kort) const;
    float min(const int kort) const;
    float maxX() const;
    float maxY() const;
    float maxZ() const;
    float minX() const;
    float minY() const;
    float minZ() const;
    //Returns element volume if exist
    float volume() const;

};

/*DECLSPEC*/ int numNodesInElement(const ElementType type);

#endif // SBFELEMENT_H
