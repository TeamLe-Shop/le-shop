cmake_minimum_required(VERSION 2.8.12)
project(le-shop)

find_package(Curses REQUIRED)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-std=c99 -pedantic -Wall)
    if(SANITIZE)
        add_compile_options(-fsanitize=${SANITIZE})
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${SANITIZE}")
    endif()
endif()

add_executable(shop
item.h
main.c
screen.c
screen.h
shop.c
shop.h
user.c
user.h
usd.h
usd.c
util/stringutil.c
util/stringutil.h
util/vector.c
util/vector.h
)
target_link_libraries(shop ${CURSES_LIBRARIES})
