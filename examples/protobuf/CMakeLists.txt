SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/examples/bin)
add_subdirectory(codec)

# add_subdirectory(rpc)
# add_subdirectory(rpcbalancer)
# add_subdirectory(rpcbench)

# if(CARES_INCLUDE_DIR AND CARES_LIBRARY)
#   add_subdirectory(resolver)
# else()
#   add_subdirectory(resolver EXCLUDE_FROM_ALL)
# endif()
