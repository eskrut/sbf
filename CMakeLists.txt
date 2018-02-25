project(sbf)
cmake_minimum_required(VERSION 2.8)

set(SBF_MAJOR_VERSION 0)
set(SBF_MINOR_VERSION 3)
set(SBF_PATCH_VERSION 5)
set(SBF_VERSION ${SBF_MAJOR_VERSION}.${SBF_MINOR_VERSION}.${SBF_PATCH_VERSION})

#set(CMAKE_DEBUG_POSTFIX "-dev" CACHE STRING "Postfix for debug configuration")

set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")

if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/sbf)
endif()

set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

include_directories(
  "${PROJECT_SOURCE_DIR}/src"
  "${PROJECT_BINARY_DIR}")

add_subdirectory(src)

source_group("Source Files" FILES ${sources})
source_group("Header Files" FILES ${headers})

if(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++1y -Wall -Wextra -pedantic ${CMAKE_CXX_FLAGS}")
endif()


configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

add_library(${PROJECT_NAME} SHARED ${sources} ${headers} config.h.in)

#set_target_properties(sbf PROPERTIES PUBLIC_HEADER "src/sbf.h;${CMAKE_CURRENT_BINARY_DIR}/config.h")
set_target_properties(sbf PROPERTIES PUBLIC_HEADER "${headers};${CMAKE_CURRENT_BINARY_DIR}/config.h")

install(TARGETS sbf
  EXPORT sbfTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/sbf"
    COMPONENT dev)

export(TARGETS sbf
  FILE "${PROJECT_BINARY_DIR}/sbfTargets.cmake")

export(PACKAGE sbf)

file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")

#if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
#  set(CONFIG_IN "sbfConfig.cmake.debug.in")
#else()
  set(CONFIG_IN "sbfConfig.cmake.in")
#endif()

set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/src" "${PROJECT_BINARY_DIR}")
configure_file(${CONFIG_IN}
  "${PROJECT_BINARY_DIR}/sbfConfig.cmake" @ONLY)

set(CONF_INCLUDE_DIRS "\${SBF_CMAKE_DIR}/${REL_INCLUDE_DIR}/sbf")
configure_file(${CONFIG_IN}
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/sbfConfig.cmake" @ONLY)

configure_file(sbfConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/sbfConfigVersion.cmake" @ONLY)

install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/sbfConfig.cmake"
  "${PROJECT_BINARY_DIR}/sbfConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

install(EXPORT sbfTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)

set(USE_STD_THREADS ON CACHE BOOL "Use c++11 threads instead of posix or win32" FORCE)
#mark_as_advanced(USE_STD_THREADS)
if(USE_STD_THREADS)
    add_definitions(-DTHREAD_MODEL_STD)
endif()

set(SBF_NUM_THREADS "8" CACHE STRING "Number of threads to lounch parallel routines")
add_definitions(-DSBF_NUM_THREADS=${SBF_NUM_THREADS})

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

option(MAKE_PYTHON_BINDINGS "Build ib for use in Python" ON)
if(MAKE_PYTHON_BINDINGS)
    add_subdirectory(boost.python)
endif()
