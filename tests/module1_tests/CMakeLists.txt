cmake_minimum_required(VERSION 3.6)

set(MODULE_TEST module1_test)

project(${MODULE_TEST})

set(SOURCE_FILES test1.cpp)

add_executable(${MODULE_TEST} ${SOURCE_FILES})

target_link_libraries(${MODULE_TEST} module1 gtest gtest_main gmock)