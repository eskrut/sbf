#ifndef SBFSTIFFMATRIXBLOCK3X3ITERATOR_H
#define SBFSTIFFMATRIXBLOCK3X3ITERATOR_H

#include "sbfMatrixIterator.h"
#include "sbfStiffMatrixBlock3x3.h"

class sbfStiffMatrixBlock3x3Iterator : public sbfMatrixIterator
{
public:
    sbfStiffMatrixBlock3x3Iterator(sbfStiffMatrixBlock3x3 * matrix);
private:
    sbfStiffMatrixBlock3x3 * matrix_;
private:
    //!Base matrix topology type.
    MatrixType type_;

    //!Base address of matrix data
    double * base_;

    //!Block size
    static const int blockSize_{9};

    //Indexes to access columns in rows. Diagonal elements are always in normal storage.
    //!Shifts to certain row in array for normal storage. Length is [numNodes + 1].
    int * shiftsRowNormal_;
    //!Indexes of columns stored by rows in normal storage. Length is [numBlocks]. It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowNormal_[i] and stops before shiftsRowNormal_[i+1].
    int * columnsByRowsNormal_;
    //!Shifts to certain row in array for alternative storage. Length is [numNodes + 1].
    int * shiftsRowAlter_;
    //!Indexes of columns stored by rows in alternative storage. Length is dependent. It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowAlter_[i] and stops before shiftsRowAlter_[i+1].
    int * columnsByRowsAlter_;
    //!Pointers to actual data.
    double ** blocksByRowsAlter_;

    //Some helpers
    double * curData_;
    int curShiftNormal_;
    int shiftNormalLast_;
    int curShiftAlter_;
    int shiftAlterLast_;
    bool isInNormal_;
    bool isHaveNext_;

public:
    //Reimplementation of pure virtual functions of base class
    //!Setup iterations ower columns data in row rowIndex
    virtual void setToRow(const int rowIndex);
    //!Setup iterations ower rows data in column columnIndex
    virtual void setToColumn(const int columnIndex);
    //!Setup iterations ower columns data in row rowIndex from end to gegin
    virtual void setToRowInverse(const int rowIndex);
    //!Setup iterations ower rows data in column columnIndex from end to gegin
    virtual void setToColumnInverse(const int columnIndex);
    //!Check if there is some data
    virtual bool haveNext() const;
    //!Switch to next. If there in no more blocks returns false.
    virtual bool next();
    //!Get pointer to data.
    virtual double* data();
    //!Check if a current data corresponds to diagonal
    virtual bool isDiagonal() const;
    //!Check if data should be transposed.
    virtual bool isInNormal() const;
};

#endif // SBFSTIFFMATRIXBLOCK3X3ITERATOR_H
