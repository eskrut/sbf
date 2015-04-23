#include "class_sbfElement.h"

#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <vector>
#include "iterable_converter.hpp"

#include "sbfElement.h"

void class_sbfElement_object()
{
    using namespace boost::python;

    enum_<ElementType>("ElementType")
            .value("NO_DEFINED_ELEMENT", ElementType::NO_DEFINED_ELEMENT)
            .value("BEAM_LINEAR_3DOF", ElementType::BEAM_LINEAR_3DOF)
            .value("BEAM_QUADRATIC_3DOF", ElementType::BEAM_QUADRATIC_3DOF)
            .value("BEAM_LINEAR_6DOF", ElementType::BEAM_LINEAR_6DOF)
            .value("BEAM_QUADRATIC_6DOF", ElementType::BEAM_QUADRATIC_6DOF)
            .value("RECTANGLE_LINEAR", ElementType::RECTANGLE_LINEAR)
            .value("RECTANGLE_QUADRATIC", ElementType::RECTANGLE_QUADRATIC)
            .value("TRIANGLE_LINEAR", ElementType::TRIANGLE_LINEAR)
            .value("TRIANGLE_QUADRATIC", ElementType::TRIANGLE_QUADRATIC)
            .value("HEXAHEDRON_LINEAR", ElementType::HEXAHEDRON_LINEAR)
            .value("HEXAHEDRON_QUADRATIC", ElementType::HEXAHEDRON_QUADRATIC)
            .value("TRIANGLE_PRISM_LINEAR", ElementType::TRIANGLE_PRISM_LINEAR)
            .value("TRIANGLE_PRISM_QUADRATIC", ElementType::TRIANGLE_PRISM_QUADRATIC)
            .value("TETRAHEDRON_LINEAR", ElementType::TETRAHEDRON_LINEAR)
            .value("TETRAHEDRON_QUADRATIC", ElementType::TETRAHEDRON_QUADRATIC)
            .value("TETRAHEDRON_LINEAR", ElementType::TETRAHEDRON_LINEAR)
            ;

    class_<sbfElement>("Element", init<const ElementType , const std::vector<int> &>())
            .def("mtr", &sbfElement::mtr)
            .def("setMtr", &sbfElement::setMtr)
            .def("type", &sbfElement::type)
            .def("setType", &sbfElement::setType)
            .def("numNodes", &sbfElement::numNodes)
            .def("indexes", &sbfElement::indexes)
            .def("setIndexes", static_cast<void (sbfElement::*)(const std::vector<int> &)>(&sbfElement::setNodes))
            .def("numNodeDof", &sbfElement::numNodeDof)
            ;
}
