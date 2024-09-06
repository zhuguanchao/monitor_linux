#
# Dependencies

find_package(Qt5 
  REQUIRED COMPONENTS
  Core
  Widgets
)

set(SOURCES
    main.cpp
    monitor_inter.cpp
    cpu_softirq_model.cpp
    cpu_load_model.cpp
    monitor_widget.cpp
    cpu_stat_model.cpp
    mem_model.cpp
    net_model.cpp
)
include_directories(${CMAKE_MODULE_PATH}/../rpc_manager/client)
add_executable(display ${SOURCES})
set_target_properties(display PROPERTIES AUTOMOC TRUE)


target_include_directories(display PUBLIC
    ${CMAKE_MODULE_PATH}/rpc_manager/client
    ${CMAKE_MODULE_PATH}/proto
)

target_link_libraries(display
    PUBLIC
    client
    monitor_proto
    Qt5::Widgets
    Qt5::Core
    # qwt-qt5
)
