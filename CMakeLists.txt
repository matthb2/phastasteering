project(phastasteering)
cmake_minimum_required(VERSION 2.8)
include_directories(${CMAKE_SOURCE_DIR}/external/cppzmq) 
include_directories(${CMAKE_SOURCE_DIR}/external/libzmq/include)

find_package(Threads REQUIRED)

add_subdirectory(external/libzmq)
set(ZMQ_BUILD_FRAMEWORK OFF)
add_subdirectory(gui)
add_subdirectory(libphastasteering)
add_subdirectory(test)
