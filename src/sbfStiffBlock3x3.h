#ifndef SBFSTIFFBLOCK3X3_H
#define SBFSTIFFBLOCK3X3_H

#include "sbfDeclspec.h"
#include "sbfEnums.h"

class DECLSPEC sbfStiffBlock3x3
{
public:
    sbfStiffBlock3x3();
    sbfStiffBlock3x3(const sbfStiffBlock3x3 & block);
    virtual ~sbfStiffBlock3x3();
private:
    //Linear storage array for stiffness block, i.e. 9 doubles
    double *data_;
    //Block location type
    BlockType type_;
    //Length of block data
    int length_;
    //Global indexes of block in terms of node numbers
    int indI_, indJ_;
public:
    //Returns pointer to block array
    double *data();
    void setType(BlockType type);
    BlockType type();
    //Get/set block indexes
    int indI();
    int indJ();
    void setIndI(int ind);
    void setIndJ(int ind);
    //Returns length of block data
    int dataLength();
};

#endif // SBFSTIFFBLOCK3X3_H
