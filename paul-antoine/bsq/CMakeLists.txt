cmake_minimum_required(VERSION 3.24)
project(bsq C)

set(CMAKE_C_STANDARD 23)

add_executable(bsq main.c bsq.c bsq.h)
