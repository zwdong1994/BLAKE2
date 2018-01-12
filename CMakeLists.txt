cmake_minimum_required(VERSION 3.5)
project(BLAKE)

SET(CMAKE_C_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)

ADD_DEFINITIONS(-g -W -lpthread -Wall -lrt -lcrypto -lstdc++ -D_GLIBCXX_USE_CXX11_ABI=0 -fpermissive -O3 -m64)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

include_directories( /usr/include sse/ testvectors/)
link_libraries("/usr/lib/x86_64-linux-gnu/librt.so")
link_libraries("/usr/lib/x86_64-linux-gnu/libcrypto.a")
link_directories(/lib/x86_64-linux-gnu)

message("${CMAKE_SOURCE_DIR}")

set(SOURCE_FILES  sse/blake2-config.h sse/blake2b.c sse/blake2bp.c sse/blake2s.c sse/blake2sp.c sse/blake2xb.c
        sse/blake2xs.c      sse/simple_blake2b.cpp)
add_executable(BLAKE ${SOURCE_FILES})