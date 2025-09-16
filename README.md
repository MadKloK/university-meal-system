# University Meal Reservation System

[![CMake](https://img.shields.io/badge/CMake-3.10+-blue.svg)](https://cmake.org)
[![C++17](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)

a Cpp meal system that just works as well as the nothing it does

## Features

- Student account management
- Meal reservation/cancellation
- Dining hall capacity tracking
- Balance and meal credit system

## Prerequisites

- CMake 3.10+
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 19.15+)

## Building

```bash
# Configure project
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release

# Compile
make -j4  # Uses 4 cores for faster compilation

# Run program
./university-meal-system

## License  
[MIT](LICENSE) - Copyright © 1939 Mohammad Zeynali & Mehdi Esmailzade
```

## Atttention!

- note that the provided data is only for testing purposes.
- edit the ".gitignore" file to prevent any data leak!
