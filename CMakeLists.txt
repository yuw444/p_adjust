cmake_minimum_required(VERSION 3.16.0)

project(p_adjust VERSION 1.0)

set(CMAKE_C_STANDARD 99)
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(SOURCES
    ./src/pvalue.c
    ./src/utils.c
    ./test/test_vary_argument.c
)

add_executable(p_adjust ${SOURCES})

