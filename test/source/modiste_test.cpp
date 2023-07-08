#include <type_traits>

#include "modiste/modiste.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <proto/default.pb.h>

TEST(DefaultTest, nameIsCorrect)
{
  ASSERT_EQ(name(), "modiste");
}

TEST(DefaultTest, typeIsProtobufMessage)
{
  ASSERT_TRUE(modiste::IsProtobuf<example::Default>);
}

TEST(DefaultTest, messageHasMetadata)
{
  const auto is_metadata =
      std::is_base_of_v<example::Metadata, modiste::metadata<example::Default>>;
  ASSERT_TRUE(is_metadata);
}
