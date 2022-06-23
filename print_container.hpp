#pragma once

#include <iostream>

namespace print_container_helper {
    template<template<class> class container, class T> void multi_out_impl(std::ostream& os, container<T> v);
    template<class K, class V> void multi_out_impl(std::ostream& os, std::pair<K, V> p);
    template<class T> void multi_out_impl(std::ostream& os, T v);
    void multi_out_impl(std::ostream& os, std::string s){
        os << s;
    }
        
    template<template<class...> class container, class T, class... Args> void multi_out_impl(std::ostream& os, container<T, Args...> v){
        os << "{ ";
        for(auto i = v.begin(); i != v.end();){
            multi_out_impl(os, *i);
            os << (++i != v.end() ? ", " : "");
        }
        os << " }";
    }
        
    template<class K, class V> void multi_out_impl(std::ostream& os, std::pair<K, V> p){
        os << "( ";
        multi_out_impl(os, p.first);
        os << ", ";
        multi_out_impl(os, p.second);
        os << " )";
    }
        
    template<class T> void multi_out_impl(std::ostream& os, T v){
        os << v;
    }
}

#define out(x) (std::cout << # x << " = ", print_container_helper::multi_out_impl(std::cout, x), std::cout << std::endl )
