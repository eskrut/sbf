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
    friend class sbfStiffMatrixBlockIterator<dim>;
public:
    explicit sbfStiffMatrixBlock ( sbfMesh *mesh,
                                   sbfPropertiesSet *propSet,
                                   MatrixType type = MatrixType::FULL_MATRIX,
                                   bool makeReport = false);
    ~sbfStiffMatrixBlock();

private:
    //! Dimention of blocks stored in matrix. I.e. DOF at node
    static const int blockDim_ = dim;
    //! Length of single block stored in matrix
    static const int blockSize_ = blockDim_ * blockDim_;

    //TODO consider types of numNodes, numBlocks, numBlocksAlter
    //! Number of nodes used to construct stiffness matrix (nodes in FE mesh)
    size_t numNodes_;
    //! Number of stiffness blocks in matrix
    size_t numBlocks_;
    //! Number of stiffness blocks in alternative storage. To deal with symetry
    size_t numBlocksAlter_;
    //! Linear storage array for stiffness data by blocks
    //! Length is [blockDim_^2*numBlocks_]
    double *data_;
    //! Indexes of stiffness blocks in data_.
    //! Length is [numBlocks_] : [indJ0(of indI0), indJ1(of indI0), ... indJN(on indIN)].
    size_t *indJ_;
    //! Array for indexing to certain stiff block row
    //! Length is [numNodes_+1]
    size_t *shiftInd_;
    //! Indexes of stiffness blocks with alternative storage
    //! shiftInd_ != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    size_t *indJAlter_;
    //! Array for indexing to certain stiff block row with alternative storage
    //! shiftIndAlter_ != nullptr when UP_TREANGLE_MATRIX or
    //! DOWN_TREANGLE_MATRIX
    size_t *shiftIndAlter_;
    //! Array of pointers to data corresponded to alternative indexation
    //! ptrDataAlter_ != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    double **ptrDataAlter_;
    //! Column iteration indexation
    std::vector<std::vector<
    std::pair<size_t /*rowId*/, double * /*ptr*/> /*column*/
    > > columnsIndsPtrs_;
    //! Column iteration indexation in alter storage
    std::vector<std::vector<
    std::pair<size_t /*rowId*/, double * /*ptr*/> /*column*/
    > > columnsIndsPtrsAlter_;

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
    void setNumBlocksNodes ( size_t numBlocks, size_t numNodes, size_t numBlocksAlter = 0 );
    //! Calculate indexes and shift arrays by sbfMesh mesh topology and target
    //! matrix topology for specific elements indexes
    //@{
    /**
     * General method
     * @param begin pointer to first element in array of processing elements IDs
     * @param end pointer to end (last+1) of processing elements IDs
     */
    void updateIndexesFromMesh (unsigned int *begin, unsigned int *end , bool makeReport = true);
    //! Reimplementation for continious sequence of elements
    void updateIndexesFromMesh ( unsigned int startElemIndex, unsigned int stopElemIndex, bool makeReportu = true );
    //! Reimplementation for all elements in mesh
    void updateIndexesFromMesh(bool makeReport = true);
    //@}
    //! Updates pointers in alter storage
    void updataAlterPtr();
    //! Returns pointer to stiffness block with indexes indI, indJ.
    //! Search in regular storage ONLY
    double *blockPtr (unsigned int indI, unsigned int indJ );
    //! Update columns indexing
    void updateColumnsIndsPtrs();

public:

    //Implementations of base pure virtual functions

//    //! Implementation of stiff matrix compute and assembly
//    virtual void compute ( int startID, int stopID );
    //! Set all blocks to null
    virtual void null();
    //! Create new matrix iterator
    virtual sbfMatrixIterator *createIterator() /*const*/;
    //! Get number of DOF. @see blockDim_
    virtual int numDof() const { return blockDim_; }

    //Implementations of base virtual functions

    //! Get type of matrix topology
    MatrixStoreType storeType() const { return MatrixStoreType::FULL; }
    //! Test matrix validness
    bool isValid();
    //! Get pointer to data
    double *data() const { return data_; }
    //! Read matrix from file stream
    void read_stream ( std::ifstream &in );
    //! Write matrix to file stream
    void write_stream ( std::ofstream &out ) const;
    //! Create incomplete Cholessky factor L LT
    sbfStiffMatrix *createIncompleteChol() /*const*/;
    //! Solve L*LT*u=f equation. Matrix should by L LT factor
    /**
     * @param u left side - displacements
     * @param f right side - forces
     * @param iterator matrix iterator to use in solution. If nullptr new
     * iterator will be created and destroyed while solving.
     */
    void solve_L_LT_u_eq_f ( double *u,
                             double *f,
                             sbfMatrixIterator *iterator = nullptr );
};

#endif // SBFSTIFFMATRIXBLOCK_H
