# FactorInteger

Factors Integers

## What this is
A small C++ library that computes the prime factorization of an integer greater than 2, returning ordered pairs `(primeBase, power)`.

- Example: `72 -> (2,3), (3,2)`

The main API is `factorinteger::Factorization` in `include/FactorInteger/Factorization.hpp`.

## Layout
- `include/` public headers
- `src/` library implementation
- `tests/` GoogleTest unit tests (fetched automatically)
- `examples/` small runnable example

## Build
```sh
cmake -S . -B build
cmake --build build
```

## Run tests
```sh
ctest --test-dir build --output-on-failure
```

## Run the example
```sh
./build/examples/factor_integer_example 72
```

## Install + use via `find_package`
```sh
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./install
cmake --build build
cmake --install build
```

Then, in another project:
```cmake
find_package(FactorInteger CONFIG REQUIRED)

target_link_libraries(your_target PRIVATE FactorInteger::FactorInteger)
```

## Use via CMake `FetchContent`
In another CMake project:
```cmake
include(FetchContent)
FetchContent_Declare(
  FactorInteger
  GIT_REPOSITORY https://github.com/AbstractClassroom-CPP/FactorInteger
  GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(FactorInteger)

target_link_libraries(your_target PRIVATE FactorInteger::FactorInteger)
```
