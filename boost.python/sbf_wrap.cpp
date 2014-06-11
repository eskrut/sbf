#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>

#include "sbfEnums.h"
#include "sbfNode.h"
#include "sbfElement.h"
#include "sbfMesh.h"

/// @brief Type that allows for registration of conversions from
///        python iterable types.
struct iterable_converter
{
  /// @note Registers converter from a python interable type to the
  ///       provided type.
  template <typename Container>
  iterable_converter&
  from_python()
  {
    boost::python::converter::registry::push_back(
      &iterable_converter::convertible,
      &iterable_converter::construct<Container>,
      boost::python::type_id<Container>());
    return *this;
  }

  /// @brief Check if PyObject is iterable.
  static void* convertible(PyObject* object)
  {
    return PyObject_GetIter(object) ? object : NULL;
  }

  /// @brief Convert iterable PyObject to C++ container type.
  ///
  /// Container Concept requirements:
  ///
  ///   * Container::value_type is CopyConstructable.
  ///   * Container can be constructed and populated with two iterators.
  ///     I.e. Container(begin, end)
  template <typename Container>
  static void construct(
    PyObject* object,
    boost::python::converter::rvalue_from_python_stage1_data* data)
  {
    namespace python = boost::python;
    // Object is a borrowed reference, so create a handle indicting it is
    // borrowed for proper reference counting.
    python::handle<> handle(python::borrowed(object));

    // Obtain a handle to the memory block that the converter has allocated
    // for the C++ type.
    typedef python::converter::rvalue_from_python_storage<Container>
                                                                 storage_type;
    void* storage = reinterpret_cast<storage_type*>(data)->storage.bytes;

    typedef python::stl_input_iterator<typename Container::value_type>
                                                                     iterator;

    // Allocate the C++ type into the converter's memory block, and assign
    // its handle to the converter's convertible variable.  The C++
    // container is populated by passing the begin and end iterators of
    // the python object to the container's constructor.
    data->convertible = new (storage) Container(
      iterator(python::object(handle)), // begin
      iterator());                      // end
  }
};

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
}
