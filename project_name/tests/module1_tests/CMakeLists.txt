set(MODULE_TEST module1_test)

add_executable(${MODULE_TEST})
target_sources(${MODULE_TEST}
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/test1.cpp"
)

# This a workaround to prevent linking errors on Windows.
if (WIN32)
    target_compile_definitions( ${MODULE_TEST} PRIVATE -DGTEST_LINKED_AS_SHARED_LIBRARY )
endif()

target_link_libraries(
    ${MODULE_TEST}
    PRIVATE
        project_options
        project_warnings
        module1
        gmock_main
)

gtest_discover_tests(${MODULE_TEST})

