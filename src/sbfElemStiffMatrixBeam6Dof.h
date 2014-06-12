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
    static const int blockSize_ = numDOF_*numDOF_;
    void init();
    void clean();
public:
    void computeSM();
    RowColData rowColData();
};

#endif // SBFELEMSTIFFMATRIXBEAM6DOF_H
