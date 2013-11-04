#include "sbfElemStiffMatrixHexa8.h"

#include "sbfMesh.h"
#include "sbfElement.h"
#include "sbfNode.h"
#include "sbfMaterialProperties.h"
#include "sbfPropertiesSet.h"
#include "sbfReporter.h"

const double intCrd1[] = {0.0};
const double intWgh1[] = {2.0};
const double intCrd2[] = {-5.773502691896257645e-01, 5.773502691896257645e-01};
const double intWgh2[] = {1.0, 1.0};
const double intCrd3[] = {-7.745966692414833771e-01, 0.0, 7.745966692414833771e-01};
const double intWgh3[] = {5.555555555555555556e-01, 8.888888888888888889e-01, 5.555555555555555556e-01};
const double intCrd4[] = {-0.861136311594953, -0.339981043584856, 0.339981043584856, 0.861136311594953};
const double intWgh4[] = {0.347854845137454, 0.652145154862546, 0.652145154862546, 0.347854845137454};

double const * intCrd[] = {intCrd1, intCrd2, intCrd3, intCrd4};
double const * intWgh[] = {intWgh1, intWgh2, intWgh3, intWgh4};

sbfElemStiffMatrixHexa8::sbfElemStiffMatrixHexa8()
{
    data_ = new double [8*8*9];
    elem_ = NULL;
    numIntPoints_ = 2;
    propSet_ = NULL;
}
sbfElemStiffMatrixHexa8::sbfElemStiffMatrixHexa8(sbfElement * elem)
{
    data_ = new double [8*8*9];
    numIntPoints_ = 2;
    setElem(elem);
    propSet_ = NULL;
}
sbfElemStiffMatrixHexa8::~sbfElemStiffMatrixHexa8()
{
    if(data_ != NULL)
        delete [] data_;
}
void sbfElemStiffMatrixHexa8::setElem(sbfElement * elem)
{
    if(elem->type() != ElementType::HEXAHEDRON_LINEAR)
    {
        elem_ = NULL;
        return;
    }
    elem_ = elem;
    sbfMesh *mesh = elem->mesh();
    sbfNode node;
    std::vector<int> indexes = elem->indexes();
    for(int ct = 0; ct < 8; ct++)
    {
        ind_[ct] = indexes[ct];
        node = mesh->node(indexes[ct]);
        crd_[ct] = node.x();
        crd_[ct+8] = node.y();
        crd_[ct+8*2] = node.z();
    }
}
sbfElement & sbfElemStiffMatrixHexa8::elem()
{return *elem_;}
void sbfElemStiffMatrixHexa8::setNumIntPoints(int numIntPoints)
{numIntPoints_ = numIntPoints;}
int sbfElemStiffMatrixHexa8::numIntPoints()
{return numIntPoints_;}
void sbfElemStiffMatrixHexa8::computeH(double r, double s, double t)
{
    /*
     *Compute values of form functions at specific point in natural coordinates
     *H_[0] = h0(r, s, t), H_[1] = h1(r, s, t), etc.
     */
    double onePlusR = (1.+r);
    double oneMinusR = (1.-r);
    double onePlusS = (1.+s);
    double oneMinusS = (1.-s);
    double onePlusT = (1.+t);
    double oneMinusT = (1.-t);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ERROR in nodes numeration. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Solved
    H_[0] = onePlusR*onePlusS*onePlusT/8.0;
    H_[3] = oneMinusR*onePlusS*onePlusT/8.0;
    H_[2] = oneMinusR*oneMinusS*onePlusT/8.0;
    H_[1] = onePlusR*oneMinusS*onePlusT/8.0;
    H_[4] = onePlusR*onePlusS*oneMinusT/8.0;
    H_[7] = oneMinusR*onePlusS*oneMinusT/8.0;
    H_[6] = oneMinusR*oneMinusS*oneMinusT/8.0;
    H_[5] = onePlusR*oneMinusS*oneMinusT/8.0;
}
void sbfElemStiffMatrixHexa8::computeDHDN(double r, double s, double t)
{
    /*
     * Compute values of form functions derivatives over natural coordinates at specific point in natural coordinates
     * DHDN_[0*3 + 0] = d h0 / d r, DHDN_[0*3 + 1] = d h0 / d s, DHDN_[0*3 + 2] = d h0 / d t, DHDN_[1*3 + 0] = d h1 / d r, etc.
     */
    double onePlusR = (1.+r);
    double oneMinusR = (1.-r);
    double onePlusS = (1.+s);
    double oneMinusS = (1.-s);
    double onePlusT = (1.+t);
    double oneMinusT = (1.-t);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ERROR in nodes numeration. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Solved
    DHDN_[0] = onePlusS*onePlusT/8.0;//d h0 / d r
    DHDN_[1] = onePlusR*onePlusT/8.0;//d h0 / d s
    DHDN_[2] = onePlusR*onePlusS/8.0;//d h0 / d t
    DHDN_[9] = -onePlusS*onePlusT/8.0;//d h1 / d r
    DHDN_[10] = oneMinusR*onePlusT/8.0;
    DHDN_[11] = oneMinusR*onePlusS/8.0;
    DHDN_[6] = -oneMinusS*onePlusT/8.0;//d h2 / d r
    DHDN_[7] = -oneMinusR*onePlusT/8.0;
    DHDN_[8] = oneMinusR*oneMinusS/8.0;
    DHDN_[3] = oneMinusS*onePlusT/8.0;//d h3 / d r
    DHDN_[4] = -onePlusR*onePlusT/8.0;
    DHDN_[5] = onePlusR*oneMinusS/8.0;
    DHDN_[12] = onePlusS*oneMinusT/8.0;//d h4 / d r
    DHDN_[13] = onePlusR*oneMinusT/8.0;
    DHDN_[14] = -onePlusR*onePlusS/8.0;
    DHDN_[21] = -onePlusS*oneMinusT/8.0;//d h5 / d r
    DHDN_[22] = oneMinusR*oneMinusT/8.0;
    DHDN_[23] = -oneMinusR*onePlusS/8.0;
    DHDN_[18] = -oneMinusS*oneMinusT/8.0;//d h6 / d r
    DHDN_[19] = -oneMinusR*oneMinusT/8.0;
    DHDN_[20] = -oneMinusR*oneMinusS/8.0;
    DHDN_[15] = oneMinusS*oneMinusT/8.0;//d h7 / d r
    DHDN_[16] = -onePlusR*oneMinusT/8.0;
    DHDN_[17] = -onePlusR*oneMinusS/8.0;
}
void sbfElemStiffMatrixHexa8::computeJ()
{
    /*
     * Compute Jacobian and its determinant. computeDHDN(r, s, t) should be performed before !
     * J_[0] = d x / d r = d h_i / d r * x_i, J_[1] = d h_i / d r * y_i, J_[2] = d h_i / d r * z_i, J_[3] = d h_i / d s * x_i
     */
    J_[0] = DHDN_[0]*crd_[0] + DHDN_[3]*crd_[1] + DHDN_[6]*crd_[2] + DHDN_[9]*crd_[3] + DHDN_[12]*crd_[4] + DHDN_[15]*crd_[5] + DHDN_[18]*crd_[6] + DHDN_[21]*crd_[7];
    J_[1] = DHDN_[0]*crd_[8] + DHDN_[3]*crd_[9] + DHDN_[6]*crd_[10] + DHDN_[9]*crd_[11] + DHDN_[12]*crd_[12] + DHDN_[15]*crd_[13] + DHDN_[18]*crd_[14] + DHDN_[21]*crd_[15];
    J_[2] = DHDN_[0]*crd_[16] + DHDN_[3]*crd_[17] + DHDN_[6]*crd_[18] + DHDN_[9]*crd_[19] + DHDN_[12]*crd_[20] + DHDN_[15]*crd_[21] + DHDN_[18]*crd_[22] + DHDN_[21]*crd_[23];
    J_[3] = DHDN_[1]*crd_[0] + DHDN_[4]*crd_[1] + DHDN_[7]*crd_[2] + DHDN_[10]*crd_[3] + DHDN_[13]*crd_[4] + DHDN_[16]*crd_[5] + DHDN_[19]*crd_[6] + DHDN_[22]*crd_[7];
    J_[4] = DHDN_[1]*crd_[8] + DHDN_[4]*crd_[9] + DHDN_[7]*crd_[10] + DHDN_[10]*crd_[11] + DHDN_[13]*crd_[12] + DHDN_[16]*crd_[13] + DHDN_[19]*crd_[14] + DHDN_[22]*crd_[15];
    J_[5] = DHDN_[1]*crd_[16] + DHDN_[4]*crd_[17] + DHDN_[7]*crd_[18] + DHDN_[10]*crd_[19] + DHDN_[13]*crd_[20] + DHDN_[16]*crd_[21] + DHDN_[19]*crd_[22] + DHDN_[22]*crd_[23];
    J_[6] = DHDN_[2]*crd_[0] + DHDN_[5]*crd_[1] + DHDN_[8]*crd_[2] + DHDN_[11]*crd_[3] + DHDN_[14]*crd_[4] + DHDN_[17]*crd_[5] + DHDN_[20]*crd_[6] + DHDN_[23]*crd_[7];
    J_[7] = DHDN_[2]*crd_[8] + DHDN_[5]*crd_[9] + DHDN_[8]*crd_[10] + DHDN_[11]*crd_[11] + DHDN_[14]*crd_[12] + DHDN_[17]*crd_[13] + DHDN_[20]*crd_[14] + DHDN_[23]*crd_[15];
    J_[8] = DHDN_[2]*crd_[16] + DHDN_[5]*crd_[17] + DHDN_[8]*crd_[18] + DHDN_[11]*crd_[19] + DHDN_[14]*crd_[20] + DHDN_[17]*crd_[21] + DHDN_[20]*crd_[22] + DHDN_[23]*crd_[23];
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
void sbfElemStiffMatrixHexa8::computeDHDG(/*double r, double s, double t*/)
{
    /*
     * Compute values of form functions derivatives over global coordinates at specific point in natural coordinates
     * DHDG[0*3+0] = d h0 / d x = invJ_[0] * d h0 / d r + invJ_[1] * d h0 / d s + invJ_[2] * d h0 / d t.
     * DHDG[0*3+1] = d h0 / d y. etc.
     */
    DHDG_[0] = invJ_[0]*DHDN_[0] + invJ_[1]*DHDN_[1] + invJ_[2]*DHDN_[2];//d h0 / d x
    DHDG_[1] = invJ_[3]*DHDN_[0] + invJ_[4]*DHDN_[1] + invJ_[5]*DHDN_[2];//d h0 / d y
    DHDG_[2] = invJ_[6]*DHDN_[0] + invJ_[7]*DHDN_[1] + invJ_[8]*DHDN_[2];//d h0 / d z
    DHDG_[3] = invJ_[0]*DHDN_[3] + invJ_[1]*DHDN_[4] + invJ_[2]*DHDN_[5];//d h1 / d x
    DHDG_[4] = invJ_[3]*DHDN_[3] + invJ_[4]*DHDN_[4] + invJ_[5]*DHDN_[5];
    DHDG_[5] = invJ_[6]*DHDN_[3] + invJ_[7]*DHDN_[4] + invJ_[8]*DHDN_[5];
    DHDG_[6] = invJ_[0]*DHDN_[6] + invJ_[1]*DHDN_[7] + invJ_[2]*DHDN_[8];//d h2 / d x
    DHDG_[7] = invJ_[3]*DHDN_[6] + invJ_[4]*DHDN_[7] + invJ_[5]*DHDN_[8];
    DHDG_[8] = invJ_[6]*DHDN_[6] + invJ_[7]*DHDN_[7] + invJ_[8]*DHDN_[8];
    DHDG_[9] = invJ_[0]*DHDN_[9] + invJ_[1]*DHDN_[10] + invJ_[2]*DHDN_[11];//d h3 / d x
    DHDG_[10] = invJ_[3]*DHDN_[9] + invJ_[4]*DHDN_[10] + invJ_[5]*DHDN_[11];
    DHDG_[11] = invJ_[6]*DHDN_[9] + invJ_[7]*DHDN_[10] + invJ_[8]*DHDN_[11];
    DHDG_[12] = invJ_[0]*DHDN_[12] + invJ_[1]*DHDN_[13] + invJ_[2]*DHDN_[14];//d h4 / d x
    DHDG_[13] = invJ_[3]*DHDN_[12] + invJ_[4]*DHDN_[13] + invJ_[5]*DHDN_[14];
    DHDG_[14] = invJ_[6]*DHDN_[12] + invJ_[7]*DHDN_[13] + invJ_[8]*DHDN_[14];
    DHDG_[15] = invJ_[0]*DHDN_[15] + invJ_[1]*DHDN_[16] + invJ_[2]*DHDN_[17];//d h5 / d x
    DHDG_[16] = invJ_[3]*DHDN_[15] + invJ_[4]*DHDN_[16] + invJ_[5]*DHDN_[17];
    DHDG_[17] = invJ_[6]*DHDN_[15] + invJ_[7]*DHDN_[16] + invJ_[8]*DHDN_[17];
    DHDG_[18] = invJ_[0]*DHDN_[18] + invJ_[1]*DHDN_[19] + invJ_[2]*DHDN_[20];//d h6 / d x
    DHDG_[19] = invJ_[3]*DHDN_[18] + invJ_[4]*DHDN_[19] + invJ_[5]*DHDN_[20];
    DHDG_[20] = invJ_[6]*DHDN_[18] + invJ_[7]*DHDN_[19] + invJ_[8]*DHDN_[20];
    DHDG_[21] = invJ_[0]*DHDN_[21] + invJ_[1]*DHDN_[22] + invJ_[2]*DHDN_[23];//d h7 / d x
    DHDG_[22] = invJ_[3]*DHDN_[21] + invJ_[4]*DHDN_[22] + invJ_[5]*DHDN_[23];
    DHDG_[23] = invJ_[6]*DHDN_[21] + invJ_[7]*DHDN_[22] + invJ_[8]*DHDN_[23];
}

void sbfElemStiffMatrixHexa8::computeSM()
{
    /*
     * Compute stiffness matrix of element
     */

    if(propSet_ == NULL)
    {/*Throw an exception*/debugMsg("ERROR!!! properties are not set correctly!!!")}

    sbfMaterialProperties *mp = propSet_->material(elem_->mtr() - 1);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    double E = mp->propertyTable("elastic module")->curValue();
    double mu = mp->propertyTable("puasson ratio")->curValue();

    double c_mul = E/((1+mu)*(1-2*mu));//Additional multiplicator

    //Perform integration over volume of integral(BT*C*B*detJ dV)
    for(int ct = 0; ct < 8*8*9; data_[ct++] = 0);//Nulling
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
                computeDHDG(/*r, s, t*/);
                for(int ct = 0; ct < 8; ct++){//Loop on form functions to obtain result of BT*C
                    temp_[3*6*ct] = DHDG_[3*ct]*(1-mu)*c_mul;
                    temp_[3*6*ct + 1] = temp_[3*6*ct + 2] = DHDG_[3*ct]*mu*c_mul;
                    temp_[3*6*ct + 3] = DHDG_[3*ct+1]*((1-2.*mu)/2.)*c_mul;
                    //temp_[3*6*ct + 4] = 0.;// - by matrix topology
                    temp_[3*6*ct + 5] = DHDG_[3*ct+2]*((1-2.*mu)/2.)*c_mul;
                    temp_[3*6*ct + 6] = DHDG_[3*ct+1]*mu*c_mul;
                    temp_[3*6*ct + 7] = DHDG_[3*ct+1]*(1-mu)*c_mul;
                    temp_[3*6*ct + 8] = temp_[3*6*ct + 6];
                    temp_[3*6*ct + 9] = DHDG_[3*ct]*((1-2.*mu)/2.)*c_mul;
                    temp_[3*6*ct + 10] = DHDG_[3*ct+2]*((1-2.*mu)/2.)*c_mul;
                    //temp_[3*6*ct + 11] = 0.;// - by matrix topology
                    temp_[3*6*ct + 12] = temp_[3*6*ct + 13] = DHDG_[3*ct+2]*mu*c_mul;
                    temp_[3*6*ct + 14] = DHDG_[3*ct+2]*(1-mu)*c_mul;
                    //temp_[3*6*ct + 15] = 0.;// - by matrix topology
                    temp_[3*6*ct + 16] = DHDG_[3*ct+1]*((1-2.*mu)/2.)*c_mul;
                    temp_[3*6*ct + 17] = DHDG_[3*ct]*((1-2.*mu)/2.)*c_mul;
                }//Loop on form functions to obtain result of BT*C
                //Compute matrix multiplication (BT*C)*B and add result to stiffness matrix with weights and determinant
                for(int ct1 = 0; ct1 < 8; ct1++){//Loop on rows blocks of matrix (BT*C) upper triangle
                    for(int ct2 = ct1; ct2 < 8; ct2++){//Loop on rows blocks of matrix B upper triangle
                        data_[(ct1*3)*3*8 + ct2*3] += (temp_[3*6*ct1]*DHDG_[3*ct2]+temp_[3*6*ct1+3]*DHDG_[3*ct2+1]+temp_[3*6*ct1+5]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;
                        data_[(ct1*3)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+1]*DHDG_[3*ct2+1]+temp_[3*6*ct1+3]*DHDG_[3*ct2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+4] == 0;
                        data_[(ct1*3)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+2]*DHDG_[3*ct2+2]+temp_[3*6*ct1+5]*DHDG_[3*ct2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+4] == 0;

                        data_[(ct1*3+1)*3*8 + ct2*3] += (temp_[3*6*ct1+6]*DHDG_[3*ct2]+temp_[3*6*ct1+9]*DHDG_[3*ct2+1])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+11] == 0;
                        data_[(ct1*3+1)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+7]*DHDG_[3*ct2+1]+temp_[3*6*ct1+9]*DHDG_[3*ct2]+temp_[3*6*ct1+10]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;
                        data_[(ct1*3+1)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+8]*DHDG_[3*ct2+2]+temp_[3*6*ct1+10]*DHDG_[3*ct2+1])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+11] == 0;

                        data_[(ct1*3+2)*3*8 + ct2*3] += (temp_[3*6*ct1+12]*DHDG_[3*ct2]+temp_[3*6*ct1+17]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+15] == 0;
                        data_[(ct1*3+2)*3*8 + ct2*3 + 1] += (temp_[3*6*ct1+13]*DHDG_[3*ct2+1]+temp_[3*6*ct1+16]*DHDG_[3*ct2+2])*weigthR*weigthS*weigthT*detJ_;//temp_[3*6*ct1+15] == 0;
                        data_[(ct1*3+2)*3*8 + ct2*3 + 2] += (temp_[3*6*ct1+14]*DHDG_[3*ct2+2]+temp_[3*6*ct1+16]*DHDG_[3*ct2+1]+temp_[3*6*ct1+17]*DHDG_[3*ct2])*weigthR*weigthS*weigthT*detJ_;
                    }//Loop on rows blocks of matrix B
                }//Loop on rows blocks of matrix (BT*C)

            }//Loop in t dir
        }//Loop in s dir
    }//Loop in r dir
    for(int ct1 = 0; ct1 < 8; ct1++){//Loop on rows blocks of matrix (BT*C) lower triangle
        for(int ct2 = 0; ct2 < ct1; ct2++){//Loop on rows blocks of matrix B lower triangle
            data_[(ct1*3)*3*8 + ct2*3] = data_[(ct2*3)*3*8 + ct1*3];
            data_[(ct1*3)*3*8 + ct2*3 + 1] = data_[(ct2*3+1)*3*8 + ct1*3];
            data_[(ct1*3)*3*8 + ct2*3 + 2] = data_[(ct2*3+2)*3*8 + ct1*3];

            data_[(ct1*3+1)*3*8 + ct2*3] = data_[(ct2*3)*3*8 + ct1*3 + 1];
            data_[(ct1*3+1)*3*8 + ct2*3 + 1] = data_[(ct2*3+1)*3*8 + ct1*3 + 1];
            data_[(ct1*3+1)*3*8 + ct2*3 + 2] = data_[(ct2*3+2)*3*8 + ct1*3 + 1];

            data_[(ct1*3+2)*3*8 + ct2*3] = data_[(ct2*3)*3*8 + ct1*3 + 2];
            data_[(ct1*3+2)*3*8 + ct2*3 + 1] = data_[(ct2*3+1)*3*8 + ct1*3 + 2];
            data_[(ct1*3+2)*3*8 + ct2*3 + 2] = data_[(ct2*3+2)*3*8 + ct1*3 + 2];
        }//Loop on rows blocks of matrix B
    }//Loop on rows blocks of matrix (BT*C)
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
double sbfElemStiffMatrixHexa8::computeMass(double rho)
{return rho*computeVolume();}
double sbfElemStiffMatrixHexa8::computeMass()
{
    if(propSet_ == NULL)
    {/*Throw an exception*/debugMsg("ERROR!!! properties are not set correctly!!!")}

    sbfMaterialProperties *mp = propSet_->material(elem_->mtr() - 1);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    double rho = mp->propertyTable("density")->curValue();
    return computeMass(rho);
}

