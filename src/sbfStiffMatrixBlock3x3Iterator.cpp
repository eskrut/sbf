#include "sbfStiffMatrixBlock3x3Iterator.h"
#include <stdexcept>

//TODO This all may have poor efficiency

sbfStiffMatrixBlock3x3Iterator::sbfStiffMatrixBlock3x3Iterator(sbfStiffMatrixBlock3x3 *matrix) :
    matrix_(matrix),
    type_(matrix->type()),
    isInNormal_(false),
    isHaveNext_(false),
    isValid_(false)
{
    columnsByRowsNormal_ = const_cast<int *>(matrix->indData());
    shiftsRowNormal_ = const_cast<int *>(matrix->shiftIndData());
    columnsByRowsAlter_ = const_cast<int *>(matrix->indDataAlter());
    shiftsRowAlter_ = const_cast<int *>(matrix->shiftIndDataAlter());
    blocksByRowsAlter_ = matrix->ptrDataAlter();
    base_ = const_cast<double *>(matrix->data());
}

void sbfStiffMatrixBlock3x3Iterator::setToRow(const int rowIndex)
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
            curColumnIndex_ = columnsByRowsNormal_[curShiftNormal_];
            isInNormal_ = true;
            curData_ = base_ + blockSize_*curShiftNormal_;
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
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX
}

void sbfStiffMatrixBlock3x3Iterator::setToColumn(const int columnIndex)
{
    curColumnIndex_ = columnIndex;
    dir_ = IterateDirection::ColumnDirect;
    curShiftNormal_ = shiftsRowNormal_[curColumnIndex_];
    shiftNormalLast_ = shiftsRowNormal_[curColumnIndex_ + 1];
    if (shiftsRowAlter_) {
        curShiftAlter_ = shiftsRowAlter_[curColumnIndex_];
        shiftAlterLast_ = shiftsRowAlter_[curColumnIndex_ + 1];
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
            curRowIndex_ = columnsByRowsNormal_[curShiftNormal_];
            isInNormal_ = false;
            curData_ = base_ + blockSize_*curShiftNormal_;
            isValid_ = true;
        }
        else {
            curRowIndex_ = columnsByRowsAlter_[curShiftAlter_];
            isInNormal_ = true;
            curData_ = blocksByRowsAlter_[curShiftAlter_];
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX
}

void sbfStiffMatrixBlock3x3Iterator::setToRowInverse(const int rowIndex)
{
    //Since matrix have symmetry, this will actually iterate over row
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
            curData_ = base_ + blockSize_*curShiftNormal_;
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX
}

void sbfStiffMatrixBlock3x3Iterator::setToColumnInverse(const int columnIndex)
{
    //Since matrix have symmetry, this will actually iterate over row
    curColumnIndex_ = columnIndex;
    dir_ = IterateDirection::ColumnInvert;
    curShiftNormal_ = shiftsRowNormal_[curColumnIndex_ + 1] - 1;
    shiftNormalLast_ = shiftsRowNormal_[curColumnIndex_];
    if (shiftsRowAlter_) {
        curShiftAlter_ = shiftsRowAlter_[curColumnIndex_ + 1];
        shiftAlterLast_ = shiftsRowAlter_[curColumnIndex_];
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
            curRowIndex_ = columnsByRowsAlter_[curShiftAlter_];
            isInNormal_ = true;
            curData_ = blocksByRowsAlter_[curShiftAlter_];
            isValid_ = true;
            //Litle hack to perform next()
            curShiftNormal_++;
        }
        else {
            curRowIndex_ = columnsByRowsNormal_[curShiftNormal_];
            isInNormal_ = false;
            curData_ = base_ + blockSize_*curShiftNormal_;
            isValid_ = true;
        }
    }//type_ != UP_TREANGLE_MATRIX
    else {//type_ == UP_TREANGLE_MATRIX
        throw std::runtime_error("Not implemented yet :(");
    }//type_ == UP_TREANGLE_MATRIX
}

bool sbfStiffMatrixBlock3x3Iterator::isValid() const
{
    return isValid_;
}

