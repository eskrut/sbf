import string, os, sys, re

numFunctions = 400;
numAlterFunctions = 400;

outFile = file("unrolledFunctions.hpp", 'w');

str1 ="/* Automatically generated with generateUnrolledFunctions.py script\n** DO NOT EDIT! */\n\n"
outFile.write(str1)

str1 ="#ifndef UNROLLED_FUNCTIONS_HPP\n#define UNROLLED_FUNCTIONS_HPP\n\n"
outFile.write(str1)

str1 ="typedef void (*makeMulRowFuncPtrType)(double *, double *, double *, int *);\n"
outFile.write(str1)
str1 = "const int numMakeMulRowFunctions = "+str(numFunctions)+";\n\n"
outFile.write(str1)

str1 ="typedef void (*makeMulRowAlterFuncPtrType)(double *, double **, double *, int *);\n"
outFile.write(str1)
str1 = "const int numMakeMulRowAlterFunctions = "+str(numAlterFunctions)+";\n\n"
outFile.write(str1)

str2 = "static void (*makeMulRowFunctions[])(double *, double *, double *, int *) = {"

for i in range(0, numFunctions+1):
	str1 = "void makeMulRow_"+str(i)+"(double *vector, double *stifPtr, double *rezPtr, int *shiftBase){\n\tdouble vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr;\n\ttmpRez1 = tmpRez2  = tmpRez3 = 0.0;\n\tfor(int ct = 0; ct < "+str(i)+"; ++ct){\n\t\tvectPtr = vector + 3**shiftBase;\n\t\tvectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access\n\t\ttmpRez1 += stifPtr[0]*vectTmp1;tmpRez1 += stifPtr[1]*vectTmp2;tmpRez1 += stifPtr[2]*vectTmp3;\n\t\ttmpRez2 += stifPtr[3]*vectTmp1;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez2 += stifPtr[5]*vectTmp3;\n\t\ttmpRez3 += stifPtr[6]*vectTmp1;tmpRez3 += stifPtr[7]*vectTmp2;tmpRez3 += stifPtr[8]*vectTmp3;\n\t\tstifPtr += 9;++shiftBase;\n\t}\n\trezPtr[0] = tmpRez1;rezPtr[1] = tmpRez2;rezPtr[2] = tmpRez3;\n}\n"
	if i != 0:
		str2 = str2 + ", "
	str2 = str2 + "makeMulRow_"+str(i);
	outFile.write(str1)

str2 = str2 + "};\n"
outFile.write(str2)

str2 = "static void (*makeMulRowAlterFunctions[])(double *, double **, double *, int *) = {"
for i in range(0, numAlterFunctions+1):
	str1 = "void makeMulRowAlter_"+str(i)+"(double *vector, double **ptrDataAlter, double *rezPtr, int *shiftBase){\n\tdouble vectTmp1, vectTmp2, vectTmp3, tmpRez1, tmpRez2, tmpRez3, *vectPtr, *stifPtr;\n\ttmpRez1 = tmpRez2  = tmpRez3 = 0.0;\n\tfor(int ct = 0; ct < "+str(i)+"; ++ct){\n\t\tstifPtr = ptrDataAlter[ct];\n\t\tvectPtr = vector + 3**shiftBase;\n\t\tvectTmp1 = vectPtr[0];vectTmp2 = vectPtr[1];vectTmp3 = vectPtr[2];//Variables for further access\n\t\ttmpRez1 += stifPtr[0]*vectTmp1;tmpRez2 += stifPtr[1]*vectTmp1;tmpRez3 += stifPtr[2]*vectTmp1;\n\t\ttmpRez1 += stifPtr[3]*vectTmp2;tmpRez2 += stifPtr[4]*vectTmp2;tmpRez3 += stifPtr[5]*vectTmp2;\n\t\ttmpRez1 += stifPtr[6]*vectTmp3;tmpRez2 += stifPtr[7]*vectTmp3;tmpRez3 += stifPtr[8]*vectTmp3;\n\t\t++shiftBase;\n\t}\n\trezPtr[0] += tmpRez1;rezPtr[1] += tmpRez2;rezPtr[2] += tmpRez3;\n}\n"
	if i != 0:
		str2 = str2 + ", "
	str2 = str2 + "makeMulRowAlter_"+str(i);
	outFile.write(str1)

str2 = str2 + "};\n"
outFile.write(str2)

str1 ="\n#endif//UNROLLED_FUNCTIONS_HPP\n"
outFile.write(str1)
outFile.close()
