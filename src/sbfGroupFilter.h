#ifndef SBFGROUPFILTER_H
#define SBFGROUPFILTER_H

#include <limits>
enum class ElementType: short;
class sbfMesh;
class sbfNode;
class sbfElement;

class /*DECLSPEC*/ sbfGroupFilter
//Holds information abaut filter used for grouping
{
public:
    sbfGroupFilter();
    ~sbfGroupFilter();
private:
    bool mtrF_;
    bool xMaxF_, xMinF_, yMaxF_, yMinF_, zMaxF_, zMinF_;
    float xMax_, xMin_, yMax_, yMin_, zMax_, zMin_;
    bool typeF_;
    int mtr_;
    ElementType type_;
    sbfMesh *mesh_;
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
    void setMesh(sbfMesh *mesh);
    bool isPass(sbfElement & elem);
    bool isPass(sbfNode & node);
};

#endif // SBFGROUPFILTER_H
