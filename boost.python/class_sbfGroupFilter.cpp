#include "class_sbfGroupFilter.h"

#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>

#include "sbfGroupFilter.h"
#include "sbfElement.h"
#include "sbfNode.h"

void class_sbfGroupFilter_object()
{
    using namespace boost::python;

    class_<sbfGroupFilter>("GroupFilter", "Object for filtering on materials, coordinates, types, etc.", init<>())
            .def("setMtrF", &sbfGroupFilter::setMtrF)
            .def("unsetMtrF", &sbfGroupFilter::unsetMtrF)
            .def("setTypeF", &sbfGroupFilter::setTypeF)
            .def("unsetTypeF", &sbfGroupFilter::unsetTypeF)
            .def("setCrdF", &sbfGroupFilter::setCrdF)
            .def("setCrdXF", &sbfGroupFilter::setCrdXF)
            .def("setCrdYF", &sbfGroupFilter::setCrdYF)
            .def("setCrdZF", &sbfGroupFilter::setCrdZF)
            .def("unsetCrdF", &sbfGroupFilter::unsetCrdF)
            .def("isPass", static_cast<bool (sbfGroupFilter::*)(const sbfElement&)>(&sbfGroupFilter::isPass))
            .def("isPass", static_cast<bool (sbfGroupFilter::*)(const sbfNode&)>(&sbfGroupFilter::isPass))
            ;
}
