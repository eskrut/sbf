#ifndef SBFSTIFFMATRIXBAND6_H
#define SBFSTIFFMATRIXBAND6_H

class sbfStiffMatrixBand6;

#include "sbfStiffMatrix.h"
#include "sbfStiffMatrixBand6Iterator.h"

class sbfStiffMatrixBand6 : public sbfStiffMatrix
{
    friend class sbfStiffMatrixBand6Iterator;
public:
    explicit sbfStiffMatrixBand6(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type = MatrixType::FULL_MATRIX);
    ~sbfStiffMatrixBand6();

private:
    static const int blockDim_ = 6;
    static const int blockSize_ = blockDim_*blockDim_;

    //Number of nodes, used to construct stiffness matrix. I.e. nodes in FE mesh.
    int numNodes_;
    //Number of stiffness blocks in matrix.
    int numBlocks_;
    //Number of stiffness blocks in alternative storage. To deal with symetry.
    int numBlocksAlter_;
    //Linear storage array for stiffness data by blocks of 36 values. [36*numBlocks_]
    double *data_;
    //Indexes of first and last (included) stiffness blocks in data_. [numNodes_*2] [indJ0(of indI0), indJK(of indI0), ...].
    int *indJ_;
    //Array for indexing to certain stiff block row. [numNodes_+1]
    int *shiftInd_;
    //Indexes of stiffness blocks with alternative storage. != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    int *indJAlter_;
    //Array for indexing to certain stiff block row with alternative storage. != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    int *shiftIndAlter_;
    //Array of pointers to data corresponded to alternative indexation. != nullptr when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
    double **ptrDataAlter_;

    //Column iteration indexation
    std::vector<std::vector<std::pair<int /*rowId*/, double* /*ptr*/> /*column*/ > > columnsIndsPtrs_;
    std::vector<std::vector<std::pair<int /*rowId*/, double* /*ptr*/> /*column*/ > > columnsIndsPtrsAlter_;

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
    //Update columns indexing
    void updateColumnsIndsPtrs();

public:
    MatrixStoreType storeType() const { return MatrixStoreType::FULL; }
    sbfMatrixIterator *createIterator() /*const*/;
    void compute(int startID, int stopID);
    sbfStiffMatrix *createChol() /*const*/;
    sbfStiffMatrix *createLDLT();
    void solve_L_LT_u_eq_f(double *u, double *f, sbfMatrixIterator *iterator = nullptr);
    void solve_L_D_LT_u_eq_f(double *u, double *f, sbfMatrixIterator *iterator = nullptr);
    bool isValid();
    double *data() const { return data_; }
    void read_stream(std::ifstream &in);
    void write_stream(std::ofstream &out) const;
    int numDof() const { return blockDim_; }
};

#endif // SBFSTIFFMATRIXBAND6_H
