/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ex06.hpp
*/

#pragma once
#include <iostream>
#include <sstream>

template<typename T>
std::string print(T){
    return ("[???]");
}

template<>
std::string print(int a){
    std::stringstream oss;
    oss << a;
    return std::string("[int:") + oss.str() + std::string("]");;
}

template<>
std::string print(float f){
    std::stringstream oss;
    oss << f;
    return std::string("[float:") + oss.str() + std::string("f]");
}
template<>
std::string print(std::string s){
    return "[string:\"" + s + "\"]";
}

template<typename T, typename U = T>
class Tuple {
    public:
        T a;
        U b;
        std::string toString(){
            return std::string("[TUPLE ") + print(a) + std::string(" ") + print(b) + std::string("]");
        }
};
