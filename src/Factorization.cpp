#include "FactorInteger/Factorization.hpp"

#include <cmath>
#include <stdexcept>

namespace factorinteger {

static void require_gt_two(std::int64_t n) {
  if (n <= 2) {
    throw std::invalid_argument("Factorization requires n > 2");
  }
}

Factorization::Factorization(std::int64_t n) : n_(n) {
  require_gt_two(n_);

  std::int64_t remaining = n_;

  // Factor 2 separately.
  if ((remaining % 2) == 0) {
    std::uint32_t count = 0;
    while ((remaining % 2) == 0) {
      remaining /= 2;
      ++count;
    }
    factors_.push_back(PrimePower{2, count});
  }

  // Odd trial division up to sqrt(remaining).
  for (std::int64_t p = 3; p * p <= remaining; p += 2) {
    if ((remaining % p) != 0) continue;

    std::uint32_t count = 0;
    while ((remaining % p) == 0) {
      remaining /= p;
      ++count;
    }
    factors_.push_back(PrimePower{p, count});
  }

  // If there's anything left, it's prime.
  if (remaining > 1) {
    factors_.push_back(PrimePower{remaining, 1});
  }
}

}  // namespace factorinteger

