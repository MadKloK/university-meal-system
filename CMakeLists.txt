cmake_minimum_required(VERSION 3.10)
project(university-meal-system LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Core library
add_library(meal_lib
    src/data/system_log.cpp
    src/models/user.cpp
    src/models/student.cpp
    src/models/reservation.cpp
    src/models/meal.cpp
    src/models/transaction.cpp         
    src/models/dining_hall.cpp
    src/models/shopping_cart.cpp       
    src/panels/admin_panel.cpp
    src/panels/student_panel.cpp
    src/data/user_file_manager.cpp
    src/data/config_path.cpp
    src/models/admin.cpp
    src/core/admin_session.cpp
    src/core/student_session.cpp
    src/data/session_file_manager.cpp 
    src/panels/admin_panel.cpp       
    src/data/storage.cpp            
    src/data/storage_file_manager.cpp  
    libs/crypt_blowfish/crypt_blowfish.c
    libs/crypt_blowfish/crypt_gensalt.c
    libs/crypt_blowfish/wrapper.c
)

target_include_directories(meal_lib PUBLIC
    include
    libs/crypt_blowfish      # for ow-crypt.h
    libs/catch2
    libs/json
)

# Application executable
add_executable(meal_app app/main.cpp)
target_link_libraries(meal_app PRIVATE meal_lib)

# Enable tests if tests/ exists
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    enable_testing()

    add_executable(meal_tests
        tests/test_hpass.cpp
        tests/test_student.cpp
        tests/test_meal.cpp
        tests/test_reservation.cpp
        tests/test_dining_hall.cpp
    )
    target_link_libraries(meal_tests PRIVATE meal_lib)

    target_include_directories(meal_tests PRIVATE
        include/
        libs/catch2
        libs/json
        libs/crypt_blowfish
    )

    add_test(NAME all_tests COMMAND meal_tests)
endif()
