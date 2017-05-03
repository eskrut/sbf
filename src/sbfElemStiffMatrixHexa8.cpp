#include "sbfElemStiffMatrixHexa8.h"

#include "sbfPropertiesSet.h"
#include "sbfElement.h"
#include <cmath>
#include "sbfReporter.h"

sbfElemStiffMatrixHexa8::sbfElemStiffMatrixHexa8(sbfElement *elem, sbfPropertiesSet *propSet) :
    sbfElemStiffMatrix(elem, propSet)
{
    init();
}

void sbfElemStiffMatrixHexa8::init()
{
    data_ = new double [numNodes_*numNodes_*numDOF_*numDOF_];
    crd_ = new double [numNodes_*3];
    ind_ = new int [numNodes_];
    h_ = new double [numNodes_];
    dhdn_ = new double [numNodes_*3];
    dhdg_ = new double [numNodes_*3];
    temp_ = new double [numNodes_*3*6];
    numIntPoints_ = 2;
}

void sbfElemStiffMatrixHexa8::clean()
{
    if (data_) {delete data_; data_ = nullptr;}
    if (crd_) {delete crd_; crd_ = nullptr;}
    if (ind_) {delete ind_; ind_ = nullptr;}
    if (h_) {delete h_; h_ = nullptr;}
    if (dhdn_) {delete dhdn_; dhdn_ = nullptr;}
    if (dhdg_) {delete dhdg_; dhdg_ = nullptr;}
    if (temp_) {delete temp_; temp_ = nullptr;}
}

void sbfElemStiffMatrixHexa8::computeH(double r, double s, double t)
{
    /*
     *Compute values of form functions at specific point in natural coordinates
     *h_[0] = h0(r, s, t), h_[1] = h1(r, s, t), etc.
     */
    double onePlusR = (1.+r);
    double oneMinusR = (1.-r);
    double onePlusS = (1.+s);
    double oneMinusS = (1.-s);
    double onePlusT = (1.+t);
    double oneMinusT = (1.-t);

    h_[0] = onePlusR*onePlusS*onePlusT/8.0;
    h_[3] = oneMinusR*onePlusS*onePlusT/8.0;
    h_[2] = oneMinusR*oneMinusS*onePlusT/8.0;
    h_[1] = onePlusR*oneMinusS*onePlusT/8.0;
    h_[4] = onePlusR*onePlusS*oneMinusT/8.0;
    h_[7] = oneMinusR*onePlusS*oneMinusT/8.0;
    h_[6] = oneMinusR*oneMinusS*oneMinusT/8.0;
    h_[5] = onePlusR*oneMinusS*oneMinusT/8.0;
}

void sbfElemStiffMatrixHexa8::computeDHDN(double r, double s, double t)
{
    /*
     * Compute values of form functions derivatives over natural coordinates at specific point in natural coordinates
     * dhdn_[0*3 + 0] = d h0 / d r, dhdn_[0*3 + 1] = d h0 / d s, dhdn_[0*3 + 2] = d h0 / d t, dhdn_[1*3 + 0] = d h1 / d r, etc.
     */
    double onePlusR = (1.+r);
    double oneMinusR = (1.-r);
    double onePlusS = (1.+s);
    double oneMinusS = (1.-s);
    double onePlusT = (1.+t);
    double oneMinusT = (1.-t);

    dhdn_[0] = onePlusS*onePlusT/8.0;//d h0 / d r
    dhdn_[1] = onePlusR*onePlusT/8.0;//d h0 / d s
    dhdn_[2] = onePlusR*onePlusS/8.0;//d h0 / d t
    dhdn_[9] = -onePlusS*onePlusT/8.0;//d h1 / d r
    dhdn_[10] = oneMinusR*onePlusT/8.0;
    dhdn_[11] = oneMinusR*onePlusS/8.0;
    dhdn_[6] = -oneMinusS*onePlusT/8.0;//d h2 / d r
    dhdn_[7] = -oneMinusR*onePlusT/8.0;
    dhdn_[8] = oneMinusR*oneMinusS/8.0;
    dhdn_[3] = oneMinusS*onePlusT/8.0;//d h3 / d r
    dhdn_[4] = -onePlusR*onePlusT/8.0;
    dhdn_[5] = onePlusR*oneMinusS/8.0;
    dhdn_[12] = onePlusS*oneMinusT/8.0;//d h4 / d r
    dhdn_[13] = onePlusR*oneMinusT/8.0;
    dhdn_[14] = -onePlusR*onePlusS/8.0;
    dhdn_[21] = -onePlusS*oneMinusT/8.0;//d h5 / d r
    dhdn_[22] = oneMinusR*oneMinusT/8.0;
    dhdn_[23] = -oneMinusR*onePlusS/8.0;
    dhdn_[18] = -oneMinusS*oneMinusT/8.0;//d h6 / d r
    dhdn_[19] = -oneMinusR*oneMinusT/8.0;
    dhdn_[20] = -oneMinusR*oneMinusS/8.0;
    dhdn_[15] = oneMinusS*oneMinusT/8.0;//d h7 / d r
    dhdn_[16] = -onePlusR*oneMinusT/8.0;
    dhdn_[17] = -onePlusR*oneMinusS/8.0;
}

void sbfElemStiffMatrixHexa8::computeDHDG()
{
    /*
     * Compute values of form functions derivatives over global coordinates at specific point in natural coordinates
     * dhdg_[0*3+0] = d h0 / d x = invJ_[0] * d h0 / d r + invJ_[1] * d h0 / d s + invJ_[2] * d h0 / d t.
     * dhdg_[0*3+1] = d h0 / d y. etc.
     */
    dhdg_[0] = invJ_[0]*dhdn_[0] + invJ_[1]*dhdn_[1] + invJ_[2]*dhdn_[2];//d h0 / d x
    dhdg_[1] = invJ_[3]*dhdn_[0] + invJ_[4]*dhdn_[1] + invJ_[5]*dhdn_[2];//d h0 / d y
    dhdg_[2] = invJ_[6]*dhdn_[0] + invJ_[7]*dhdn_[1] + invJ_[8]*dhdn_[2];//d h0 / d z
    dhdg_[3] = invJ_[0]*dhdn_[3] + invJ_[1]*dhdn_[4] + invJ_[2]*dhdn_[5];//d h1 / d x
    dhdg_[4] = invJ_[3]*dhdn_[3] + invJ_[4]*dhdn_[4] + invJ_[5]*dhdn_[5];
    dhdg_[5] = invJ_[6]*dhdn_[3] + invJ_[7]*dhdn_[4] + invJ_[8]*dhdn_[5];
    dhdg_[6] = invJ_[0]*dhdn_[6] + invJ_[1]*dhdn_[7] + invJ_[2]*dhdn_[8];//d h2 / d x
    dhdg_[7] = invJ_[3]*dhdn_[6] + invJ_[4]*dhdn_[7] + invJ_[5]*dhdn_[8];
    dhdg_[8] = invJ_[6]*dhdn_[6] + invJ_[7]*dhdn_[7] + invJ_[8]*dhdn_[8];
    dhdg_[9] = invJ_[0]*dhdn_[9] + invJ_[1]*dhdn_[10] + invJ_[2]*dhdn_[11];//d h3 / d x
    dhdg_[10] = invJ_[3]*dhdn_[9] + invJ_[4]*dhdn_[10] + invJ_[5]*dhdn_[11];
    dhdg_[11] = invJ_[6]*dhdn_[9] + invJ_[7]*dhdn_[10] + invJ_[8]*dhdn_[11];
    dhdg_[12] = invJ_[0]*dhdn_[12] + invJ_[1]*dhdn_[13] + invJ_[2]*dhdn_[14];//d h4 / d x
    dhdg_[13] = invJ_[3]*dhdn_[12] + invJ_[4]*dhdn_[13] + invJ_[5]*dhdn_[14];
    dhdg_[14] = invJ_[6]*dhdn_[12] + invJ_[7]*dhdn_[13] + invJ_[8]*dhdn_[14];
    dhdg_[15] = invJ_[0]*dhdn_[15] + invJ_[1]*dhdn_[16] + invJ_[2]*dhdn_[17];//d h5 / d x
    dhdg_[16] = invJ_[3]*dhdn_[15] + invJ_[4]*dhdn_[16] + invJ_[5]*dhdn_[17];
    dhdg_[17] = invJ_[6]*dhdn_[15] + invJ_[7]*dhdn_[16] + invJ_[8]*dhdn_[17];
    dhdg_[18] = invJ_[0]*dhdn_[18] + invJ_[1]*dhdn_[19] + invJ_[2]*dhdn_[20];//d h6 / d x
    dhdg_[19] = invJ_[3]*dhdn_[18] + invJ_[4]*dhdn_[19] + invJ_[5]*dhdn_[20];
    dhdg_[20] = invJ_[6]*dhdn_[18] + invJ_[7]*dhdn_[19] + invJ_[8]*dhdn_[20];
    dhdg_[21] = invJ_[0]*dhdn_[21] + invJ_[1]*dhdn_[22] + invJ_[2]*dhdn_[23];//d h7 / d x
    dhdg_[22] = invJ_[3]*dhdn_[21] + invJ_[4]*dhdn_[22] + invJ_[5]*dhdn_[23];
    dhdg_[23] = invJ_[6]*dhdn_[21] + invJ_[7]*dhdn_[22] + invJ_[8]*dhdn_[23];
}

