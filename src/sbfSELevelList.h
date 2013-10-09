#ifndef SBFSELEVELLIST_H
#define SBFSELEVELLIST_H

#include <list>
#include <vector>

class sbfMesh;
class sbfSElement;
class sbfSELevel;

class /*DECLSPEC*/ sbfSELevelList
//Holds information about super element layers
{
public:
    sbfSELevelList();
    ~sbfSELevelList();
private:
    std::list<sbfSELevel> list_;
    sbfMesh * mesh_;
public:
    int numLevels();//Returns number of SE layers
    sbfSELevel & level(int seqNumber);
    void writeToFiles(const char * baseName = "level", int numDigits = 3);
    int readFromFiles(const char * baseName = "level", int numDigits = 3);
    void setMesh(sbfMesh * mesh);//Sets base mesh
    std::vector< std::vector<sbfSElement *> > selevels (std::vector<sbfSElement *> * fakeSEs = nullptr);
};

#endif // SBFSELEVELLIST_H
