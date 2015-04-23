#include "class_sbfSELevel.h"

#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <vector>
#include "iterable_converter.hpp"

#include "sbfSELevel.h"

void class_sbfSELevel_object()
{
    using namespace boost::python;

    class_<sbfSELevel>("SELevel", init<>())
            .def("size", &sbfSELevel::size)
            .def("levelIndex", &sbfSELevel::levelIndex)
            .def("index", &sbfSELevel::index)
            .def("setIndex", &sbfSELevel::setIndex)
            .def("numSE", &sbfSELevel::numSE)
            .def("indexesOfSE", &sbfSELevel::indexesOfSE)
            .def("prev", &sbfSELevel::prev, return_internal_reference<>())
            .def("next", &sbfSELevel::next, return_internal_reference<>())
            .def("read", &sbfSELevel::readFromFile)
            .def("write", &sbfSELevel::writeToFile)
            ;
}
