cmake_minimum_required(VERSION 3.10)
project(university-meal-system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Core library
add_library(meal_lib
    src/student.cpp
    src/reservation.cpp
    src/meal.cpp
    src/dining_hall.cpp
)
target_include_directories(meal_lib PUBLIC include)

# Application executable
add_executable(meal_app app/main.cpp)
target_link_libraries(meal_app PRIVATE meal_lib)

# Add bcrypt.c to the core library
target_sources(meal_lib PRIVATE libs/bcrypt/bcrypt.c)

# Include headers
target_include_directories(meal_lib PUBLIC
    include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/bcrypt
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/catch2
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/json
)

# Enable tests if tests/ exists
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    enable_testing()
    add_executable(meal_tests
        tests/test_student.cpp
        tests/test_meal.cpp
        tests/test_reservation.cpp
        tests/test_dining_hall.cpp
    )
    target_link_libraries(meal_tests PRIVATE meal_lib)

    # Include headers for tests + third-party
    target_include_directories(meal_tests PRIVATE
        include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/bcrypt
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/catch2
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/json
    )

    add_test(NAME all_tests COMMAND meal_tests)
endif()
