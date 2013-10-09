#ifndef _SBFMATRIX_H_
#define _SBFMATRIX_H_

#include "stdio.h"

#include "sbfMesh.h"
#include "sbfProperty.h"

namespace sbf{

//Forward declaration
class DECLSPEC StiffBlock3x3;
class DECLSPEC StiffMatrixBlock3x3;

class DECLSPEC ElemStiffMatrixHexa8;

enum BlockType {NO_DEFINED_BLOCK, DIAGONAL_BLOCK, UP_TREANGLE_BLOCK, DOWN_TREANGLE_BLOCK};
enum MatrixType {NO_DEFINED_MATRIX, FULL_MATRIX, UP_TREANGLE_MATRIX, DOWN_TREANGLE_MATRIX};
enum LockType {EXACT_LOCK_TYPE, APPROXIMATE_LOCK_TYPE};

struct StiffMatrixBlock3x3MultiplicationData// <- Goes to .h file to include in StiffMatrixBlock3x3 class
{
	int startRow, stopRow;//Start and stop rows of this matrix part
	int *rowIndexes, rowIndexesLength;//For version with not sequenced rows
	StiffMatrixBlock3x3 *stiffMatrix;
	double *vector, *result;//pointers to data
	ThreadType thread;
	EventType start, stop;
	int threadID;
	bool flagCancel;
};

class DECLSPEC StiffBlock3x3
{
public:
	StiffBlock3x3();
	StiffBlock3x3(const StiffBlock3x3 & block);
	virtual ~StiffBlock3x3();
private:
	double *data_;//Linear storage array for stiffness block, i.e. 9 doubles
	BlockType type_;//Block location type
	int length_;//Length of block data
	int indI_, indJ_;//Global indexes of block in terms of node numbers
public:
	double *data();//Returns pointer to block array
	void setType(BlockType type);
	BlockType type();
	//Get/set block indexes
	int indI();
	int indJ();
	void setIndI(int ind);
	void setIndJ(int ind);
	int dataLength();//Returns length of block data
};

class DECLSPEC StiffMatrixBlock3x3
{
public:
	StiffMatrixBlock3x3();
	StiffMatrixBlock3x3(int numBlocks, int numNodes);
	//StiffMatrixBlock3x3(const StiffMatrixBlock3x3 & matrix);
	virtual ~StiffMatrixBlock3x3();
private:
	MatrixType type_;//Matrix topology type.
	int numNodes_;//Number of nodes, used to construct stiffness matrix. I.e. nodes in FE mesh.
	int numBlocks_;//Number of stiffness blocks in matrix.
	int numBlocksAlter_;//Number of stiffness blocks in alternative storage.
	double *data_;//Linear storage array for stiffness data by blocks of 9 values. [9*numBlocks_]
	int *indJ_;//Indexes of stiffness blocks in data_. [numBlocks_] [indJ0(of indI0), indJ1(of indI0), ...].
	int *shiftInd_;//Array for indexing to certain stiff block row. [numNodes_+1]
	int *indJAlter_;//Indexes of stiffness blocks with alternative storage. != NULL when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
	int *shiftIndAlter_;//Array for indexing to certain stiff block row with alternative storage. != NULL when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
	double **ptrDataAlter_;//Array of pointers to data corresponded to alternative indexation. != NULL when UP_TREANGLE_MATRIX or DOWN_TREANGLE_MATRIX
	bool * flagInitialized_;//Indicators of blocks initialization. [numBlocks_]
	bool isDOFMerged_;//Flag of matrix assemblage type; if false - blocks with equal indexes form different elements stored separately

	//StiffMatrixBlock3x3MultiplicationData * threadsData_;//For processing matrix multiplication with threads
	StiffMatrixBlock3x3MultiplicationData threadsData_[SBF_NUM_THREADS];

	sbfMesh * mesh_;//Pointer to corresponding mesh
	sbfPropertiesSet * propSet_;//Pointer to set of materials properties

