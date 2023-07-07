#include "modiste/modiste.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(DefaultTest, nameIsCorrect)
{
  ASSERT_EQ(name(), "modiste");
}
