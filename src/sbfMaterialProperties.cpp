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
    { delete t.second; t.second = nullptr; }
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

bool sbfMaterialProperties::removeTable(const std::string &name)
{
    auto pos = tables_.find(name);
    if (pos != tables_.end()) {
        delete pos->second;
        tables_.erase(pos);
        return true;
    }
    return false;
}

void sbfMaterialProperties::read(std::ifstream &in)
{
    std::getline(in, name_);
    size_t numTables;
    in >> numTables;
    in.ignore(10, '\n');
    for(size_t ct = 0; ct < numTables; ct++) {
        std::string name;
        std::getline(in, name);
        auto table = new sbfPropertyTable(name);
        table->read(in);
        tables_[name] = table;
    }
}

void sbfMaterialProperties::write(std::ofstream &out) const
{
    out << name_ << std::endl << tables_.size() << std::endl;
    for(auto t : tables_) {
        out << t.first << std::endl;
        t.second->write(out);
    }
}

void sbfMaterialProperties::read(const char *fileName)
{
    std::ifstream in(fileName);
    if ( !in.good() )
        throw std::runtime_error(std::string("Cant read file ") + fileName);
    read(in);
    in.close();
}

void sbfMaterialProperties::write(const char *fileName) const
{
    std::ofstream out(fileName);
    if ( !out.good() )
        throw std::runtime_error(std::string("Cant write file ") + fileName);
    write(out);
    out.close();
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
