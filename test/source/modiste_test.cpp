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

TEST(DefaultTest, messageHasMetadataVersion)
{
  const auto is_version =
      std::is_base_of_v<std::string, modiste::version<example::Default>>;
  ASSERT_TRUE(is_version);
}

TEST(DefaultTest, messageHasData)
{
  const auto is_data =
      std::is_base_of_v<example::Data, modiste::data<example::Default>>;
  ASSERT_TRUE(is_data);
}

TEST(DefaultTest, isModisteConforming)
{
  ASSERT_TRUE(modiste::IsModisteConforming<example::Default>);
}
