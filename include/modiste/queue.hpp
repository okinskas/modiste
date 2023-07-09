#pragma once

namespace modiste
{

template<typename T>
using default_wrapper = T;

template<typename T>
struct default_operations
{
  using wrapper = default_wrapper<T>;
};

template<typename T,
         template<typename> typename Operations = default_operations>
class queue
{
public:
  auto pop() -> typename Operations<T>::wrapper;
  auto push(T) -> void;
};

}  // namespace modiste
