#ifndef SBFSTIFFMATRIXBANDITERATOR_H
#define SBFSTIFFMATRIXBANDITERATOR_H

template <int dim> class sbfStiffMatrixBandIterator;

#include "sbfMatrixIterator.h"
#include "sbfStiffMatrixBand.h"

/**
 * @brief sbfStiffMatrixBandIterator is an iterator object to deal with sbfStiffMatrixBand matrices
 */

template <int dim>
class sbfStiffMatrixBandIterator : public sbfMatrixIterator
{
public:
    //! Construct iterator object
    sbfStiffMatrixBandIterator ( const sbfStiffMatrixBand<dim> *matrix );

private:
    //! Base matrix topology type.
    MatrixType type_;
    //! Base address of matrix data
    double *base_;
    //! Block size
    static const int blockSize_ = dim * dim;

    //Indexes to access columns in rows. Diagonal elements are always in normal storage.
    //! Shifts to certain row in array for normal storage.
    //! Length is [numNodes + 1].
    int *shiftsRowNormal_;
    //! Indexes of first and last columns stored by rows in normal storage.
    //! Length is [numNodes * 2]. It holds column IDs in row 0, 1, etc.
    //! Column IDs of row i starts from shiftsRowNormal_[i] and stops before shiftsRowNormal_[i+1].
    int *columnsByRowsNormal_;
    //! Shifts to certain row in array for alternative storage.
    //! Length is [numNodes + 1].
    int *shiftsRowAlter_;
    //! Indexes of first and last columns stored by rows in alternative storage.
    //! Length is [numNodes * 2]. It holds column IDs in row 0, 1, etc.
    //! Column IDs of row i starts from shiftsRowAlter_[i] and stops before shiftsRowAlter_[i+1].
    int *columnsByRowsAlter_;
    //! Pointers to actual data.
    double **blocksByRowsAlter_;

    //Column iteration indexation
    using ColumnDataType = std::vector<std::pair<int /*rowId*/, double * /*ptr*/> /*column*/ >;
    //! row ID and corresponding data pointer to indexating in columns
    const std::vector<ColumnDataType> &columnsIndsPtrs_;
    //! row ID and corresponding data pointer to indexating in columns in alter storage
    const std::vector<ColumnDataType> &columnsIndsPtrsAlter_;

    //! Pointer for current column
    const ColumnDataType *curColumnIndsPtrs_;
    //! Pointer for current column in alter storage
    const ColumnDataType *curColumnIndsPtrsAlter_;
    //! std iterator through column
    ColumnDataType::const_iterator colIndsPtrsIter_;
    //! std iterator through column in alter storage
    ColumnDataType::const_iterator colIndsPtrsAlterIter_;
    //! std iterator to column end
    ColumnDataType::const_iterator colIndsPtrsEnd_;
    //! std iterator to column end in alter storage
    ColumnDataType::const_iterator colIndsPtrsAlterEnd_;
    //! std reverce iterator through column
    ColumnDataType::const_reverse_iterator colIndsPtrsIterRev_;
    //! std reverce iterator through column in alter storage
    ColumnDataType::const_reverse_iterator colIndsPtrsAlterIterRev_;
    //! std reverce iterator to column end
    ColumnDataType::const_reverse_iterator colIndsPtrsEndRev_;
    //! std reverce iterator to column end in alter storage
    ColumnDataType::const_reverse_iterator colIndsPtrsAlterEndRev_;

    //Some helpers

    //! Pointer to current block
    double *curData_;
    //! Current shift value
    int curShiftNormal_;
    //! Current shift to last
    int shiftNormalLast_;
    //! Current shift value in alter storage
    int curShiftAlter_;
    //! Current shift to last in alter storage
    int shiftAlterLast_;
    //! Flag for normal or alter storage
    bool isInNormal_;
    //! Flag for existing next block
    bool isHaveNext_;
    //! Flag for validness
    bool isValid_;

public:
    //Reimplementation of pure virtual functions of base class

    //! Setup iterations ower columns data in row rowIndex
    virtual void setToRow ( const int rowIndex );
    //! Setup iterations ower rows data in column columnIndex
    virtual void setToColumn ( const int columnIndex );
    //! Setup iterations ower columns data in row rowIndex from end to gegin
    virtual void setToRowInverse ( const int rowIndex );
    //! Setup iterations ower rows data in column columnIndex from end to gegin
    virtual void setToColumnInverse ( const int columnIndex );
    //! Check if current state is valid
    virtual bool isValid() const;
    //! Check if there is some data
    virtual bool haveNext() const;
    //! Switch to next. If there in no more blocks returns false.
    virtual bool next();
    //! Get pointer to data.
    //@{
    virtual double *data() const;
    virtual double *data ( bool *isInNormal ) const;
    //@}
    //! Check if a current data corresponds to diagonal
    virtual bool isDiagonal() const;
    //! Check if data should be transposed.
    virtual bool isInNormal() const;
    //! Get pointer to diagonal data of row (column) index
    virtual double *diagonal ( const int index ) const;
};

#endif // SBFSTIFFMATRIXBANDITERATOR_H
