#ifndef SBFSTIFFMATRIXBLOCK_H
#define SBFSTIFFMATRIXBLOCK_H

template <int dim> class sbfStiffMatrixBlock;

#include "sbfStiffMatrix.h"
#include "sbfStiffMatrixBlockIterator.h"

/**
 * @brief The sbfStiffMatrixBlock class is a template class for storing and
 * processing stiffness matrices as rows of nonzero blocks with dimention specified in
 * template parameter. This template is used to implicitly generate classes of 3
 * and 6 block dimentions which included to library as precompiled classes.
 * @see sbfStiffMatrixBlock3 sbfStiffMatrixBlock6 sbfStiffMatrix
 */

template <int dim>
class sbfStiffMatrixBlock : public sbfStiffMatrix
{
public:
    explicit sbfStiffMatrixBlock ( sbfMesh *mesh,
                                   sbfPropertiesSet *propSet,
                                   MatrixType type = MatrixType::FULL_MATRIX );
    ~sbfStiffMatrixBlock();

private:
    //! Dimention of blocks stored in matrix. I.e. DOF at node
    static const int blockDim_ = dim;
    //! Length of single block stored in matrix
    static const int blockSize_ = blockDim_ * blockDim_;

    //! Number of nodes used to construct stiffness matrix (nodes in FE mesh)
    int numNodes_;
    //! Number of stiffness blocks in matrix
    int numBlocks_;
    //! Number of stiffness blocks in alternative storage. To deal with symetry
    int numBlocksAlter_;
    //! Linear storage array for stiffness data by blocks
    //! Length is [blockDim_^2*numBlocks_]
    double *data_;
    //! Indexes of stiffness blocks in data_.
    //! Length is [numBlocks_] : [indJ0(of indI0), indJ1(of indI0), ... indJN(on indIN)].
    int *indJ_;
    //! Array for indexing to certain stiff block row
    //! Length is [numNodes_+1]
    int *shiftInd_;
    //! Indexes of stiffness blocks with alternative storage
    //! shiftInd_ != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    int *indJAlter_;
    //! Array for indexing to certain stiff block row with alternative storage
    //! shiftIndAlter_ != nullptr when UP_TREANGLE_MATRIX or
    //! DOWN_TREANGLE_MATRIX
    int *shiftIndAlter_;
    //! Array of pointers to data corresponded to alternative indexation
    //! ptrDataAlter_ != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    double **ptrDataAlter_;

    //! Basic initialization function
    void init();
    //! Clean all data (call delete for initialized arrays)
    void clean();
    //! Prepare required arrays according to matrix type, nodes and blocks nambers
    void allocate();
    //! Reallocate memory for matrix in accordance to numbers of blocks and
    //! nodes. numNodes required to perform indexing to certain row of blocks
    /**
     * @param numBlocks number of blocks in matrix
     * @param numNodes number of nodes
     * @param numBlocksAlter number of blocks in alter storage
     */
    void setNumBlocksNodes ( int numBlocks, int numNodes, int numBlocksAlter = 0 );
    //! Calculate indexes and shift arrays by sbfMesh mesh topology and target
    //! matrix topology for specific elements indexes
    //@{
    /**
     * General method
     * @param begin pointer to first element in array of processing elements IDs
     * @param end pointer to end (last+1) of processing elements IDs
     */
    void updateIndexesFromMesh ( int *begin, int *end );
    //! Reimplementation for continious sequence of elements
    void updateIndexesFromMesh ( int startElemIndex, int stopElemIndex );
    //! Reimplementation for all elements in mesh
    void updateIndexesFromMesh();
    //@}
    //! Set all blocks to null
    void null();
    //! Updates pointers in alter storage
    void updataAlterPtr();
    //! Returns pointer to stiffness block with indexes indI, indJ.
    //! Search in regular storage ONLY
    double *blockPtr ( int indI, int indJ );
};

#endif // SBFSTIFFMATRIXBLOCK_H
