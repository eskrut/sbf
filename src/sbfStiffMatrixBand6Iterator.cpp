#include "sbfStiffMatrixBand6Iterator.h"

sbfStiffMatrixBand6Iterator::sbfStiffMatrixBand6Iterator(sbfStiffMatrixBand6 *matrix) :
    sbfMatrixIterator(matrix),
    type_(matrix->type()),
    isInNormal_(false),
    isHaveNext_(false),
    isValid_(false),
    columnsIndsPtrs_(matrix->columnsIndsPtrs_),
    columnsIndsPtrsAlter_(matrix->columnsIndsPtrsAlter_),
    curColumnIndsPtrs_(nullptr),
    curColumnIndsPtrsAlter_(nullptr)
{
    columnsByRowsNormal_ = matrix->indJ_;
    shiftsRowNormal_ = matrix->shiftInd_;
    columnsByRowsAlter_ = matrix->indJAlter_;
    shiftsRowAlter_ = matrix->shiftIndAlter_;
    blocksByRowsAlter_ = matrix->ptrDataAlter_;
    base_ = matrix->data_;
}

void sbfStiffMatrixBand6Iterator::setToRow(const int rowIndex)
{
    curRowIndex_ = rowIndex;
    dir_ = IterateDirection::RowDirect;
    curShiftNormal_ = shiftsRowNormal_[curRowIndex_];
    shiftNormalLast_ = shiftsRowNormal_[curRowIndex_ + 1];
    if (shiftsRowAlter_) {
        curShiftAlter_ = shiftsRowAlter_[curRowIndex_];
        shiftAlterLast_ = shiftsRowAlter_[curRowIndex_ + 1];
    }
    else {
        curShiftAlter_ = shiftAlterLast_ = -1;
    }
    if (curShiftNormal_ == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_)
        isHaveNext_ = false;
    else
        isHaveNext_ = true;

    if ( !(type_ & UP_TREANGLE_MATRIX) ) {
        if ( curShiftNormal_ != shiftNormalLast_ ) {
            curColumnIndex_ = columnsByRowsNormal_[rowIndex*2];
            isInNormal_ = true;
            curData_ = base_ + blockSize_*curShiftNormal_;
            isValid_ = true;
        }
        else {
            curColumnIndex_ = columnsByRowsAlter_[rowIndex*2];
            isInNormal_ = false;
            curData_ = blocksByRowsAlter_[curShiftAlter_];
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX
    curColumnIndsPtrs_ = nullptr;
    curColumnIndsPtrsAlter_ = nullptr;
}

void sbfStiffMatrixBand6Iterator::setToColumn(const int columnIndex)
{
    curColumnIndsPtrs_ = &(columnsIndsPtrs_[columnIndex]);
    curColumnIndsPtrsAlter_ = &(columnsIndsPtrsAlter_[columnIndex]);
    colIndsPtrsIter_ = curColumnIndsPtrs_->begin();
    colIndsPtrsAlterIter_ = curColumnIndsPtrsAlter_->begin();
    colIndsPtrsEnd_ = curColumnIndsPtrs_->end();
    colIndsPtrsAlterEnd_ = curColumnIndsPtrsAlter_->end();
    curColumnIndex_ = columnIndex;
    dir_ = IterateDirection::ColumnDirect;

//    if ( colIndsPtrsIter_+1 < colIndsPtrsEnd_ || colIndsPtrsAlterIter_ < colIndsPtrsAlterEnd_ )
    if (
            (
                colIndsPtrsAlterIter_ == colIndsPtrsAlterEnd_ && colIndsPtrsIter_+1 < colIndsPtrsEnd_
                ) || (
                colIndsPtrsAlterIter_+1 == colIndsPtrsAlterEnd_ && colIndsPtrsIter_ < colIndsPtrsEnd_
                ) || (
                colIndsPtrsAlterIter_+1 < colIndsPtrsAlterEnd_ || colIndsPtrsIter_+1 < colIndsPtrsEnd_
                )
            )
        isHaveNext_ = true;
    else
        isHaveNext_ = false;
    if ( !(type_ & UP_TREANGLE_MATRIX) ) {
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
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX

//    //Since matrix have symmetry, this will actually iterate over row
//    curColumnIndex_ = columnIndex;
//    dir_ = IterateDirection::ColumnDirect;
//    curShiftNormal_ = shiftsRowNormal_[curColumnIndex_];
//    shiftNormalLast_ = shiftsRowNormal_[curColumnIndex_ + 1];
//    if (shiftsRowAlter_) {
//        curShiftAlter_ = shiftsRowAlter_[curColumnIndex_];
//        shiftAlterLast_ = shiftsRowAlter_[curColumnIndex_ + 1];
//    }
//    else {
//        curShiftAlter_ = shiftAlterLast_ = -1;
//    }
//    if (curShiftNormal_ == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_)
//        isHaveNext_ = false;
//    else
//        isHaveNext_ = true;

//    if ( !(type_ & UP_TREANGLE_MATRIX) ) {
//        if ( curShiftNormal_ != shiftNormalLast_ ) {
//            curRowIndex_ = columnsByRowsNormal_[columnIndex*2];
//            isInNormal_ = false;
//            curData_ = base_ + blockSize_*curShiftNormal_;
//            isValid_ = true;
//        }
//        else {
//            curRowIndex_ = columnsByRowsAlter_[columnIndex*2];
//            isInNormal_ = true;
//            curData_ = blocksByRowsAlter_[curShiftAlter_];
//            isValid_ = true;
//        }
//    }//type_ != UP_TREANGLE_MATRIX
//    else {//type_ == UP_TREANGLE_MATRIX
//        throw std::runtime_error("Not implemented yet :(");
//    }//type_ == UP_TREANGLE_MATRIX
}

void sbfStiffMatrixBand6Iterator::setToRowInverse(const int rowIndex)
{
    curRowIndex_ = rowIndex;
    dir_ = IterateDirection::RowInvert;
    curShiftNormal_ = shiftsRowNormal_[curRowIndex_ + 1] - 1;
    shiftNormalLast_ = shiftsRowNormal_[curRowIndex_];
    if (shiftsRowAlter_) {
        curShiftAlter_ = shiftsRowAlter_[curRowIndex_ + 1];
        shiftAlterLast_ = shiftsRowAlter_[curRowIndex_];
    }
    else {
        curShiftAlter_ = shiftAlterLast_ = -1;
    }
    if (curShiftNormal_ == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_)
        isHaveNext_ = false;
    else
        isHaveNext_ = true;

    if ( !(type_ & UP_TREANGLE_MATRIX) ) {
        if ( --curShiftAlter_ >= shiftAlterLast_ ) {
            curColumnIndex_ = columnsByRowsAlter_[rowIndex*2+1];
            isInNormal_ = false;
            curData_ = blocksByRowsAlter_[curShiftAlter_];
            isValid_ = true;
            //Litle hack to perform next()
            curShiftNormal_++;
        }
        else {
            curColumnIndex_ = columnsByRowsNormal_[rowIndex*2+1];
            isInNormal_ = true;
            curData_ = base_ + blockSize_*curShiftNormal_;
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX
    curColumnIndsPtrs_ = nullptr;
    curColumnIndsPtrsAlter_ = nullptr;
}

void sbfStiffMatrixBand6Iterator::setToColumnInverse(const int columnIndex)
{
    curColumnIndsPtrs_ = &(columnsIndsPtrs_[columnIndex]);
    curColumnIndsPtrsAlter_ = &(columnsIndsPtrsAlter_[columnIndex]);
    colIndsPtrsIterRev_ = curColumnIndsPtrs_->rbegin();
    colIndsPtrsAlterIterRev_ = curColumnIndsPtrsAlter_->rbegin();
    colIndsPtrsEndRev_ = curColumnIndsPtrs_->rend();
    colIndsPtrsAlterEndRev_ = curColumnIndsPtrsAlter_->rend();
    curColumnIndex_ = columnIndex;
    dir_ = IterateDirection::ColumnInvert;

//    if ( colIndsPtrsIterRev_+1 < colIndsPtrsEndRev_ || colIndsPtrsAlterIterRev_+1 < colIndsPtrsAlterEndRev_ )
    if (
            (
                colIndsPtrsAlterIterRev_ == colIndsPtrsAlterEndRev_ && colIndsPtrsIterRev_+1 < colIndsPtrsEndRev_
                ) || (
                colIndsPtrsAlterIterRev_+1 == colIndsPtrsAlterEndRev_ && colIndsPtrsIterRev_ < colIndsPtrsEndRev_
                ) || (
                colIndsPtrsAlterIterRev_+1 < colIndsPtrsAlterEndRev_ || colIndsPtrsIterRev_+1 < colIndsPtrsEndRev_
                )
            )
        isHaveNext_ = true;
    else
        isHaveNext_ = false;
    if ( !(type_ & UP_TREANGLE_MATRIX) ) {
        if ( colIndsPtrsIterRev_ != colIndsPtrsEndRev_ ) {
            curRowIndex_ = colIndsPtrsIterRev_->first;
            isInNormal_ = true;
            curData_ = colIndsPtrsIterRev_->second;
            isValid_ = true;
            //To make increment in next()
            if(colIndsPtrsAlterIterRev_ != colIndsPtrsAlterEndRev_)
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
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX
//    //Since matrix have symmetry, this will actually iterate over row
//    curColumnIndex_ = columnIndex;
//    dir_ = IterateDirection::ColumnInvert;
//    curShiftNormal_ = shiftsRowNormal_[curColumnIndex_ + 1] - 1;
//    shiftNormalLast_ = shiftsRowNormal_[curColumnIndex_];
//    if (shiftsRowAlter_) {
//        curShiftAlter_ = shiftsRowAlter_[curColumnIndex_ + 1];
//        shiftAlterLast_ = shiftsRowAlter_[curColumnIndex_];
//    }
//    else {
//        curShiftAlter_ = shiftAlterLast_ = -1;
//    }
//    if (curShiftNormal_ == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_)
//        isHaveNext_ = false;
//    else
//        isHaveNext_ = true;

//    if ( !(type_ & UP_TREANGLE_MATRIX) ) {
//        if ( --curShiftAlter_ >= shiftAlterLast_ ) {
//            curRowIndex_ = columnsByRowsAlter_[columnIndex*2+1];
//            isInNormal_ = true;
//            curData_ = blocksByRowsAlter_[curShiftAlter_];
//            isValid_ = true;
//            //Litle hack to perform next()
//            curShiftNormal_++;
//        }
//        else {
//            curRowIndex_ = columnsByRowsNormal_[columnIndex*2+1];
//            isInNormal_ = false;
//            curData_ = base_ + blockSize_*curShiftNormal_;
//            isValid_ = true;
//        }
//    }//type_ != UP_TREANGLE_MATRIX
//    else {//type_ == UP_TREANGLE_MATRIX
//        throw std::runtime_error("Not implemented yet :(");
//    }//type_ == UP_TREANGLE_MATRIX
}

bool sbfStiffMatrixBand6Iterator::isValid() const
{
    return isValid_;
}

bool sbfStiffMatrixBand6Iterator::haveNext() const
{
    return isHaveNext_;
}

bool sbfStiffMatrixBand6Iterator::next()
{
    if (!isHaveNext_){
        isValid_ = false;
        return false;
    }
    isValid_ = true;
    if ( !(type_ & UP_TREANGLE_MATRIX) ) {
        switch (dir_) {
        case IterateDirection::RowDirect:
            if ( isInNormal_ && ++curShiftNormal_ != shiftNormalLast_) {
                ++curColumnIndex_;
                curData_ = base_ + blockSize_*curShiftNormal_;
                if ( curShiftNormal_+1 == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_) isHaveNext_ = false;
            }
            else if ( curShiftAlter_ != shiftAlterLast_ ) {
                if (isInNormal_) {
                    isInNormal_ = false;
                    curShiftAlter_--;//For first block only
                }
                ++curShiftAlter_;
                ++curColumnIndex_;
                curData_ = blocksByRowsAlter_[curShiftAlter_];
                if ( curShiftAlter_+1 == shiftAlterLast_ ) isHaveNext_ = false;
            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        case IterateDirection::ColumnDirect:
            if( curColumnIndsPtrsAlter_->size() && colIndsPtrsAlterIter_ +1 < colIndsPtrsAlterEnd_ ) {
                ++colIndsPtrsAlterIter_;
                curRowIndex_ = colIndsPtrsAlterIter_->first;
                isInNormal_ = false;
                curData_ = colIndsPtrsAlterIter_->second;
                isValid_ = true;
            }
            else if( colIndsPtrsIter_ +1 < colIndsPtrsEnd_ ) {
                ++colIndsPtrsIter_;
                curRowIndex_ = colIndsPtrsIter_->first;
                isInNormal_ = true;
                curData_ = colIndsPtrsIter_->second;
                isValid_ = true;
            }
//            if ( !isInNormal_ && ++curShiftNormal_ != shiftNormalLast_) {
//                ++curRowIndex_;
//                curData_ = base_ + blockSize_*curShiftNormal_;
//                if ( curShiftNormal_+1 == shiftNormalLast_ && curShiftAlter_ == shiftAlterLast_ ) isHaveNext_ = false;
//            }
//            else if ( curShiftAlter_ != shiftAlterLast_ ) {
//                if (!isInNormal_) {
//                    isInNormal_ = true;
//                    curShiftAlter_--;//For first block only
//                }
//                ++curShiftAlter_;
//                ++curRowIndex_;
//                curData_ = blocksByRowsAlter_[curShiftAlter_];
//                if ( curShiftAlter_+1 == shiftAlterLast_ ) isHaveNext_ = false;
//            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        case IterateDirection::RowInvert:
            if ( !isInNormal_ && --curShiftAlter_ >= shiftAlterLast_ ) {
                --curColumnIndex_;
                curData_ = blocksByRowsAlter_[curShiftAlter_];
            }
            else if ( curShiftNormal_-- >= shiftNormalLast_ ) {
                if(!isInNormal_)
                    isInNormal_ = true;
                --curColumnIndex_;
                curData_ = base_ + blockSize_*curShiftNormal_;
                if ( curShiftNormal_ == shiftNormalLast_ ) isHaveNext_ = false;
            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        case IterateDirection::ColumnInvert:
            if( colIndsPtrsIterRev_ +1 < colIndsPtrsEndRev_ ) {
                ++colIndsPtrsIterRev_;
                curRowIndex_ = colIndsPtrsIterRev_->first;
                isInNormal_ = true;
                curData_ = colIndsPtrsIterRev_->second;
                isValid_ = true;
            }
            else if( curColumnIndsPtrsAlter_->size() && colIndsPtrsAlterIterRev_ +1 < colIndsPtrsAlterEndRev_ ) {
                ++colIndsPtrsAlterIterRev_;
                curRowIndex_ = colIndsPtrsAlterIterRev_->first;
                isInNormal_ = false;
                curData_ = colIndsPtrsAlterIterRev_->second;
                isValid_ = true;
            }
//            if ( isInNormal_ && --curShiftAlter_ >= shiftAlterLast_ ) {
//                --curRowIndex_;
//                curData_ = blocksByRowsAlter_[curShiftAlter_];
//            }
//            else if ( curShiftNormal_-- >= shiftNormalLast_ ) {
//                if(isInNormal_)
//                    isInNormal_ = false;
//                --curRowIndex_;
//                curData_ = base_ + blockSize_*curShiftNormal_;
//                if ( curShiftNormal_ == shiftNormalLast_ ) isHaveNext_ = false;
//            }
            else {
                curData_ = nullptr;
                isHaveNext_ = false;
                isValid_ = false;
            }
            break;
        default:
            throw std::runtime_error("Unhandled behavior");
            break;
        }
    }//type_ != UP_TREANGLE_MATRIX
    return isValid_;
}

double *sbfStiffMatrixBand6Iterator::data() const
{
    return curData_;
}

double *sbfStiffMatrixBand6Iterator::data(bool *isInNormal) const
{
    *isInNormal = isInNormal_;
    return curData_;
}

bool sbfStiffMatrixBand6Iterator::isDiagonal() const
{
    if (curRowIndex_ == curColumnIndex_) return true;
    return false;
}

bool sbfStiffMatrixBand6Iterator::isInNormal() const
{
    return isInNormal_;
}

double *sbfStiffMatrixBand6Iterator::diagonal(const int index) const
{
    //Diagonal should be always be in normal storage
    if ( columnsByRowsNormal_[index*2 + 1] == index )
        //As I expected, we deal with low triangle matrix!
        return base_ + blockSize_*(shiftsRowNormal_[index+1]-1);
    if ( columnsByRowsNormal_[index*2] == index )
        //Still OK, this is probably up triangle matrix
        return base_ + blockSize_*(shiftsRowNormal_[index]);
    //Hmmm... A full matrix?
    if ( index < columnsByRowsNormal_[index*2] || index > columnsByRowsNormal_[index*2+1])
        //Imposible!
        return nullptr;
    //May be I should return this one and do not make all work abowe?
    return base_ + blockSize_*(shiftsRowNormal_[index] + index - columnsByRowsNormal_[index*2]);
}
