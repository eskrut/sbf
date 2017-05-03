#ifndef SBFGROUPFILTER_H
#define SBFGROUPFILTER_H

#include <limits>
#include "sbfDeclspec.h"
enum class ElementType: short;
class sbfMesh;
class sbfNode;
class sbfElement;

class DECLSPEC sbfGroupFilter
//Holds information abaut filter used for grouping
{
public:
    sbfGroupFilter();
    ~sbfGroupFilter();

    static sbfGroupFilter makeNearX(float crd, float tolerance = 1e-7);
    static sbfGroupFilter makeNearY(float crd, float tolerance = 1e-7);
    static sbfGroupFilter makeNearZ(float crd, float tolerance = 1e-7);
    static sbfGroupFilter makeNodeFunc(std::function<bool (const sbfNode & node)> func);
    static sbfGroupFilter makeElemFunc(std::function<bool (const sbfElement & elem)> func);
    static sbfGroupFilter makeMtr(int mtr);

private:
    bool mtrF_;
    bool xMaxF_, xMinF_, yMaxF_, yMinF_, zMaxF_, zMinF_;
    float xMax_, xMin_, yMax_, yMin_, zMax_, zMin_;
    bool typeF_;
    int mtr_;
    ElementType type_;
    std::function<bool (const sbfNode & node)> nodeFiltFunction{nullptr};
    std::function<bool (const sbfElement & elem)> elemFiltFunction{nullptr};

public:
    void setMtrF(int mtr);
    void unsetMtrF();
    void setTypeF(ElementType type);
    void unsetTypeF();
    void setCrdF(float xMin = -std::numeric_limits<float>::max(), float xMax = std::numeric_limits<float>::max(), float yMin = -std::numeric_limits<float>::max(), float yMax = std::numeric_limits<float>::max(), float zMin = -std::numeric_limits<float>::max(), float zMax = std::numeric_limits<float>::max());
    void setCrdXF(float xMin = -std::numeric_limits<float>::max(), float xMax = std::numeric_limits<float>::max());
    void setCrdYF(float yMin = -std::numeric_limits<float>::max(), float yMax = std::numeric_limits<float>::max());
    void setCrdZF(float zMin = -std::numeric_limits<float>::max(), float zMax = std::numeric_limits<float>::max());
    void unsetCrdF();
    void setNodeFunction(std::function<bool (const sbfNode & node)> func);
    void setElemFunction(std::function<bool (const sbfElement & elem)> func);
    bool isPass(const sbfElement & elem);
    bool isPass(const sbfNode & node);
};

#endif // SBFGROUPFILTER_H
