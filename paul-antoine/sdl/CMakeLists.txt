cmake_minimum_required(VERSION 3.24)
project(sdl)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/lib/cmake/SDL2)
set(SDL2_DIR ${CMAKE_SOURCE_DIR}/lib/cmake/SDL2)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.c)

add_executable(sdl ${SOURCE_FILES})
target_link_libraries(sdl ${SDL2_LIBRARY} ${CMAKE_SOURCE_DIR}/lib/libSDL2main.a SDL2)