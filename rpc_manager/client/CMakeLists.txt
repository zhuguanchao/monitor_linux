
set(SOURCES
    # main.cpp
    rpc_client.cpp
)

add_library(client  ${SOURCES})

target_include_directories(client PUBLIC
${CMAKE_MODULE_PATH}/proto
)

target_link_libraries(client
    PUBLIC
    monitor_proto
)


# INSTALL(TARGETS client
#        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )
