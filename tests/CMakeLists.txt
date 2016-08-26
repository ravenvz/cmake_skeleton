cmake_minimum_required(VERSION 3.6)

set(PROJECT_TESTS project_name_tests)
project(${PROJECT_TESTS})

find_package(Threads REQUIRED)

include(ExternalProject)
set(THIRD_PARTY_LIBS_FOLDER_PREFIX third_party)
include(CMakeLists-gtest.txt)

add_custom_target(${PROJECT_TESTS})
add_dependencies(${PROJECT_TESTS} gtest gtest_main gmock)

add_subdirectory(module1_tests)
