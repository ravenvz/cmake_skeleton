cmake_minimum_required(VERSION 3.10)

set(PROJECT project_name)

project(${PROJECT})

set("${PROJECT}_BINARY_DIR" bin)
set("${PROJECT}_SOURCE_DIR" src)
set("${PROJECT}_LIB_DIR" lib)
set("${PROJECT}_ARCHIVE_DIR" lib/static)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_BINARY_DIR})
if (WIN32)
    set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_BINARY_DIR})
else()
    set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_LIB_DIR})
endif()
set (ARCHIVE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_ARCHIVE_DIR})

set (EXECUTABLE_INSTALL_PATH_SUFFIX bin)
set (LIBRARY_INSTALL_PATH_SUFFIX lib)

set (CMAKE_VERBOSE_MAKEFILE OFF)

if (!WIN32)
    find_package(ECM REQUIRED NO_MODULE)
    set(CMAKE_MODULE_PATH ${ECM_MODULE_DIR})
    include(ECMEnableSanitizers)
endif()

add_subdirectory(project_name)
