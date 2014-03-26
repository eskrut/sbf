project(sbf)
cmake_minimum_required(VERSION 2.8)

set(SBF_MAJOR_VERSION 0)
set(SBF_MINOR_VERSION 3)
set(SBF_PATCH_VERSION 5)
set(SBF_VERSION ${SBF_MAJOR_VERSION}.${SBF_MINOR_VERSION}.${SBF_PATCH_VERSION})

set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")

if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/sbf)
endif()

set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

include_directories(
  "${PROJECT_SOURCE_DIR}"
  "${PROJECT_BINARY_DIR}")

add_subdirectory(src)

source_group("Source Files" FILES ${sources})
source_group("Header Files" FILES ${headers})

if(UNIX)
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -Wall" ${CMAKE_CXX_FLAGS})
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

set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(sbfConfig.cmake.in
  "${PROJECT_BINARY_DIR}/sbfConfig.cmake" @ONLY)

set(CONF_INCLUDE_DIRS "\${SBF_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(sbfConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/sbfConfig.cmake" @ONLY)

configure_file(sbfConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/sbfConfigVersion.cmake" @ONLY)

install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/sbfConfig.cmake"
  "${PROJECT_BINARY_DIR}/sbfConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

install(EXPORT sbfTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)