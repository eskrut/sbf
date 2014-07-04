#include "sbfMatrixIterator.h"
#include "sbfStiffMatrix.h"

sbfMatrixIterator::sbfMatrixIterator(const sbfStiffMatrix *matrix):
    matrix_(matrix)
{
}

sbfMatrixIterator::~sbfMatrixIterator()
{
}

int sbfMatrixIterator::row() const
{
    return curRowIndex_;
}

int sbfMatrixIterator::column() const
{
    return curColumnIndex_;
}

std::pair<int, int> sbfMatrixIterator::rowColumn() const
{
    return std::pair<int, int>{curRowIndex_, curColumnIndex_};
}
