#include "sbfStiffBlock3x3.h"

sbfStiffBlock3x3::sbfStiffBlock3x3()
{
    length_ = 9;
    data_ = new double [length_];
    type_ = BlockType::NO_DEFINED_BLOCK;
    indI_ = indJ_ = -1;
}
sbfStiffBlock3x3::sbfStiffBlock3x3(const sbfStiffBlock3x3 & block)
{
    if(data_ == NULL)
        data_ = new double [length_];
    if(block.data_ != NULL)
        for(int ct = 0; ct < length_; ct++)
            data_[ct] = block.data_[ct];
    indI_ = block.indI_;
    indJ_ = block.indJ_;
    type_ = block.type_;
}
sbfStiffBlock3x3::~sbfStiffBlock3x3()
{
    if(data_ != NULL)
        delete [] data_;
}

double * sbfStiffBlock3x3::data()
{
    return data_;
}

void sbfStiffBlock3x3::setType(BlockType type)
{
    type_ = type;
}

BlockType sbfStiffBlock3x3::type()
{
    return type_;
}

int sbfStiffBlock3x3::indI()
{
    return indI_;
}

int sbfStiffBlock3x3::indJ()
{
    return indJ_;
}

void sbfStiffBlock3x3::setIndI(int ind)
{
    indI_ = ind;
}

void sbfStiffBlock3x3::setIndJ(int ind)
{
    indJ_ = ind;
}

int sbfStiffBlock3x3::dataLength()
{
    return length_;
}
