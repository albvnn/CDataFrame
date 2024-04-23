cmake_minimum_required(VERSION 3.27)
project(CDataFrame C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CDataFrame
        main.c
        column.h
        column.c
        sort.h
        sort.c
        cdataframe.c
        cdataframe.h
        double-linked-list.c
        double-linked-list.h)
