/*
 * sbfProperty.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: eugen
 */

#include "sbfProperty.h"

sbf::PropertyTable::PropertyTable()
{
	name_ = "not set";
	table_.reserve(10);
}
sbf::PropertyTable::PropertyTable(const std::string & name)
{
	name_ = name;
	table_.reserve(10);
}
sbf::PropertyTable::~PropertyTable()
{table_.clear();}

void sbf::PropertyTable::addNodeValue(float param, float value)
{
	sbf::PropertyNode node;
	node.param = param;
	node.value = value;
	if(table_.size() == 0 || param > table_.back().param)
		table_.push_back(node);
	else if(param < table_.front().param)
		table_.insert(table_.begin(), node);
	else{
		bool flagFound = false;
		std::vector<sbf::PropertyNode>::iterator it1, it2;
		it1 = it2 = table_.begin();
		for(it2++; it2 != table_.end(); it1++, it2++){
			if((*it1).param < param && param < (*it2).param)
				{table_.insert(it2, node); flagFound = true; break;}
		}
		if(!flagFound)
		{/*Throw an exception*/}
	}
}

float sbf::PropertyTable::value(float param)
{
	if(table_.size() == 1)
		return table_[0].value;
	else if(table_.size() == 0)
	{/*Throw an exception*/return -std::numeric_limits<float>::max();}
	std::vector<sbf::PropertyNode>::iterator it1, it2;
	it1 = it2 = table_.begin();
	for(it2++; it2 != table_.end(); it1++, it2++)
		if(param < (*it2).param)
			break;
	return (*it1).value + ( (*it2).value - (*it1).value )/( (*it2).param - (*it1).param )*( param - (*it1).param );
}

void sbf::PropertyTable::setCurParam(const float param)
{curParam_ = param; curValue_ = value(curParam_);}
float sbf::PropertyTable::curValue()
{return curValue_;}

const std::string & sbf::PropertyTable::name()
{return name_;}

sbf::MaterialProperties::MaterialProperties()
{name_ = "not set";}
sbf::MaterialProperties::MaterialProperties(const std::string & name)
{name_ = name;}
sbf::MaterialProperties::~MaterialProperties()
{tables_.clear();}
void sbf::MaterialProperties::addTable(const std::string & name)
{
	PropertyTable table(name);
	tables_[name]=table;
}
void sbf::MaterialProperties::addTable(PropertyTable & table)
{tables_[table.name()]=table;}
sbf::PropertyTable * sbf::MaterialProperties::propertyTable(const std::string & name)
{
	std::map<std::string, sbf::PropertyTable>::iterator it = tables_.find(name);
	if(it != tables_.end())
		return &((*it).second);
	else
		return NULL;
}

sbf::MaterialProperties sbf::MaterialProperties::makeMPropertiesSteel()
{
	MaterialProperties mProperties;
	sbf::PropertyTable eTable("elastic module");
	eTable.addNodeValue(24.0f, 200000.0f);
	eTable.setCurParam(24.0f);
	mProperties.addTable(eTable);

	sbf::PropertyTable nuTable("puasson ratio");
	nuTable.addNodeValue(24.0f, 0.3f);
	nuTable.setCurParam(24.0f);
	mProperties.addTable(nuTable);

	sbf::PropertyTable densTable("density");
	densTable.addNodeValue(24.0f, 7800.0f);
	densTable.setCurParam(24.0f);
	mProperties.addTable(densTable);

	return mProperties;
}

sbf::MaterialProperties * sbf::sbfPropertiesSet::material(const int seqNumber)
{
	return &materials_.at(seqNumber);
	//return &materials_[seqNumber];
}
void sbf::sbfPropertiesSet::addMaterial(MaterialProperties material)
{materials_.push_back(material);}
