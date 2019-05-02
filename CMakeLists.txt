cmake_minimum_required(VERSION 3.14)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_executable(printf srcs/main.c srcs/validation.c srcs/parse_arguments.c)