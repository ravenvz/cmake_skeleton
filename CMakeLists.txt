cmake_minimum_required(VERSION 3.9)

set(PROJECT project_name)

project(${PROJECT})

set("${PROJECT}_BINARY_DIR" bin)
set("${PROJECT}_SOURCE_DIR" src)
set("${PROJECT}_LIB_DIR" lib)
set("${PROJECT}_ARCHIVE_DIR" lib/static)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_LIB_DIR})
set (ARCHIVE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_ARCHIVE_DIR})

set (EXECUTABLE_INSTALL_PATH_SUFFIX bin)
set (LIBRARY_INSTALL_PATH_SUFFIX lib)

set (CMAKE_VERBOSE_MAKEFILE OFF)

if (!WIN32)
    find_package(ECM REQUIRED NO_MODULE)
    set(CMAKE_MODULE_PATH ${ECM_MODULE_DIR})
    include(ECMEnableSanitizers)
endif()

include(compiler_options.cmake)

set(SOURCE_FILES src/main.cpp)

add_executable(${PROJECT} ${SOURCE_FILES})

target_compile_features(${PROJECT} PUBLIC cxx_std_17)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    target_compile_options(${PROJECT} PUBLIC ${CLANG_COMPILE_OPTIONS})
elseif(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT} PUBLIC ${GCC_COMPILE_OPTIONS})
else()
  message(FATAL_ERROR "Unknown compiler.")
endif()

target_link_libraries(${PROJECT} module1)

add_subdirectory(module1)
add_subdirectory(tests)
