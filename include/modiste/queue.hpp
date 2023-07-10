#pragma once

#include <concepts>
#include <utility>

#include <boost/outcome.hpp>
#include <boost/outcome/result.hpp>
#include <modiste/modiste.hpp>

namespace outcome = BOOST_OUTCOME_V2_NAMESPACE;

namespace modiste
{

template<typename Ops>
concept IsQueueOpsConforming = requires(Ops ops) {
  {
    ops.push()
  } -> std::derived_from<typename Ops::push_status>;
  {
    ops.pop()
  } -> std::derived_from<
      outcome::result<typename Ops::data, typename Ops::error>>;
};

struct default_status
{
  int m_code;
  std::string m_message;
};

template<typename T>
struct default_operations
{
  using pop_data = T;
  using push_status = default_status;
  using error_status = default_status;
};

template<typename T, template<typename> typename Ops = default_operations>
  requires IsModisteConforming<T> && IsQueueOpsConforming<Ops<T>>
class queue
{
public:
  explicit queue(Ops<T> ops);
  auto push(T data) -> Ops<T>::push_status;
  auto pop() -> outcome::result<typename Ops<T>::pop_data,
                                typename Ops<T>::error_status>;

private:
  Ops<T> m_ops;
};

template<typename T, template<typename> typename Ops>
  requires IsModisteConforming<T> && IsQueueOpsConforming<Ops<T>>
queue<T, Ops>::queue(Ops<T> ops)
    : m_ops(std::move(ops))
{
}

template<typename T, template<typename> typename Ops>
  requires IsModisteConforming<T> && IsQueueOpsConforming<Ops<T>>
auto queue<T, Ops>::push(T data) -> Ops<T>::push_status
{
  return m_ops.push(std::move(data));
}

template<typename T, template<typename> typename Ops>
  requires IsModisteConforming<T> && IsQueueOpsConforming<Ops<T>>
auto queue<T, Ops>::pop()
    -> outcome::result<typename Ops<T>::pop_data, typename Ops<T>::error_status>
{
  return m_ops.pop();
}

}  // namespace modiste
