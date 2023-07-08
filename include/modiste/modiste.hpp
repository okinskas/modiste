#pragma once

#include <string>
#include <type_traits>

#include <fmt/core.h>
#include <google/protobuf/message.h>

/**
 * @brief Return the name of this header-only library
 */
inline auto name() -> std::string
{
  return fmt::format("{}", "modiste");
}

namespace modiste
{

template<typename T>
concept IsProtobuf = std::is_base_of_v<google::protobuf::Message, T>;

}  // namespace modiste
