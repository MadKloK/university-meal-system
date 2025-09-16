cmake_minimum_required(VERSION 3.10)
project(university-meal-system LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Collect all library sources
file(GLOB_RECURSE LIB_CPP_SOURCES
    src/core/*.cpp
    src/data/*.cpp
    src/models/*.cpp
    src/panels/*.cpp
)

file(GLOB LIB_C_SOURCES
    libs/crypt_blowfish/*.c
)

add_library(meal_lib
    ${LIB_CPP_SOURCES}
    ${LIB_C_SOURCES}
)

target_include_directories(meal_lib PUBLIC
    include
    libs/crypt_blowfish      # For ow-crypt.h
    libs/catch2
    libs/json
)

# Application executable
add_executable(meal_app app/main.cpp)
target_link_libraries(meal_app PRIVATE meal_lib)

# Tests
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    enable_testing()
    file(GLOB TEST_SOURCES tests/*.cpp)

    add_executable(meal_tests ${TEST_SOURCES})
    target_link_libraries(meal_tests PRIVATE meal_lib)

    target_include_directories(meal_tests PRIVATE
        include
        libs/catch2
        libs/json
        libs/crypt_blowfish
    )

    add_test(NAME all_tests COMMAND meal_tests)
endif()