void sbfElemStiffMatrixHexa8::computeJ()
{
    /*
     * Compute Jacobian and its determinant. computeDHDN(r, s, t) should be performed before !
     * J_[0] = d x / d r = d h_i / d r * x_i, J_[1] = d h_i / d r * y_i, J_[2] = d h_i / d r * z_i, J_[3] = d h_i / d s * x_i
     */
    J_[0] = dhdn_[0]*crd_[0] + dhdn_[3]*crd_[1] + dhdn_[6]*crd_[2] + dhdn_[9]*crd_[3] + dhdn_[12]*crd_[4] + dhdn_[15]*crd_[5] + dhdn_[18]*crd_[6] + dhdn_[21]*crd_[7];
    J_[1] = dhdn_[0]*crd_[8] + dhdn_[3]*crd_[9] + dhdn_[6]*crd_[10] + dhdn_[9]*crd_[11] + dhdn_[12]*crd_[12] + dhdn_[15]*crd_[13] + dhdn_[18]*crd_[14] + dhdn_[21]*crd_[15];
    J_[2] = dhdn_[0]*crd_[16] + dhdn_[3]*crd_[17] + dhdn_[6]*crd_[18] + dhdn_[9]*crd_[19] + dhdn_[12]*crd_[20] + dhdn_[15]*crd_[21] + dhdn_[18]*crd_[22] + dhdn_[21]*crd_[23];
    J_[3] = dhdn_[1]*crd_[0] + dhdn_[4]*crd_[1] + dhdn_[7]*crd_[2] + dhdn_[10]*crd_[3] + dhdn_[13]*crd_[4] + dhdn_[16]*crd_[5] + dhdn_[19]*crd_[6] + dhdn_[22]*crd_[7];
    J_[4] = dhdn_[1]*crd_[8] + dhdn_[4]*crd_[9] + dhdn_[7]*crd_[10] + dhdn_[10]*crd_[11] + dhdn_[13]*crd_[12] + dhdn_[16]*crd_[13] + dhdn_[19]*crd_[14] + dhdn_[22]*crd_[15];
    J_[5] = dhdn_[1]*crd_[16] + dhdn_[4]*crd_[17] + dhdn_[7]*crd_[18] + dhdn_[10]*crd_[19] + dhdn_[13]*crd_[20] + dhdn_[16]*crd_[21] + dhdn_[19]*crd_[22] + dhdn_[22]*crd_[23];
    J_[6] = dhdn_[2]*crd_[0] + dhdn_[5]*crd_[1] + dhdn_[8]*crd_[2] + dhdn_[11]*crd_[3] + dhdn_[14]*crd_[4] + dhdn_[17]*crd_[5] + dhdn_[20]*crd_[6] + dhdn_[23]*crd_[7];
    J_[7] = dhdn_[2]*crd_[8] + dhdn_[5]*crd_[9] + dhdn_[8]*crd_[10] + dhdn_[11]*crd_[11] + dhdn_[14]*crd_[12] + dhdn_[17]*crd_[13] + dhdn_[20]*crd_[14] + dhdn_[23]*crd_[15];
    J_[8] = dhdn_[2]*crd_[16] + dhdn_[5]*crd_[17] + dhdn_[8]*crd_[18] + dhdn_[11]*crd_[19] + dhdn_[14]*crd_[20] + dhdn_[17]*crd_[21] + dhdn_[20]*crd_[22] + dhdn_[23]*crd_[23];
    detJ_ = J_[0]*J_[4]*J_[8] + J_[1]*J_[5]*J_[6] + J_[2]*J_[3]*J_[7] - J_[2]*J_[4]*J_[6] - J_[0]*J_[5]*J_[7] - J_[1]*J_[3]*J_[8];
    invJ_[0] = (J_[4]*J_[8] - J_[5]*J_[7])/detJ_;
    invJ_[1] = (J_[2]*J_[7] - J_[1]*J_[8])/detJ_;
    invJ_[2] = (J_[1]*J_[5] - J_[2]*J_[4])/detJ_;
    invJ_[3] = (J_[5]*J_[6] - J_[3]*J_[8])/detJ_;
    invJ_[4] = (J_[0]*J_[8] - J_[2]*J_[6])/detJ_;
    invJ_[5] = (J_[2]*J_[3] - J_[0]*J_[5])/detJ_;
    invJ_[6] = (J_[3]*J_[7] - J_[4]*J_[6])/detJ_;
    invJ_[7] = (J_[1]*J_[6] - J_[0]*J_[7])/detJ_;
    invJ_[8] = (J_[0]*J_[4] - J_[1]*J_[3])/detJ_;
}

