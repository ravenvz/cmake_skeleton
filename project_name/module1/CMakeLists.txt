set(MODULE module1)

add_library(${MODULE} SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_sources(${MODULE}
PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/include/module1/Dummy.h"
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/src/Dummy.cpp"
)

target_link_libraries(
    ${MODULE}
    PRIVATE
        project_options
        project_warnings
)

target_include_directories(${MODULE} PUBLIC include)
