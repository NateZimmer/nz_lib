
cmake_minimum_required(VERSION 3.10)

set(my_source 
    ./src/add.c
    ./test/add_test.c
)

set(my_include 
    ./module/acutest/include
)

include_directories(${my_include})

project(hello_action VERSION 1.0)

add_executable(hello_action ${my_source})