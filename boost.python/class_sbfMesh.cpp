#include "class_sbfMesh.h"

#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <vector>
#include "iterable_converter.hpp"

#include "sbfMesh.h"
#include "sbfNode.h"
#include "sbfElement.h"
#include "sbfGroupFilter.h"
#include "sbfElementGroup.h"
#include "sbfMeshBuilders.h"

void class_sbfMesh_object()
{
    using namespace boost::python;
    using vf = std::vector<float>;

    enum_<FileVersion>("FileVersion")
            .value("OLD_FORMAT", FileVersion::OLD_FORMAT)
            .value("NEW_FORMAT", FileVersion::NEW_FORMAT)
            .value("AUTO_FORMAT", FileVersion::AUTO_FORMAT)
            .value("NOT_DEFINED_FORMAT", FileVersion::NOT_DEFINED_FORMAT)
            ;

    class_<sbfMesh>("Mesh", "Class for representing FE meshes", init<>())
            .def(init<const sbfMesh &>()/*, "Copy existing mesh"*/)
            .def("read", static_cast<int (sbfMesh::*)(const std::string&, const std::string&, const std::string&)>(&sbfMesh::readMeshFromFiles))
            .def("readInd", &sbfMesh::readIndFromFile)
            .def("readCrd", &sbfMesh::readCrdFromFile)
            .def("readMtr", &sbfMesh::readMtrFromFile)
            .def("write", static_cast<int (sbfMesh::*)(const std::string&, const std::string&, const std::string&)>(&sbfMesh::writeMeshToFiles))
            .def("write", static_cast<int (sbfMesh::*)(const std::string&)>(&sbfMesh::writeMeshToFilesWithPrefix))
            .def("writeInd", &sbfMesh::writeIndToFile)
            .def("writeCrd", &sbfMesh::writeCrdToFile)
            .def("writeMtr", &sbfMesh::writeMtrToFile)
            .def("printInfo", &sbfMesh::printInfo)
            .def("numNodes", &sbfMesh::numNodes)
            .def("numElements", &sbfMesh::numElements)
            .def("addNode", static_cast<int (sbfMesh::*)(const sbfNode &, bool, float)>(&sbfMesh::addNode))
            .def("addNode", static_cast<int (sbfMesh::*)(float, float, float, bool, float)>(&sbfMesh::addNode))
            .def("deleteNode", &sbfMesh::deleteNode)
            .def("addElement", &sbfMesh::addElement)
            .def("deleteElement", &sbfMesh::deleteElement)
            .def("addMesh", static_cast<void (sbfMesh::*)(const sbfMesh *, bool, bool, float)>(&sbfMesh::addMesh))
            .def("node", static_cast<sbfNode &(sbfMesh::*)(const int)>(&sbfMesh::node), return_internal_reference<>())
            .def("elem", static_cast<sbfElement &(sbfMesh::*)(const int)>(&sbfMesh::elem), return_internal_reference<>())
            .def("nodeIDAt", &sbfMesh::nodeAt)
            .def("scale", static_cast<void (sbfMesh::*)(float)>(&sbfMesh::scale))
            .def("scale", static_cast<void (sbfMesh::*)(float, float, float)>(&sbfMesh::scale))
            .def("translate", &sbfMesh::translate)
            .def("rotate", &sbfMesh::rotate)
            .def("addElementGroup",
                 static_cast<sbfElementGroup * (sbfMesh::*)(sbfGroupFilter)>(&sbfMesh::addElementGroup),
                 return_internal_reference<>())
            .def("elementGroup", &sbfMesh::elemGroup, return_internal_reference<>())
            .def("clearElementGroups", &sbfMesh::clearElemGroups)
            .def("processGroups", &sbfMesh::processElemGroups)
            .def("setMtr", &sbfMesh::setMtr)
            .def("increaseMtr", &sbfMesh::increaseMtr)
            .def("replaceMtr", &sbfMesh::replaceMtr)
            .def("makeBlock",
                 static_cast<sbfMesh *(*)(vf &, vf &, vf &, ElementType)>(&sbfMeshBuilder::makeBlock),
                 return_value_policy<manage_new_object>())
            .def("makeBlock",
                 static_cast<sbfMesh *(*)(float, float, float, int, int, int, ElementType)>(&sbfMeshBuilder::makeBlock),
                 return_value_policy<manage_new_object>())
            .staticmethod("makeBlock")
            .def("makeCylinderPart",
                 static_cast<sbfMesh *(*)(vf &, vf &, vf &, ElementType)>(&sbfMeshBuilder::makeTubePart),
                 return_value_policy<manage_new_object>())
            .def("makeCylinderPart",
                 static_cast<sbfMesh *(*)(float, float, float, float, float, float, int, int, int, ElementType)>(&sbfMeshBuilder::makeTubePart),
                 return_value_policy<manage_new_object>())
            .staticmethod("makeCylinderPart")
            ;
}
