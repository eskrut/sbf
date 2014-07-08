#ifndef SBFSTIFFMATRIXBLOCK3X3_H
#define SBFSTIFFMATRIXBLOCK3X3_H

class sbfStiffMatrixBlock3x3;

#include "sbfStiffMatrix.h"
#include "sbfStiffMatrixBlock3x3Iterator.h"

class sbfStiffMatrixBlock3x3 : public sbfStiffMatrix
{
    friend class sbfStiffMatrixBlock3x3Iterator;
public:
    explicit sbfStiffMatrixBlock3x3(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type = MatrixType::FULL_MATRIX);
    ~sbfStiffMatrixBlock3x3();

private:
    static const int blockDim_ = 3;
    static const int blockSize_ = blockDim_*blockDim_;

    //FIXME the following is copy/paste from other class. Consider to make some base template class with blockSize_ as parameter
    //Number of nodes, used to construct stiffness matrix. I.e. nodes in FE mesh.
    int numNodes_;
    //Number of stiffness blocks in matrix.
    int numBlocks_;
    //Number of stiffness blocks in alternative storage. To deal with symetry.
    int numBlocksAlter_;
    //Linear storage array for stiffness data by blocks of 36 values. [36*numBlocks_]
    double *data_;
    //Indexes of stiffness blocks in data_. [numBlocks_] [indJ0(of indI0), indJ1(of indI0), ...].
    int *indJ_;
    //Array for indexing to certain stiff block row. [numNodes_+1]
    int *shiftInd_;
    //Indexes of stiffness blocks with alternative storage. != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    int *indJAlter_;
    //Array for indexing to certain stiff block row with alternative storage. != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    int *shiftIndAlter_;
    //Array of pointers to data corresponded to alternative indexation. != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    double **ptrDataAlter_;
    //Basic initialization function
    void init();
    //Clean all data (call delete for initialized arrays)
    void clean();
    //Prepare required arrays according to matrix type, nodes and blocks nambers
    void allocate();
    //Reallocate memory for matrix in accordance to numbers of blocks and nodes. numNodes required to perform indexing to certain row of blocks
    void setNumBlocksNodes(int numBlocks, int numNodes, int numBlocksAlter = 0);
    //Calculate indexes and shift arrays by sbfMesh mesh topology and target matrix topology for specific elements indexes
    //General method
    void updateIndexesFromMesh(int *begin, int *end);
    //Reimplementation for continious sequence of elements
    void updateIndexesFromMesh(int startElemIndex, int stopElemIndex);
    //Reimplementation for all elements in mesh
    void updateIndexesFromMesh();
    //Set all blocks to null
    void null();
    //Updates pointers in alter storage
    void updataAlterPtr();
    //Returns pointer to stiffness block with indexes indI, indJ. Search in regular storage ONLY
    double * blockPtr(int indI, int indJ);

public:
    MatrixStoreType storeType() const { return MatrixStoreType::COMPACT; }
    sbfMatrixIterator *createIterator() /*const*/;
    void compute(int startID, int stopID);
    sbfStiffMatrix *createIncompleteChol() /*const*/;
    void solve_L_LT_u_eq_f(double *u, double *f, sbfMatrixIterator *iterator = nullptr);
    bool isValid();
    void read_stream(std::ifstream &in);
    void write_stream(std::ofstream &out) const;
    int numDof() const { return blockDim_; }
};

#endif // SBFSTIFFMATRIXBLOCK3X3_H
