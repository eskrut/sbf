/*
 * sbfProperty.h
 *
 *  Created on: Mar 9, 2012
 *      Author: eugen
 */

#ifndef _SBFPROPERTY_H_
#define _SBFPROPERTY_H_

#include "sbfDeclspec.h"
#include <vector>
#include <string>
#include <map>
#include <limits>

namespace sbf{

typedef struct{float param, value;}PropertyNode;

class DECLSPEC PropertyTable
{
public:
	PropertyTable();//Refuse default constructor
	PropertyTable(const std::string & name);
	~PropertyTable();
	//Allow automatically generated copy constructor and operator=
	//PropertyTable(const PropertyTable & pTable);
	//PropertyTable & operator=(const PropertyTable &);
private:
	std::string name_;
	std::vector< PropertyNode > table_;
	float curParam_;
	float curValue_;
public:
	float value(const float param);
	void addNodeValue(const float param, const float value);
	void setCurParam(const float param);
	float curValue();
	const std::string & name();
};

class DECLSPEC MaterialProperties
{
public:
	MaterialProperties();
	MaterialProperties(const std::string & name);
	~MaterialProperties();
private:
	std::string name_;
	std::map<std::string, PropertyTable> tables_;
public:
	PropertyTable * propertyTable(const std::string & name);
	void addTable(const std::string & name);
	void addTable(PropertyTable & table);

	static MaterialProperties makeMPropertiesSteel();
};

class DECLSPEC sbfPropertiesSet
{
private:
	std::vector<sbf::MaterialProperties> materials_;
public:
	MaterialProperties * material(const int seqNumber);
	void addMaterial(MaterialProperties material);
};

}//End namespace sbf

#endif /* _SBFPROPERTY_H_ */
