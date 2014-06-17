#ifndef SBFSTIFFMATRIX_H
#define SBFSTIFFMATRIX_H

#include "sbfEnums.h"
#include "sbfMesh.h"
#include "sbfPropertiesSet.h"
#include "sbfMatrixIterator.h"

/**
 * @brief The sbfStiffMatrix class is an abstract base class for stiffness matrices
 */

class sbfStiffMatrix
{
public:
    explicit sbfStiffMatrix(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type);
    virtual ~sbfStiffMatrix() {}

protected:
    sbfMesh *mesh_;
    sbfPropertiesSet *propSet_;
    MatrixType type_;

public:
    sbfMesh *mesh() const;
    sbfPropertiesSet *propSet() const;
    void setPropSet(sbfPropertiesSet *propSet);
    bool read(const char * name);
    bool write(const char * name) const;
    MatrixType type() const { return type_; }
    virtual MatrixStoreType storeType() const { return MatrixStoreType::NO_DEFINED_STORE_TYPE; }
    void computeSequantially();

    //Virtual functions that should be implemented in derived class

    virtual void compute(int startID, int stopID) = 0;

    virtual sbfMatrixIterator *createIterator() /*const*/ = 0;

    virtual void read(std::ifstream &in) {}
    virtual void write(std::ofstream &out) const {}

    virtual sbfStiffMatrix *createIncompleteChol() /*const*/ { return nullptr; }
    virtual void solve_L_LT_u_eq_f(double *u, double *f, sbfMatrixIterator *iterator = nullptr) { }

    virtual bool isValid() { return false; }
};

#endif // SBFSTIFFMATRIX_H
