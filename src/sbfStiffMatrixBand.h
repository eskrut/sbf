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
 * @see sbfStiffMatrixBand3 sbfStiffMatrixBand6 sbfStiffMatrix
 */

template <int dim>
class sbfStiffMatrixBand : public sbfStiffMatrix
{
    friend class sbfStiffMatrixBandIterator<dim>;
public:
    //! Construct matrix, initialize arrays and prepare indexation
    explicit sbfStiffMatrixBand ( sbfMesh *mesh,
                                  sbfPropertiesSet *propSet,
                                  MatrixType type = MatrixType::FULL_MATRIX );
    //! Destroy object, clean arrays
    ~sbfStiffMatrixBand();
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
    //! Indexes of first and last (included) stiffness blocks in data_
    //! Length is [numNodes_*2]
    //! Content is [indJ0(of indI0), indJK(of indI0), ...].
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
    //! Column iteration indexation
    std::vector<std::vector<
    std::pair<int /*rowId*/, double * /*ptr*/> /*column*/
    > > columnsIndsPtrs_;
    //! Column iteration indexation in alter storage
    std::vector<std::vector<
    std::pair<int /*rowId*/, double * /*ptr*/> /*column*/
    > > columnsIndsPtrsAlter_;

    //! Basic initialization function
    void init();
    //! Clean all data (call delete for initialized arrays)
    void clean();
    //! Prepare required arrays according to matrix type,
    //! nodes and blocks nambers
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
    //! Update columns indexing
    void updateColumnsIndsPtrs();

public:

    //Implementations of base pure virtual functions

    //! Implementation of stiff matrix compute and assembly
    virtual void compute ( int startID, int stopID );
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
    //! Create Cholessky factor L LT
    sbfStiffMatrix *createChol();
    //! Create L D LT factor
    sbfStiffMatrix *createLDLT();
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
    //! Solve L*D*LT*u=f equation. Matrix should by Chol factor
    /**
     * @param u left side - displacements
     * @param f right side - forces
     * @param iterator matrix iterator to use in solution. If nullptr new
     * iterator will be created and destroyed while solving.
     */
    void solve_L_D_LT_u_eq_f ( double *u,
                               double *f,
                               sbfMatrixIterator *iterator = nullptr );
};

#endif // SBFSTIFFMATRIXBAND_H
