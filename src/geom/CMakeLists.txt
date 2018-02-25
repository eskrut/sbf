file(GLOB sources_loc *.cpp)
file(GLOB headers_loc *.h)

set(sources ${sources} ${sources_loc} PARENT_SCOPE)
set(headers ${headers} ${headers_loc} PARENT_SCOPE)
