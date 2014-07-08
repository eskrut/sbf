#ifndef SBFELEMSTIFFMATRIXHEXA8_H
#define SBFELEMSTIFFMATRIXHEXA8_H

//#include "sbfDeclspec.h"
//#include "sbfEnums.h"

//class sbfPropertiesSet;
//class sbfElement;

/*
 *    7-------6
 *   /|      /|     Z
 *  4-------5 |     |   Y
 *  | |     | |     |  /
 *  | 3- - -|-2     | /
 *  |/      |/      |/
 *  0-------1       0-------- X
*/

#include "sbfElemStiffMatrix.h"

class DECLSPEC sbfElemStiffMatrixHexa8 : public sbfElemStiffMatrix
{
public:
    explicit sbfElemStiffMatrixHexa8(sbfElement *elem, sbfPropertiesSet *propSet);
private:
    static const int numNodes_ = 8;
    static const int numDOF_ = 3;
    static const int blockSize_ = numDOF_*numDOF_;
    //FIXME - this is intermediate buffer
    double dataBuf_[numNodes_*numNodes_*blockSize_];
    void init();
    void clean();
    void computeH(double r, double s = 0, double t = 0);
    void computeDHDN(double r, double s = 0, double t = 0);
    void computeDHDG();
    void computeJ();
public:
    void computeSM();
    double computeVolume();
    RowColData rowColData();
};

//class DECLSPEC sbfElemStiffMatrixHexa8
//{
//public:
//    sbfElemStiffMatrixHexa8();
//    sbfElemStiffMatrixHexa8(sbfElement * elem);
//    virtual ~sbfElemStiffMatrixHexa8();
//private:
//    //Linear storage array for element stiffness matrix.
//    double *data_;
//    //Pointer to linked geometric element.
//    //Pointer to linked geometric element.
//    sbfElement *elem_;
//    //Number of points for numerical integration.
//    int numIntPoints_;
//    //Coordinates of element nodes.
//    double crd_[8*3];
//    //Indexes of element nodes.
//    int ind_[8];
//    //Jacobian.
//    double J_[9];
//    //determinant of Jacobian.
//    double detJ_;
//    //invert Jacobian.
//    double invJ_[9];
//    //temporary hold of form functions values.
//    double H_[8];
//    //temporary hold of form functions derivatives over natural coordinates.
//    double DHDN_[8*3];
//    //temporary hold of form functions derivatives over global coordinates.
//    double DHDG_[8*3];
//    //temporary hold for result of matrix multiplication BT*C. ? Sparse matrix with constant topology - may it necessary to optimize memory
//    double temp_[8*3*6];

//    sbfPropertiesSet * propSet_;//Pointer to set of materials properties
//public:
//    //Set/get linked element
//    void setElem(sbfElement *elem);
//    sbfElement & elem();
//    //Set/get number of points in each directions which are used in numerical integration
//    void setNumIntPoints(int numIntPoints);
//    int numIntPoints();

//    //Compute values of form functions at natural coordinates (r, s, t).
//    void computeH(double r, double s, double t);
//    //Compute values of form functions derivations over natural coordinates at natural coordinates (r, s, t).
//    void computeDHDN(double r, double s, double t);
//    //Compute values of form functions derivations over global coordinates at natural coordinates (r, s, t).
//    void computeDHDG();
//    //Compute Jacobian, its determinant and inverse at natural coordinates (r, s, t).
//    void computeJ();
//    //Compute stiffness matrix.
//    void computeSM();

//    //Compute element mass
//    double computeMass();
//    //Compute element mass
//    double computeMass(double rho);
//    //Compute element volume
//    double computeVolume();

//    //Store stiffness block 3*3 of local indexes localIndI & localIndJ into data as linear array (no check or allocation of memory).
//    void getBlockDataLoc(double * data, int localIndI, int localIndJ);
//    //Store stiffness block 3*3 of global indexes indI & indJ into data as linear array (no check or allocation of memory).
//    void getBlockDataGlob(double * data, int indI, int indJ);
//    //Similar, but adds data not replace
//    void addBlockDataLoc(double * data, int localIndI, int localIndJ);
//    void addBlockDataGlob(double * data, int indI, int indJ);
//    double * data();//Returns pointer to linear array with stiff data.

//    void setPropSet(sbfPropertiesSet * propSet);
//    sbfPropertiesSet * propSet();
//};

#endif // SBFELEMSTIFFMATRIXHEXA8_H
