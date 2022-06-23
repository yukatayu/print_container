#pragma once

#include <iostream>

namespace print_container_helper {
    template<template<class> class container, class T> void multi_out_impl(container<T> v);
    template<class K, class V> void multi_out_impl(std::pair<K, V> p);
    template<class T> void multi_out_impl(T v);
    void multi_out_impl(std::string s){
        std::cout << s;
    }
        
    template<template<class...> class container, class T, class... Args> void multi_out_impl(container<T, Args...> v){
        std::cout << "{ ";
        for(auto i = v.begin(); i != v.end();){
            multi_out_impl(*i);
            std::cout << (++i != v.end() ? ", " : "");
        }
        std::cout << " }";
    }
        
    template<class K, class V> void multi_out_impl(std::pair<K, V> p){
        std::cout << "( ";
        multi_out_impl(p.first);
        std::cout << ", ";
        multi_out_impl(p.second);
        std::cout << " )";
    }
        
    template<class T> void multi_out_impl(T v){
        std::cout << v;
    }
}

#define out(x) (std::cout << # x << " = ", print_container_helper::multi_out_impl(x), std::cout << std::endl )
