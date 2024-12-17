#cmake_minimum_required(VERSION 3.15)
#project(Wizz_mania_server)
#
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(Wizz_mania_server main.cpp
#        Server.cpp
#        testThread.cpp)
#
#target_link_libraries(Wizz_mania_server ws2_32)
#
#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)
#target_link_libraries(Wizz_mania_server ws2_32 Threads::Threads)

cmake_minimum_required(VERSION 3.15)
project(Wizz_mania_server)

set(CMAKE_CXX_STANDARD 20)

# Ajouter le chemin vers vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

# Inclure OpenSSL
find_package(OpenSSL REQUIRED)

# Trouver et configurer les threads
find_package(Threads REQUIRED)

add_executable(Wizz_mania_server main.cpp
        Server.cpp
        testThread.cpp)

target_link_libraries(Wizz_mania_server ws2_32 Threads::Threads OpenSSL::SSL OpenSSL::Crypto)
