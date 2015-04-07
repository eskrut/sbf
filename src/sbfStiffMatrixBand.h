#ifndef SBFSTIFFMATRIXBAND_H
#define SBFSTIFFMATRIXBAND_H

template <int dim> class sbfStiffMatrixBand;

#include "sbfStiffMatrix.h"
#include "sbfStiffMatrixBandIterator.h"

/**
 * @brief The sbfStiffMatrixBand class is a template class for storing and
 * processing stiffness matrices as rows of bands with band width specified in
 * template parameter. This template is used to implicitly generate classes of 3
 * and 6 band width which included to library as precompiled classes.
 * @see sbfStiffMatrixBand3 sbfStiffMatrixBand6
 */

template <int dim>
class sbfStiffMatrixBand : public sbfStiffMatrix
{
public:
    explicit sbfStiffMatrixBand(sbfMesh *mesh,
                                sbfPropertiesSet *propSet,
                                MatrixType type = MatrixType::FULL_MATRIX);
    ~sbfStiffMatrixBand();
private:
    //! @brief blockDim_ Dimention of blocks stored in matrix. I.e. DOF at node
    static const int blockDim_ = dim;
    //! @brief blockSize_ Length of single block stored in matrix
    static const int blockSize_ = blockDim_*blockDim_;

public:
    virtual void compute(int startID, int stopID) {}
    virtual sbfMatrixIterator *createIterator() /*const*/ {}
    virtual int numDof() const {}
};

#endif // SBFSTIFFMATRIXBAND_H
