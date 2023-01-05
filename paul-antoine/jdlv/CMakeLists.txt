cmake_minimum_required(VERSION 3.24)
project(jdlv C)

set(CMAKE_C_STANDARD 23)

add_executable(jdlv src/main.c src/error.c include/error.h src/screen_handling.c src/util.c include/util.h)
target_link_libraries(jdlv SDL2)