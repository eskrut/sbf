#include "sbfElemStiffMatrixBeam6Dof.h"
#include "sbfPropertiesSet.h"
#include "sbfElement.h"
#include <cmath>

sbfElemStiffMatrixBeam6Dof::sbfElemStiffMatrixBeam6Dof(sbfElement *elem, sbfPropertiesSet *propSet) :
    sbfElemStiffMatrix(elem, propSet)
{
    init();
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

void sbfElemStiffMatrixBeam6Dof::computeSM()
{
    sbfMaterialProperties *mp = propSet_->material(elem_->mtr() - 1);
    double E = mp->propertyTable("elastic module")->curValue();
    double G = mp->propertyTable("shear module")->curValue();
    double A = mp->propertyTable("area")->curValue();
    double Ix = mp->propertyTable("Ix")->curValue();
    double Iy = mp->propertyTable("Iy")->curValue();
    double Iz = mp->propertyTable("Iz")->curValue();

    //FIXME - this is cheat!!!!
    double L = std::sqrt( std::pow(crd_[0] - crd_[3], 2.0) + std::pow(crd_[1] - crd_[4], 2.0) + std::pow(crd_[2] - crd_[5], 2.0) );
    double EA_L = E*A/L;
    double EIz12_L3 = 12*E*Iz/std::pow(L, 3.0);
    double EIy12_L3 = 12*E*Iy/std::pow(L, 3.0);
    double EIz6_L2 = 6*E*Iz/std::pow(L, 2.0);
    double EIy6_L2 = 6*E*Iy/std::pow(L, 2.0);
    double EIz4_L = 4*E*Iz/L;
    double EIy4_L = 4*E*Iy/L;
    double GIx_L = G*Ix/L;

    for(int ct = 0; ct < numNodes_*numNodes_*numDOF_*numDOF_; ++ct) data_[ct] = 0.0;
    double *d00 = data_ + blockSize_*0;
    double *d01 = data_ + blockSize_*1;
    double *d10 = data_ + blockSize_*2;
    double *d11 = data_ + blockSize_*3;

    int shift = 0;
    d00[shift] =  EA_L;
    d01[shift] = -EA_L;
    d10[shift] = -EA_L;
    d11[shift] =  EA_L;

    shift = numDOF_*3+3;
    d00[shift] =  GIx_L;
    d01[shift] = -GIx_L;
    d10[shift] = -GIx_L;
    d11[shift] =  GIx_L;

    shift = numDOF_*1+1;
    d00[shift] =  EIz12_L3;
    d01[shift] = -EIz12_L3;
    d10[shift] = -EIz12_L3;
    d11[shift] =  EIz12_L3;

    shift = numDOF_*2+2;
    d00[shift] =  EIy12_L3;
    d01[shift] = -EIy12_L3;
    d10[shift] = -EIy12_L3;
    d11[shift] =  EIy12_L3;

    shift = numDOF_*1+5;
    d00[shift] =  EIz6_L2;
    d01[shift]=  EIz6_L2;
    d10[shift] = -EIz6_L2;
    d11[shift]= -EIz6_L2;

    shift = numDOF_*2+4;
    d00[shift] = -EIy6_L2;
    d01[shift]= -EIy6_L2;
    d10[shift] =  EIy6_L2;
    d11[shift]=  EIy6_L2;

    shift = numDOF_*5+1;
    d00[shift] =  EIz6_L2;
    d01[shift] = -EIz6_L2;
    d10[shift]=  EIz6_L2;
    d11[shift]= -EIz6_L2;

    shift = numDOF_*4+2;
    d00[shift] = -EIy6_L2;
    d01[shift] =  EIy6_L2;
    d10[shift]= -EIy6_L2;
    d11[shift]=  EIy6_L2;

    shift = numDOF_*4+4;
    d00[shift]  =  EIy4_L;
    d01[shift] =  EIy4_L/2;
    d10[shift] =  EIy4_L/2;
    d11[shift]=  EIy4_L;

    shift = numDOF_*5+5;
    d00[shift]  =  EIz4_L;
    d01[shift] =  EIz4_L/2;
    d10[shift] =  EIz4_L/2;
    d11[shift]=  EIz4_L;

    //Rotate matrix
}

sbfElemStiffMatrix::RowColData sbfElemStiffMatrixBeam6Dof::rowColData()
{
    RowColData rez;
    for(int rowCt = 0; rowCt < numNodes_; ++rowCt)
        for(int columnCt = 0; columnCt < numNodes_; ++columnCt)
            rez.push_back(std::make_pair(std::make_pair(rowCt, columnCt), data_+(rowCt*numNodes_+columnCt)*blockSize_));
    return rez;
}
