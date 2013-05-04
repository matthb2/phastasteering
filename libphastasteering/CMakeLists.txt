add_library(libphastasteering phastasteering.c)
target_link_libraries(libphastasteering libzmq ${CMAKE_THREAD_LIBS_INIT} ${MPI_C_LIBRARIES})

if(NOT APPLE)
	target_link_libraries(libphastasteering rt)
endif(NOT APPLE)
