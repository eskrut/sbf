#include <boost/python.hpp>
#include <boost/python/scope.hpp>
#include <boost/python/stl_iterator.hpp>

#include "class_sbfNode.h"
#include "class_sbfElement.h"
#include "class_sbfMesh.h"

#include "iterable_converter.hpp"

#include <vector>
#include <list>
#include <string>

template<typename T>
struct Vector_to_python_list
{

    static PyObject* convert(std::vector<T> const& v)
    {
        using namespace std;
        using namespace boost::python;
        using boost::python::list;
        list l;
        typename vector<T>::const_iterator p;
        for(p=v.begin();p!=v.end();++p){
            l.append(object(*p));
        }
        return incref(l.ptr());
    }
};

BOOST_PYTHON_MODULE(libsbfpy)
{
    boost::python::scope().attr("__doc__") = "Python bindings for sbf library";

    // Register interable conversions.
    iterable_converter()
            // Build-in type.
            .from_python<std::vector<int>>()
            .from_python<std::vector<float>>()
            .from_python<std::vector<double>>()
            .from_python<std::list<int>>()
            // Each dimension needs to be convertable.
            .from_python<std::vector<std::string>>()
            .from_python<std::vector<std::vector<std::string>>>()
            ;
    boost::python::to_python_converter<std::vector<int>, Vector_to_python_list<int>>();

    class_sbfNode_object();
    class_sbfElement_object();
    class_sbfMesh_object();
}
