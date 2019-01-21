project(sbfTests)
cmake_minimum_required(VERSION 2.8)

if(UNIX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic ${CMAKE_CXX_FLAGS}")
endif()

set (tests_srcs
main.cpp
#sbfStiffMatrixBandIterator.cpp
sbfStiffMatrixBand.cpp
#sbfStiffMatrixBlockIterator.cpp
sbfSElement.cpp
meshbuilders.cpp
)

find_package(sbf REQUIRED)
include_directories(${SBF_INCLUDE_DIRS})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

option(TEST_SIMPLE_STIFF "Test common simple stiff matrixes operations" ON)
if(TEST_SIMPLE_STIFF)
    add_subdirectory(simpleStiff)
endif()

add_executable(${PROJECT_NAME} ${tests_srcs})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${SBF_LIBRARIES})
enable_testing()
add_test(${PROJECT_NAME} ${PROJECT_NAME})
