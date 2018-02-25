#include "sbfgeom2dface.h"

#include "assert.h"

#include "sbfReporter.h"
#include "sbfMesh.h"
#include "sbfElement.h"

#include "sbfgeom2dline.h"
#include "sbfgeom2darc.h"

sbfGeom2DFace::sbfGeom2DFace(std::shared_ptr<const sbfGeom2DEdge> bottom,
                             std::shared_ptr<const sbfGeom2DEdge> right,
                             std::shared_ptr<const sbfGeom2DEdge> top,
                             std::shared_ptr<const sbfGeom2DEdge> left) :
    b_(bottom),
    r_(right),
    t_(top),
    l_(left)
{
    //assert edge correct begin/end order
    //FIXME choose valid tolerance
    assert(b_->begin().isSame(l_->end()));
    assert(b_->end().isSame(r_->begin()));

    assert(r_->begin().isSame(b_->end()));
    assert(r_->end().isSame(t_->begin()));

    assert(t_->begin().isSame(r_->end()));
    assert(t_->end().isSame(l_->begin()));

    assert(l_->begin().isSame(t_->end()));
    assert(l_->end().isSame(b_->begin()));
}

void sbfGeom2DFace::setPartitions(int bottom, int right, int top, int left)
{
    assert(bottom > 0);
    assert(right > 0);
    std::vector<float> b, r, t, l;
    b.resize(bottom, 1.0/bottom);
    r.resize(right, 1.0/right);
    if(top > 0) {
        t.resize(top, 1.0/top);
    }
    else {
        t = b;
    }
    if(left > 0) {
        l.resize(left, 1.0/left);
    }
    else {
        l = r;
    }

    setPartitions(b.begin(), b.end(), r.begin(), r.end()/*, t.begin(), t.end(), l.begin(), l.end()*/);
}

template<class Iterator>
void sbfGeom2DFace::setPartitions(Iterator bBeg, Iterator bEnd,
                                  Iterator rBeg, Iterator rEnd/*,
                                  Iterator tBeg, Iterator tEnd,
                                  Iterator lBeg, Iterator lEnd*/)
{
    auto updatePortions = [](std::vector<float> &p, Iterator b, Iterator e) {
        p.clear();
        p.reserve(std::distance(b, e) + 1);
        p.push_back(0);
        for(auto i = b; i != e; ++i)
            p.push_back(p.back() + *i);
        p.back() = 1;
    };

    updatePortions(portionsB_, bBeg, bEnd);
    updatePortions(portionsR_, rBeg, rEnd);
//    updatePortions(portionsT_, tBeg, tEnd);
//    updatePortions(portionsL_, lBeg, lEnd);
    portionsT_.reserve(portionsB_.size());
    for(auto i = portionsB_.rbegin(); i != portionsB_.rend(); i++) {
        portionsT_.push_back(*i);
    }
    portionsL_.reserve(portionsR_.size());
    for(auto i = portionsR_.rbegin(); i != portionsR_.rend(); i++) {
        portionsL_.push_back(*i);
    }
}

