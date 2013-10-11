#ifndef SBFMATERIALPROPERTIES_H
#define SBFMATERIALPROPERTIES_H

#include "sbfPropertyTable.h"
#include <map>

class DECLSPEC sbfMaterialProperties
{
public:
    sbfMaterialProperties();
    sbfMaterialProperties(const std::string & name);
    ~sbfMaterialProperties();
private:
    std::string name_;
    std::map<std::string, sbfPropertyTable> tables_;
public:
    sbfPropertyTable * propertyTable(const std::string & name);
    void addTable(const std::string & name);
    void addTable(sbfPropertyTable &table);

    static sbfMaterialProperties makeMPropertiesSteel();
};

#endif // SBFMATERIALPROPERTIES_H
