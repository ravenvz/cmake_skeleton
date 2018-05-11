cmake_minimum_required(VERSION 3.6)

set(MODULE_TEST module1_test)

project(${MODULE_TEST})

set(SOURCE_FILES test1.cpp)

add_executable(${MODULE_TEST} ${SOURCE_FILES})

# This a workaround to prevent linking errors on Windows. Not sure if it will be required on linux machine.
target_compile_definitions( ${MODULE_TEST} PRIVATE -DGTEST_LINKED_AS_SHARED_LIBRARY )

# Choose any of those three
gtest_add_tests(TARGET ${MODULE_TEST} TEST_PREFIX old:)
# gtest_discover_tests(${MODULE_TEST} TEST_PREFIX new:)
# add_test(${MODULE_TEST} ${MODULE_TEST})

target_link_libraries(${MODULE_TEST} module1 gmock_main)
