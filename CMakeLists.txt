cmake_minimum_required(VERSION 3.10)
project(university-meal-system LANGUAGES CXX)

# Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Core library (all class implementations)
add_library(meal_lib
    src/student.cpp
    src/reservation.cpp
    src/meal.cpp
    src/dining_hall.cpp
)
target_include_directories(meal_lib PUBLIC include)

# Main executable (only contains main.cpp)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE meal_lib)

# Testing (optional)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests AND NOT CMAKE_CONFIGURATION_TYPES)
    enable_testing()
    
    # Create test executable
    add_executable(meal_tests
        tests/test_student.cpp
        tests/test_meal.cpp
        tests/test_reservation.cpp
        tests/test_dining_hall.cpp
    )
    target_link_libraries(meal_tests PRIVATE meal_lib)
    
    # Register tests
    add_test(NAME student_tests COMMAND meal_tests [student])
    add_test(NAME meal_tests COMMAND meal_tests [meal])
    add_test(NAME all_tests COMMAND meal_tests)
endif()