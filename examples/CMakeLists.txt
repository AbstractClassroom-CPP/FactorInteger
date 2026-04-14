add_executable(factor_integer_example
  factor_integer_example.cpp
)

target_link_libraries(factor_integer_example PRIVATE FactorInteger::FactorInteger)

target_compile_features(factor_integer_example PRIVATE cxx_std_17)

