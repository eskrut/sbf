#ifndef SBFPROPERTYTABLE_H
#define SBFPROPERTYTABLE_H

#include <string>
#include <vector>
#include <fstream>
#include "sbfDeclspec.h"

typedef struct{float param, value;}PropertyNode;

class DECLSPEC sbfPropertyTable
{
public:
    sbfPropertyTable();
    sbfPropertyTable(const std::string &name);
    ~sbfPropertyTable();
    static sbfPropertyTable makeTable(const std::string &name, float param, float value);
private:
    std::string name_;
    std::vector<PropertyNode> table_;
    float curParam_;
    float curValue_;
public:
    float value(const float param);
    void addNodeValue(const float param, const float value);
    void setNodeValue(const float param, const float value);
    void setCurParam(const float param);
    float curValue() const;
    float curParam() const;
    const std::string &name() const;

    void read(std::ifstream &in);
    void write(std::ofstream &out) const;
};

#endif // SBFPROPERTYTABLE_H
