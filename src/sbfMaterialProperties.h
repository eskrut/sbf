#ifndef SBFMATERIALPROPERTIES_H
#define SBFMATERIALPROPERTIES_H

#include "sbfPropertyTable.h"
#include <map>
#include <fstream>

class DECLSPEC sbfMaterialProperties
{
public:
    sbfMaterialProperties();
    sbfMaterialProperties(const std::string & name);
    ~sbfMaterialProperties();
private:
    std::string name_;
    std::map<std::string, sbfPropertyTable*> tables_;
public:
    sbfPropertyTable *propertyTable(const std::string & name);
    void addTable(const std::string &name);
    void addTable(sbfPropertyTable *table);

    void read(std::ifstream &in);
    void write(std::ofstream &out) const;

    static sbfMaterialProperties *makeMPropertiesSteel();
    static sbfMaterialProperties *makeMPropertiesGold();
    static sbfMaterialProperties *makeMPropertiesSilver();
    static sbfMaterialProperties *makeMPropertiesBronze();
    static sbfMaterialProperties *makeMPropertiesRubber();
};

#endif // SBFMATERIALPROPERTIES_H