void sbfElemStiffMatrixHexa8::getBlockDataLoc(double * data, int localIndI, int localIndJ)
{
    /*
     * data - pointer to store stiffness block 3*3 with row index localIndI and column index localIndJ.
     * local indexing.
     * memory of data is not checked or allocated, it should be done before calling thise method
     */
    if(localIndI > 7 || localIndJ > 7 || localIndI < 0 || localIndJ < 0 || data == NULL)
        return;
    double *pointer = data_+localIndI*3*3*8 + 3*localIndJ;
    data[0] = *pointer++;
    data[1] = *pointer++;
    data[2] = *pointer;
    pointer += 7*3+1;
    data[3] = *pointer++;
    data[4] = *pointer++;
    data[5] = *pointer;
    pointer += 7*3+1;
    data[6] = *pointer++;
    data[7] = *pointer++;
    data[8] = *pointer;
}
void sbfElemStiffMatrixHexa8::getBlockDataGlob(double * data, int indI, int indJ)
{
    /*
     * data - pointer to store stiffness block 3*3.
     * Row and column indexes of block are evaluated by mapping global indexes indI and indJ.
     * memory of data is not checked or allocated, it should be done before calling thise method
     */
    if(data == NULL)
        return;
    int localIndI = -1, localIndJ = -1;
    int ctFound = 0;
    for(int ct = 0; ct < 8; ct++){
        if(indI == ind_[ct])
        {localIndI = ct; ctFound++;}
        if(indJ == ind_[ct])
        {localIndJ = ct; ctFound++;}
        if(ctFound == 2) break;
    }
    getBlockDataLoc(data, localIndI, localIndJ);
}
void sbfElemStiffMatrixHexa8::addBlockDataLoc(double * data, int localIndI, int localIndJ)
{
    /*
     * data - pointer to store stiffness block 3*3 with row index localIndI and column index localIndJ.
     * local indexing.
     * memory of data is not checked or allocated, it should be done before calling thise method
     */
    if(localIndI > 7 || localIndJ > 7 || localIndI < 0 || localIndJ < 0 || data == NULL)
        return;
    double *pointer = data_+localIndI*3*3*8 + 3*localIndJ;
    data[0] += *pointer++;
    data[1] += *pointer++;
    data[2] += *pointer;
    pointer += 7*3+1;
    data[3] += *pointer++;
    data[4] += *pointer++;
    data[5] += *pointer;
    pointer += 7*3+1;
    data[6] += *pointer++;
    data[7] += *pointer++;
    data[8] += *pointer;
}
void sbfElemStiffMatrixHexa8::addBlockDataGlob(double * data, int indI, int indJ)
{
    /*
     * data - pointer to store stiffness block 3*3.
     * Row and column indexes of block are evaluated by mapping global indexes indI and indJ.
     * memory of data is not checked or allocated, it should be done before calling thise method
     */
    if(data == NULL)
        return;
    int localIndI = -1, localIndJ = -1;
    int ctFound = 0;
    for(int ct = 0; ct < 8; ct++){
        if(indI == ind_[ct])
        {localIndI = ct; ctFound++;}
        if(indJ == ind_[ct])
        {localIndJ = ct; ctFound++;}
        if(ctFound == 2) break;
    }
    addBlockDataLoc(data, localIndI, localIndJ);
}
double * sbfElemStiffMatrixHexa8::data()
{return data_;}
void sbfElemStiffMatrixHexa8::setPropSet(sbfPropertiesSet * propSet)
{propSet_ = propSet;}
sbfPropertiesSet * sbfElemStiffMatrixHexa8::propSet()
{return propSet_;}
