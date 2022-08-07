
cmake_minimum_required(VERSION 3.10)

set(my_source 
    ./src/hello_action.c
)

project(hello_action VERSION 1.0)

add_executable(hello_action ${my_source})