void sbfElemStiffMatrixHexa8::computeSM()
{
    /*
     * Compute stiffness matrix of element
     */

    if(propSet_ == nullptr)
    {
        /*Throw an exception*/
        debugMsg("ERROR!!! properties are not set correctly!!!");
        return;
    }

    sbfMaterialProperties *mp = propSet_->material(elem_->mtr() - 1);
    double E = mp->propertyTable("elastic module")->curValue();
    double mu = mp->propertyTable("puasson ratio")->curValue();

    double c_mul = E/((1+mu)*(1-2*mu));//Additional multiplicator

    //Perform integration over volume of integral(BT*C*B*detJ dV)
    for(int ct = 0; ct < 8*8*9; dataBuf_[ct++] = 0);//Nulling
    for(int ct = 0; ct < 8*3*6; temp_[ct++] = 0);//Nulling
    //Loop over integration points
    for(int ctR = 0; ctR < numIntPoints_; ctR++){//Loop in r dir
        double r, s, t;
        double weigthR, weigthS, weigthT;
        r = intCrd[numIntPoints_-1][ctR];
        weigthR = intWgh[numIntPoints_-1][ctR];
        for(int ctS = 0; ctS < numIntPoints_; ctS++){//Loop in s dir
            s = intCrd[numIntPoints_-1][ctS];
            weigthS = intWgh[numIntPoints_-1][ctS];
            for(int ctT = 0; ctT < numIntPoints_; ctT++){//Loop in t dir
                t = intCrd[numIntPoints_-1][ctT];
                weigthT = intWgh[numIntPoints_-1][ctT];
                computeH(r, s, t);
                computeDHDN(r, s, t);
                computeJ();
                computeDHDG();
                for(int ct = 0; ct < 8; ct++){//Loop on form functions to obtain result of BT*C
                    temp_[3*6*ct] = dhdg_[3*ct]*(1-mu)*c_mul;
                    temp_[3*6*ct + 1] = temp_[3*6*ct + 2] = dhdg_[3*ct]*mu*c_mul;
                    temp_[3*6*ct + 3] = dhdg_[3*ct+1]*((1-2.*mu)/2.)*c_mul;
                    //temp_[3*6*ct + 4] = 0.;// - by matrix topology
                    temp_[3*6*ct + 5] = dhdg_[3*ct+2]*((1-2.*mu)/2.)*c_mul;
                    temp_[3*6*ct + 6] = dhdg_[3*ct+1]*mu*c_mul;
                    temp_[3*6*ct + 7] = dhdg_[3*ct+1]*(1-mu)*c_mul;
                    temp_[3*6*ct + 8] = temp_[3*6*ct + 6];
                    temp_[3*6*ct + 9] = dhdg_[3*ct]*((1-2.*mu)/2.)*c_mul;
                    temp_[3*6*ct + 10] = dhdg_[3*ct+2]*((1-2.*mu)/2.)*c_mul;
                    //temp_[3*6*ct + 11] = 0.;// - by matrix topology
                    temp_[3*6*ct + 12] = temp_[3*6*ct + 13] = dhdg_[3*ct+2]*mu*c_mul;
                    temp_[3*6*ct + 14] = dhdg_[3*ct+2]*(1-mu)*c_mul;
                    //temp_[3*6*ct + 15] = 0.;// - by matrix topology
                    temp_[3*6*ct + 16] = dhdg_[3*ct+1]*((1-2.*mu)/2.)*c_mul;
                    temp_[3*6*ct + 17] = dhdg_[3*ct]*((1-2.*mu)/2.)*c_mul;
                }//Loop on form functions to obtain result of BT*C
                //Compute matrix multiplication (BT*C)*B and add result to stiffness matrix with weights and determinant
                for(int ct1 = 0; ct1 < 8; ct1++){//Loop on rows blocks of matrix (BT*C) upper triangle
                    for(int ct2 = ct1; ct2 < 8; ct2++){//Loop on rows blocks of matrix B upper triangle
                        dataBuf_[(ct1*3)*3*8 + ct2*3] += (temp_[3*6*ct1]*dhdg_[3*ct2]+temp_[3*6*ct1+3]*dhdg_[3*ct2+1]+temp_[3*6*ct1+5]*dhdg_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;
                        dataBuf_[(ct1*3)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+1]*dhdg_[3*ct2+1]+temp_[3*6*ct1+3]*dhdg_[3*ct2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+4] == 0;
                        dataBuf_[(ct1*3)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+2]*dhdg_[3*ct2+2]+temp_[3*6*ct1+5]*dhdg_[3*ct2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+4] == 0;

                        dataBuf_[(ct1*3+1)*3*8 + ct2*3] += (temp_[3*6*ct1+6]*dhdg_[3*ct2]+temp_[3*6*ct1+9]*dhdg_[3*ct2+1])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+11] == 0;
                        dataBuf_[(ct1*3+1)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+7]*dhdg_[3*ct2+1]+temp_[3*6*ct1+9]*dhdg_[3*ct2]+temp_[3*6*ct1+10]*dhdg_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;
                        dataBuf_[(ct1*3+1)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+8]*dhdg_[3*ct2+2]+temp_[3*6*ct1+10]*dhdg_[3*ct2+1])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+11] == 0;

                        dataBuf_[(ct1*3+2)*3*8 + ct2*3] += (temp_[3*6*ct1+12]*dhdg_[3*ct2]+temp_[3*6*ct1+17]*dhdg_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+15] == 0;
                        dataBuf_[(ct1*3+2)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+13]*dhdg_[3*ct2+1]+temp_[3*6*ct1+16]*dhdg_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+15] == 0;
                        dataBuf_[(ct1*3+2)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+14]*dhdg_[3*ct2+2]+temp_[3*6*ct1+16]*dhdg_[3*ct2+1]+temp_[3*6*ct1+17]*dhdg_[3*ct2])*weigthR*weigthS*weigthT*detJ_;
                    }//Loop on rows blocks of matrix B
                }//Loop on rows blocks of matrix (BT*C)

            }//Loop in t dir
        }//Loop in s dir
    }//Loop in r dir
    for(int ct1 = 0; ct1 < 8; ct1++){//Loop on rows blocks of matrix (BT*C) lower triangle
        for(int ct2 = 0; ct2 < ct1; ct2++){//Loop on rows blocks of matrix B lower triangle
            dataBuf_[(ct1*3)*3*8 + ct2*3] = dataBuf_[(ct2*3)*3*8 + ct1*3];
            dataBuf_[(ct1*3)*3*8 + ct2*3 + 1] = dataBuf_[(ct2*3+1)*3*8 + ct1*3];
            dataBuf_[(ct1*3)*3*8 + ct2*3 + 2] = dataBuf_[(ct2*3+2)*3*8 + ct1*3];

            dataBuf_[(ct1*3+1)*3*8 + ct2*3] = dataBuf_[(ct2*3)*3*8 + ct1*3 + 1];
            dataBuf_[(ct1*3+1)*3*8 + ct2*3 + 1] = dataBuf_[(ct2*3+1)*3*8 + ct1*3 + 1];
            dataBuf_[(ct1*3+1)*3*8 + ct2*3 + 2] = dataBuf_[(ct2*3+2)*3*8 + ct1*3 + 1];

            dataBuf_[(ct1*3+2)*3*8 + ct2*3] = dataBuf_[(ct2*3)*3*8 + ct1*3 + 2];
            dataBuf_[(ct1*3+2)*3*8 + ct2*3 + 1] = dataBuf_[(ct2*3+1)*3*8 + ct1*3 + 2];
            dataBuf_[(ct1*3+2)*3*8 + ct2*3 + 2] = dataBuf_[(ct2*3+2)*3*8 + ct1*3 + 2];
        }//Loop on rows blocks of matrix B
    }//Loop on rows blocks of matrix (BT*C)
    //Unroll to nurmal block storage
    for(int ct1 = 0; ct1 < 8*3; ++ct1) for(int ct2 = 0; ct2 < 8*3; ++ct2) {
        int rowID = ct1/3;
        int rowDof = ct1%3;
        int colID = ct2/3;
        int colDof = ct2%3;
        data_[numNodes_*rowID*blockSize_ + colID*blockSize_ + rowDof*numDOF_ + colDof] = dataBuf_[ct1*3*8+ct2];
    }
}

