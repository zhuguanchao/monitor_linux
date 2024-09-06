cmake_minimum_required(VERSION 3.10.2)
project(test_monitor LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_CXX_STANDARD 17)
#//通过设置 CMAKE_MODULE_PATH 变量为 ${CMAKE_SOURCE_DIR}/cmake，
#你告诉了 CMake 在项目根源目录下的 /cmake 子目录中搜索自定义的 .CMake 模块文件。

add_subdirectory(rpc_manager)
add_subdirectory(test_monitor)
add_subdirectory(proto)
add_subdirectory(display_monitor)