#ifndef SBFSELEMENT_H
#define SBFSELEMENT_H

#include <vector>
#include <map>
#include <set>
#include <array>
#include <random>
#include "sbfDeclspec.h"
#include "sbfAdditions.h"

class sbfMesh;

class DECLSPEC sbfSElement
{
public:
    sbfSElement();
    sbfSElement(const sbfMesh *mesh, int index = -1);
    ~sbfSElement();
private:
    const sbfMesh *mesh_;
    sbfSElement *parent_, **childrens_;
    int numChildren_;
    int seIndex_;//this SE index
    int * regElemIndexes_;//Indexes of regular (not SE) elements.
    int * nodesIds_;
    std::set<int> innerNodes_;
    std::set<int> outerNodes_;
    void initialize();
public:
    int numSElements () {return numChildren_; }
    void setIndex (int index) { seIndex_ = index; }
    int index () { return seIndex_; }
    std::vector<int> regElemIndexes ();
    void setRegElemIndexes (std::vector<int> regElemIndexes);
    void setChildrens (std::vector<sbfSElement *> selems);
    void addChildren(sbfSElement * selem);
    sbfSElement * children(int index) {
        sbfSElement * rez = nullptr;
        if(childrens_ && index < numChildren_) rez = childrens_[index];
        return rez;
    }
    void setMesh (const sbfMesh *mesh) { mesh_ = mesh; }
    const sbfMesh *mesh () { return mesh_; }
    sbfSElement * parent () {return parent_;}
    void setParent (sbfSElement *parent) { parent_ = parent; }
public:
    struct SEStat {
        int numSEelements;
        int numRegElements;
        int numAverallNodes;
        int numInnerNodes;
        int numOuterNodes;
    };
private:
    SEStat stat_;
    void updateStat();
public:
    SEStat stat() const { return stat_; }
    template<class Iterator>
    static void update(Iterator beg, Iterator end)
    {
        std::multiset<int> nodes;
        for(auto it = beg; it != end; ++it) {
            (*it)->updateStat();
            const auto &seNodes = (*it)->outerNodes_;
            nodes.insert(seNodes.begin(), seNodes.end());
            if((*it)->childrens_) update((*it)->childrens_, (*it)->childrens_+(*it)->numChildren_);
        }
        std::set<int> borderNodes;
        for(auto it : nodes) if (nodes.count(it)>1) borderNodes.insert(it);
        for(auto it = beg; it != end; ++it) {
            const auto outCopy = (*it)->outerNodes_;
            auto &out = (*it)->outerNodes_;
            out.clear();
            auto &inn = (*it)->innerNodes_;
            for(auto o : outCopy)
                if( !borderNodes.count(o) )
                    inn.insert(o);
                else
                    out.insert(o);
            (*it)->stat_.numInnerNodes = inn.size();
            (*it)->stat_.numOuterNodes = out.size();
        }
    }

private:
    struct FacesMapType{
        std::multimap<double /*weight*/, std::vector<int> /*faceIndexes*/> map;
        static const int weightsLength = 50;
        std::array<double, weightsLength> weights;
        FacesMapType(const std::array<double, weightsLength> &weights) {
            for(int ct = 0; ct < weightsLength; ++ct) this->weights[ct] = weights[ct];
        }
        void addFace(std::vector<int> &&indexes){
            double w = 0;
            const int length = indexes.size();
            std::sort(indexes.begin(), indexes.end());
            for(int ct = 0; ct < length; ++ct) w += weights[ct]*indexes[ct];
            map.insert(std::make_pair(w, std::move(indexes)));
        }
    };
    FacesMapType processUpdateInChilds(const std::array<double, FacesMapType::weightsLength> &weights);
};

#endif // SBFSELEMENT_H
