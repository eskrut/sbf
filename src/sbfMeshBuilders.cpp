#include "sbfMesh.h"
#include "sbfNode.h"
#include "sbfElement.h"

sbfMesh * sbfMesh::makeBlock(std::vector<float> & crdX, std::vector<float> & crdY, std::vector<float> & crdZ, ElementType type)
{
    //TODO is there a requirement to check vectors validity?
    sbfMesh * block = new sbfMesh();

    switch(type){
    case ElementType::HEXAHEDRON_LINEAR:
    {
        block->reserveNodesNumber((int)(crdX.size()*crdY.size()*crdZ.size()));
        int xNum = (int)(crdX.size()-1);
        int yNum = (int)(crdY.size()-1);
        int zNum = (int)(crdZ.size()-1);
        int allNum = xNum*yNum*zNum;
        block->reserveElementsNumber(allNum);
        for(std::vector<float>::iterator itZ = crdZ.begin(); itZ != crdZ.end(); itZ++)
            for(std::vector<float>::iterator itY = crdY.begin(); itY != crdY.end(); itY++)
                for(std::vector<float>::iterator itX = crdX.begin(); itX != crdX.end(); itX++)
                    block->addNode(*itX, *itY, *itZ, false);
        sbfElement elem;
        elem.setMtr(1);
        elem.setType(ElementType::HEXAHEDRON_LINEAR);
        for(int ctz = 0; ctz < zNum; ctz++){
            for(int cty = 0; cty < yNum; cty++){
                for(int ctx = 0; ctx < xNum; ctx++){
                    //create one element
                    int temp0 = xNum+1;
                    int temp1 = ctz*(yNum+1)*temp0;
                    int temp2 = (ctz+1)*(yNum+1)*temp0;
                    elem.setNode(0, temp1 + cty*temp0 + ctx);
                    elem.setNode(1, temp1 + cty*temp0 + ctx+1);
                    elem.setNode(2, temp1 + (cty+1)*temp0 + ctx+1);
                    elem.setNode(3, temp1 + (cty+1)*temp0 + ctx);
                    elem.setNode(4, temp2 + cty*temp0 + ctx);
                    elem.setNode(5, temp2 + cty*temp0 + ctx+1);
                    elem.setNode(6, temp2 + (cty+1)*temp0 + ctx+1);
                    elem.setNode(7, temp2 + (cty+1)*temp0 + ctx);
                    block->addElement(elem);
                }
            }
        }
        break;
    }
    case ElementType::HEXAHEDRON_QUADRATIC:
        break;
    default :
        break;
    }

    return block;
}
sbfMesh * sbfMesh::makeBlock(float xSide, float ySide, float zSide, int xPart, int yPart, int zPart, ElementType type)
{
    if (xSide == 0 || ySide == 0 || zSide == 0 || xPart <= 0 || yPart <= 0 || zPart <= 0) return nullptr;
    if (type != ElementType::HEXAHEDRON_LINEAR && type != ElementType::HEXAHEDRON_QUADRATIC) return nullptr;
    std::vector<float> crdX, crdY, crdZ;
    crdX.reserve(xPart+1);
    crdY.reserve(yPart+1);
    crdZ.reserve(zPart+1);
    float step;
    step = xSide/xPart;
    for(int ct = 0; ct <= xPart; ct++)
        crdX.push_back(step*ct);
    step = ySide/yPart;
    for(int ct = 0; ct <= yPart; ct++)
        crdY.push_back(step*ct);
    step = zSide/zPart;
    for(int ct = 0; ct <= zPart; ct++)
        crdZ.push_back(step*ct);
    return sbfMesh::makeBlock(crdX, crdY, crdZ, type);
}

sbfMesh * sbfMesh::makeCylinderPart(float rInner, float rOuter, float phiStart, float phiStop, float zStart, float zStop, int rPart, int phiPart, int zPart, ElementType type)
{
    sbfMesh * cylinder = sbfMesh::makeBlock(rOuter-rInner, phiStop-phiStart, zStop-zStart, rPart, phiPart, zPart, type);
    cylinder->translate(rInner, phiStart, zStart);
    //Perform coordinate system transformation
    cylinder->applyToAllNodes([](sbfNode &node){
        auto r = node.x();
        auto phi = node.y();
        node.setX(r*std::cos(phi));
        node.setY(r*std::sin(phi));
    });

    return cylinder;
}

sbfMesh *sbfMesh::makeCylinderPart(std::vector<float> &radiuses, std::vector<float> &angles, std::vector<float> &zCrds, ElementType type)
{
    sbfMesh * cylinder = sbfMesh::makeBlock(radiuses, angles, zCrds, type);
    //Perform coordinate system transformation
    cylinder->applyToAllNodes([](sbfNode &node){
        auto r = node.x();
        auto phi = node.y();
        node.setX(r*std::cos(phi));
        node.setY(r*std::sin(phi));
    });

    return cylinder;
}