double sbfElemStiffMatrixHexa8::computeVolume()
{
    double vol = 0;
    //Loop over integration points
    for(int ctR = 0; ctR < numIntPoints_; ctR++){//Loop in r dir
        double r, s, t;
        double weigthR, weigthS, weigthT;
        r = intCrd[numIntPoints_-1][ctR];
        weigthR = intWgh[numIntPoints_-1][ctR];
        for(int ctS = 0; ctS < numIntPoints_; ctS++){//Loop in s dir
            s = intCrd[numIntPoints_-1][ctS];
            weigthS = intWgh[numIntPoints_-1][ctS];
            for(int ctT = 0; ctT < numIntPoints_; ctT++){//Loop in t dir
                t = intCrd[numIntPoints_-1][ctT];
                weigthT = intWgh[numIntPoints_-1][ctT];
                computeH(r, s, t);
                computeDHDN(r, s, t);
                computeJ();
                vol += weigthR*weigthS*weigthT*detJ_;
            }//Loop in t dir
        }//Loop in s dir
    }//Loop in r dir
    return vol;
}

sbfElemStiffMatrix::RowColData sbfElemStiffMatrixHexa8::rowColData()
{
    RowColData rez;
    for(int rowCt = 0; rowCt < numNodes_; ++rowCt)
        for(int columnCt = 0; columnCt < numNodes_; ++columnCt)
            rez.push_back(std::make_pair(std::make_pair(ind_[rowCt], ind_[columnCt]), data_+(rowCt*numNodes_+columnCt)*blockSize_));
    return rez;
}
