include(FetchContent)

# CMake policy for URL extract timestamps (avoids noisy dev warning on newer CMake)
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

# Keep GTest local to the build.
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# For MSVC: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(FactorInteger_tests
  test_factorization.cpp
)

target_link_libraries(FactorInteger_tests
  PRIVATE
    FactorInteger::FactorInteger
    GTest::gtest_main
)

target_compile_features(FactorInteger_tests PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(FactorInteger_tests)
