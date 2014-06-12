#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>

#include "sbfEnums.h"
#include "sbfNode.h"
#include "sbfElement.h"
#include "sbfMesh.h"
#include "sbfPropertyTable.h"
#include "sbfMaterialProperties.h"
#include "sbfPropertiesSet.h"

#include "iterable_converter.hpp"

BOOST_PYTHON_MODULE(libsbfpy)
{
    using namespace boost::python;

    // Register interable conversions.
    iterable_converter()
            // Build-in type.
            .from_python<std::vector<int>>()
            .from_python<std::vector<float>>()
            // Each dimension needs to be convertable.
            .from_python<std::vector<std::string> >()
            .from_python<std::vector<std::vector<std::string> > >()
            ;

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

    enum_<FileVersion>("FileVersion")
            .value("OLD_FORMAT", FileVersion::OLD_FORMAT)
            .value("NEW_FORMAT", FileVersion::NEW_FORMAT)
            .value("AUTO_FORMAT", FileVersion::AUTO_FORMAT)
            .value("NOT_DEFINED_FORMAT", FileVersion::NOT_DEFINED_FORMAT)
            ;

    class_<sbfNode>("sbfNode", init<float, float, float>())
            .def(init<const sbfNode &>())
            .def("rotate", &sbfNode::rotate)
            ;
    class_<sbfElement>("sbfElement", init<const ElementType , const std::vector<int> &>())
            ;

    int (sbfMesh::*addNode_crd)(float, float, float, bool, float) = &sbfMesh::addNode;
    int (sbfMesh::*addNode_node)(const sbfNode &, bool, float) = &sbfMesh::addNode;
    void (sbfMesh::*scale_xyz)(float, float, float) = &sbfMesh::scale;
    sbfMesh *(sbfMesh::*makeBlock_vec)(std::vector<float> &, std::vector<float> &, std::vector<float> &, ElementType);
    sbfMesh *(sbfMesh::*makeBlock_dim)(float, float, float, int, int, int, ElementType);
    sbfMesh *(sbfMesh::*makeCylinderPart_vec)(std::vector<float> &, std::vector<float> &, std::vector<float> &, ElementType);
    sbfMesh *(sbfMesh::*makeCylinderPart_dim)(float, float, float, float, float, float, int, int, int, ElementType);
    void (sbfMesh::*addMesh_ptr)(sbfMesh *, bool, bool, float) = &sbfMesh::addMesh;
    class_<sbfMesh>("sbfMesh", init<>())
            .def(init<const sbfMesh &>())
            .def("readMeshFromFiles", &sbfMesh::readMeshFromFiles)
            .def("writeMeshToFiles", &sbfMesh::writeMeshToFiles)
            .def("addNode", addNode_crd)
            .def("addNode", addNode_node)
            .def("addElement", &sbfMesh::addElement)
            .def("scale", scale_xyz)
            .def("translate", &sbfMesh::translate)
            .def("rotate", &sbfMesh::rotate)
            .def("makeBlock", makeBlock_vec, return_value_policy<manage_new_object>())
            .def("makeBlock", makeBlock_dim, return_value_policy<manage_new_object>())
            .staticmethod("makeBlock")
            .def("makeCylinderPart", makeCylinderPart_vec, return_value_policy<manage_new_object>())
            .def("makeCylinderPart", makeCylinderPart_dim, return_value_policy<manage_new_object>())
            .staticmethod("makeCylinderPart")
            .def("addMesh", addMesh_ptr)
            .def("setMtr", &sbfMesh::setMtr)
            .def("increaseMtr", &sbfMesh::increaseMtr)
//            .def("", &sbfMesh::)
//            .def("", &sbfMesh::)
//            .def("", &sbfMesh::)
            ;

    class_<sbfPropertyTable>("sbfPropertyTable", init<const std::string &>())
            .def("value", &sbfPropertyTable::value)
            .def("addNodeValue", &sbfPropertyTable::addNodeValue)
            .def("setCurParam", &sbfPropertyTable::setCurParam)
            .def("curValue", &sbfPropertyTable::curValue)
            .def("name", &sbfPropertyTable::name, return_value_policy<reference_existing_object>())
            ;

    void (sbfMaterialProperties::*addTable_ptr)(sbfPropertyTable *) = &sbfMaterialProperties::addTable;
    class_<sbfMaterialProperties>("sbfMaterialProperties", init<const std::string &>())
            .def("addTable", addTable_ptr)
            .def("propertyTable", &sbfMaterialProperties::propertyTable, return_value_policy<reference_existing_object>())
            .def("makeMPropertiesSteel", &sbfMaterialProperties::makeMPropertiesSteel, return_value_policy<manage_new_object>())
            .staticmethod("makeMPropertiesSteel")
            ;

    class_<sbfPropertiesSet>("sbfPropertiesSet")
            .def("material", &sbfPropertiesSet::material, return_value_policy<reference_existing_object>())
            .def("addMaterial", &sbfPropertiesSet::addMaterial)
            ;
}