	void init();//Basic initialization function
	void clean();//Clean all data (call delete for initialized arrays)
	void allocate();//Prepare required arrays according to matrix type, nodes and blocks nambers
	void setNumBlocksNodes(int numBlocks, int numNodes, int numBlocksAlter = 0);//Reallocate memory for matrix in accordance to numbers of blocks and nodes. numNodes required to perform indexing to certain row of blocks
public:
	//Calculate indexes and shift arrays by sbfMesh mesh topology and target matrix topology for specific elements indexes
	void updateIndexesFromMesh(int *elemIndexes, int elemIndexesLength, MatrixType type = FULL_MATRIX, bool merge = true);//General method
	void updateIndexesFromMesh(int startElemIndex, int stopElemIndex, MatrixType type = FULL_MATRIX, bool merge = true);//Reimplementation for continious sequence of elements
	void updateIndexesFromMesh(MatrixType type = FULL_MATRIX, bool merge = true);//Reimplementation for all elements in mesh
	double * blockPtr(int indI, int indJ);//Returns pointer to stiffness block with indexes indI, indJ. Search in regular storage ONLY
	double * data(int indI, int indJ, bool *isDirect = NULL);//Returns pointer to stiffness block with indexes indI, indJ. Optionally set flag of normal or alternative storage
	const double * data();//Returns pointer to the start of data block.
	double * addBlockData(double * data, int indI, int indJ);
	const int * indData();
	const int * shiftIndData();
	double ** ptrDataAlter();//Returns pointer to the start of Alter data block pointers.
	const int * indDataAlter();
	const int * shiftIndDataAlter();
	//Set indexing arrays
	void setIndData(int numNodes, int numBlocks, int * indJ, int * shiftInd, int numBlocksAlter = 0, int * indJAlter = NULL, int * shiftIndAlter = NULL);
	void updataAlterPtr();
	int numNodes();
	int numBlocks();
	void setType(MatrixType type);
	MatrixType type();
	//Nulling entire matrix or specific block
	void null();
	void null(int indI, int indJ);
	int checkNulls();//Check if all block are initialized; 0 - all are nulls, 1 - some blocks are null, 2 - all are initialized

	void compute();//Compute stiffness matrixes of all elements and assembly to this
	void compute(int *elemIndexes, int elemIndexesLength);
	void computeParallel();//Compute stiffness matrixes of all elements and assembly to this in parallel mode
	void computeParallel(int *elemIndexes, int elemIndexesLength);
	void lockKort(int indI, int kort, double val = 0.0, double * force = NULL, LockType lockType = EXACT_LOCK_TYPE);

	void multiplyByVector(double * vector, double * result);//Multiply this matrix by vector and store result (memory should be allocated for result)
	void multiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength);//Multiply this matrix by vector and store result with specified rows to process

	//Prepare data to further parallel multiplying, i.e. prepare threads and signals
	void prepareParallelMultiplyByVector(double * vector, double * result);
	void prepareParallelMultiplyByVector(double * vector, double * result, int *rowIndexes, int rowIndexesLength);
	void makeParallelMultiplyByVector();//Make multiplication with prepared settings
	void clearParallelMultiplyByVector();//Stop threads and destroy mutexes

	void read(std::ifstream &in);
	void write(std::ofstream &out);

	void printTopology(const char * name);
	void printTopology2(const char * name, int plotRate = 1);

	void setMesh(sbfMesh * mesh);
	sbfMesh * mesh();
	void setPropSet(sbfPropertiesSet * propSet);
	sbfPropertiesSet * propSet();

	StiffMatrixBlock3x3 * makeIncompleteChol(double thresholdAmp = 0);//Create new low triangle matrix with incomplete cholessky factor
};

