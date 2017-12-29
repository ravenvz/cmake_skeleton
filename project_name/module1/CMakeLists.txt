set(MODULE module1)

project(${MODULE})

set(SOURCE_FILES src/Dummy.cpp)
set(HEADER_FILES include/module1/Dummy.h)

add_library(${MODULE} SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${MODULE} PUBLIC include)
target_compile_features(${MODULE} PUBLIC cxx_std_17)
