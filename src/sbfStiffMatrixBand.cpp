#include "sbfStiffMatrixBand.h"

template <int dim>
sbfStiffMatrixBand<dim>::sbfStiffMatrixBand(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type) :
    sbfStiffMatrix(mesh, propSet, type)
{

}

template <int dim>
sbfStiffMatrixBand<dim>::~sbfStiffMatrixBand()
{

}

template class sbfStiffMatrixBand<3>;
