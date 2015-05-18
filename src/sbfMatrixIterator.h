#ifndef SBFMATRIXITERATOR_H
#define SBFMATRIXITERATOR_H

#include <utility> //for std::pair

//! @class sbfMatrixIterator
//! @brief This class should be used as a base polymorphic class to implement iteration mechanism over rows and columns of specific matrixes.

class sbfStiffMatrix;

class sbfMatrixIterator
{
public:
    sbfMatrixIterator(const sbfStiffMatrix *matrix);
    virtual ~sbfMatrixIterator();

public:
    //Pure virtual interfaces. Should be reimplemented in derived classes.
    //!Setup iterations ower columns data in row rowIndex
    virtual void setToRow(const unsigned int rowIndex) = 0;
    //!Setup iterations ower rows data in column columnIndex
    virtual void setToColumn(const int unsigned columnIndex) = 0;
    //!Setup iterations ower columns data in row rowIndex from end to gegin
    virtual void setToRowInverse(const unsigned int rowIndex) = 0;
    //!Setup iterations ower rows data in column columnIndex from end to gegin
    virtual void setToColumnInverse(const unsigned int columnIndex) = 0;
    //!Check if current state is valid
    virtual bool isValid() const = 0;
    //!Check if there is some data
    virtual bool haveNext() const = 0;
    //!Switch to next. If there in no more blocks returns false.
    virtual bool next() = 0;
    //!Switch to next count tumes.
    bool next(int count) { bool rez; for(int ct = 0; ct < count; ++ct) rez = next(); return rez;}
    //!Get pointer to data.
    //TODO is it necessary to make template or deduce internal pointers type at compile-time?
    virtual double* data() const = 0;
    virtual double* data(bool * isInNormal) const = 0;
    //!Check if a current data corresponds to diagonal
    virtual bool isDiagonal() const = 0;
    //TODO may be this should be declared in some base class designed to work with block matrixes?
    //!Check if data should be transposed.
    virtual bool isInNormal() const = 0;
    //!Get pointer to diagonal data of row (column) index
    virtual double * diagonal(const unsigned int index) const = 0;
    //!Get dimention of single record in matrix
    virtual int numDOF() const = 0;
    //!Get size of single record in matrix
    virtual int dataItemSize() const = 0;

protected:
    enum class IterateDirection { RowDirect, RowInvert, ColumnDirect, ColumnInvert };
    //!Base matrix
    const sbfStiffMatrix *matrix_;
    //!Current row in use
    unsigned int curRowIndex_;
    //!Current column in use
    unsigned int curColumnIndex_;
    //!Current direction
    IterateDirection dir_;
public:
    const sbfStiffMatrix *matrix() const { return matrix_; }
    unsigned int row() const;
    unsigned int column() const;
    std::pair<unsigned int, unsigned int> rowColumn() const;
};

#endif // SBFMATRIXITERATOR_H