bool sbfStiffMatrixBlock3x3Iterator::haveNext() const
{
    return isHaveNext_;
}

bool sbfStiffMatrixBlock3x3Iterator::next()
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
                curColumnIndex_ = columnsByRowsNormal_[curShiftNormal_];
                curData_ = base_ + blockSize_*curShiftNormal_;
                if ( curShiftNormal_+1 == shiftNormalLast_ ) isHaveNext_ = false;
            }
            else if ( curShiftAlter_ != shiftAlterLast_ ) {
                if (isInNormal_) {
                    isInNormal_ = false;
                    curShiftAlter_--;//For first block only
                }
                curShiftAlter_++;
                curColumnIndex_ = columnsByRowsAlter_[curShiftAlter_];
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
            if ( !isInNormal_ && ++curShiftNormal_ != shiftNormalLast_) {
                curRowIndex_ = columnsByRowsNormal_[curShiftNormal_];
                curData_ = base_ + blockSize_*curShiftNormal_;
                if ( curShiftNormal_+1 == shiftNormalLast_ ) isHaveNext_ = false;
            }
            else if ( curShiftAlter_ != shiftAlterLast_ ) {
                if (!isInNormal_) {
                    isInNormal_ = true;
                    curShiftAlter_--;//For first block only
                }
                curShiftAlter_++;
                curRowIndex_ = columnsByRowsAlter_[curShiftAlter_];
                curData_ = blocksByRowsAlter_[curShiftAlter_];
                if ( curShiftAlter_+1 == shiftAlterLast_ ) isHaveNext_ = false;
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
                if(!isInNormal_)
                    isInNormal_ = true;
                curColumnIndex_ = columnsByRowsNormal_[curShiftNormal_];
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
            if ( isInNormal_ && --curShiftAlter_ >= shiftAlterLast_ ) {
                curRowIndex_ = columnsByRowsAlter_[curShiftAlter_];
                curData_ = blocksByRowsAlter_[curShiftAlter_];
            }
            else if ( curShiftNormal_-- >= shiftNormalLast_ ) {
                if(isInNormal_)
                    isInNormal_ = false;
                curRowIndex_ = columnsByRowsNormal_[curShiftNormal_];
                curData_ = base_ + blockSize_*curShiftNormal_;
                if ( curShiftNormal_ == shiftNormalLast_ ) isHaveNext_ = false;
            }
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

double * sbfStiffMatrixBlock3x3Iterator::sbfStiffMatrixBlock3x3Iterator::data() const
{
    return curData_;
}

double *sbfStiffMatrixBlock3x3Iterator::data(bool *isInNormal) const
{
    *isInNormal = isInNormal_;
    return curData_;
}

bool sbfStiffMatrixBlock3x3Iterator::isDiagonal() const
{
    if (curRowIndex_ == curColumnIndex_) return true;
    return false;
}

bool sbfStiffMatrixBlock3x3Iterator::isInNormal() const
{
    return isInNormal_;
}

double *sbfStiffMatrixBlock3x3Iterator::diagonal(const int index) const
{
    //Diagonal should be always be in normal storage
    int shiftStop = shiftsRowNormal_[index+1];
    shiftStop--;
    if(columnsByRowsNormal_[shiftStop] == index)
        //Wow! I find it at once!!! I gess it is low triangle matrix.
        return base_ + blockSize_*(shiftStop);
    int shiftStart = shiftsRowNormal_[index];
    if(columnsByRowsNormal_[shiftStart] == index)
        //Cool it's first element. Mmmm.. Upper diagonal? Strange...
        return base_ + blockSize_*shiftStart;
    //Well, I'll go through all blocks :( And I do not like it!
    for(int ct = shiftStart + 1; ct < shiftStop; ct++)
        if(columnsByRowsNormal_[ct] == index)
            //Gosh, I'm almost lost a hope!
            return base_ + blockSize_*ct;
    //It is not possible!!! I'm unhappy! So many work and what?! Thiere is no diagonal element! Take your NULL and do not bring me such a bad data!
    return nullptr;
}
