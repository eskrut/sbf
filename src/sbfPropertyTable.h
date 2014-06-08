#ifndef SBFPROPERTYTABLE_H
#define SBFPROPERTYTABLE_H

#include <string>
#include <vector>
#include "sbfDeclspec.h"

typedef struct{float param, value;}PropertyNode;

class DECLSPEC sbfPropertyTable
{
public:
    sbfPropertyTable();
    sbfPropertyTable(const std::string & name);
    ~sbfPropertyTable();
private:
    std::string name_;
    std::vector<PropertyNode> table_;
    float curParam_;
    float curValue_;
public:
    float value(const float param);
    void addNodeValue(const float param, const float value);
    void setCurParam(const float param);
    float curValue() const;
    const std::string &name() const;
};

#endif // SBFPROPERTYTABLE_H
