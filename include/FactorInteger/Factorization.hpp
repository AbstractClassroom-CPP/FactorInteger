#pragma once

#include <cstdint>
#include <vector>

namespace factorinteger {

struct PrimePower {
  std::int64_t prime = 0;
  std::uint32_t power = 0;
};

/**
 * @brief Computes the prime factorization of an integer > 2.
 *
 * Returns ordered pairs (primeBase, power), with primeBase strictly increasing.
 * Example: 72 -> (2,3), (3,2)
 */
class Factorization {
 public:
  /// @throws std::invalid_argument if n <= 2
  explicit Factorization(std::int64_t n);

  [[nodiscard]] std::int64_t value() const noexcept { return n_; }

  /// Prime powers in ascending prime order.
  [[nodiscard]] const std::vector<PrimePower>& factors() const noexcept { return factors_; }

 private:
  std::int64_t n_;
  std::vector<PrimePower> factors_;
};

}  // namespace factorinteger

