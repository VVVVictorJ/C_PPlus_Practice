cmake_minimum_required(VERSION 3.16)

#添加对c++11的支持
set( CMAKE_CXX_FLAGS "-std=c++11" )
#定义输出文件目录
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
#定义源文件目录
aux_source_directory(${PROJECT_SOURCE_DIR}/src/test/src test_src)
#头文件目录
include_directories("${PROJECT_SOURCE_DIR}/src/lib/include")
#库文件目录
link_directories("${PROJECT_BINARY_DIR}/lib")
#定义可执行文件名
add_executable(test ${test_src})
#链接静态库文件
target_link_libraries(test libfoo.a)