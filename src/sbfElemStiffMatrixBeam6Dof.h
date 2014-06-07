#ifndef SBFELEMSTIFFMATRIXBEAM6DOF_H
#define SBFELEMSTIFFMATRIXBEAM6DOF_H

#include "sbfElemStiffMatrix.h"

class DECLSPEC sbfElemStiffMatrixBeam6Dof : public sbfElemStiffMatrix
{
public:
    explicit sbfElemStiffMatrixBeam6Dof(sbfElement *elem, sbfPropertiesSet *propSet);
private:
    static const int numNodes_ = 2;
    static const int numDOF_ = 6;
    void init();
    void clean();
    void computeH(double r);
    void computeDHDN(double r);
    void computeDHDG();
    void computeJ();
public:
    void computeSM();
};

#endif // SBFELEMSTIFFMATRIXBEAM6DOF_H
