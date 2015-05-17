#ifndef SBFSELEVELLIST_H
#define SBFSELEVELLIST_H

#include <list>
#include <vector>
#include "sbfDeclspec.h"

class sbfMesh;
class sbfSElement;
class sbfSELevel;

class DECLSPEC sbfSELevelList
//Holds information about super element layers
{
public:
    sbfSELevelList();
    ~sbfSELevelList();
private:
    std::list<sbfSELevel> list_;
    const sbfMesh *mesh_;
public:
    int numLevels();//Returns number of SE layers
    sbfSELevel & level(int seqNumber);
    void addLevel(const sbfSELevel &level);
    void writeToFiles(const char * baseName = "level", int numDigits = 3);
    int readFromFiles(const char * baseName = "level", int numDigits = 3);
    void setMesh(const sbfMesh *mesh);//Sets base mesh
    std::vector< std::vector<sbfSElement *> > selevels (std::vector<sbfSElement *> * fakeSEs = nullptr);
};

#endif // SBFSELEVELLIST_H
