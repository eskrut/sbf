#include "sbfGroup.h"
#include "sbfGroupFilter.h"

sbfGroup::sbfGroup()
{}
sbfGroup::~sbfGroup()
{}

void sbfGroup::addFilter(const sbfGroupFilter &filter)
{
    filters_.push_back(filter);
}
void sbfGroup::clearFilters()
{
    filters_.clear();
}
int sbfGroup::numFilters()
{
    return (int)filters_.size();
}
sbfGroupFilter & sbfGroup::filter(int count)
{
    return filters_[count];
}
