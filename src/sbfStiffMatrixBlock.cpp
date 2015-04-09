#include "sbfStiffMatrixBlock.h"

template <int dim>
sbfStiffMatrixBlock<dim>::sbfStiffMatrixBlock ( sbfMesh *mesh,
                                           sbfPropertiesSet *propSet,
                                           MatrixType type = MatrixType::FULL_MATRIX ) :
    sbfStiffMatrix(mesh, propSet, )
{
}

template <int dim>
sbfStiffMatrixBlock<dim>::~sbfStiffMatrixBlock()
{

}

template class sbfStiffMatrixBlock<3>;
template class sbfStiffMatrixBlock<6>;
