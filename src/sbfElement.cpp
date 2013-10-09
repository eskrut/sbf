#include "sbfElement.h"
#include "sbfNode.h"
#include "sbfMesh.h"

sbfElement::sbfElement()
{}
sbfElement::sbfElement(const int numNodes)
{
    ind_.resize(numNodes, -1);
}
sbfElement::sbfElement(const ElementType type, const std::vector<int> & indexes)
{
    type_ = type; setNodes(indexes);
}
sbfElement::~sbfElement()
{
    ind_.clear();
}

void sbfElement::setNumNodes(const int nNodes)
{
    ind_.resize(nNodes, -1);
}
int sbfElement::numNodes() const
{
    return static_cast<int>(ind_.size());
}
void sbfElement::setNode(const int sequenceNumber, const int nodeNumber)
{
    ind_[sequenceNumber] = nodeNumber;
}
void sbfElement::addNode(const int nodeNumber)
{
    ind_.push_back(nodeNumber);
}
int sbfElement::nodeIndex(const int sequenceNumber) const
{
    return ind_[sequenceNumber];
}
std::vector<int> sbfElement::indexes() const
{
    return ind_;
}
void sbfElement::setNodes(const int nodeNumber, int first, ...)
{
    for(int ct = 0; ct < nodeNumber; ct++)
        ind_[ct] = *(&first + ct);
}
void sbfElement::setNodes(const std::vector<int> & indexes)
{
    ind_.clear();
    ind_ = indexes;
}
void sbfElement::setMtr(const int material)
{
    mtr_ = material;
}
int sbfElement::mtr() const
{
    return mtr_;
}
void sbfElement::setType(const ElementType & type)
{
    type_ = type;
    setNumNodes(numNodesInElement(type));
}
ElementType sbfElement::type() const
{
    return type_;
}
std::vector<std::vector<int> > sbfElement::facesNodesIndexes() const
{
    std::vector<std::vector<int> > facesNodes;
    switch (type()){
    case ElementType::TETRAHEDRON_LINEAR : {
        facesNodes.push_back(std::vector<int>{ind_[0], ind_[1], ind_[2]});
        facesNodes.push_back(std::vector<int>{ind_[0], ind_[3], ind_[1]});
        facesNodes.push_back(std::vector<int>{ind_[1], ind_[3], ind_[2]});
        facesNodes.push_back(std::vector<int>{ind_[2], ind_[3], ind_[0]});
        break;
    }
    case ElementType::TETRAHEDRON_QUADRATIC : {
        facesNodes.push_back(std::vector<int>{ind_[0], ind_[4], ind_[1], ind_[5], ind_[2], ind_[6]});
        facesNodes.push_back(std::vector<int>{ind_[0], ind_[7], ind_[3], ind_[8], ind_[1], ind_[4]});
        facesNodes.push_back(std::vector<int>{ind_[1], ind_[8], ind_[3], ind_[9], ind_[2], ind_[5]});
        facesNodes.push_back(std::vector<int>{ind_[2], ind_[9], ind_[3], ind_[7], ind_[0], ind_[6]});
        break;
    }
    case ElementType::HEXAHEDRON_LINEAR : {
        facesNodes.push_back(std::vector<int>{ind_[0], ind_[1], ind_[2], ind_[3]});
        facesNodes.push_back(std::vector<int>{ind_[4], ind_[7], ind_[6], ind_[5]});
        facesNodes.push_back(std::vector<int>{ind_[0], ind_[4], ind_[5], ind_[1]});
        facesNodes.push_back(std::vector<int>{ind_[1], ind_[5], ind_[6], ind_[2]});
        facesNodes.push_back(std::vector<int>{ind_[2], ind_[6], ind_[7], ind_[3]});
        facesNodes.push_back(std::vector<int>{ind_[3], ind_[7], ind_[4], ind_[0]});
        break;
    }
    case ElementType::HEXAHEDRON_QUADRATIC : {
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
sbfNode sbfElement::centreOfMass() const
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
{
    mesh_ = mesh;
}
sbfMesh * sbfElement::mesh() const
{
    return mesh_;
}
float sbfElement::max(const int kort) const
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
float sbfElement::min(const int kort) const
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
float sbfElement::maxX() const
{
    return max(0);
}
float sbfElement::maxY() const
{
    return max(1);
}
float sbfElement::maxZ() const
{
    return max(2);
}
float sbfElement::minX() const
{
    return min(0);
}
float sbfElement::minY() const
{
    return min(1);
}
float sbfElement::minZ() const
{
    return min(2);
}
float sbfElement::volume() const
{
    double vol;
    switch (type()) {
    case ElementType::HEXAHEDRON_LINEAR :
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


int numNodesInElement(const ElementType type)
{
    switch ( type ) {
    case ElementType::HEXAHEDRON_LINEAR:
        return 8;
    case ElementType::HEXAHEDRON_QUADRATIC:
        return 20;
    case ElementType::BEAM_LINEAR_3DOF:
        return 2;
    case ElementType::BEAM_QUADRATIC_3DOF:
        return 3;
    case ElementType::BEAM_LINEAR_6DOF:
        return 2;
    case ElementType::BEAM_QUADRATIC_6DOF:
        return 3;
    case ElementType::RECTANGLE_LINEAR:
        return 4;
    case ElementType::TETRAHEDRON_LINEAR:
        return 4;
    case ElementType::TETRAHEDRON_QUADRATIC:
        return 10;
    default:
        return -1;
    }
    return -1;
}
