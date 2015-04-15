#ifndef SBFSTIFFMATRIXBLOCKITERATOR_H
#define SBFSTIFFMATRIXBLOCKITERATOR_H

template <int dim> class sbfStiffMatrixBlockIterator;

#include "sbfMatrixIterator.h"
#include "sbfStiffMatrixBlock.h"

/**
 * @brief sbfStiffMatrixBlockIterator is an iterator object to deal with sbfStiffMatrixBlock matrices
 */

template <int dim>
class sbfStiffMatrixBlockIterator : public sbfMatrixIterator
{
public:
    //! Construct iterator object
    sbfStiffMatrixBlockIterator ( const sbfStiffMatrixBlock<dim> *matrix );

private:
    //! Base matrix topology type.
    MatrixType type_;
    //! Base address of matrix data
    double *base_;
    //! Block size
    static const int blockSize_ = dim * dim;

    //Indexes to access columns in rows. Diagonal elements are always in normal storage.
    //! Shifts to certain row in array for normal storage. Length is [numNodes + 1].
    int *shiftsRowNormal_;
    //! Indexes of columns stored by rows in normal storage. Length is [numBlocks].
    //! It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowNormal_[i] and stops before shiftsRowNormal_[i+1].
    int *columnsByRowsNormal_;
    //! Shifts to certain row in array for alternative storage. Length is [numNodes + 1].
    int *shiftsRowAlter_;
    //! Indexes of columns stored by rows in alternative storage. Length is dependent.
    //! It holds column IDs in row 0, 1, etc. Column IDs of row i starts from shiftsRowAlter_[i] and stops before shiftsRowAlter_[i+1].
    int *columnsByRowsAlter_;
    //!Pointers to actual data.
    double **blocksByRowsAlter_;

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
    //! Get dimention of single record in matrix
    virtual int numDOF() const { return dim; }
    //! Get size of single record in matrix
    virtual int dataItemSize() const { return dim*dim; }
};

#endif // SBFSTIFFMATRIXBLOCKITERATOR_H
