#ifndef SBFSTIFFMATRIXBLOCK6x6ITERATOR_H
#define SBFSTIFFMATRIXBLOCK6x6ITERATOR_H

class sbfStiffMatrixBlock6x6Iterator;

#include "sbfMatrixIterator.h"
#include "sbfStiffMatrixBlock6x6.h"

class sbfStiffMatrixBlock6x6Iterator : public sbfMatrixIterator
{
public:
    sbfStiffMatrixBlock6x6Iterator(sbfStiffMatrixBlock6x6 *matrix);
private:
    sbfStiffMatrixBlock6x6 *matrix_;
    //!Base matrix topology type.
    MatrixType type_;

    //!Base address of matrix data
    double *base_;

    //!Block size
    static const int blockSize_ = 36;

    //Indexes to access columns in rows. Diagonal elements are always in normal storage.
    //!Shifts to certain row in array for normal storage. Length is [numNodes + 1].
    int *shiftsRowNormal_;
    //!Indexes of columns stored by rows in normal storage. Length is [numBlocks]. It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowNormal_[i] and stops before shiftsRowNormal_[i+1].
    int *columnsByRowsNormal_;
    //!Shifts to certain row in array for alternative storage. Length is [numNodes + 1].
    int *shiftsRowAlter_;
    //!Indexes of columns stored by rows in alternative storage. Length is dependent. It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowAlter_[i] and stops before shiftsRowAlter_[i+1].
    int *columnsByRowsAlter_;
    //!Pointers to actual data.
    double **blocksByRowsAlter_;

    //Some helpers
    double *curData_;
    int curShiftNormal_;
    int shiftNormalLast_;
    int curShiftAlter_;
    int shiftAlterLast_;
    bool isInNormal_;
    bool isHaveNext_;
    bool isValid_;

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
    //!Check if current state is valid
    virtual bool isValid() const;
    //!Check if there is some data
    virtual bool haveNext() const;
    //!Switch to next. If there in no more blocks returns false.
    virtual bool next();
    //!Get pointer to data.
    virtual double* data() const;
    virtual double* data(bool * isInNormal) const;
    //!Check if a current data corresponds to diagonal
    virtual bool isDiagonal() const;
    //!Check if data should be transposed.
    virtual bool isInNormal() const;
    //!Get pointer to diagonal data of row (column) index
    virtual double * diagonal(const int index) const;
};

#endif // SBFSTIFFMATRIXBLOCK6x6ITERATOR_H
