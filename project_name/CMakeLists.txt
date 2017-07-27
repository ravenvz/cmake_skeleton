set(PROJECT project_binary_name)

project(${PROJECT})

set(SOURCE_FILES main/main.cpp)

add_executable(${PROJECT} ${SOURCE_FILES})

include(compiler_options.cmake)

target_compile_features(${PROJECT} PUBLIC cxx_std_17)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    target_compile_options(${PROJECT} PUBLIC ${CLANG_COMPILE_OPTIONS})
elseif(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT} PUBLIC ${GCC_COMPILE_OPTIONS})
else()
  message(FATAL_ERROR "Unknown compiler.")
endif()

add_subdirectory(module1)

if (CMAKE_BUILD_TESTS)
    add_subdirectory(tests)
endif()
