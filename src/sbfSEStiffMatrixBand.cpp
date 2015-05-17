#include "sbfSEStiffMatrixBand.h"

#include "sbfMesh.h"
#include "sbfSElement.h"
#include "sbfStiffMatrixBand.h"
#include "sbfStiffMatrixBlock.h"
#include <cassert>

template <int dim>
sbfSEStiffMatrixBand<dim>::sbfSEStiffMatrixBand(const sbfSElement *sElem) :
    sElem_(sElem)
{
    //This asserts for non 0 level
    assert(sElem->children(0) == nullptr);

}

template <int dim>
sbfSEStiffMatrixBand<dim>::~sbfSEStiffMatrixBand()
{

}

template class sbfSEStiffMatrixBand<3>;
template class sbfSEStiffMatrixBand<6>;
