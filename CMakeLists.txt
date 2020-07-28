cmake_minimum_required(VERSION 3.13)

project(hello)

set (CMAKE_VERBOSE_MAKEFILE on)
set (THIRDPART_DIR "/home/sunwu/GameServer/ThirdPart")

set(CMAKE_CXX_COMPILER "${THIRDPART_DIR}/gcc-8.3.0/bin/c++8.3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -g -g3 -Wall -Werror")

include_directories("${THIRDPART_DIR}/gcc-8.3.0/include/c++/8.3.0/")
include_directories("${THIRDPART_DIR}/lua/include/")

link_directories(
	${THIRDPART_DIR}/gcc-8.3.0/lib/gcc/x86_64-redhat-linux/8.3.0
	${THIRDPART_DIR}/gcc-8.3.0/lib64
	${THIRDPART_DIR}/lua/lib
	)

#find_package(lua)
target_link_libraries(TARGET lua)

add_executable(hello hello.cpp)

