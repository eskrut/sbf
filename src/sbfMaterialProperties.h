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
    void addTable(const std::string &name, float param, float value);
    void addTable(sbfPropertyTable *table);
    bool removeTable(const std::string &name);

    void read(std::ifstream &in);
    void write(std::ofstream &out) const;
    void read(const char *fileName);
    void write(const char *fileName) const;

    static sbfMaterialProperties *makeMPropertiesSteel();
    static sbfMaterialProperties *makeMPropertiesGold();
    static sbfMaterialProperties *makeMPropertiesSilver();
    static sbfMaterialProperties *makeMPropertiesBronze();
    static sbfMaterialProperties *makeMPropertiesRubber();
};

#endif // SBFMATERIALPROPERTIES_H
