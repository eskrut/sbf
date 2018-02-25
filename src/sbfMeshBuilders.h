#ifndef SBFMESHBUILDERS_H
#define SBFMESHBUILDERS_H

#include <vector>
#include "sbfEnums.h"
#include "sbfDeclspec.h"

class sbfMesh;

namespace sbfMeshBuilder
{
//General nonuniform block
sbfMesh * makeBlock(std::vector<float> & crdX,
                    std::vector<float> & crdY,
                    std::vector<float> & crdZ,
                    ElementType type = ElementType::HEXAHEDRON_LINEAR);

//Uniform block
sbfMesh * makeBlock(float xSide, float ySide, float zSide,
                    int xPart, int yPart, int zPart,
                    ElementType type = ElementType::HEXAHEDRON_LINEAR);

//Uniform part of cylinder
sbfMesh * makeTubePart(float rInner, float rOuter,
                       float phiStart, float phiStop,
                       float zStart, float zStop,
                       int rPart, int phiPart, int zPart,
                       ElementType type = ElementType::HEXAHEDRON_LINEAR);

//Nonniform part of cylinder
sbfMesh * makeTubePart(std::vector<float> &radiuses,
                       std::vector<float> &angles,
                       std::vector<float> &zCrds,
                       ElementType type = ElementType::HEXAHEDRON_LINEAR);

//Make part of cylinred rod
sbfMesh * makeCylinderPart(float radius, float length, float angle,
                           int phiPart, int zPart,
                           float innerSquarePortion = 0.5,
                           ElementType type = ElementType::HEXAHEDRON_LINEAR);

//Make part of cylinred rod
sbfMesh * makeCylinderPart(float radius, float length, float angle,
                           std::vector<float> phiPart, std::vector<float> zPart,
                           float innerSquarePortion = 0.5,
                           ElementType type = ElementType::HEXAHEDRON_LINEAR);

}

#endif // SBFMESHBUILDERS_H
