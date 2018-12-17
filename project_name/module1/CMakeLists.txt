set(MODULE module1)

project(${MODULE})

add_library(${MODULE} SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_sources(${MODULE}
PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/include/module1/Dummy.h"
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/src/Dummy.cpp"
)

target_include_directories(${MODULE} PUBLIC include)
target_compile_features(${MODULE} PUBLIC cxx_std_17)
