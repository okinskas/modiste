#include "modiste/queue.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <proto/default.pb.h>

#include "modiste/modiste.hpp"

TEST(QueueTest, canUseWithDefaults)
{
  modiste::queue<example::Default> queue;

  ASSERT_TRUE(true);
}
