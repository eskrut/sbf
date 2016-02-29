#include "sbfMatrixIterator.h"
#include "sbfStiffMatrix.h"

sbfMatrixIterator::sbfMatrixIterator(const sbfStiffMatrix *matrix):
    matrix_(matrix)
{
}

sbfMatrixIterator::~sbfMatrixIterator()
{
}

unsigned int sbfMatrixIterator::row() const
{
    return curRowIndex_;
}

unsigned int sbfMatrixIterator::column() const
{
    return curColumnIndex_;
}

std::pair<unsigned int, unsigned int> sbfMatrixIterator::rowColumn() const
{
    return std::make_pair(curRowIndex_, curColumnIndex_);
}
