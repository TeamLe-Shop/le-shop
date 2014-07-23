cmake_minimum_required(VERSION 2.8.12)
project(le-shop)

find_package(Curses REQUIRED)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-std=c99 -pedantic -Wall)
endif()

add_executable(shop
item.c
item.h
main.c
screen.c
screen.h
shop.c
shop.h
util/stringutil.c
util/stringutil.h
util/vector.c
util/vector.h
)
target_link_libraries(shop ${CURSES_LIBRARIES})
