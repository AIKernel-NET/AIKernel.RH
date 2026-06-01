cmake_minimum_required(VERSION 3.20)

project(AIKernel_RH C)

add_library(AIKernel_RH SHARED
    aikernel_rh.c
    aikernel_rh.h)

target_compile_definitions(AIKernel_RH PRIVATE AIKERNEL_RH_BUILD)
target_compile_features(AIKernel_RH PRIVATE c_std_11)

if(NOT MSVC)
    target_compile_options(AIKernel_RH PRIVATE -fvisibility=hidden)
endif()
