#include "sbfPropertyTable.h"
#include <limits>
sbfPropertyTable::sbfPropertyTable()
{
    name_ = "not set";
    table_.reserve(10);
}
sbfPropertyTable::sbfPropertyTable(const std::string & name)
{
    name_ = name;
    table_.reserve(10);
}
sbfPropertyTable::~sbfPropertyTable()
{table_.clear();}

void sbfPropertyTable::addNodeValue(float param, float value)
{
    PropertyNode node;
    node.param = param;
    node.value = value;
    if(table_.size() == 0 || param > table_.back().param)
        table_.push_back(node);
    else if(param < table_.front().param)
        table_.insert(table_.begin(), node);
    else{
        bool flagFound = false;
        std::vector<PropertyNode>::iterator it1, it2;
        it1 = it2 = table_.begin();
        for(it2++; it2 != table_.end(); it1++, it2++){
            if((*it1).param < param && param < (*it2).param)
                {table_.insert(it2, node); flagFound = true; break;}
        }
        if(!flagFound)
        {/*FIXME Throw an exception*/}
    }
}

float sbfPropertyTable::value(float param)
{
    if(table_.size() == 1)
        return table_[0].value;
    else if(table_.size() == 0)
    {/*FIXME Throw an exception*/return std::numeric_limits<float>::quiet_NaN();}
    std::vector<PropertyNode>::iterator it1, it2;
    it1 = it2 = table_.begin();
    for(it2++; it2 != table_.end(); it1++, it2++)
        if(param < (*it2).param)
            break;
    return (*it1).value + ( (*it2).value - (*it1).value )/( (*it2).param - (*it1).param )*( param - (*it1).param );
}

void sbfPropertyTable::setCurParam(const float param)
{curParam_ = param; curValue_ = value(curParam_);}
float sbfPropertyTable::curValue()
{return curValue_;}

const std::string & sbfPropertyTable::name()
{return name_;}
