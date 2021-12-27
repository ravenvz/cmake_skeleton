
# Download and unpack googletest at configure time
include(CMakeLists-gtest.txt)

target_include_directories(gmock_main SYSTEM BEFORE INTERFACE
    "$<BUILD_INTERFACE:${gtest_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${gmock_SOURCE_DIR}/include>")

add_subdirectory(module1_tests)
