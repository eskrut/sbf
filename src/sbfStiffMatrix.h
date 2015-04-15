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
    explicit sbfStiffMatrix ( sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type );
    virtual ~sbfStiffMatrix() {}

protected:
    sbfMesh *mesh_;
    sbfPropertiesSet *propSet_;
    MatrixType type_;

public:
    sbfMesh *mesh() const;
    sbfPropertiesSet *propSet() const;
    void setPropSet ( sbfPropertiesSet *propSet );
    bool read ( const char *name );
    bool write ( const char *name ) const;
    MatrixType type() const { return type_; }
    virtual MatrixStoreType storeType() const { return MatrixStoreType::NO_DEFINED_STORE_TYPE; }
    void computeSequantially();
    void compute ( int startID, int stopID );

    //! Create new instance of stiff matrix of specific type
    static sbfStiffMatrix *New ( sbfMesh *mesh,
                                 sbfPropertiesSet *propSet,
                                 MatrixType symType = MatrixType::FULL_MATRIX,
                                 MatrixStoreType storeType = MatrixStoreType::COMPACT );

    //Virtual functions that should be implemented in derived class
    //! Nulling matrix
    virtual void null() = 0;
    //! Create matrix specific iterator
    virtual sbfMatrixIterator *createIterator() /*const*/ = 0;
    //! Get number of DOF per node
    virtual int numDof() const = 0;

    virtual void read_stream ( std::ifstream &in ) {}
    virtual void write_stream ( std::ofstream &out ) const {}

    virtual sbfStiffMatrix *createChol() /*const*/ { return nullptr; }
    virtual sbfStiffMatrix *createIncompleteChol() /*const*/ { return nullptr; }
    virtual sbfStiffMatrix *createLDLT() { return nullptr; }
    virtual void solve_L_LT_u_eq_f ( double *u, double *f, sbfMatrixIterator *iterator = nullptr ) { }
    virtual void solve_L_D_LT_u_eq_f ( double *u, double *f, sbfMatrixIterator *iterator = nullptr ) { }

    virtual bool isValid() { return false; }

    virtual double *data() const { return nullptr; }

    void multiplyByVector ( double *vector, double *result, sbfMatrixIterator *iterator = nullptr );

    void lockDof ( int nodeIndex, int dofIndex, double value, double *force, LockType lockType );
};

#endif // SBFSTIFFMATRIX_H
