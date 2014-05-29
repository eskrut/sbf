#ifndef SBFFUNCTIONS_H
#define SBFFUNCTIONS_H

class sbfMesh;
class sbfPropertiesSet;

/**
  @brief Calculate deformation and stresses over mesh
**/
void calculateDeformStress(sbfMesh *mesh, sbfPropertiesSet *propSet, const double *displ, double *deform, double *stress);

#endif // SBFFUNCTIONS_H
