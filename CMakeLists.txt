cmake_minimum_required(VERSION 3.5.0)
project(unsafe_mem VERSION 0.1.0 LANGUAGES C CXX)

add_executable(unsafe_mem
        main.cpp
        src/base.cpp
        src/A.cpp
        src/B.cpp
        inc/A.h
        inc/B.h
        inc/base.h
        inc/max_type_size_impl.h
        inc/unsafe_mem_impl.h
)

target_compile_options(unsafe_mem PRIVATE
        -std=c++11
)