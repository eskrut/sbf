#ifndef SBFSTIFFMATRIXBANDITERATOR_H
#define SBFSTIFFMATRIXBANDITERATOR_H

template <int dim> class sbfStiffMatrixBandIterator;

#include "sbfMatrixIterator.h"
#include "sbfStiffMatrixBand.h"

template <int dim>
class sbfStiffMatrixBandIterator : public sbfMatrixIterator
{
public:
    sbfStiffMatrixBandIterator(const sbfStiffMatrixBand<dim> *matrix);
};

#endif // SBFSTIFFMATRIXBANDITERATOR_H