class DECLSPEC ElemStiffMatrixHexa8
{
public:
	ElemStiffMatrixHexa8();
	ElemStiffMatrixHexa8(sbfElement * elem);
	virtual ~ElemStiffMatrixHexa8();
private:
	double *data_;//Linear storage array for element stiffness matrix.
	sbfElement *elem_;//Pointer to linked geometric element.
	int numIntPoints_;//Number of points for numerical integration.
	double crd_[8*3];//Coordinates of element nodes.
	int ind_[8];//Indexes of element nodes.
	double J_[9];//Jacobian.
	double detJ_;//determinant of Jacobian.
	double invJ_[9];//invert Jacobian.
	double H_[8];//temporary hold of form functions values.
	double DHDN_[8*3];//temporary hold of form functions derivatives over natural coordinates.
	double DHDG_[8*3];//temporary hold of form functions derivatives over global coordinates.
	double temp_[8*3*6];//temporary hold for result of matrix multiplication BT*C. ? Sparse matrix with constant topology - may it necessary to optimize memory

	sbfPropertiesSet * propSet_;//Pointer to set of materials properties
public:
	//Set/get linked element
	void setElem(sbfElement *elem);
	sbfElement & elem();
	//Set/get number of points in each directions which are used in numerical integration
	void setNumIntPoints(int numIntPoints);
	int numIntPoints();

	void computeH(double r, double s, double t);//Compute values of form functions at natural coordinates (r, s, t).
	void computeDHDN(double r, double s, double t);//Compute values of form functions derivations over natural coordinates at natural coordinates (r, s, t).
	void computeDHDG(double r, double s, double t);//Compute values of form functions derivations over global coordinates at natural coordinates (r, s, t).
	void computeJ();//Compute Jacobian, its determinant and inverse at natural coordinates (r, s, t).
	void computeSM();//Compute stiffness matrix.

	double computeMass();//Compute element mass
	double computeMass(double rho);//Compute element mass
	double computeVolume();//Compute element volume

	void getBlockDataLoc(double * data, int localIndI, int localIndJ);//Store stiffness block 3*3 of local indexes localIndI & localIndJ into data as linear array (no check or allocation of memory).
	void getBlockDataGlob(double * data, int indI, int indJ);//Store stiffness block 3*3 of global indexes indI & indJ into data as linear array (no check or allocation of memory).
	//Similar, but adds data not replace
	void addBlockDataLoc(double * data, int localIndI, int localIndJ);
	void addBlockDataGlob(double * data, int indI, int indJ);
	double * data();//Returns pointer to linear array with stiff data.

	void setPropSet(sbfPropertiesSet * propSet);
	sbfPropertiesSet * propSet();
};

DECLSPEC void saveNodesDataFloat_NumNodesX3(double * data, int numNodes, const char * baseName, int count, const char * ext = ".sba", const int numDigits = 4);
template <class WhatToSaveType, class HowToSaveType, int kort> void saveNodesData(WhatToSaveType * data, int numNodes, const char * baseName, int count, const char * ext = ".sba", const int numDigits = 4)/*;
template <class WhatToSaveType, class HowToSaveType, int kort> void sbf::saveNodesData(WhatToSaveType * data, int numNodes, const char * baseName, int count, const char * ext, const int numDigits)*/
{
	HowToSaveType * tempF = new HowToSaveType [numNodes*kort];
	for(int ct1 = 0; ct1 < kort; ++ct1){
		for(int ct = 0; ct < numNodes; ct++){
			tempF[ct1*numNodes + ct] = (HowToSaveType)data[kort*ct + ct1];
		}
	}
	std::stringstream sstr;
	sstr << baseName;
	sstr.width(numDigits);
	sstr.fill('0');
	sstr << count;
	sstr << ext;
	std::ofstream out(sstr.str().c_str(), std::ios::binary);
	out.write((char *)tempF, numNodes*kort*sizeof(HowToSaveType));
	out.close();
	delete [] tempF;
}


}//end namespace sbf
#endif /* _SBFMATRIX_H_ */
