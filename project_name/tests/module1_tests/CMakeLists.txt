set(MODULE_TEST module1_test)

project(${MODULE_TEST})

add_executable(${MODULE_TEST})
target_sources(${MODULE_TEST}
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/test1.cpp"
)

# This a workaround to prevent linking errors on Windows.
if (WIN32)
    target_compile_definitions( ${MODULE_TEST} PRIVATE -DGTEST_LINKED_AS_SHARED_LIBRARY )
endif()

target_compile_features(${MODULE_TEST} PRIVATE cxx_std_17)
target_compile_options(${MODULE_TEST} PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_COMPILE_OPTIONS}>")
target_compile_options(${MODULE_TEST} PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_COMPILE_OPTIONS}>")

target_link_libraries(${MODULE_TEST}
    PRIVATE module1
    PRIVATE gmock_main)

gtest_discover_tests(${MODULE_TEST})

