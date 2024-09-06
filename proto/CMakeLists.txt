find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(c-ares CONFIG)
# find_package(Threads)

#
# Protobuf/Grpc source files
#
set(PROTO_FILES
    monitor_info.proto
    cpu_load.proto
    cpu_softirq.proto
    cpu_stat.proto
    mem_info.proto
    net_info.proto
)

#
# Add Library target with protobuf sources
#
add_library(monitor_proto ${PROTO_FILES})
target_link_libraries(monitor_proto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)
target_include_directories(monitor_proto PUBLIC
${PROTOBUF_INCLUDE_DIRS} 
${CMAKE_CURRENT_BINARY_DIR}
)
#${PROTOBUF_INCLUDE_DIRS}通常会由最上面的find_package(protobuf CONFIG REQUIRED)这个命令会查找系统上
#安装的 Protocol Buffers 库，并设置相关的变量，包括 ${PROTOBUF_INCLUDE_DIRS}。

#在 CMake 构建过程中，${CMAKE_CURRENT_BINARY_DIR} 通常用于指定生成的目标文件
#（可执行文件、库文件）、中间文件和自动生成的头文件的存放目录。
#例如，在使用 Protocol Buffers 生成 .pb.cc 和 .pb.h 文件时，
#通常将 ${CMAKE_CURRENT_BINARY_DIR} 用作这些文件的输出目录。



#
# Compile protobuf and grpc files in mointor proto target to cpp
#
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET monitor_proto LANGUAGE cpp)
# 上面代码相当于执行: protobuf --proto_path = IMPORT_PATH --cpp_out = DST_DIR .pb.h  .pb.cpp
protobuf_generate(TARGET monitor_proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
# 用于生成 .grpc.pb.h 和 .grpc.pb.c 文件