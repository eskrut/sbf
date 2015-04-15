#include "sbfStiffMatrixBlockIterator.h"

template <int dim>
sbfStiffMatrixBlockIterator<dim>::sbfStiffMatrixBlockIterator ( const sbfStiffMatrixBlock<dim> *matrix ) :
    sbfMatrixIterator ( matrix ),
    type_ ( matrix->type() ),
    columnsIndsPtrs_ ( matrix->columnsIndsPtrs_ ),
    columnsIndsPtrsAlter_ ( matrix->columnsIndsPtrsAlter_ ),
    curColumnIndsPtrs_ ( nullptr ),
    curColumnIndsPtrsAlter_ ( nullptr ),
    isInNormal_ ( false ),
    isHaveNext_ ( false ),
    isValid_ ( false )
{
    columnsByRowsNormal_ = matrix->indJ_;
    shiftsRowNormal_ = matrix->shiftInd_;
    columnsByRowsAlter_ = matrix->indJAlter_;
    shiftsRowAlter_ = matrix->shiftIndAlter_;
    blocksByRowsAlter_ = matrix->ptrDataAlter_;
    base_ = matrix->data_;
}

template <int dim>
void sbfStiffMatrixBlockIterator<dim>::setToRow ( const int rowIndex )
{
    //sbfStiffMatrixBlockIterator<dim>::setToRow and sbfStiffMatrixBandIterator<dim>::setToRow
    //are NEARLY same, except dealing with columnsByRowsNormal_ and columnsByRowsAlter_
    //keep this in mind during modifications
    curRowIndex_ = rowIndex;
    dir_ = IterateDirection::RowDirect;
    curShiftNormal_ = shiftsRowNormal_[curRowIndex_];
    shiftNormalLast_ = shiftsRowNormal_[curRowIndex_ + 1];
    if ( shiftsRowAlter_ ) {
        curShiftAlter_ = shiftsRowAlter_[curRowIndex_];
        shiftAlterLast_ = shiftsRowAlter_[curRowIndex_ + 1];
    }
    else {
        curShiftAlter_ = shiftAlterLast_ = -1;
    }
    if ( curShiftNormal_ == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_ )
        isHaveNext_ = false;
    else
        isHaveNext_ = true;

    if ( ! ( type_ & UP_TREANGLE_MATRIX ) ) {
        if ( curShiftNormal_ != shiftNormalLast_ ) {
            curColumnIndex_ = columnsByRowsNormal_[curShiftNormal_];
            isInNormal_ = true;
            curData_ = base_ + blockSize_ * curShiftNormal_;
            isValid_ = true;
        }
        else {
            curColumnIndex_ = columnsByRowsAlter_[curShiftAlter_];
            isInNormal_ = false;
            curData_ = blocksByRowsAlter_[curShiftAlter_];
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error ( "Not implemented yet :(" );
    }//type_ == UP_TREANGLE_MATRIX
    curColumnIndsPtrs_ = nullptr;
    curColumnIndsPtrsAlter_ = nullptr;
}

template <int dim>
void sbfStiffMatrixBlockIterator<dim>::setToColumn ( const int columnIndex )
{
    //sbfStiffMatrixBlockIterator<dim>::setToColumn and sbfStiffMatrixBandIterator<dim>::setToColumn
    //are SAME
    //keep this in mind during modifications
    curColumnIndsPtrs_ = & ( columnsIndsPtrs_[columnIndex] );
    curColumnIndsPtrsAlter_ = & ( columnsIndsPtrsAlter_[columnIndex] );
    colIndsPtrsIter_ = curColumnIndsPtrs_->begin();
    colIndsPtrsAlterIter_ = curColumnIndsPtrsAlter_->begin();
    colIndsPtrsEnd_ = curColumnIndsPtrs_->end();
    colIndsPtrsAlterEnd_ = curColumnIndsPtrsAlter_->end();
    curColumnIndex_ = columnIndex;
    dir_ = IterateDirection::ColumnDirect;

    if (
        ( colIndsPtrsAlterIter_ == colIndsPtrsAlterEnd_ && colIndsPtrsIter_ + 1 < colIndsPtrsEnd_ ) ||
        ( colIndsPtrsAlterIter_ + 1 == colIndsPtrsAlterEnd_ && colIndsPtrsIter_ < colIndsPtrsEnd_ ) ||
        ( colIndsPtrsAlterIter_ + 1 < colIndsPtrsAlterEnd_ || colIndsPtrsIter_ + 1 < colIndsPtrsEnd_ )
    )
        isHaveNext_ = true;
    else
        isHaveNext_ = false;
    if ( ! ( type_ & UP_TREANGLE_MATRIX ) ) {
        if ( colIndsPtrsAlterIter_ != colIndsPtrsAlterEnd_ ) {
            curRowIndex_ = colIndsPtrsAlterIter_->first;
            isInNormal_ = false;
            curData_ = colIndsPtrsAlterIter_->second;
            isValid_ = true;
            //To make increment in next()
            --colIndsPtrsIter_;
        }
        else {
            curRowIndex_ = colIndsPtrsIter_->first;
            isInNormal_ = true;
            curData_ = colIndsPtrsIter_->second;
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error ( "Not implemented yet :(" );
    }//type_ == UP_TREANGLE_MATRIX
}

template <int dim>
void sbfStiffMatrixBlockIterator<dim>::setToRowInverse ( const int rowIndex )
{
    //sbfStiffMatrixBlockIterator<dim>::setToRowInverse and sbfStiffMatrixBandIterator<dim>::setToRowInverse
    //are NEARLY same, except dealing with columnsByRowsNormal_ and columnsByRowsAlter_
    //keep this in mind during modifications
    curRowIndex_ = rowIndex;
    dir_ = IterateDirection::RowInvert;
    curShiftNormal_ = shiftsRowNormal_[curRowIndex_ + 1] - 1;
    shiftNormalLast_ = shiftsRowNormal_[curRowIndex_];
    if ( shiftsRowAlter_ ) {
        curShiftAlter_ = shiftsRowAlter_[curRowIndex_ + 1];
        shiftAlterLast_ = shiftsRowAlter_[curRowIndex_];
    }
    else {
        curShiftAlter_ = shiftAlterLast_ = -1;
    }
    if ( curShiftNormal_ == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_ )
        isHaveNext_ = false;
    else
        isHaveNext_ = true;

    if ( ! ( type_ & UP_TREANGLE_MATRIX ) ) {
        if ( --curShiftAlter_ >= shiftAlterLast_ ) {
            curColumnIndex_ = columnsByRowsAlter_[curShiftAlter_];
            isInNormal_ = false;
            curData_ = blocksByRowsAlter_[curShiftAlter_];
            isValid_ = true;
            //Litle hack to perform next()
            curShiftNormal_++;
        }
        else {
            curColumnIndex_ = columnsByRowsNormal_[curShiftNormal_];
            isInNormal_ = true;
            curData_ = base_ + blockSize_ * curShiftNormal_;
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error ( "Not implemented yet :(" );
    }//type_ == UP_TREANGLE_MATRIX
    curColumnIndsPtrs_ = nullptr;
    curColumnIndsPtrsAlter_ = nullptr;
}

template <int dim>
void sbfStiffMatrixBlockIterator<dim>::setToColumnInverse ( const int columnIndex )
{
    //sbfStiffMatrixBlockIterator<dim>::setToColumnInverse and sbfStiffMatrixBandIterator<dim>::setToColumnInverse
    //are SAME
    //keep this in mind during modifications
    curColumnIndsPtrs_ = & ( columnsIndsPtrs_[columnIndex] );
    curColumnIndsPtrsAlter_ = & ( columnsIndsPtrsAlter_[columnIndex] );
    colIndsPtrsIterRev_ = curColumnIndsPtrs_->rbegin();
    colIndsPtrsAlterIterRev_ = curColumnIndsPtrsAlter_->rbegin();
    colIndsPtrsEndRev_ = curColumnIndsPtrs_->rend();
    colIndsPtrsAlterEndRev_ = curColumnIndsPtrsAlter_->rend();
    curColumnIndex_ = columnIndex;
    dir_ = IterateDirection::ColumnInvert;

    if (
        ( colIndsPtrsAlterIterRev_ == colIndsPtrsAlterEndRev_ && colIndsPtrsIterRev_ + 1 < colIndsPtrsEndRev_ ) ||
        ( colIndsPtrsAlterIterRev_ + 1 == colIndsPtrsAlterEndRev_ && colIndsPtrsIterRev_ < colIndsPtrsEndRev_ ) ||
        ( colIndsPtrsAlterIterRev_ + 1 < colIndsPtrsAlterEndRev_ || colIndsPtrsIterRev_ + 1 < colIndsPtrsEndRev_ )
    )
        isHaveNext_ = true;
    else
        isHaveNext_ = false;
    if ( ! ( type_ & UP_TREANGLE_MATRIX ) ) {
        if ( colIndsPtrsIterRev_ != colIndsPtrsEndRev_ ) {
            curRowIndex_ = colIndsPtrsIterRev_->first;
            isInNormal_ = true;
            curData_ = colIndsPtrsIterRev_->second;
            isValid_ = true;
            //To make increment in next()
            if ( colIndsPtrsAlterIterRev_ != colIndsPtrsAlterEndRev_ )
                --colIndsPtrsAlterIterRev_;
        }
        else {
            curRowIndex_ = colIndsPtrsAlterIterRev_->first;
            isInNormal_ = false;
            curData_ = colIndsPtrsAlterIterRev_->second;
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error ( "Not implemented yet :(" );
    }//type_ == UP_TREANGLE_MATRIX
}

template <int dim>
bool sbfStiffMatrixBlockIterator<dim>::isValid() const
{
    return isValid_;
}

template <int dim>
bool sbfStiffMatrixBlockIterator<dim>::haveNext() const
{
    return isHaveNext_;
}

template <int dim>
bool sbfStiffMatrixBlockIterator<dim>::next()
{
    //sbfStiffMatrixBlockIterator<dim>::next and sbfStiffMatrixBandIterator<dim>::next
    //are NEARLY same, except dealing with columnsByRowsNormal_ and columnsByRowsAlter_ in row cases and
    //are SAME in column cases
    //keep this in mind during modifications
    if ( !isHaveNext_ ) {
        isValid_ = false;
        return false;
    }
    isValid_ = true;
    if ( ! ( type_ & UP_TREANGLE_MATRIX ) ) {
        switch ( dir_ ) {
        case IterateDirection::RowDirect:
            if ( isInNormal_ && ++curShiftNormal_ != shiftNormalLast_ ) {
                curColumnIndex_ = columnsByRowsNormal_[curShiftNormal_];
                curData_ = base_ + blockSize_ * curShiftNormal_;
                if ( curShiftNormal_ + 1 == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_ ) isHaveNext_ = false;
            }
            else if ( curShiftAlter_ != shiftAlterLast_ ) {
                if ( isInNormal_ ) {
                    isInNormal_ = false;
                    curShiftAlter_--;//For first block only
                }
                ++curShiftAlter_;
                curColumnIndex_ = columnsByRowsAlter_[curShiftAlter_];
                curData_ = blocksByRowsAlter_[curShiftAlter_];
                if ( curShiftAlter_ + 1 == shiftAlterLast_ ) isHaveNext_ = false;
            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        case IterateDirection::ColumnDirect:
            if ( curColumnIndsPtrsAlter_->size() && colIndsPtrsAlterIter_ + 1 < colIndsPtrsAlterEnd_ ) {
                ++colIndsPtrsAlterIter_;
                curRowIndex_ = colIndsPtrsAlterIter_->first;
                isInNormal_ = false;
                curData_ = colIndsPtrsAlterIter_->second;
                isValid_ = true;
            }
            else if ( colIndsPtrsIter_ + 1 < colIndsPtrsEnd_ ) {
                ++colIndsPtrsIter_;
                curRowIndex_ = colIndsPtrsIter_->first;
                isInNormal_ = true;
                curData_ = colIndsPtrsIter_->second;
                isValid_ = true;
                if ( colIndsPtrsIter_ + 1 == colIndsPtrsEnd_ ) isHaveNext_ = false;
            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        case IterateDirection::RowInvert:
            if ( !isInNormal_ && --curShiftAlter_ >= shiftAlterLast_ ) {
                curColumnIndex_ = columnsByRowsAlter_[curShiftAlter_];
                curData_ = blocksByRowsAlter_[curShiftAlter_];
            }
            else if ( curShiftNormal_-- >= shiftNormalLast_ ) {
                if ( !isInNormal_ )
                    isInNormal_ = true;
                curColumnIndex_ = columnsByRowsNormal_[curShiftNormal_];
                curData_ = base_ + blockSize_ * curShiftNormal_;
                if ( curShiftNormal_ == shiftNormalLast_ ) isHaveNext_ = false;
            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        case IterateDirection::ColumnInvert:
            if ( colIndsPtrsIterRev_ + 1 < colIndsPtrsEndRev_ ) {
                ++colIndsPtrsIterRev_;
                curRowIndex_ = colIndsPtrsIterRev_->first;
                isInNormal_ = true;
                curData_ = colIndsPtrsIterRev_->second;
                isValid_ = true;
                if ( colIndsPtrsIterRev_ + 1 == colIndsPtrsEndRev_ && !curColumnIndsPtrsAlter_->size() )
                    isHaveNext_ = false;
            }
            else if ( curColumnIndsPtrsAlter_->size() && colIndsPtrsAlterIterRev_ + 1 < colIndsPtrsAlterEndRev_ ) {
                ++colIndsPtrsAlterIterRev_;
                curRowIndex_ = colIndsPtrsAlterIterRev_->first;
                isInNormal_ = false;
                curData_ = colIndsPtrsAlterIterRev_->second;
                isValid_ = true;
                if ( colIndsPtrsAlterIterRev_ + 1 == colIndsPtrsAlterEndRev_ ) isHaveNext_ = false;
            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        default:
            throw std::runtime_error ( "Unhandled behavior" );
            break;
        }
    }//type_ != UP_TREANGLE_MATRIX
    return isValid_;
}

template <int dim>
double *sbfStiffMatrixBlockIterator<dim>::data() const
{
    return curData_;
}

template <int dim>
double *sbfStiffMatrixBlockIterator<dim>::data ( bool *isInNormal ) const
{
    *isInNormal = isInNormal_;
    return curData_;
}

template <int dim>
bool sbfStiffMatrixBlockIterator<dim>::isDiagonal() const
{
    if ( curRowIndex_ == curColumnIndex_ ) return true;
    return false;
}

template <int dim>
bool sbfStiffMatrixBlockIterator<dim>::isInNormal() const
{
    return isInNormal_;
}

template <int dim>
double *sbfStiffMatrixBlockIterator<dim>::diagonal ( const int index ) const
{
    //Diagonal should be always be in normal storage
    int shiftStop = shiftsRowNormal_[index + 1];
    shiftStop--;
    if ( columnsByRowsNormal_[shiftStop] == index )
        //Wow! I find it at once!!! I gess it is low triangle matrix.
        return base_ + blockSize_ * ( shiftStop );
    int shiftStart = shiftsRowNormal_[index];
    if ( columnsByRowsNormal_[shiftStart] == index )
        //Cool it's first element. Mmmm.. Upper diagonal? Strange...
        return base_ + blockSize_ * shiftStart;
    //Well, I'll go through all blocks :( And I do not like it!
    for ( int ct = shiftStart + 1; ct < shiftStop; ct++ )
        if ( columnsByRowsNormal_[ct] == index )
            //Gosh, I'm almost lost a hope!
            return base_ + blockSize_ * ct;
    //It is not possible!!! I'm unhappy! So many work and what?! Thiere is no diagonal element! Take your NULL and do not bring me such a bad data!
    return nullptr;
}

template class sbfStiffMatrixBlockIterator<3>;
template class sbfStiffMatrixBlockIterator<6>;
