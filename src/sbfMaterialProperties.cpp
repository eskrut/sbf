#include "sbfMaterialProperties.h"

sbfMaterialProperties::sbfMaterialProperties()
{name_ = "not set";}
sbfMaterialProperties::sbfMaterialProperties(const std::string & name)
{name_ = name;}
sbfMaterialProperties::~sbfMaterialProperties()
{tables_.clear();}
void sbfMaterialProperties::addTable(const std::string & name)
{
    sbfPropertyTable table(name);
    tables_[name]=table;
}
void sbfMaterialProperties::addTable(sbfPropertyTable & table)
{tables_[table.name()]=table;}
sbfPropertyTable *sbfMaterialProperties::propertyTable(const std::string & name)
{
    std::map<std::string, sbfPropertyTable>::iterator it = tables_.find(name);
    if(it != tables_.end())
        return &((*it).second);
    else
        return nullptr;
}

sbfMaterialProperties sbfMaterialProperties::makeMPropertiesSteel()
{
    sbfMaterialProperties mProperties;
    sbfPropertyTable eTable("elastic module");
    eTable.addNodeValue(24.0f, 200000.0f);
    eTable.setCurParam(24.0f);
    mProperties.addTable(eTable);

    sbfPropertyTable nuTable("puasson ratio");
    nuTable.addNodeValue(24.0f, 0.3f);
    nuTable.setCurParam(24.0f);
    mProperties.addTable(nuTable);

    sbfPropertyTable densTable("density");
    densTable.addNodeValue(24.0f, 7800.0f);
    densTable.setCurParam(24.0f);
    mProperties.addTable(densTable);

    return mProperties;
}

sbfMaterialProperties sbfMaterialProperties::makeMPropertiesGold()
{
    sbfMaterialProperties mProperties;
    sbfPropertyTable eTable("elastic module");
    eTable.addNodeValue(24.0f, 79e9);
    eTable.setCurParam(24.0f);
    mProperties.addTable(eTable);

    sbfPropertyTable nuTable("puasson ratio");
    nuTable.addNodeValue(24.0f, 0.44f);
    nuTable.setCurParam(24.0f);
    mProperties.addTable(nuTable);

    sbfPropertyTable densTable("density");
    densTable.addNodeValue(24.0f, 19300.0f);
    densTable.setCurParam(24.0f);
    mProperties.addTable(densTable);

    return mProperties;
}

sbfMaterialProperties sbfMaterialProperties::makeMPropertiesSilver()
{
    sbfMaterialProperties mProperties;
    sbfPropertyTable eTable("elastic module");
    eTable.addNodeValue(24.0f, 83e9);
    eTable.setCurParam(24.0f);
    mProperties.addTable(eTable);

    sbfPropertyTable nuTable("puasson ratio");
    nuTable.addNodeValue(24.0f, 0.37f);
    nuTable.setCurParam(24.0f);
    mProperties.addTable(nuTable);

    sbfPropertyTable densTable("density");
    densTable.addNodeValue(24.0f, 10490.0f);
    densTable.setCurParam(24.0f);
    mProperties.addTable(densTable);

    return mProperties;
}

sbfMaterialProperties sbfMaterialProperties::makeMPropertiesBronze()
{
    sbfMaterialProperties mProperties;
    sbfPropertyTable eTable("elastic module");
    eTable.addNodeValue(24.0f, 115e9);
    eTable.setCurParam(24.0f);
    mProperties.addTable(eTable);

    sbfPropertyTable nuTable("puasson ratio");
    nuTable.addNodeValue(24.0f, 0.34f);
    nuTable.setCurParam(24.0f);
    mProperties.addTable(nuTable);

    sbfPropertyTable densTable("density");
    densTable.addNodeValue(24.0f, 8960.0f);
    densTable.setCurParam(24.0f);
    mProperties.addTable(densTable);

    return mProperties;
}

sbfMaterialProperties sbfMaterialProperties::makeMPropertiesRubber()
{
    sbfMaterialProperties mProperties;
    sbfPropertyTable eTable("elastic module");
    eTable.addNodeValue(24.0f, 10.0f);
    eTable.setCurParam(24.0f);
    mProperties.addTable(eTable);

    sbfPropertyTable nuTable("puasson ratio");
    nuTable.addNodeValue(24.0f, 0.49f);
    nuTable.setCurParam(24.0f);
    mProperties.addTable(nuTable);

    sbfPropertyTable densTable("density");
    densTable.addNodeValue(24.0f, 1200.0f);
    densTable.setCurParam(24.0f);
    mProperties.addTable(densTable);

    return mProperties;
}
