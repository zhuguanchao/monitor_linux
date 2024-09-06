#
# Dependencies
#
# find_package(Threads)

#
# Sources


set(SOURCES
    main.cpp
    rpc_manager.cpp
)


add_executable(server ${SOURCES})

target_include_directories(server PUBLIC
    ${CMAKE_MODULE_PATH}/proto
    ${PROJECT_SOURCE_DIR}/rpc_manager/client
)

target_link_libraries(server
    PUBLIC
    monitor_proto
)

