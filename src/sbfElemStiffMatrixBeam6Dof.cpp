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

    double cosA = (crd_[3] - crd_[0])/L;
    if(cosA == 1.0) return;
    double rot[3] = {0, -(crd_[5] - crd_[2]), crd_[4] - crd_[1]};
    double norm = std::sqrt( std::pow(rot[1], 2.0) + std::pow(rot[2], 2.0) );
    rot[1] /= norm; rot[2] /= norm;
    double angle = -std::fabs(std::acos(cosA));

    double cs = std::cos(angle);
    double sn = std::sin(angle);

    double t[3][3], dirx = rot[0], diry = rot[1], dirz = rot[2];

    t[0][0] = cs + dirx*dirx*(1.0f - cs);
    t[0][1] = dirx*diry*(1.0f - cs) - dirz*sn;
    t[0][2] = dirx*dirz*(1.0f - cs) + diry*sn;

    t[1][0] = dirx*diry*(1.0f - cs) + dirz*sn;
    t[1][1] = cs + diry*diry*(1.0f - cs);
    t[1][2] = diry*dirz*(1.0f - cs) - dirx*sn;

    t[2][0] = dirx*dirz*(1.0f - cs) - diry*sn;
    t[2][1] = diry*dirz*(1.0f - cs) + dirx*sn;
    t[2][2] = cs + dirz*dirz*(1.0f - cs);

    using SubBlocks = double [4][9];
    SubBlocks subBlocks;
    auto getSubBlocks = [](double *block, SubBlocks &subBlocks){
        for(int ct0 = 0; ct0 < 2; ++ct0)
            for (int ct1 = 0; ct1 < 2; ++ct1)
                for (int ct = 0; ct < 9; ++ct)
                    subBlocks[ct0*2 + ct1][ct] = block[ct0*6*3 + ct1*3 + (ct/3)*6 + ct%3];
    };
    auto setBlock = [](double *block, SubBlocks &subBlocks){
        for(int ct0 = 0; ct0 < 2; ++ct0)
            for (int ct1 = 0; ct1 < 2; ++ct1)
                for (int ct = 0; ct < 9; ++ct)
                    block[ct0*6*3 + ct1*3 + (ct/3)*6 + ct%3] = subBlocks[ct0*2 + ct1][ct];
    };
    for (int ctBlocks = 0; ctBlocks < 4; ++ctBlocks) {
        double *block = data_ + blockSize_*ctBlocks;
        getSubBlocks(block, subBlocks);
        for (int subCt = 0; subCt < 4; ++subCt) {
            double *sub = subBlocks[subCt];
            double temp[9]; for (int ct = 0; ct < 9; ++ct) temp[ct] = 0.0;

            for(int ct0 = 0; ct0 < 3; ++ct0)
                for (int ct1 = 0; ct1 < 3; ++ct1)
                    for (int ct2 = 0; ct2 < 3; ++ct2)
                        temp[ct0*3+ct1] += t[ct2][ct0]*sub[ct2*3+ct1];

            for (int ct = 0; ct < 9; ++ct) sub[ct] = 0.0;
            for(int ct0 = 0; ct0 < 3; ++ct0)
                for (int ct1 = 0; ct1 < 3; ++ct1)
                    for (int ct2 = 0; ct2 < 3; ++ct2)
                        sub[ct0*3+ct1] += temp[ct0*3+ct2]*t[ct2][ct1];
        }
        setBlock(block, subBlocks);
    }
}

sbfElemStiffMatrix::RowColData sbfElemStiffMatrixBeam6Dof::rowColData()
{
    RowColData rez;
    for(int rowCt = 0; rowCt < numNodes_; ++rowCt)
        for(int columnCt = 0; columnCt < numNodes_; ++columnCt)
            rez.push_back(std::make_pair(std::make_pair(ind_[rowCt], ind_[columnCt]), data_+(rowCt*numNodes_+columnCt)*blockSize_));
    return rez;
}
