#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>

#include "class_sbfNode.h"
#include "class_sbfElement.h"
#include "class_sbfMesh.h"

#include "iterable_converter.hpp"

#include <vector>
#include <list>
#include <string>

BOOST_PYTHON_MODULE(libsbfpy)
{
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

    class_sbfNode_object();
    class_sbfElement_object();
    class_sbfMesh_object();
}
