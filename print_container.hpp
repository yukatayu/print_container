#pragma once

#include <iostream>
#include <type_traits>

namespace print_container_helper {
template <template <class> class container, class T>
void multi_out_impl(std::ostream &os, container<T> v);
template <class K, class V>
void multi_out_impl(std::ostream &os, std::pair<K, V> p);
template <class T>
void multi_out_impl(std::ostream &os, T v);
template <class... Args>
void multi_out_impl(std::ostream &os, std::tuple<Args...> t);

// vector, set, etc...
template <template <class...> class container, class T, class... Args>
void multi_out_impl(
    std::ostream &os, container<T, Args...> v,
    typename std::enable_if<
        !(std::is_same<std::tuple<T, Args...>, container<T, Args...>>::value) &&
            !(std::is_same<std::string, container<T, Args...>>::value),
        std::nullptr_t>::type = nullptr) {
  os << "{ ";
  for (auto i = v.begin(); i != v.end();) {
    multi_out_impl(os, *i);
    os << (++i != v.end() ? ", " : "");
  }
  os << " }";
}

// std::tuple
template <int i, class T>
void multi_out_impl_tuple(std::ostream &os, T t) {}
template <int i, class... Args>
void multi_out_impl_tuple(
    std::ostream &os, std::tuple<Args...> t,
    typename std::enable_if<(i < sizeof...(Args)), std::nullptr_t>::type =
        nullptr) {
  if (0 < i) os << ", ";
  multi_out_impl(os, std::get<i>(t));
  multi_out_impl_tuple<i + 1>(os, t);
}

template <class... Args>
void multi_out_impl(std::ostream &os, std::tuple<Args...> t) {
  // should use fold expression and std::make_index_sequence in C++17
  os << "( ";
  multi_out_impl_tuple<0>(os, t);
  os << " )";
}

// std::pair
template <class K, class V>
void multi_out_impl(std::ostream &os, std::pair<K, V> p) {
  os << "( ";
  multi_out_impl(os, p.first);
  os << ", ";
  multi_out_impl(os, p.second);
  os << " )";
}

// std::string
void multi_out_impl(std::ostream &os, std::string s) { os << s; }

// primitives
template <class T>
void multi_out_impl(std::ostream &os, T v) {
  os << v;
}
}  // namespace print_container_helper

#define out(x)                                           \
  (std::cout << #x << " = ",                             \
   print_container_helper::multi_out_impl(std::cout, x), \
   std::cout << std::endl)
