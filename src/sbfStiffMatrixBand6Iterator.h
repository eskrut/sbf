#ifndef SBFSTIFFMATRIXBAND6ITERATOR_H
#define SBFSTIFFMATRIXBAND6ITERATOR_H

class sbfStiffMatrixBand6Iterator;

#include "sbfMatrixIterator.h"
#include "sbfStiffMatrixBand6.h"

class sbfStiffMatrixBand6Iterator : public sbfMatrixIterator
{
public:
    sbfStiffMatrixBand6Iterator(sbfStiffMatrixBand6 *matrix);
private:
    //!Base matrix topology type.
    MatrixType type_;

    //!Base address of matrix data
    double *base_;

    //!Block size
    static const int blockSize_ = 36;

    //Indexes to access columns in rows. Diagonal elements are always in normal storage.
    //!Shifts to certain row in array for normal storage. Length is [numNodes + 1].
    int *shiftsRowNormal_;
    //!Indexes of first and last columns stored by rows in normal storage. Length is [numNodes * 2]. It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowNormal_[i] and stops before shiftsRowNormal_[i+1].
    int *columnsByRowsNormal_;
    //!Shifts to certain row in array for alternative storage. Length is [numNodes + 1].
    int *shiftsRowAlter_;
    //!Indexes of first and last columns stored by rows in alternative storage. Length is [numNodes * 2]. It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowAlter_[i] and stops before shiftsRowAlter_[i+1].
    int *columnsByRowsAlter_;
    //!Pointers to actual data.
    double **blocksByRowsAlter_;

    //Column iteration indexation
    std::vector<std::vector<std::pair<int /*rowId*/, double* /*ptr*/> /*column*/ > > &columnsIndsPtrs_;
    std::vector<std::vector<std::pair<int /*rowId*/, double* /*ptr*/> /*column*/ > > &columnsIndsPtrsAlter_;

    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>> *curColumnIndsPtrs_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>> *curColumnIndsPtrsAlter_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::iterator colIndsPtrsIter_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::iterator colIndsPtrsAlterIter_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::iterator colIndsPtrsEnd_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::iterator colIndsPtrsAlterEnd_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::reverse_iterator colIndsPtrsIterRev_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::reverse_iterator colIndsPtrsAlterIterRev_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::reverse_iterator colIndsPtrsEndRev_;
    std::vector<std::pair<int /*rowId*/, double* /*ptr*/>>::reverse_iterator colIndsPtrsAlterEndRev_;

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

#endif // SBFSTIFFMATRIXBAND6ITERATOR_H
