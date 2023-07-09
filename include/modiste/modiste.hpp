#pragma once

#include <concepts>
#include <string>
#include <type_traits>

#include <fmt/core.h>
#include <google/protobuf/message.h>

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

template<typename T>
concept IsModisteConforming = requires(T modiste_data) {
  IsProtobuf<T>;
  modiste_data.metadata();
  modiste_data.data();
  {
    modiste_data.metadata().version()
  } -> std::convertible_to<std::string>;
};

}  // namespace modiste
