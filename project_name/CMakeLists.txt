set(PROJECT project_binary_name)

project(${PROJECT})

include(compiler_options.cmake)

add_executable(${PROJECT})
target_sources(${PROJECT}
    PRIVATE
    "${cmake_current_source_dir}/main/main.cpp")

target_compile_features(${PROJECT} PUBLIC cxx_std_17)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    target_compile_options(${PROJECT} PUBLIC ${CLANG_COMPILE_OPTIONS})
elseif(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT} PUBLIC ${GCC_COMPILE_OPTIONS})
elseif(MSVC)
	message("MSVC compiler support might have issues, please check and report.")
else()
  message(FATAL_ERROR "Unknown compiler.")
endif()

add_subdirectory(module1)

if (BUILD_TESTS)
    set(TEST_RUN_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    enable_testing()
	include(GoogleTest)
	add_subdirectory(tests)
endif()
