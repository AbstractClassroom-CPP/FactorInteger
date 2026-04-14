cmake_minimum_required(VERSION 3.20)

project(FactorInteger VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(FACTORINTEGER_BUILD_TESTS "Build FactorInteger unit tests" ON)
option(FACTORINTEGER_BUILD_EXAMPLES "Build FactorInteger examples" ON)

add_library(FactorInteger)
add_library(FactorInteger::FactorInteger ALIAS FactorInteger)

target_compile_features(FactorInteger PUBLIC cxx_std_17)

target_include_directories(FactorInteger
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(FactorInteger
  PRIVATE
    src/Factorization.cpp
)

# Helpful warnings for consumers building from source
if (MSVC)
  target_compile_options(FactorInteger PRIVATE /W4)
else()
  target_compile_options(FactorInteger PRIVATE -Wall -Wextra -Wpedantic)
endif()

# --- Installation (so this project can be used via find_package) ---
install(
  TARGETS FactorInteger
  EXPORT FactorIntegerTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
  EXPORT FactorIntegerTargets
  FILE FactorIntegerTargets.cmake
  NAMESPACE FactorInteger::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/FactorInteger
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/FactorIntegerConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/FactorIntegerConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/FactorInteger
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/FactorIntegerConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/FactorIntegerConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/FactorIntegerConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/FactorInteger
)

# --- Tests ---
if (FACTORINTEGER_BUILD_TESTS)
  include(CTest)
  if (BUILD_TESTING)
    add_subdirectory(tests)
  endif()
endif()

# --- Examples ---
if (FACTORINTEGER_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

