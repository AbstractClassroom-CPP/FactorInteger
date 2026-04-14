#include "FactorInteger/Factorization.hpp"

#include <gtest/gtest.h>

using factorinteger::Factorization;
using factorinteger::PrimePower;

TEST(Factorization, ThrowsIfTooSmall) {
  EXPECT_THROW(Factorization(2), std::invalid_argument);
  EXPECT_THROW(Factorization(1), std::invalid_argument);
  EXPECT_THROW(Factorization(0), std::invalid_argument);
  EXPECT_THROW(Factorization(-10), std::invalid_argument);
}

TEST(Factorization, PrimeNumber) {
  Factorization f(13);
  ASSERT_EQ(f.factors().size(), 1u);
  EXPECT_EQ(f.factors()[0].prime, 13);
  EXPECT_EQ(f.factors()[0].power, 1u);
}

TEST(Factorization, CompositeNumber) {
  Factorization f(72);
  ASSERT_EQ(f.factors().size(), 2u);
  EXPECT_EQ(f.factors()[0].prime, 2);
  EXPECT_EQ(f.factors()[0].power, 3u);
  EXPECT_EQ(f.factors()[1].prime, 3);
  EXPECT_EQ(f.factors()[1].power, 2u);
}

TEST(Factorization, PowerOfTwo) {
  Factorization f(1024);
  ASSERT_EQ(f.factors().size(), 1u);
  EXPECT_EQ(f.factors()[0].prime, 2);
  EXPECT_EQ(f.factors()[0].power, 10u);
}

TEST(Factorization, Semiprime) {
  Factorization f(77); // 7 * 11
  ASSERT_EQ(f.factors().size(), 2u);
  EXPECT_EQ(f.factors()[0].prime, 7);
  EXPECT_EQ(f.factors()[0].power, 1u);
  EXPECT_EQ(f.factors()[1].prime, 11);
  EXPECT_EQ(f.factors()[1].power, 1u);
}

