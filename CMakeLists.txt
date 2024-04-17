cmake_minimum_required(VERSION 3.27)
project(CDataFrame C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CDataFrame
        main.c
        main.h
        column.h
        column.c)
