#ifndef SBFSELEVEL_H
#define SBFSELEVEL_H

#include <vector>

class sbfMesh;

class /*DECLSPEC*/ sbfSELevel
//Holds information about indexes of elements in super element
{
public:
    sbfSELevel();
    ~sbfSELevel();
private:
    std::vector<int> ind_;//Indexes of elements in SE layer
    int level_;//Layer index
    sbfSELevel *prevLayer_, *nextLayer_;
    sbfMesh *mesh_;
public:
    void setSize(int size);//Sets size of indexes vector should be same as number of elements at previous level
    int size();//Returns indexes vector size
    void setLevelIndex(int index);//Sets index of this level
    int levelIndex();
    void setIndex(int seqNumber, int index);//Sets index of SE in this level
    int index(int seqNumber);
    int numSE();//Returns number of SE at this level
    std::vector<int> indexesOfSE(int seqNumber);//Returns vector of element indexes which belonges to SE seqNumber in this level
    void setMesh(sbfMesh * mesh);//Sets base mesh
    sbfSELevel * prev();//Returns pointer to previous SE layer
    sbfSELevel * next();//Returns pointer to next SE layer
    void writeToFile(const char * baseName = "level", int levelIndex = -1, int numDigits = 3);
    int readFromFile(const char * baseName = "level", int levelIndex = -1, int numDigits = 3);
};

#endif // SBFSELEVEL_H
