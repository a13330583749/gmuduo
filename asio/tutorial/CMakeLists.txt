SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/asio/bin)
add_executable(asio_tutorial_timer2 timer2/timer.cc)
target_link_libraries(asio_tutorial_timer2 libmuduo_net.a libmuduo_base.a)

add_executable(asio_tutorial_timer3 timer3/timer.cc)
target_link_libraries(asio_tutorial_timer3 libmuduo_net.a libmuduo_base.a)

add_executable(asio_tutorial_timer4 timer4/timer.cc)
target_link_libraries(asio_tutorial_timer4 libmuduo_net.a libmuduo_base.a)

add_executable(asio_tutorial_timer5 timer5/timer.cc)
target_link_libraries(asio_tutorial_timer5 libmuduo_net.a libmuduo_base.a)

add_executable(asio_tutorial_timer6 timer6/timer.cc)
target_link_libraries(asio_tutorial_timer6 libmuduo_net.a libmuduo_base.a)

