#include "sbfSELevelList.h"
#include "sbfMesh.h"
#include "sbfSElement.h"
#include "sbfSELevel.h"

sbfSELevelList::sbfSELevelList()
{
    mesh_ = nullptr;
}
sbfSELevelList::~sbfSELevelList()
{
    list_.clear();
}
int sbfSELevelList::numLevels()
{
    return (int)list_.size();
}
sbfSELevel & sbfSELevelList::level(int seqNumber)
{
    std::list<sbfSELevel>::iterator it = list_.begin();
    for(int ct = 0; ct < seqNumber; ct++) it++;
    return *it;
}
void sbfSELevelList::writeToFiles(const char * baseName, int numDigits)
{
    for(std::list<sbfSELevel>::iterator it = list_.begin(); it != list_.end(); it++)
        (*it).writeToFile(baseName, (*it).levelIndex() + 1, numDigits);
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
void sbfSELevelList::setMesh(const sbfMesh *mesh)
{
    mesh_ = mesh;
}
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
