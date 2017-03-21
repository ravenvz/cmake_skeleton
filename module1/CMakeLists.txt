cmake_minimum_required(VERSION 3.6)

set(MODULE module1)

project(${MODULE})

set(SOURCE_FILES src/Dummy.cpp)
set(HEADER_FILES_FOR_CLION include/module1/Dummy.h)

add_library(${MODULE} ${SOURCE_FILES} ${HEADER_FILES_FOR_CLION})

target_include_directories(${MODULE} PUBLIC include)
target_compile_features(${MODULE} PUBLIC cxx_return_type_deduction)
