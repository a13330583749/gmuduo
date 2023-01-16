SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/examples/bin)
add_executable(netty_discard_client client.cc)
target_link_libraries(netty_discard_client muduo_net muduo_base)

add_executable(netty_discard_server server.cc)
target_link_libraries(netty_discard_server muduo_net muduo_base)

