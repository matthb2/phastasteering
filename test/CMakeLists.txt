add_executable(test test.c)
target_link_libraries(test libphastasteering ${MPI_C_LIBRARIES})
