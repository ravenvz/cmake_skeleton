add_subdirectory(main)
add_subdirectory(module1)

if(CMAKE_PROJECT_NAME STREQUAL ${PROJECT_NAME} AND ENABLE_TESTING)
    set(TEST_RUN_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
	include(GoogleTest)
    add_subdirectory(tests)
endif()
