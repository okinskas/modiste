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

template<typename T>
using metadata = std::decay_t<decltype(std::declval<T>().metadata())>;

template<typename T>
using version = std::decay_t<decltype(std::declval<metadata<T>>().version())>;

template<typename T>
using data = std::decay_t<decltype(std::declval<T>().data())>;

}  // namespace modiste
