#ifndef SBFSESTIFFMATRIXBAND_H
#define SBFSESTIFFMATRIXBAND_H

class sbfMesh;
class sbfSElement;
template <int dim> class sbfStiffMatrixBand;
template <int dim> class sbfStiffMatrixBlock;

template <int dim>
class sbfSEStiffMatrixBand
{
public:
    sbfSEStiffMatrixBand(const sbfSElement *sElem);
    ~sbfSEStiffMatrixBand();

private:
    const sbfSElement *sElem_;
    sbfMesh *fakeMeshBB_;
    sbfMesh *fakeMeshBI_;
    sbfMesh *fakeMeshII_;
    sbfStiffMatrixBand<dim> *stiffBB_;
    sbfStiffMatrixBlock<dim> *stiffBI_;
    sbfStiffMatrixBand<dim> *stiffII_;
};

#endif // SBFSESTIFFMATRIXBAND_H
