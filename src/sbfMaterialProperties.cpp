#include "sbfMaterialProperties.h"

sbfMaterialProperties::sbfMaterialProperties()
{
    name_ = "not set";
}

sbfMaterialProperties::sbfMaterialProperties(const std::string &name)
{
    name_ = name;
}

sbfMaterialProperties::~sbfMaterialProperties()
{
    for(auto t : tables_)
        delete t.second;
    tables_.clear();
}

void sbfMaterialProperties::addTable(const std::string &name)
{
    sbfPropertyTable *table = new sbfPropertyTable(name);
    tables_[name]=table;
}

void sbfMaterialProperties::addTable(sbfPropertyTable *table)
{
    tables_[table->name()]=table;
}

sbfPropertyTable *sbfMaterialProperties::propertyTable(const std::string &name)
{
    auto it = tables_.find(name);
    if(it != tables_.end())
        return (*it).second;
    else
        return nullptr;
}

sbfMaterialProperties *sbfMaterialProperties::makeMPropertiesSteel()
{
    sbfMaterialProperties *mProperties = new sbfMaterialProperties("steel");
    sbfPropertyTable *eTable = new sbfPropertyTable("elastic module");
    eTable->addNodeValue(24.0f, 200000.0f);
    eTable->setCurParam(24.0f);
    mProperties->addTable(eTable);

    sbfPropertyTable *nuTable = new sbfPropertyTable("puasson ratio");
    nuTable->addNodeValue(24.0f, 0.3f);
    nuTable->setCurParam(24.0f);
    mProperties->addTable(nuTable);

    sbfPropertyTable *densTable = new sbfPropertyTable("density");
    densTable->addNodeValue(24.0f, 7800.0f);
    densTable->setCurParam(24.0f);
    mProperties->addTable(densTable);

    return mProperties;
}

sbfMaterialProperties *sbfMaterialProperties::makeMPropertiesGold()
{
    sbfMaterialProperties *mProperties = new sbfMaterialProperties("gold");
    sbfPropertyTable *eTable = new sbfPropertyTable("elastic module");
    eTable->addNodeValue(24.0f, 79e9);
    eTable->setCurParam(24.0f);
    mProperties->addTable(eTable);

    sbfPropertyTable *nuTable = new sbfPropertyTable("puasson ratio");
    nuTable->addNodeValue(24.0f, 0.44f);
    nuTable->setCurParam(24.0f);
    mProperties->addTable(nuTable);

    sbfPropertyTable *densTable = new sbfPropertyTable("density");
    densTable->addNodeValue(24.0f, 19300.0f);
    densTable->setCurParam(24.0f);
    mProperties->addTable(densTable);

    return mProperties;
}

sbfMaterialProperties *sbfMaterialProperties::makeMPropertiesSilver()
{
    sbfMaterialProperties *mProperties = new sbfMaterialProperties("silver");
    sbfPropertyTable *eTable = new sbfPropertyTable("elastic module");
    eTable->addNodeValue(24.0f, 83e9);
    eTable->setCurParam(24.0f);
    mProperties->addTable(eTable);

    sbfPropertyTable *nuTable = new sbfPropertyTable("puasson ratio");
    nuTable->addNodeValue(24.0f, 0.37f);
    nuTable->setCurParam(24.0f);
    mProperties->addTable(nuTable);

    sbfPropertyTable *densTable = new sbfPropertyTable("density");
    densTable->addNodeValue(24.0f, 10490.0f);
    densTable->setCurParam(24.0f);
    mProperties->addTable(densTable);

    return mProperties;
}

sbfMaterialProperties *sbfMaterialProperties::makeMPropertiesBronze()
{
    sbfMaterialProperties *mProperties = new sbfMaterialProperties("bronze");
    sbfPropertyTable *eTable = new sbfPropertyTable("elastic module");
    eTable->addNodeValue(24.0f, 115e9);
    eTable->setCurParam(24.0f);
    mProperties->addTable(eTable);

    sbfPropertyTable *nuTable = new sbfPropertyTable("puasson ratio");
    nuTable->addNodeValue(24.0f, 0.34f);
    nuTable->setCurParam(24.0f);
    mProperties->addTable(nuTable);

    sbfPropertyTable *densTable = new sbfPropertyTable("density");
    densTable->addNodeValue(24.0f, 8960.0f);
    densTable->setCurParam(24.0f);
    mProperties->addTable(densTable);

    return mProperties;
}

sbfMaterialProperties *sbfMaterialProperties::makeMPropertiesRubber()
{
    sbfMaterialProperties *mProperties = new sbfMaterialProperties("rubber");
    sbfPropertyTable *eTable = new sbfPropertyTable("elastic module");
    eTable->addNodeValue(24.0f, 10.0f);
    eTable->setCurParam(24.0f);
    mProperties->addTable(eTable);

    sbfPropertyTable *nuTable = new sbfPropertyTable("puasson ratio");
    nuTable->addNodeValue(24.0f, 0.49f);
    nuTable->setCurParam(24.0f);
    mProperties->addTable(nuTable);

    sbfPropertyTable *densTable = new sbfPropertyTable("density");
    densTable->addNodeValue(24.0f, 1200.0f);
    densTable->setCurParam(24.0f);
    mProperties->addTable(densTable);

    return mProperties;
}
