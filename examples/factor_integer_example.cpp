#include "FactorInteger/Factorization.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <integer > 2>\n";
    return 2;
  }

  const long long n = std::atoll(argv[1]);

  try {
    factorinteger::Factorization f(n);
    std::cout << n << " = ";

    const auto& factors = f.factors();
    for (size_t i = 0; i < factors.size(); ++i) {
      const auto& pp = factors[i];
      if (i != 0) std::cout << " * ";
      std::cout << pp.prime;
      if (pp.power != 1) std::cout << "^" << pp.power;
    }
    std::cout << "\n";
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}

