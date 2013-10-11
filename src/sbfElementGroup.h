#ifndef SBFELEMENTGROUP_H
#define SBFELEMENTGROUP_H

#include "sbfGroup.h"
#include "sbfDeclspec.h"

class sbfMesh;
enum class ElementType : short;

class DECLSPEC sbfElementGroup : public sbfGroup
//Holds information abaut elements group
{
public:
    sbfElementGroup();
    virtual ~sbfElementGroup();

private:
    std::vector<int> list_;
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
    std::vector<int> elemIndList();
    std::vector<int> nodeIndList();
};

#endif // SBFELEMENTGROUP_H