void sbfGeom2DFace::makeMesh(ElementType type)
{
    if(type != ElementType::RECTANGLE_LINEAR)
        report.error("sbfGeom2DFace::makeMesh currently works only with ElementType::RECTANGLE_LINEAR");

    //Mesh will be constructed in 3 stages.
    //1. Creation of fake mesh based on quadrilateral with corners at face nodes
    //and straight edges.
    //2. Moving of nodes at edges to their corresponding places on real face edges.
    //3. Smoothing (weighted) of all other nodes.
    //4. If necessary create new topo growth to match partition sizes.

    for(auto ns : nodes_)
        ns.clear();
    nodes_.clear();
//    indexes_.clear();
    //FIXME this is not correct
    nodes_.resize(std::min(portionsR_.size(), portionsL_.size()));
    for(auto ns : nodes_)
        ns.reserve(std::min(portionsB_.size(), portionsT_.size()));
//    indexes_.reserve(nodes_.capacity());

    //Create fake face
    const auto fB = sbfGeom2DLine(b_->begin(), b_->end());
    const auto fR = sbfGeom2DLine(r_->begin(), r_->end());
    const auto fT = sbfGeom2DLine(t_->begin(), t_->end());
    const auto fL = sbfGeom2DLine(l_->begin(), l_->end());

    auto meshLine = [&](
            const sbfGeom2DEdge &edge,
            const std::vector<float>::iterator pBeg,
            const std::vector<float>::iterator pEnd,
            std::vector<sbfNode> &ns)
    {
        for(auto p = pBeg; p != pEnd; ++p) {
            ns.push_back(edge.nodeAtPortion(*p));
        }
    };

    auto getCross = [](const sbfNode &l1begin, const sbfNode &l1end,
            const sbfNode &l2begin, const sbfNode &l2end){
        sbfNode cross;
        auto x1 = l1begin.x();
        auto y1 = l1begin.y();
        auto x2 = l1end.x();
        auto y2 = l1end.y();

        auto x3 = l2begin.x();
        auto y3 = l2begin.y();
        auto x4 = l2end.x();
        auto y4 = l2end.y();
        cross.setX(
                    ( (x1*y2-y1*x2)*(x3-x4) - (x1-x2)*(x3*y4 - y3*x4) )
                    /
                    ( (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4) )
                    );
        cross.setY(
                    ( (x1*y2-y1*x2)*(y3-y4) - (y1-y2)*(x3*y4 - y3*x4) )
                    /
                    ( (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4) )
                    );
        return  cross;
    };

    std::vector<sbfNode> bFakeNodes, rFakeNodes, tFakeNodes, lFakeNodes;
    bFakeNodes.reserve(portionsB_.size());
    rFakeNodes.reserve(portionsR_.size());
    tFakeNodes.reserve(portionsT_.size());
    lFakeNodes.reserve(portionsL_.size());
    meshLine(fB, portionsB_.begin(), portionsB_.end(), bFakeNodes);
    meshLine(fR, portionsR_.begin(), portionsR_.end(), rFakeNodes);
    meshLine(fT, portionsT_.begin(), portionsT_.end(), tFakeNodes);
    meshLine(fL, portionsL_.begin(), portionsL_.end(), lFakeNodes);

    //mesh fake face
    {
        auto lfIt = lFakeNodes.begin(); auto lfEnd = lFakeNodes.end();
        auto rfIt = rFakeNodes.begin(); auto rfEnd = rFakeNodes.end();

        size_t counter = 0;
        for(; lfIt != lfEnd || rfIt != rfEnd; ++lfIt, ++rfIt) {

            auto bfIt = bFakeNodes.begin(); auto bfEnd = bFakeNodes.end();
            auto tfIt = tFakeNodes.begin(); auto tfEnd = tFakeNodes.end();

            for(; bfIt != bfEnd || tfIt != tfEnd; ++bfIt, ++tfIt) {
                auto n = getCross(*lfIt, *rfIt, *bfIt, *tfIt);
                nodes_[counter].push_back(n);
            }
            counter++;
        }
    }

    //mesh edges of real face
    std::vector<sbfNode> bNodes, rNodes, tNodes, lNodes;
    bNodes.reserve(portionsB_.size());
    rNodes.reserve(portionsR_.size());
    tNodes.reserve(portionsT_.size());
    lNodes.reserve(portionsL_.size());
    meshLine(*b_, portionsB_.begin(), portionsB_.end(), bNodes);
    meshLine(*r_, portionsR_.begin(), portionsR_.end(), rNodes);
    meshLine(*t_, portionsT_.begin(), portionsT_.end(), tNodes);
    meshLine(*l_, portionsL_.begin(), portionsL_.end(), lNodes);

    //shift border nodes to their real places
    for(size_t ct = 0; ct < portionsB_.size() && ct < portionsT_.size(); ++ct) {
        nodes_.front()[ct] = bNodes[ct];
        nodes_.back()[ct] = tNodes[ct];
    }

    for(size_t ct = 1; ct < portionsR_.size() - 1 && ct < portionsL_.size() - 1; ++ct) {
        nodes_[ct].front() = lNodes[ct];
        nodes_[ct].back() = rNodes[ct];
    }

    //smooth nodes
    float norm = 1;
    int iterations = 0;
    //HARDCODE
    while(norm > 1e-7 && iterations < 1000){
        norm = 0;
        for(int ctY = 1; ctY < nodes_.size()-1; ++ctY) {
            for(int ctX = 1; ctX < nodes_[ctY].size()-1; ++ctX) {
                auto n = (
                            nodes_[ctY + 0][ctX + 1] +
                        nodes_[ctY + 0][ctX - 1] +
                        nodes_[ctY + 1][ctX + 0] +
                        nodes_[ctY - 1][ctX + 0]
                        ) * 0.25;
                norm = std::max(n.distance(nodes_[ctY][ctX]), norm);
                nodes_[ctY][ctX] = n;
            }
        }
        ++iterations;
    }
    report("converged in", iterations, "iterations");
}

sbfMesh *sbfGeom2DFace::extrude(const sbfNode &dir, float length, int parts)
{
    size_t simpleNodesX = std::min(portionsB_.size(), portionsT_.size());
    size_t simpleNodesY = std::min(portionsR_.size(), portionsL_.size());
    size_t simpleNodesByLayer = simpleNodesX*simpleNodesY;
    size_t simpleElemsX = simpleNodesX - 1;
    size_t simpleElemsY = simpleNodesY - 1;

    sbfMesh *m = new sbfMesh;
    m->reserveNodesNumber(simpleNodesX * simpleNodesY * (1+parts));
    m->reserveElementsNumber(simpleElemsX*simpleElemsY*parts);

    auto normDir = dir * (1.0 / sbfNode(0, 0, 0).distance(dir));

    for(int ct = 0; ct < parts + 1; ++ct) {
        float scale = ct * length / parts;
        for(const auto &ns : nodes_)
            for(const auto &n : ns){
                m->addNode(n + (normDir * scale), false);
            }
    }

    auto getInPlaneIndexes = [&](size_t id){
        std::array<int, 4> indexes;
        auto x = id % (simpleNodesX-1);
        auto y = id / (simpleNodesX-1);
        indexes[0] = simpleNodesX * (y + 0) + (x + 0);
        indexes[1] = simpleNodesX * (y + 0) + (x + 1);
        indexes[2] = simpleNodesX * (y + 1) + (x + 1);
        indexes[3] = simpleNodesX * (y + 1) + (x + 0);
        return indexes;
    };

    for(int ct = 0; ct < parts; ++ct) {
        for(size_t elY = 0; elY < simpleElemsY; ++elY)
            for(size_t elX = 0; elX < simpleElemsX; ++elX) {
                size_t id = elY * simpleElemsX + elX;
                auto inds = getInPlaneIndexes(id);
                std::vector<int> indexes;
                //HARDCODE
                indexes.resize(8);
                for(int i = 0; i < 4; ++i) {
                    indexes[i + 0] = inds[i] + (ct + 0) * simpleNodesByLayer;
                    indexes[i + 4] = inds[i] + (ct + 1) * simpleNodesByLayer;
                }
                m->addElement(sbfElement(ElementType::HEXAHEDRON_LINEAR, indexes));
            }
    }
    m->setMtr(1);
    return m;
}

