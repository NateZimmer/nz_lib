
cmake_minimum_required(VERSION 3.10)

set(my_source 
    ./src/pcap_util/pcap_util.c
    ./src/ring_buf/ring_buf.c
    ./test/pcap_test.c
    ./test/ring_test.c
    ./test/test_master.c
)

set(my_include 
    ./module/acutest/include
)

include_directories(${my_include})

project(nz_lib_unit_test VERSION 1.0)

add_executable(nz_lib_unit_test ${my_source})