cmake_minimum_required(VERSION 3.24)
project(bsq C)

set(CMAKE_C_STANDARD 23)

add_executable(bsq bsq.c bsq_solver.c bsq_solver.h bsq_parser.c bsq_error.c)

#target_link_libraries(${PROJECT_NAME} m)