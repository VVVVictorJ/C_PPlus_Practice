cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

aux_source_directory(${PROJECT_SOURCE_DIR}/src/lib/src Findlib_src)

include_directories("${PROJECT_SOURCE_DIR}/src/lib/include")

add_library(finded SHARED ${Findlib_src})

add_library(finded_static STATIC ${Findlib_src})

set_target_properties(finded_static PROPERTIES OUTPUT_NAME "finded")

