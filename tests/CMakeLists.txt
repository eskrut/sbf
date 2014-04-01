project(sbfTests)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

#if(UNIX)
#    list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
#endif()

find_package(sbf REQUIRED)
include_directories(${SBF_INCLUDE_DIRS})

set(TARGET_QT_VERSION "5" CACHE STRING "Expected Qt version")

set_property(CACHE TARGET_QT_VERSION PROPERTY STRINGS 4 5)

if(NOT (TARGET_QT_VERSION VERSION_EQUAL "4" OR TARGET_QT_VERSION VERSION_EQUAL "5"))
  message(FATAL_ERROR "Expected value for TARGET_QT_VERSION is either '4' or '5'")
endif()

file(GLOB headersToMoc test_*.h)

if(TARGET_QT_VERSION VERSION_GREATER "4")
  find_package(Qt5Test REQUIRED)
  include_directories(${Qt5Test_INCLUDE_DIRS})
  add_definitions(${Qt5Test_DEFINITIONS})

  qt5_wrap_cpp(MOCSrcs ${headersToMoc})

  set(QT_LIBRARIES ${Qt5Test_LIBRARIES})
else()
  find_package(Qt REQUIRED)
  include(${QT_USE_FILE})
  include_directories(${QT_INCLUDE_DIRS})
  qt4_wrap_cpp(MOCSrcs ${headersToMoc})
endif()

add_executable(${PROJECT_NAME} ${SRC_LIST} ${MOCSrcs})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SBF_LIBRARIES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
