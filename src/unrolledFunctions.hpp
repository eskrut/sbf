/* Automatically generated with generateUnrolledFunctions.py script
** DO NOT EDIT! */

#ifndef UNROLLED_FUNCTIONS_HPP
#define UNROLLED_FUNCTIONS_HPP

typedef void (*makeMulRowFuncPtrType)(double *, double *, double *, int *);
const int numMakeMulRowFunctions = 400;

typedef void (*makeMulRowAlterFuncPtrType)(double *, double **, double *, int *);
const int numMakeMulRowAlterFunctions = 400;

void makeMulRow_0(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 0; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_1(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 1; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_2(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 2; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_3(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 3; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_4(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 4; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_5(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 5; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_6(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 6; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_7(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 7; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_8(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 8; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_9(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 9; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_10(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 10; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_11(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 11; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_12(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 12; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_13(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 13; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_14(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 14; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_15(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 15; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_16(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 16; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_17(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 17; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_18(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 18; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_19(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 19; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_20(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 20; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_21(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 21; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_22(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 22; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_23(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 23; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_24(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 24; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_25(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 25; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_26(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 26; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_27(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 27; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_28(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 28; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_29(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 29; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_30(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 30; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_31(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 31; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_32(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 32; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_33(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 33; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_34(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 34; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_35(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 35; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_36(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 36; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_37(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 37; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_38(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 38; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_39(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 39; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_40(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 40; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_41(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 41; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_42(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 42; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_43(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 43; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_44(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 44; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_45(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 45; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_46(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 46; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_47(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 47; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_48(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 48; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_49(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 49; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_50(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 50; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_51(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 51; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_52(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 52; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_53(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 53; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_54(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 54; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_55(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 55; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_56(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 56; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_57(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 57; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_58(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 58; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_59(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 59; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_60(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 60; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_61(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 61; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_62(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 62; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_63(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 63; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_64(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 64; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_65(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 65; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_66(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 66; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_67(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 67; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_68(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 68; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_69(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 69; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_70(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 70; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_71(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 71; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_72(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 72; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_73(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 73; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_74(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 74; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_75(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 75; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_76(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 76; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_77(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 77; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_78(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 78; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_79(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 79; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_80(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 80; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_81(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 81; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_82(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 82; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_83(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 83; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_84(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 84; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_85(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 85; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_86(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 86; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_87(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 87; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_88(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 88; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_89(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 89; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_90(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 90; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_91(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 91; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_92(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 92; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_93(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 93; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_94(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 94; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_95(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 95; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_96(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 96; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_97(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 97; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_98(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 98; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_99(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 99; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_100(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 100; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_101(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 101; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_102(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 102; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_103(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 103; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_104(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 104; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_105(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 105; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_106(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 106; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_107(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 107; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_108(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 108; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_109(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 109; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_110(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 110; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_111(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 111; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_112(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 112; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_113(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 113; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_114(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 114; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_115(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 115; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_116(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 116; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_117(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 117; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_118(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 118; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_119(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 119; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_120(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 120; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_121(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 121; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_122(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 122; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_123(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 123; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_124(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 124; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_125(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 125; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_126(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 126; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_127(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 127; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_128(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 128; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_129(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 129; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_130(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 130; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_131(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 131; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_132(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 132; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_133(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 133; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_134(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 134; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_135(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 135; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_136(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 136; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_137(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 137; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_138(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 138; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_139(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 139; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_140(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 140; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_141(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 141; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_142(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 142; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_143(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 143; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_144(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 144; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_145(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 145; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_146(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 146; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_147(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 147; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_148(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 148; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_149(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 149; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_150(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 150; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_151(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 151; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_152(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 152; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_153(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 153; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_154(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 154; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_155(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 155; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_156(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 156; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_157(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 157; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_158(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 158; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_159(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 159; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_160(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 160; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_161(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 161; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_162(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 162; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_163(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 163; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_164(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 164; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_165(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 165; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_166(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 166; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_167(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 167; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_168(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 168; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_169(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 169; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_170(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 170; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_171(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 171; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_172(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 172; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_173(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 173; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_174(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 174; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_175(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 175; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_176(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 176; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_177(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 177; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_178(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 178; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_179(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 179; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_180(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 180; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_181(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 181; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_182(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 182; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_183(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 183; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_184(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 184; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_185(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 185; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_186(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 186; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_187(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 187; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_188(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 188; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_189(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 189; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_190(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 190; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_191(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 191; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_192(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 192; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_193(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 193; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_194(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 194; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_195(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 195; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_196(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 196; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_197(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 197; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_198(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 198; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_199(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 199; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_200(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 200; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_201(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 201; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_202(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 202; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_203(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 203; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_204(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 204; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_205(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 205; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_206(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 206; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_207(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 207; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_208(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 208; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_209(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 209; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_210(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 210; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_211(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 211; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_212(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 212; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_213(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 213; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_214(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 214; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_215(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 215; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_216(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 216; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_217(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 217; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_218(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 218; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_219(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 219; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_220(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 220; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_221(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 221; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_222(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 222; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_223(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 223; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_224(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 224; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_225(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 225; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_226(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 226; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_227(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 227; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_228(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 228; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_229(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 229; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_230(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 230; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_231(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 231; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_232(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 232; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_233(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 233; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_234(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 234; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_235(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 235; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_236(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 236; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_237(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 237; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_238(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 238; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_239(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 239; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_240(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 240; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_241(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 241; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_242(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 242; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_243(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 243; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_244(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 244; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_245(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 245; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_246(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 246; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_247(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 247; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_248(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 248; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_249(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 249; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_250(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 250; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_251(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 251; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_252(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 252; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_253(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 253; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_254(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 254; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_255(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 255; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_256(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 256; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_257(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 257; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_258(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 258; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_259(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 259; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_260(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 260; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_261(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 261; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_262(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 262; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_263(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 263; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_264(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 264; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_265(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 265; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_266(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 266; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_267(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 267; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_268(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 268; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_269(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 269; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_270(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 270; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_271(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 271; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_272(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 272; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_273(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 273; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_274(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 274; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_275(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 275; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_276(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 276; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_277(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 277; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_278(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 278; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_279(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 279; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_280(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 280; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_281(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 281; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_282(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 282; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_283(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 283; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_284(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 284; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_285(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 285; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_286(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 286; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_287(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 287; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_288(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 288; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_289(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 289; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_290(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 290; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_291(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 291; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_292(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 292; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_293(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 293; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_294(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 294; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_295(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 295; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_296(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 296; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_297(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 297; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_298(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 298; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_299(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 299; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_300(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 300; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_301(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 301; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_302(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 302; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_303(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 303; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_304(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 304; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_305(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 305; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_306(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 306; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_307(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 307; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_308(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 308; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_309(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 309; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_310(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 310; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_311(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 311; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_312(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 312; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_313(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 313; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_314(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 314; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_315(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 315; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_316(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 316; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_317(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 317; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_318(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 318; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_319(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 319; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_320(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 320; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_321(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 321; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_322(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 322; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_323(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 323; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_324(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 324; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_325(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 325; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_326(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 326; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_327(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 327; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_328(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 328; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_329(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 329; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_330(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 330; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_331(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 331; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_332(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 332; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_333(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 333; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_334(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 334; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_335(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 335; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_336(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 336; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_337(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 337; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_338(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 338; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_339(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 339; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_340(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 340; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_341(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 341; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_342(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 342; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_343(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 343; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_344(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 344; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_345(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 345; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_346(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 346; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_347(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 347; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_348(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 348; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_349(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 349; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_350(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 350; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_351(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 351; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_352(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 352; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_353(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 353; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_354(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 354; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_355(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 355; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_356(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 356; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_357(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 357; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_358(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 358; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_359(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 359; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_360(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 360; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_361(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 361; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_362(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 362; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_363(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 363; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_364(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 364; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_365(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 365; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_366(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 366; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_367(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 367; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_368(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 368; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_369(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 369; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_370(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 370; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_371(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 371; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_372(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 372; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_373(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 373; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_374(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 374; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_375(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 375; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_376(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 376; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_377(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 377; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_378(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 378; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_379(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 379; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_380(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 380; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_381(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 381; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_382(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 382; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_383(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 383; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_384(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 384; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_385(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 385; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_386(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 386; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_387(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 387; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_388(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 388; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_389(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 389; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_390(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 390; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_391(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 391; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_392(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 392; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_393(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 393; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_394(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 394; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_395(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 395; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_396(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 396; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_397(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 397; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_398(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 398; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_399(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 399; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
void makeMulRow_400(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 400; ++ct){
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;
		tmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;
		tmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;
		stifPtr += 9;++shiftBase;
	}
	rezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;
}
static void (*makeMulRowFunctions[])(double *, double *, double *, int *) = {makeMulRow_0, makeMulRow_1, makeMulRow_2, makeMulRow_3, makeMulRow_4, makeMulRow_5, makeMulRow_6, makeMulRow_7, makeMulRow_8, makeMulRow_9, makeMulRow_10, makeMulRow_11, makeMulRow_12, makeMulRow_13, makeMulRow_14, makeMulRow_15, makeMulRow_16, makeMulRow_17, makeMulRow_18, makeMulRow_19, makeMulRow_20, makeMulRow_21, makeMulRow_22, makeMulRow_23, makeMulRow_24, makeMulRow_25, makeMulRow_26, makeMulRow_27, makeMulRow_28, makeMulRow_29, makeMulRow_30, makeMulRow_31, makeMulRow_32, makeMulRow_33, makeMulRow_34, makeMulRow_35, makeMulRow_36, makeMulRow_37, makeMulRow_38, makeMulRow_39, makeMulRow_40, makeMulRow_41, makeMulRow_42, makeMulRow_43, makeMulRow_44, makeMulRow_45, makeMulRow_46, makeMulRow_47, makeMulRow_48, makeMulRow_49, makeMulRow_50, makeMulRow_51, makeMulRow_52, makeMulRow_53, makeMulRow_54, makeMulRow_55, makeMulRow_56, makeMulRow_57, makeMulRow_58, makeMulRow_59, makeMulRow_60, makeMulRow_61, makeMulRow_62, makeMulRow_63, makeMulRow_64, makeMulRow_65, makeMulRow_66, makeMulRow_67, makeMulRow_68, makeMulRow_69, makeMulRow_70, makeMulRow_71, makeMulRow_72, makeMulRow_73, makeMulRow_74, makeMulRow_75, makeMulRow_76, makeMulRow_77, makeMulRow_78, makeMulRow_79, makeMulRow_80, makeMulRow_81, makeMulRow_82, makeMulRow_83, makeMulRow_84, makeMulRow_85, makeMulRow_86, makeMulRow_87, makeMulRow_88, makeMulRow_89, makeMulRow_90, makeMulRow_91, makeMulRow_92, makeMulRow_93, makeMulRow_94, makeMulRow_95, makeMulRow_96, makeMulRow_97, makeMulRow_98, makeMulRow_99, makeMulRow_100, makeMulRow_101, makeMulRow_102, makeMulRow_103, makeMulRow_104, makeMulRow_105, makeMulRow_106, makeMulRow_107, makeMulRow_108, makeMulRow_109, makeMulRow_110, makeMulRow_111, makeMulRow_112, makeMulRow_113, makeMulRow_114, makeMulRow_115, makeMulRow_116, makeMulRow_117, makeMulRow_118, makeMulRow_119, makeMulRow_120, makeMulRow_121, makeMulRow_122, makeMulRow_123, makeMulRow_124, makeMulRow_125, makeMulRow_126, makeMulRow_127, makeMulRow_128, makeMulRow_129, makeMulRow_130, makeMulRow_131, makeMulRow_132, makeMulRow_133, makeMulRow_134, makeMulRow_135, makeMulRow_136, makeMulRow_137, makeMulRow_138, makeMulRow_139, makeMulRow_140, makeMulRow_141, makeMulRow_142, makeMulRow_143, makeMulRow_144, makeMulRow_145, makeMulRow_146, makeMulRow_147, makeMulRow_148, makeMulRow_149, makeMulRow_150, makeMulRow_151, makeMulRow_152, makeMulRow_153, makeMulRow_154, makeMulRow_155, makeMulRow_156, makeMulRow_157, makeMulRow_158, makeMulRow_159, makeMulRow_160, makeMulRow_161, makeMulRow_162, makeMulRow_163, makeMulRow_164, makeMulRow_165, makeMulRow_166, makeMulRow_167, makeMulRow_168, makeMulRow_169, makeMulRow_170, makeMulRow_171, makeMulRow_172, makeMulRow_173, makeMulRow_174, makeMulRow_175, makeMulRow_176, makeMulRow_177, makeMulRow_178, makeMulRow_179, makeMulRow_180, makeMulRow_181, makeMulRow_182, makeMulRow_183, makeMulRow_184, makeMulRow_185, makeMulRow_186, makeMulRow_187, makeMulRow_188, makeMulRow_189, makeMulRow_190, makeMulRow_191, makeMulRow_192, makeMulRow_193, makeMulRow_194, makeMulRow_195, makeMulRow_196, makeMulRow_197, makeMulRow_198, makeMulRow_199, makeMulRow_200, makeMulRow_201, makeMulRow_202, makeMulRow_203, makeMulRow_204, makeMulRow_205, makeMulRow_206, makeMulRow_207, makeMulRow_208, makeMulRow_209, makeMulRow_210, makeMulRow_211, makeMulRow_212, makeMulRow_213, makeMulRow_214, makeMulRow_215, makeMulRow_216, makeMulRow_217, makeMulRow_218, makeMulRow_219, makeMulRow_220, makeMulRow_221, makeMulRow_222, makeMulRow_223, makeMulRow_224, makeMulRow_225, makeMulRow_226, makeMulRow_227, makeMulRow_228, makeMulRow_229, makeMulRow_230, makeMulRow_231, makeMulRow_232, makeMulRow_233, makeMulRow_234, makeMulRow_235, makeMulRow_236, makeMulRow_237, makeMulRow_238, makeMulRow_239, makeMulRow_240, makeMulRow_241, makeMulRow_242, makeMulRow_243, makeMulRow_244, makeMulRow_245, makeMulRow_246, makeMulRow_247, makeMulRow_248, makeMulRow_249, makeMulRow_250, makeMulRow_251, makeMulRow_252, makeMulRow_253, makeMulRow_254, makeMulRow_255, makeMulRow_256, makeMulRow_257, makeMulRow_258, makeMulRow_259, makeMulRow_260, makeMulRow_261, makeMulRow_262, makeMulRow_263, makeMulRow_264, makeMulRow_265, makeMulRow_266, makeMulRow_267, makeMulRow_268, makeMulRow_269, makeMulRow_270, makeMulRow_271, makeMulRow_272, makeMulRow_273, makeMulRow_274, makeMulRow_275, makeMulRow_276, makeMulRow_277, makeMulRow_278, makeMulRow_279, makeMulRow_280, makeMulRow_281, makeMulRow_282, makeMulRow_283, makeMulRow_284, makeMulRow_285, makeMulRow_286, makeMulRow_287, makeMulRow_288, makeMulRow_289, makeMulRow_290, makeMulRow_291, makeMulRow_292, makeMulRow_293, makeMulRow_294, makeMulRow_295, makeMulRow_296, makeMulRow_297, makeMulRow_298, makeMulRow_299, makeMulRow_300, makeMulRow_301, makeMulRow_302, makeMulRow_303, makeMulRow_304, makeMulRow_305, makeMulRow_306, makeMulRow_307, makeMulRow_308, makeMulRow_309, makeMulRow_310, makeMulRow_311, makeMulRow_312, makeMulRow_313, makeMulRow_314, makeMulRow_315, makeMulRow_316, makeMulRow_317, makeMulRow_318, makeMulRow_319, makeMulRow_320, makeMulRow_321, makeMulRow_322, makeMulRow_323, makeMulRow_324, makeMulRow_325, makeMulRow_326, makeMulRow_327, makeMulRow_328, makeMulRow_329, makeMulRow_330, makeMulRow_331, makeMulRow_332, makeMulRow_333, makeMulRow_334, makeMulRow_335, makeMulRow_336, makeMulRow_337, makeMulRow_338, makeMulRow_339, makeMulRow_340, makeMulRow_341, makeMulRow_342, makeMulRow_343, makeMulRow_344, makeMulRow_345, makeMulRow_346, makeMulRow_347, makeMulRow_348, makeMulRow_349, makeMulRow_350, makeMulRow_351, makeMulRow_352, makeMulRow_353, makeMulRow_354, makeMulRow_355, makeMulRow_356, makeMulRow_357, makeMulRow_358, makeMulRow_359, makeMulRow_360, makeMulRow_361, makeMulRow_362, makeMulRow_363, makeMulRow_364, makeMulRow_365, makeMulRow_366, makeMulRow_367, makeMulRow_368, makeMulRow_369, makeMulRow_370, makeMulRow_371, makeMulRow_372, makeMulRow_373, makeMulRow_374, makeMulRow_375, makeMulRow_376, makeMulRow_377, makeMulRow_378, makeMulRow_379, makeMulRow_380, makeMulRow_381, makeMulRow_382, makeMulRow_383, makeMulRow_384, makeMulRow_385, makeMulRow_386, makeMulRow_387, makeMulRow_388, makeMulRow_389, makeMulRow_390, makeMulRow_391, makeMulRow_392, makeMulRow_393, makeMulRow_394, makeMulRow_395, makeMulRow_396, makeMulRow_397, makeMulRow_398, makeMulRow_399, makeMulRow_400};
void makeMulRowAlter_0(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 0; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_1(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 1; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_2(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 2; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_3(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 3; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_4(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 4; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_5(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 5; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_6(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 6; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_7(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 7; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_8(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 8; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_9(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 9; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_10(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 10; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_11(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 11; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_12(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 12; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_13(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 13; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_14(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 14; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_15(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 15; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_16(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 16; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_17(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 17; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_18(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 18; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_19(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 19; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_20(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 20; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_21(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 21; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_22(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 22; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_23(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 23; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_24(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 24; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_25(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 25; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_26(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 26; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_27(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 27; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_28(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 28; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_29(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 29; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_30(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 30; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_31(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 31; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_32(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 32; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_33(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 33; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_34(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 34; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_35(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 35; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_36(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 36; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_37(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 37; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_38(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 38; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_39(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 39; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_40(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 40; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_41(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 41; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_42(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 42; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_43(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 43; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_44(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 44; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_45(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 45; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_46(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 46; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_47(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 47; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_48(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 48; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_49(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 49; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_50(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 50; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_51(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 51; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_52(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 52; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_53(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 53; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_54(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 54; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_55(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 55; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_56(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 56; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_57(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 57; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_58(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 58; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_59(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 59; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_60(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 60; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_61(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 61; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_62(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 62; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_63(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 63; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_64(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 64; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_65(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 65; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_66(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 66; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_67(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 67; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_68(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 68; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_69(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 69; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_70(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 70; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_71(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 71; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_72(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 72; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_73(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 73; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_74(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 74; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_75(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 75; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_76(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 76; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_77(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 77; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_78(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 78; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_79(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 79; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_80(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 80; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_81(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 81; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_82(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 82; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_83(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 83; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_84(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 84; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_85(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 85; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_86(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 86; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_87(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 87; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_88(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 88; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_89(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 89; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_90(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 90; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_91(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 91; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_92(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 92; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_93(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 93; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_94(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 94; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_95(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 95; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_96(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 96; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_97(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 97; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_98(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 98; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_99(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 99; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_100(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 100; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_101(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 101; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_102(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 102; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_103(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 103; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_104(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 104; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_105(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 105; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_106(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 106; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_107(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 107; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_108(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 108; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_109(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 109; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_110(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 110; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_111(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 111; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_112(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 112; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_113(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 113; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_114(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 114; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_115(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 115; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_116(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 116; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_117(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 117; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_118(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 118; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_119(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 119; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_120(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 120; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_121(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 121; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_122(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 122; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_123(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 123; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_124(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 124; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_125(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 125; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_126(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 126; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_127(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 127; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_128(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 128; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_129(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 129; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_130(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 130; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_131(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 131; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_132(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 132; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_133(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 133; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_134(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 134; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_135(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 135; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_136(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 136; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_137(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 137; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_138(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 138; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_139(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 139; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_140(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 140; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_141(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 141; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_142(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 142; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_143(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 143; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_144(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 144; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_145(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 145; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_146(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 146; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_147(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 147; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_148(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 148; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_149(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 149; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_150(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 150; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_151(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 151; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_152(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 152; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_153(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 153; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_154(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 154; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_155(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 155; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_156(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 156; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_157(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 157; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_158(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 158; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_159(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 159; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_160(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 160; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_161(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 161; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_162(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 162; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_163(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 163; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_164(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 164; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_165(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 165; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_166(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 166; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_167(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 167; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_168(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 168; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_169(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 169; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_170(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 170; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_171(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 171; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_172(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 172; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_173(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 173; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_174(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 174; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_175(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 175; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_176(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 176; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_177(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 177; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_178(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 178; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_179(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 179; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_180(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 180; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_181(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 181; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_182(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 182; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_183(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 183; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_184(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 184; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_185(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 185; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_186(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 186; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_187(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 187; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_188(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 188; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_189(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 189; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_190(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 190; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_191(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 191; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_192(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 192; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_193(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 193; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_194(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 194; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_195(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 195; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_196(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 196; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_197(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 197; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_198(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 198; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_199(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 199; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_200(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 200; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_201(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 201; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_202(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 202; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_203(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 203; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_204(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 204; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_205(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 205; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_206(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 206; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_207(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 207; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_208(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 208; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_209(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 209; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_210(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 210; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_211(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 211; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_212(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 212; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_213(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 213; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_214(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 214; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_215(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 215; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_216(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 216; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_217(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 217; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_218(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 218; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_219(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 219; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_220(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 220; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_221(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 221; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_222(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 222; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_223(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 223; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_224(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 224; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_225(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 225; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_226(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 226; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_227(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 227; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_228(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 228; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_229(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 229; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_230(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 230; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_231(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 231; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_232(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 232; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_233(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 233; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_234(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 234; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_235(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 235; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_236(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 236; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_237(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 237; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_238(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 238; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_239(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 239; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_240(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 240; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_241(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 241; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_242(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 242; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_243(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 243; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_244(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 244; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_245(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 245; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_246(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 246; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_247(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 247; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_248(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 248; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_249(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 249; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_250(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 250; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_251(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 251; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_252(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 252; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_253(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 253; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_254(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 254; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_255(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 255; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_256(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 256; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_257(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 257; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_258(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 258; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_259(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 259; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_260(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 260; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_261(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 261; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_262(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 262; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_263(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 263; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_264(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 264; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_265(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 265; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_266(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 266; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_267(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 267; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_268(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 268; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_269(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 269; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_270(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 270; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_271(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 271; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_272(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 272; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_273(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 273; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_274(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 274; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_275(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 275; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_276(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 276; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_277(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 277; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_278(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 278; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_279(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 279; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_280(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 280; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_281(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 281; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_282(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 282; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_283(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 283; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_284(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 284; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_285(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 285; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_286(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 286; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_287(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 287; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_288(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 288; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_289(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 289; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_290(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 290; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_291(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 291; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_292(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 292; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_293(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 293; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_294(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 294; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_295(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 295; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_296(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 296; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_297(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 297; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_298(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 298; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_299(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 299; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_300(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 300; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_301(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 301; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_302(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 302; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_303(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 303; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_304(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 304; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_305(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 305; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_306(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 306; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_307(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 307; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_308(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 308; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_309(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 309; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_310(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 310; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_311(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 311; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_312(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 312; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_313(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 313; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_314(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 314; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_315(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 315; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_316(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 316; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_317(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 317; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_318(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 318; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_319(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 319; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_320(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 320; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_321(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 321; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_322(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 322; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_323(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 323; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_324(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 324; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_325(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 325; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_326(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 326; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_327(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 327; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_328(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 328; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_329(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 329; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_330(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 330; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_331(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 331; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_332(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 332; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_333(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 333; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_334(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 334; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_335(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 335; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_336(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 336; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_337(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 337; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_338(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 338; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_339(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 339; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_340(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 340; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_341(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 341; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_342(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 342; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_343(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 343; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_344(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 344; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_345(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 345; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_346(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 346; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_347(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 347; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_348(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 348; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_349(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 349; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_350(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 350; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_351(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 351; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_352(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 352; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_353(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 353; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_354(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 354; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_355(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 355; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_356(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 356; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_357(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 357; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_358(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 358; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_359(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 359; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_360(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 360; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_361(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 361; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_362(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 362; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_363(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 363; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_364(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 364; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_365(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 365; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_366(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 366; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_367(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 367; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_368(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 368; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_369(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 369; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_370(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 370; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_371(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 371; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_372(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 372; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_373(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 373; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_374(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 374; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_375(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 375; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_376(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 376; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_377(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 377; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_378(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 378; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_379(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 379; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_380(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 380; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_381(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 381; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_382(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 382; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_383(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 383; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_384(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 384; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_385(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 385; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_386(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 386; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_387(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 387; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_388(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 388; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_389(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 389; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_390(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 390; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_391(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 391; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_392(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 392; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_393(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 393; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_394(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 394; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_395(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 395; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_396(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 396; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_397(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 397; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_398(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 398; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_399(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 399; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
void makeMulRowAlter_400(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){
	double vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;
	tmpRez1 = tmpRez2  = tmpRez3 = 0.0;
	for(int ct = 0; ct < 400; ++ct){
		stifPtr = ptrDataAlter[ct];
		vectPtr = vector + 3**shiftBase;
		vectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access
		tmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;
		tmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;
		tmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;
		++shiftBase;
	}
	rezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;
}
static void (*makeMulRowAlterFunctions[])(double *, double **, double *, int *) = {makeMulRowAlter_0, makeMulRowAlter_1, makeMulRowAlter_2, makeMulRowAlter_3, makeMulRowAlter_4, makeMulRowAlter_5, makeMulRowAlter_6, makeMulRowAlter_7, makeMulRowAlter_8, makeMulRowAlter_9, makeMulRowAlter_10, makeMulRowAlter_11, makeMulRowAlter_12, makeMulRowAlter_13, makeMulRowAlter_14, makeMulRowAlter_15, makeMulRowAlter_16, makeMulRowAlter_17, makeMulRowAlter_18, makeMulRowAlter_19, makeMulRowAlter_20, makeMulRowAlter_21, makeMulRowAlter_22, makeMulRowAlter_23, makeMulRowAlter_24, makeMulRowAlter_25, makeMulRowAlter_26, makeMulRowAlter_27, makeMulRowAlter_28, makeMulRowAlter_29, makeMulRowAlter_30, makeMulRowAlter_31, makeMulRowAlter_32, makeMulRowAlter_33, makeMulRowAlter_34, makeMulRowAlter_35, makeMulRowAlter_36, makeMulRowAlter_37, makeMulRowAlter_38, makeMulRowAlter_39, makeMulRowAlter_40, makeMulRowAlter_41, makeMulRowAlter_42, makeMulRowAlter_43, makeMulRowAlter_44, makeMulRowAlter_45, makeMulRowAlter_46, makeMulRowAlter_47, makeMulRowAlter_48, makeMulRowAlter_49, makeMulRowAlter_50, makeMulRowAlter_51, makeMulRowAlter_52, makeMulRowAlter_53, makeMulRowAlter_54, makeMulRowAlter_55, makeMulRowAlter_56, makeMulRowAlter_57, makeMulRowAlter_58, makeMulRowAlter_59, makeMulRowAlter_60, makeMulRowAlter_61, makeMulRowAlter_62, makeMulRowAlter_63, makeMulRowAlter_64, makeMulRowAlter_65, makeMulRowAlter_66, makeMulRowAlter_67, makeMulRowAlter_68, makeMulRowAlter_69, makeMulRowAlter_70, makeMulRowAlter_71, makeMulRowAlter_72, makeMulRowAlter_73, makeMulRowAlter_74, makeMulRowAlter_75, makeMulRowAlter_76, makeMulRowAlter_77, makeMulRowAlter_78, makeMulRowAlter_79, makeMulRowAlter_80, makeMulRowAlter_81, makeMulRowAlter_82, makeMulRowAlter_83, makeMulRowAlter_84, makeMulRowAlter_85, makeMulRowAlter_86, makeMulRowAlter_87, makeMulRowAlter_88, makeMulRowAlter_89, makeMulRowAlter_90, makeMulRowAlter_91, makeMulRowAlter_92, makeMulRowAlter_93, makeMulRowAlter_94, makeMulRowAlter_95, makeMulRowAlter_96, makeMulRowAlter_97, makeMulRowAlter_98, makeMulRowAlter_99, makeMulRowAlter_100, makeMulRowAlter_101, makeMulRowAlter_102, makeMulRowAlter_103, makeMulRowAlter_104, makeMulRowAlter_105, makeMulRowAlter_106, makeMulRowAlter_107, makeMulRowAlter_108, makeMulRowAlter_109, makeMulRowAlter_110, makeMulRowAlter_111, makeMulRowAlter_112, makeMulRowAlter_113, makeMulRowAlter_114, makeMulRowAlter_115, makeMulRowAlter_116, makeMulRowAlter_117, makeMulRowAlter_118, makeMulRowAlter_119, makeMulRowAlter_120, makeMulRowAlter_121, makeMulRowAlter_122, makeMulRowAlter_123, makeMulRowAlter_124, makeMulRowAlter_125, makeMulRowAlter_126, makeMulRowAlter_127, makeMulRowAlter_128, makeMulRowAlter_129, makeMulRowAlter_130, makeMulRowAlter_131, makeMulRowAlter_132, makeMulRowAlter_133, makeMulRowAlter_134, makeMulRowAlter_135, makeMulRowAlter_136, makeMulRowAlter_137, makeMulRowAlter_138, makeMulRowAlter_139, makeMulRowAlter_140, makeMulRowAlter_141, makeMulRowAlter_142, makeMulRowAlter_143, makeMulRowAlter_144, makeMulRowAlter_145, makeMulRowAlter_146, makeMulRowAlter_147, makeMulRowAlter_148, makeMulRowAlter_149, makeMulRowAlter_150, makeMulRowAlter_151, makeMulRowAlter_152, makeMulRowAlter_153, makeMulRowAlter_154, makeMulRowAlter_155, makeMulRowAlter_156, makeMulRowAlter_157, makeMulRowAlter_158, makeMulRowAlter_159, makeMulRowAlter_160, makeMulRowAlter_161, makeMulRowAlter_162, makeMulRowAlter_163, makeMulRowAlter_164, makeMulRowAlter_165, makeMulRowAlter_166, makeMulRowAlter_167, makeMulRowAlter_168, makeMulRowAlter_169, makeMulRowAlter_170, makeMulRowAlter_171, makeMulRowAlter_172, makeMulRowAlter_173, makeMulRowAlter_174, makeMulRowAlter_175, makeMulRowAlter_176, makeMulRowAlter_177, makeMulRowAlter_178, makeMulRowAlter_179, makeMulRowAlter_180, makeMulRowAlter_181, makeMulRowAlter_182, makeMulRowAlter_183, makeMulRowAlter_184, makeMulRowAlter_185, makeMulRowAlter_186, makeMulRowAlter_187, makeMulRowAlter_188, makeMulRowAlter_189, makeMulRowAlter_190, makeMulRowAlter_191, makeMulRowAlter_192, makeMulRowAlter_193, makeMulRowAlter_194, makeMulRowAlter_195, makeMulRowAlter_196, makeMulRowAlter_197, makeMulRowAlter_198, makeMulRowAlter_199, makeMulRowAlter_200, makeMulRowAlter_201, makeMulRowAlter_202, makeMulRowAlter_203, makeMulRowAlter_204, makeMulRowAlter_205, makeMulRowAlter_206, makeMulRowAlter_207, makeMulRowAlter_208, makeMulRowAlter_209, makeMulRowAlter_210, makeMulRowAlter_211, makeMulRowAlter_212, makeMulRowAlter_213, makeMulRowAlter_214, makeMulRowAlter_215, makeMulRowAlter_216, makeMulRowAlter_217, makeMulRowAlter_218, makeMulRowAlter_219, makeMulRowAlter_220, makeMulRowAlter_221, makeMulRowAlter_222, makeMulRowAlter_223, makeMulRowAlter_224, makeMulRowAlter_225, makeMulRowAlter_226, makeMulRowAlter_227, makeMulRowAlter_228, makeMulRowAlter_229, makeMulRowAlter_230, makeMulRowAlter_231, makeMulRowAlter_232, makeMulRowAlter_233, makeMulRowAlter_234, makeMulRowAlter_235, makeMulRowAlter_236, makeMulRowAlter_237, makeMulRowAlter_238, makeMulRowAlter_239, makeMulRowAlter_240, makeMulRowAlter_241, makeMulRowAlter_242, makeMulRowAlter_243, makeMulRowAlter_244, makeMulRowAlter_245, makeMulRowAlter_246, makeMulRowAlter_247, makeMulRowAlter_248, makeMulRowAlter_249, makeMulRowAlter_250, makeMulRowAlter_251, makeMulRowAlter_252, makeMulRowAlter_253, makeMulRowAlter_254, makeMulRowAlter_255, makeMulRowAlter_256, makeMulRowAlter_257, makeMulRowAlter_258, makeMulRowAlter_259, makeMulRowAlter_260, makeMulRowAlter_261, makeMulRowAlter_262, makeMulRowAlter_263, makeMulRowAlter_264, makeMulRowAlter_265, makeMulRowAlter_266, makeMulRowAlter_267, makeMulRowAlter_268, makeMulRowAlter_269, makeMulRowAlter_270, makeMulRowAlter_271, makeMulRowAlter_272, makeMulRowAlter_273, makeMulRowAlter_274, makeMulRowAlter_275, makeMulRowAlter_276, makeMulRowAlter_277, makeMulRowAlter_278, makeMulRowAlter_279, makeMulRowAlter_280, makeMulRowAlter_281, makeMulRowAlter_282, makeMulRowAlter_283, makeMulRowAlter_284, makeMulRowAlter_285, makeMulRowAlter_286, makeMulRowAlter_287, makeMulRowAlter_288, makeMulRowAlter_289, makeMulRowAlter_290, makeMulRowAlter_291, makeMulRowAlter_292, makeMulRowAlter_293, makeMulRowAlter_294, makeMulRowAlter_295, makeMulRowAlter_296, makeMulRowAlter_297, makeMulRowAlter_298, makeMulRowAlter_299, makeMulRowAlter_300, makeMulRowAlter_301, makeMulRowAlter_302, makeMulRowAlter_303, makeMulRowAlter_304, makeMulRowAlter_305, makeMulRowAlter_306, makeMulRowAlter_307, makeMulRowAlter_308, makeMulRowAlter_309, makeMulRowAlter_310, makeMulRowAlter_311, makeMulRowAlter_312, makeMulRowAlter_313, makeMulRowAlter_314, makeMulRowAlter_315, makeMulRowAlter_316, makeMulRowAlter_317, makeMulRowAlter_318, makeMulRowAlter_319, makeMulRowAlter_320, makeMulRowAlter_321, makeMulRowAlter_322, makeMulRowAlter_323, makeMulRowAlter_324, makeMulRowAlter_325, makeMulRowAlter_326, makeMulRowAlter_327, makeMulRowAlter_328, makeMulRowAlter_329, makeMulRowAlter_330, makeMulRowAlter_331, makeMulRowAlter_332, makeMulRowAlter_333, makeMulRowAlter_334, makeMulRowAlter_335, makeMulRowAlter_336, makeMulRowAlter_337, makeMulRowAlter_338, makeMulRowAlter_339, makeMulRowAlter_340, makeMulRowAlter_341, makeMulRowAlter_342, makeMulRowAlter_343, makeMulRowAlter_344, makeMulRowAlter_345, makeMulRowAlter_346, makeMulRowAlter_347, makeMulRowAlter_348, makeMulRowAlter_349, makeMulRowAlter_350, makeMulRowAlter_351, makeMulRowAlter_352, makeMulRowAlter_353, makeMulRowAlter_354, makeMulRowAlter_355, makeMulRowAlter_356, makeMulRowAlter_357, makeMulRowAlter_358, makeMulRowAlter_359, makeMulRowAlter_360, makeMulRowAlter_361, makeMulRowAlter_362, makeMulRowAlter_363, makeMulRowAlter_364, makeMulRowAlter_365, makeMulRowAlter_366, makeMulRowAlter_367, makeMulRowAlter_368, makeMulRowAlter_369, makeMulRowAlter_370, makeMulRowAlter_371, makeMulRowAlter_372, makeMulRowAlter_373, makeMulRowAlter_374, makeMulRowAlter_375, makeMulRowAlter_376, makeMulRowAlter_377, makeMulRowAlter_378, makeMulRowAlter_379, makeMulRowAlter_380, makeMulRowAlter_381, makeMulRowAlter_382, makeMulRowAlter_383, makeMulRowAlter_384, makeMulRowAlter_385, makeMulRowAlter_386, makeMulRowAlter_387, makeMulRowAlter_388, makeMulRowAlter_389, makeMulRowAlter_390, makeMulRowAlter_391, makeMulRowAlter_392, makeMulRowAlter_393, makeMulRowAlter_394, makeMulRowAlter_395, makeMulRowAlter_396, makeMulRowAlter_397, makeMulRowAlter_398, makeMulRowAlter_399, makeMulRowAlter_400};

#endif//UNROLLED_FUNCTIONS_HPP
