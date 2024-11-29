cmake_minimum_required(VERSION 3.15)
project(Wizz_mania_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wizz_mania_server main.cpp Server.cpp testThread.cpp)

if(WIN32)
    target_link_libraries(Wizz_mania_server ws2_32)
endif()


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Wizz_mania_server Threads::Threads)

