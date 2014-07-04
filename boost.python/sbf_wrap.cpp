#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <vector>

#include "sbfEnums.h"
#include "sbfNode.h"
#include "sbfElement.h"
#include "sbfMesh.h"
#include "sbfPropertyTable.h"
#include "sbfMaterialProperties.h"
#include "sbfPropertiesSet.h"
#include "sbfStiffMatrix.h"
#include "sbfMatrixIterator.h"

#include "iterable_converter.hpp"

BOOST_PYTHON_MODULE(libsbfpy)
{
    using namespace boost::python;

    // Register interable conversions.
    iterable_converter()
            // Build-in type.
            .from_python<std::vector<int>>()
            .from_python<std::vector<float>>()
            .from_python<std::vector<double>>()
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

    //FIXME compiler says that cant find appropriate signature :(
//    sbfMesh *(sbfMesh::*makeBlock_vec)(std::vector<float> &, std::vector<float> &, std::vector<float> &, ElementType) = &sbfMesh::makeBlock;
//    sbfMesh *(sbfMesh::*makeBlock_dim)(float, float, float, int, int, int, ElementType) = &sbfMesh::makeBlock;
//    sbfMesh *(sbfMesh::*makeCylinderPart_vec)(std::vector<float> &, std::vector<float> &, std::vector<float> &, ElementType) = &sbfMesh::makeCylinderPart;
//    sbfMesh *(sbfMesh::*makeCylinderPart_dim)(float, float, float, float, float, float, int, int, int, ElementType) = &sbfMesh::makeCylinderPart;
    void (sbfMesh::*addMesh_ptr)(const sbfMesh *, bool, bool, float) = &sbfMesh::addMesh;
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
//            .def("makeBlock", (sbfMesh *(sbfMesh::*)(std::vector<float> &, std::vector<float> &, std::vector<float> &, ElementType))&sbfMesh::makeBlock)
//            .def("makeBlock", makeBlock_vec, return_value_policy<manage_new_object>())
//            .def("makeBlock", makeBlock_dim, return_value_policy<manage_new_object>())
//            .staticmethod("makeBlock")
//            .def("makeCylinderPart", makeCylinderPart_vec, return_value_policy<manage_new_object>())
//            .def("makeCylinderPart", makeCylinderPart_dim, return_value_policy<manage_new_object>())
//            .staticmethod("makeCylinderPart")
            .def("addMesh", addMesh_ptr)
            .def("setMtr", &sbfMesh::setMtr)
            .def("increaseMtr", &sbfMesh::increaseMtr)
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

    struct sbfStiffMatrix_Wrap : sbfStiffMatrix, wrapper<sbfStiffMatrix>
    {
        sbfStiffMatrix_Wrap(sbfMesh *mesh, sbfPropertiesSet *propSet, MatrixType type) :
            sbfStiffMatrix(mesh, propSet, type) {}
        // Pure virtual methods
        void compute(int startID, int stopID) { this->get_override("compute")(startID, stopID); }
        sbfMatrixIterator *createIterator() { return this->get_override("createIterator")(); }
        int numDof() const { return this->get_override("numDof")(); }

        // Virtual functions
        MatrixStoreType storeType() const
        {
            if( override storeType = this->get_override("storeType") ) return storeType();
            return sbfStiffMatrix::storeType();
        }
        MatrixStoreType default_storeType() const { return this->sbfStiffMatrix::storeType(); }

        void read_stream(std::ifstream &in)
        {
            if( override read_stream = this->get_override("read") ) read_stream(in);
            else sbfStiffMatrix::read_stream(in);
        }
        void default_read(std::ifstream &in) { this->sbfStiffMatrix::read_stream(in); }

        void write_stream(std::ofstream &out) const
        {
            if( override write_stream = this->get_override("write") ) write_stream(out);
            else sbfStiffMatrix::write_stream(out);
        }
        void default_write(std::ofstream &out) const { this->sbfStiffMatrix::write_stream(out); }
    };
    void (sbfStiffMatrix::*read_stream)(std::ifstream &in) = &sbfStiffMatrix::read_stream;
    void (sbfStiffMatrix::*write_stream)(std::ofstream &out) const = &sbfStiffMatrix::write_stream;

    class_<sbfStiffMatrix_Wrap, boost::noncopyable>("sbfStiffMatrix", init<sbfMesh *, sbfPropertiesSet *, MatrixType>())
            .def("compute", pure_virtual(&sbfStiffMatrix::compute))
            .def("createIterator", pure_virtual(&sbfStiffMatrix::createIterator), return_value_policy<manage_new_object>())
            .def("storeType", &sbfStiffMatrix::storeType, &sbfStiffMatrix_Wrap::default_storeType)
            .def("read", read_stream, &sbfStiffMatrix_Wrap::default_read)
            .def("write", write_stream, &sbfStiffMatrix_Wrap::default_write)
            ;

    struct sbfMatrixIterator_Wrap : sbfMatrixIterator, wrapper<sbfMatrixIterator>
    {
        sbfMatrixIterator_Wrap() : sbfMatrixIterator(nullptr) {}

        // Pure virtual methods
        void setToRow(const int rowIndex) { this->get_override("setToRow")(rowIndex); }
        void setToColumn(const int columnIndex) { this->get_override("setToColumn")(columnIndex); }
        void setToRowInverse(const int rowIndex) { this->get_override("setToRowInverse")(rowIndex); }
        void setToColumnInverse(const int columnIndex) { this->get_override("setToColumnInverse")(columnIndex); }
        bool isValid() const { return this->get_override("isValid")(); }
        bool haveNext() const { return this->get_override("haveNext")(); }
        bool next() { return this->get_override("next")(); }
        double *data() const { return this->get_override("data")(); }
        double *data(bool *isInNormal) const { return this->get_override("data")(isInNormal); }
        bool isDiagonal() const { return this->get_override("isDiagonal")(); }
        bool isInNormal() const { return this->get_override("isInNormal")(); }
        double *diagonal(const int index) const { return this->get_override("diagonal")(index); }
    };

    class_<sbfMatrixIterator_Wrap, boost::noncopyable>("sbfMatrixIterator", init<>(nullptr))
            .def("setToRow", pure_virtual(&sbfMatrixIterator::setToRow))
            .def("setToColumn", pure_virtual(&sbfMatrixIterator::setToColumn))
            .def("setToRowInverse", pure_virtual(&sbfMatrixIterator::setToRowInverse))
            .def("setToColumnInverse", pure_virtual(&sbfMatrixIterator::setToColumnInverse))
            .def("isValid", pure_virtual(&sbfMatrixIterator::isValid))
            .def("haveNext", pure_virtual(&sbfMatrixIterator::haveNext))
            .def("next", pure_virtual(&sbfMatrixIterator::next))
//            .def("data", pure_virtual( (double *(sbfMatrixIterator::*)() const)&sbfMatrixIterator::data ), return_value_policy<reference_existing_object>())
            .def("isDiagonal", pure_virtual(&sbfMatrixIterator::isDiagonal))
            .def("isInNormal", pure_virtual(&sbfMatrixIterator::isInNormal))
//            .def("diagonal", pure_virtual(&sbfMatrixIterator::diagonal), return_value_policy<reference_existing_object>())
            ;
}
