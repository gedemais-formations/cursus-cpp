cmake_minimum_required(VERSION 3.24)
project(bsq C)

set(CMAKE_C_STANDARD 23)

add_executable(bsq src/bsq.c src/bsq_solver.c include/bsq_solver.h src/bsq_parser.c src/bsq_error.c)

#target_link_libraries(${PROJECT_NAME} m)