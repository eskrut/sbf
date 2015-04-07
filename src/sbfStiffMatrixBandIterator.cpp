#include "sbfStiffMatrixBandIterator.h"

template <int dim>
sbfStiffMatrixBandIterator<dim>::sbfStiffMatrixBandIterator(const sbfStiffMatrixBand<dim> *matrix) :
    sbfMatrixIterator(matrix)
{
}
