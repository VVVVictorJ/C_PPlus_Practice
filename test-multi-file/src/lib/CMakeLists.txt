cmake_minimum_required(VERSION 3.16)

#添加对c++11的支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

#PROJECT_BINARY_DIR 为源外编译目录
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

#PROJECT_SOURCE_DIR 为工程顶层目录
aux_source_directory(${PROJECT_SOURCE_DIR}/src/lib/src FOOlib_src)

#指明头文件目录
include_directories("${PROJECT_SOURCE_DIR}/src/lib/include")

#SHARED 为生成动态库文件 libfoo.so 
add_library(foo SHARED ${FOOlib_src})

#STATIC 生成静态库文件 libfoo_static.a
add_library(foo_static STATIC ${FOOlib_src})

#重置静态库文件名为libfoo，因为cmake不允许输出重名
set_target_properties(foo_static PROPERTIES OUTPUT_NAME "foo")
