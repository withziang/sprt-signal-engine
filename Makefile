cmake_minimum_required(VERSION 3.16)
project(sse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sse_lib
    src/ingest.cpp
    src/log.cpp
    src/normalize.cpp
    src/signal_engine.cpp
    src/algos/xsp.cpp
)

target_include_directories(sse_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(sse_test
    test/main.cpp
)

target_link_libraries(sse_test
    PRIVATE sse_lib
)
