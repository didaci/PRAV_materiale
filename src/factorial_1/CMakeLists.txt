cmake_minimum_required(VERSION 3.21)
project(factorial_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(factorial_1 main.c mymath.c mymath.h)
