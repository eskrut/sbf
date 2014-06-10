find_package(Boost COMPONENTS python REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(../src)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARIES})

add_library(sbfpy SHARED sbf_wrap.cpp)
target_link_libraries(sbfpy
${Boost_LIBRARIES}
${PYTHON_LIBRARIES}
sbf
)
