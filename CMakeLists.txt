cmake_minimum_required(VERSION 2.8.12)
project(le-shop)

find_package(Curses REQUIRED)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-std=c99 -pedantic -Wall)
endif()

aux_source_directory(. SRC_FILES)
add_executable(shop ${SRC_FILES})
target_link_libraries(shop ${CURSES_LIBRARIES})
