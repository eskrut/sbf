#include "class_sbfElementGroup.h"

#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>

#include "sbfElementGroup.h"
#include "sbfGroupFilter.h"
#include "sbfElement.h"

void class_sbfElementGroup_object()
{
    using namespace boost::python;

    class_<sbfElementGroup>("ElementGroup", "Group of elements.", init<>())
            .def("addFilter", &sbfElementGroup::addFilter)
            .def("numFilters", &sbfElementGroup::numFilters)
            .def("filter", &sbfElementGroup::filter, return_internal_reference<>())
            .def("clear", &sbfElementGroup::clearGroup)
            .def("elemIndexes", &sbfElementGroup::elemIndList)
            .def("nodeIndexes", &sbfElementGroup::nodeIndList)
            ;
}
