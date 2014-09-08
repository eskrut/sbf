#ifndef SBFSELEMENT_H
#define SBFSELEMENT_H

#include <vector>
#include "sbfDeclspec.h"

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
};

#endif // SBFSELEMENT_H
