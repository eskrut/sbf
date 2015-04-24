find_package(Boost COMPONENTS python REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(../src)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARY_DIRS})

add_library(sbfpy SHARED
sbf_wrap.cpp
class_sbfNode.cpp
class_sbfElement.cpp
class_sbfMesh.cpp
class_sbfGroupFilter.cpp
class_sbfSELevel.cpp
class_sbfSELevelList.cpp
class_sbfGroupFilter.cpp
class_sbfElementGroup.cpp
)
set_target_properties( sbfpy
    PROPERTIES
    SUFFIX ".so"
)
#set_target_properties( sbfpy
#    PROPERTIES
#    PREFIX ""
#)
target_link_libraries(sbfpy
${Boost_LIBRARIES}
${PYTHON_LIBRARIES}
sbf
)
