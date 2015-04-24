#include "class_sbfSELevelList.h"

#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <vector>
#include "iterable_converter.hpp"

#include "sbfSELevelList.h"
#include "sbfSELevel.h"

void class_sbfSELevelList_object()
{
    using namespace boost::python;

    class_<sbfSELevelList>("SELevelList", init<>())
            .def("numLevels", &sbfSELevelList::numLevels)
            .def("level", &sbfSELevelList::level, return_internal_reference<>())
            .def("read", &sbfSELevelList::readFromFiles)
            .def("write", &sbfSELevelList::writeToFiles)
            ;

}
