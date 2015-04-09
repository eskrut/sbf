project(sbfTests)
cmake_minimum_required(VERSION 2.8)

if(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra -pedantic ${CMAKE_CXX_FLAGS}")
endif()
#aux_source_directory(. SRC_LIST)
set (SRC_LIST
main.cpp
sbfStiffMatrixBandIterator.cpp
sbfStiffMatrixBand.cpp
)

find_package(sbf REQUIRED)
include_directories(${SBF_INCLUDE_DIRS})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${SBF_LIBRARIES})
enable_testing()
add_test(${PROJECT_NAME} ${PROJECT_NAME})

set(CMAKE_VERBOSE_MAKEFILE ON)
