#ifndef SBFELEMSTIFFMATRIX_H
#define SBFELEMSTIFFMATRIX_H

#include "sbfDeclspec.h"
#include "sbfEnums.h"
#include <list>

class sbfPropertiesSet;
class sbfElement;

const double intCrd1[] = {0.0};
const double intWgh1[] = {2.0};
const double intCrd2[] = {-5.773502691896257645e-01, 5.773502691896257645e-01};
const double intWgh2[] = {1.0, 1.0};
const double intCrd3[] = {-7.745966692414833771e-01, 0.0, 7.745966692414833771e-01};
const double intWgh3[] = {5.555555555555555556e-01, 8.888888888888888889e-01, 5.555555555555555556e-01};
const double intCrd4[] = {-0.861136311594953, -0.339981043584856, 0.339981043584856, 0.861136311594953};
const double intWgh4[] = {0.347854845137454, 0.652145154862546, 0.652145154862546, 0.347854845137454};

const double *const intCrd[] = {intCrd1, intCrd2, intCrd3, intCrd4};
const double *const intWgh[] = {intWgh1, intWgh2, intWgh3, intWgh4};

class DECLSPEC sbfElemStiffMatrix
{
public:
    explicit sbfElemStiffMatrix(sbfElement *elem, sbfPropertiesSet *propSet);
    virtual ~sbfElemStiffMatrix() {}
protected:
    sbfElement *elem_;
    sbfPropertiesSet *propSet_;

    //! Pointer to stiffness data
    double *data_;
    //! Element nodes coordinates
    double *crd_;
    //! Indexes of elementnodes
    int *ind_;
    //! Jacobian
    double J_[9];
    //! Determinant of Jacobian
    double detJ_;
    //! Inverce Jacobian
    double invJ_[9];
    //! Temporary hold for form functions values
    double *h_;
    //! Temporary hold for form functions derivative values in local coordinates
    double *dhdn_;
    //! Temporary hold for form functions derivative values in global coordinates
    double *dhdg_;
    //! Temporary hold for BT*C matrix multiplication
    double *temp_;
    //! Number of integration points in each direction
    int numIntPoints_;

private:
    virtual void init() = 0;
    virtual void clean() = 0;
public:
    virtual int numDOF() const = 0;

private:
    //! @brief Compute values of form functions at natural coordinates (r, s, t).
    virtual void computeH(double r, double s = 0, double t = 0) {(void)(r);(void)(s);(void)(t);}
    //! @brief Compute values of form functions derivations over natural coordinates at natural coordinates (r, s, t).
    virtual void computeDHDN(double r, double s = 0, double t = 0) {(void)(r);(void)(s);(void)(t);}
    //! @brief Compute values of form functions derivations over global coordinates at natural coordinates (r, s, t).
    virtual void computeDHDG() {}
    //! @brief Compute Jacobian, its determinant and inverse at natural coordinates (r, s, t).
    virtual void computeJ() {}
public:
    void setElem(sbfElement *elem);
    sbfElement *elem() const { return elem_; }
    //! @brief This function shoudl be implemented in subclasses to compute elemente stiffness matrix
    virtual void computeSM() = 0;
    virtual double computeVolume() { return 0; }
    double *data() const { return data_; }
    using RowColData = std::list<std::pair<std::pair<int/*rowID*/, int/*columnID*/>, const double */*data*/>>;
    virtual RowColData rowColData() = 0;
    int numIntPoints() const;
    void setNumIntPoints(int numIntPoints);
};

#endif // SBFELEMSTIFFMATRIX_H
