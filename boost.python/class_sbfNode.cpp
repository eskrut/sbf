#include "class_sbfNode.h"

#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>

#include "sbfNode.h"

void class_sbfNode_object()
{
    using namespace boost::python;

    class_<sbfNode>("Node", init<float, float, float>())
            .def(init<const sbfNode &>())
            .def("x", &sbfNode::x)
            .def("y", &sbfNode::y)
            .def("z", &sbfNode::z)
            .def("setX", &sbfNode::setX)
            .def("setY", &sbfNode::setY)
            .def("setZ", &sbfNode::setZ)
            .def("isSame", &sbfNode::isSame)
            .def("isSameX", &sbfNode::isSameX)
            .def("isSameY", &sbfNode::isSameY)
            .def("isSameZ", &sbfNode::isSameZ)
            .def("distance", &sbfNode::distance)
            .def("rotate", &sbfNode::rotate)
            ;
}
