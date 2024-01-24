set(MODULE main)

add_executable(${MODULE})

target_sources(${MODULE}
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
)
