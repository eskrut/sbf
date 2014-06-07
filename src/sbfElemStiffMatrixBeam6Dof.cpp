#include "sbfElemStiffMatrixBeam6Dof.h"

sbfElemStiffMatrixBeam6Dof::sbfElemStiffMatrixBeam6Dof(sbfElement *elem, sbfPropertiesSet *propSet) :
    sbfElemStiffMatrix(elem, propSet)
{
}

void sbfElemStiffMatrixBeam6Dof::init()
{
    data_ = new double [numNodes_*numNodes_*numDOF_*numDOF_];
    crd_ = new double [numNodes_*3];
    ind_ = new int [numNodes_];
    h_ = new double [numNodes_];
    dhdn_ = new double [numNodes_];
    dhdg_ = new double [numNodes_*3];
    temp_ = new double [numNodes_*3*6];
}

void sbfElemStiffMatrixBeam6Dof::clean()
{
    if (data_) {delete data_; data_ = nullptr;}
    if (crd_) {delete crd_; crd_ = nullptr;}
    if (ind_) {delete ind_; ind_ = nullptr;}
    if (h_) {delete h_; h_ = nullptr;}
    if (dhdn_) {delete dhdn_; dhdn_ = nullptr;}
    if (dhdg_) {delete dhdg_; dhdg_ = nullptr;}
    if (temp_) {delete temp_; temp_ = nullptr;}
}

void sbfElemStiffMatrixBeam6Dof::computeH(double r)
{
    h_[0] = (1 - r) / 2.0;
    h_[1] = (1 + r) / 2.0;
}

void sbfElemStiffMatrixBeam6Dof::computeDHDN(double r)
{
//    dhdn_[0] =
}

void sbfElemStiffMatrixBeam6Dof::computeDHDG()
{

}

void sbfElemStiffMatrixBeam6Dof::computeJ()
{

}

void sbfElemStiffMatrixBeam6Dof::computeSM()
{

}
