project(Pool_lib)

SET(SOURCES pool.cpp)
SET(HEADERS pool.hpp)

add_library(
        Pool
        ${SOURCES}
        ${HEADERS}
)

target_include_directories(Pool PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")