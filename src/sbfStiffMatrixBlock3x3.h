#ifndef SBFSTIFFMATRIXBLOCK3X3_H
#define SBFSTIFFMATRIXBLOCK3X3_H

#include <fstream>
#include "sbfDeclspec.h"
#include "sbfEnums.h"
#include "sbfMesh.h"

class sbfStiffBlock3x3;
class sbfPropertiesSet;
class sbfStiffMatrixBlock3x3;
class sbfStiffMatrixBlock3x3Iterator;

struct StiffMatrixBlock3x3MultiplicationData
{
    int startRow, stopRow;//Start and stop rows of this matrix part
    int *rowIndexes, rowIndexesLength;//For version with not sequenced rows
    sbfStiffMatrixBlock3x3 *stiffMatrix;
    double *vector, *result;//pointers to data
    ThreadType thread;
    EventType start, stop;
    int threadID;
    bool flagCancel;
};

class DECLSPEC sbfStiffMatrixBlock3x3
{
    //FIXME class should provide indexes of rows number for sertain columns.
    //Otherwice loops like
    /*
     *for(int colCt = 0; colCt < diagCt; colCt++){//Loop on blocks in row
     *  blockCt = cholFactor->blockPtr(diagCt, colCt);
     *  if(!blockCt) continue;
     *  ...
     *}
    */
    // will be uneffitient
public:
    sbfStiffMatrixBlock3x3();
    sbfStiffMatrixBlock3x3(int numBlocks, int numNodes);
    //StiffMatrixBlock3x3(const StiffMatrixBlock3x3 & matrix);
    ~sbfStiffMatrixBlock3x3();
private:
    //Matrix topology type.
    MatrixType type_;
    //Number of nodes, used to construct stiffness matrix. I.e. nodes in FE mesh.
    int numNodes_;
    //Number of stiffness blocks in matrix.
    int numBlocks_;
    //Number of stiffness blocks in alternative storage. To deal with symetry.
    int numBlocksAlter_;
    //Linear storage array for stiffness data by blocks of 9 values. [9*numBlocks_]
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
    //Indicators of blocks initialization. [numBlocks_]
    bool * flagInitialized_;
    //Flag of matrix assemblage type; if false - blocks with equal indexes form different elements stored separately
    bool isDOFMerged_;

    //StiffMatrixBlock3x3MultiplicationData * threadsData_;//For processing matrix multiplication with threads
    StiffMatrixBlock3x3MultiplicationData threadsData_[sbfNumThreads];

    sbfMesh * mesh_;//Pointer to corresponding mesh
    sbfPropertiesSet * propSet_;//Pointer to set of materials properties

    //Basic initialization function
    void init();
    //Clean all data (call delete for initialized arrays)
    void clean();
    //Prepare required arrays according to matrix type, nodes and blocks nambers
    void allocate();
    //Reallocate memory for matrix in accordance to numbers of blocks and nodes. numNodes required to perform indexing to certain row of blocks
    void setNumBlocksNodes(int numBlocks, int numNodes, int numBlocksAlter = 0);
public:
    //Calculate indexes and shift arrays by sbfMesh mesh topology and target matrix topology for specific elements indexes
    //General method
    void updateIndexesFromMesh(int *elemIndexes, int elemIndexesLength, MatrixType type = FULL_MATRIX, bool merge = true);
    //Reimplementation for continious sequence of elements
    void updateIndexesFromMesh(int startElemIndex, int stopElemIndex, MatrixType type = FULL_MATRIX, bool merge = true);
    //Reimplementation for all elements in mesh
    void updateIndexesFromMesh(MatrixType type = FULL_MATRIX, bool merge = true);
    //Returns pointer to stiffness block with indexes indI, indJ. Search in regular storage ONLY
    double * blockPtr(int indI, int indJ);
    //Returns pointer to stiffness block with indexes indI, indJ. Optionally set flag of normal or alternative storage
    double * data(int indI, int indJ, bool *isDirect = nullptr);
    //Returns pointer to the start of data block.
    const double * data();
    double * addBlockData(double * data, int indI, int indJ);
    const int * indData();
    const int * shiftIndData();
    //Returns pointer to the start of Alter data block pointers.
    double ** ptrDataAlter();
    const int * indDataAlter();
    const int * shiftIndDataAlter();
    //Set indexing arrays. This will make deep copy.
    void setIndData(int numNodes, int numBlocks, int * indJ, int * shiftInd, int numBlocksAlter = 0, int * indJAlter = nullptr, int * shiftIndAlter = nullptr);
    void updataAlterPtr();
    int numNodes();
    int numBlocks();
    void setType(MatrixType type);
    MatrixType type();
    //Nulling entire matrix or specific block
    void null();
    void null(int indI, int indJ);
    //Check if all block are initialized; 0 - all are nulls, 1 - some blocks are null, 2 - all are initialized
    int checkNulls();
    std::vector<std::vector<int>> columnsInRows();
    std::vector<std::vector<int>> rowsInColumns();

    //TODO make methods like:
    //TODO UPD it may be better to make some class which halps to iterate through non-zero elements in rows and columns
    sbfStiffMatrixBlock3x3Iterator * createIterator();
    //void setRefBlock(int indI, int indJ);
    //std::pair<double * blockPtr, int columnInd> nextInRow();
    //std::pair<double * blockPtr, int rowInd> nextInColumn();

    //Compute stiffness matrixes of all elements and assembly to this
    void compute();
    void compute(int *elemIndexes, int elemIndexesLength);
    //Compute stiffness matrixes of all elements and assembly to this in parallel mode
    void computeParallel();
    void computeParallel(int *elemIndexes, int elemIndexesLength);
    void lockKort(int indI, int kort, double val = 0.0, double * force = nullptr, LockType lockType = EXACT_LOCK_TYPE);

    //Multiply this matrix by vector and store result (memory should be allocated for result)
    void multiplyByVector(double * vector, double * result);
    //Multiply this matrix by vector and store result with specified rows to process
    void multiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength);

    //Prepare data to further parallel multiplying, i.e. prepare threads and signals
    void prepareParallelMultiplyByVector(double * vector, double * result);
    void prepareParallelMultiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength);
    //Make multiplication with prepared settings
    void makeParallelMultiplyByVector();
    //Stop threads and destroy mutexes
    void clearParallelMultiplyByVector();

    void read(std::ifstream &in);
    void write(std::ofstream &out);

    void printTopology(const char * name);
    void printTopology2(const char * name, int plotRate = 1);

    void setMesh(sbfMesh * mesh);
    sbfMesh * mesh();
    void setPropSet(sbfPropertiesSet * propSet);
    sbfPropertiesSet * propSet();

    //Create new low triangle matrix with incomplete cholessky factor
    sbfStiffMatrixBlock3x3 * makeIncompleteChol();
    void solve_L_LT_u_eq_f(double *u, double *f);
};

#endif // SBFSTIFFMATRIXBLOCK3X3_H
