file(GLOB sources_loc *.cpp)
file(GLOB headers_loc *.h)

add_subdirectory(geom)

set(sources ${sources} ${sources_loc} PARENT_SCOPE)
set(headers ${headers} ${headers_loc} PARENT_SCOPE)
