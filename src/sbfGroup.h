#ifndef SBFGROUP_H
#define SBFGROUP_H

#include <vector>
#include "sbfDeclspec.h"

class sbfGroupFilter;

class DECLSPEC sbfGroup
//Base class for grouping
{
public:
    sbfGroup();
    virtual ~sbfGroup();
private:
    std::vector<sbfGroupFilter> filters_;
public:
    void addFilter(const sbfGroupFilter & filter);
    void clearFilters();
    int numFilters();
    sbfGroupFilter & filter(int count);
};

#endif // SBFGROUP_H
