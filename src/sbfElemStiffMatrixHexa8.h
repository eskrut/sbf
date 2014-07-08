#ifndef SBFELEMSTIFFMATRIXHEXA8_H
#define SBFELEMSTIFFMATRIXHEXA8_H

/*
 *    7-------6
 *   /|      /|     Z
 *  4-------5 |     |   Y
 *  | |     | |     |  /
 *  | 3- - -|-2     | /
 *  |/      |/      |/
 *  0-------1       0-------- X
*/

#include "sbfElemStiffMatrix.h"

class DECLSPEC sbfElemStiffMatrixHexa8 : public sbfElemStiffMatrix
{
public:
    explicit sbfElemStiffMatrixHexa8(sbfElement *elem, sbfPropertiesSet *propSet);
private:
    static const int numNodes_ = 8;
    static const int numDOF_ = 3;
    static const int blockSize_ = numDOF_*numDOF_;
    //FIXME - this is intermediate buffer
    double dataBuf_[numNodes_*numNodes_*blockSize_];
    void init();
    void clean();
    void computeH(double r, double s = 0, double t = 0);
    void computeDHDN(double r, double s = 0, double t = 0);
    void computeDHDG();
    void computeJ();
public:
    void computeSM();
    double computeVolume();
    RowColData rowColData();
};

#endif // SBFELEMSTIFFMATRIXHEXA8_H
