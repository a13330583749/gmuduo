SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/EventLoop)
add_executable(EventLoop_unittest EventLoop_unittest.cc)
target_link_libraries(EventLoop_unittest libmuduo_net.a libmuduo_base.a)

add_executable(gEventLoop_unittest gEventLoop_unittest.cc)
target_link_libraries(gEventLoop_unittest libmuduo_net.a libmuduo_base.a)
