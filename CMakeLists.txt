cmake_minimum_required(VERSION 3.6)

set(PROJECT project_name)

project(${PROJECT})

set(SOURCE_FILES src/main.cpp)

add_executable(${PROJECT} ${SOURCE_FILES})

add_subdirectory(tests)
add_subdirectory(src/module1)