#include "modiste/modiste.hpp"

// #include <catch2/catch_test_macros.hpp>
#include <gtest/gtest.h>

TEST(DefaultTest, nameIsCorrect)
{
  ASSERT_EQ(name(), "modiste");
}
