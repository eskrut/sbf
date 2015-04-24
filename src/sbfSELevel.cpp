#include "sbfSELevel.h"
#include <list>
#include <set>
#include <fstream>
#include <sstream>
#include "sbfMesh.h"

sbfSELevel::sbfSELevel()
{
    prevLayer_ = nullptr;
    nextLayer_ = nullptr;
    level_ = -1;
    mesh_ = nullptr;
}
sbfSELevel::~sbfSELevel()
{
    ind_.clear();
}
void sbfSELevel::setMesh(const sbfMesh *mesh)
{
    mesh_ = mesh;
}
void sbfSELevel::setSize(int size)
{
    ind_.resize(size, -1);
}
int sbfSELevel::size()
{
    return (int) ind_.size();
}
void sbfSELevel::setLevelIndex(int index)
{
    level_ = index;
}
int sbfSELevel::levelIndex()
{
    return level_;
}
void sbfSELevel::setIndex(int seqNumber, int index)
{
    ind_.at(seqNumber) = index;
}
int sbfSELevel::index(int seqNumber)
{
    return ind_[seqNumber];
}
int sbfSELevel::numSE()
{
    std::set<int> seList;
    for(std::vector<int>::iterator it = ind_.begin(); it != ind_.end(); it++)
        seList.insert(*it);
    return (int) seList.size();
}
std::vector<int> sbfSELevel::indexesOfSE(int seqNumber)
{
    std::vector<int> indexes;
    if(seqNumber >= numSE())
        return indexes;
    indexes.reserve(ind_.size());
    int length = (int)ind_.size();
    for(int ct = 0; ct < length; ct++)
        if(ind_[ct] == seqNumber) indexes.push_back(ct);
    return indexes;
}

void sbfSELevel::addIndexes(const std::vector<int> &indexes)
{
    ind_.insert(ind_.end(), indexes.begin(), indexes.end());
}
sbfSELevel * sbfSELevel::prev()
{
    return prevLayer_;
}
sbfSELevel * sbfSELevel::next()
{
    return nextLayer_;
}
void sbfSELevel::writeToFile(const char * baseName, int levelIndex, int numDigits)
{
    std::stringstream sStream;
    sStream << baseName;
    sStream.width(numDigits);
    sStream.fill('0');
    if(levelIndex != -1)
        sStream << levelIndex;
    else
        sStream << level_+1;
    sStream << ".sba";

    std::ofstream out(sStream.str().c_str(), std::ios::binary);
    for(std::vector<int>::iterator it = ind_.begin();it != ind_.end(); it++)
        (*it)++;
    out.write((const char *)&ind_[0], (int)ind_.size()*sizeof(ind_[0]));
    out.close();
}
int sbfSELevel::readFromFile(const char * baseName, int levelIndex, int numDigits)
{
    std::stringstream sStream;
    sStream << baseName;
    sStream.width(numDigits);
    sStream.fill('0');
    if(levelIndex != -1)
        sStream << levelIndex;
    else
        sStream << level_+1;
    sStream << ".sba";

    std::ifstream in(sStream.str().c_str(), std::ios::binary);
    if(!in.good())
        return 1;
    in.seekg(0, std::ios::end);
    setSize((int)in.tellg()/sizeof(ind_[0]));
    in.seekg(0, std::ios::beg);
    in.read((char *)&ind_[0], (int)ind_.size()*sizeof(ind_[0]));
    for(std::vector<int>::iterator it = ind_.begin();it != ind_.end(); it++)
        (*it)--;
    in.close();
    return 0;
}
