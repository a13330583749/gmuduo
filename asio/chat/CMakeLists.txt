SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/asio/bin)
add_executable(asio_chat_client client.cc)
target_link_libraries(asio_chat_client libmuduo_net.a libmuduo_base.a)

add_executable(asio_chat_loadtest loadtest.cc)
target_link_libraries(asio_chat_loadtest libmuduo_net.a libmuduo_base.a)

add_executable(asio_chat_server server.cc)
target_link_libraries(asio_chat_server libmuduo_net.a libmuduo_base.a)

add_executable(asio_chat_server_threaded server_threaded.cc)
target_link_libraries(asio_chat_server_threaded libmuduo_net.a libmuduo_base.a)

add_executable(asio_chat_server_threaded_efficient server_threaded_efficient.cc)
target_link_libraries(asio_chat_server_threaded_efficient libmuduo_net.a libmuduo_base.a)

add_executable(asio_chat_server_threaded_highperformance server_threaded_highperformance.cc)
target_link_libraries(asio_chat_server_threaded_highperformance libmuduo_net.a libmuduo_base.a)

