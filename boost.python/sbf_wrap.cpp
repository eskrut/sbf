#include <Python.h>
#include <boost/python.hpp>

int test()
{
    return 42;
}

BOOST_PYTHON_MODULE(libsbfpy)
{
    using namespace boost::python;
    def("test", test);
}
