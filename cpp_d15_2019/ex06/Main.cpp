/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/

#include "ex06.hpp"
#include <iostream>

int main(){
    // Tuple<int, std::string> t;
    // t.a = 42;
    // t.b = std::string ("Boeuf aux oignons");

   // std::cout << t.a << "\n" << t.b <<std::endl;

    Tuple <int> u;
    u.a = 42;
    u.b = 21;

    std::cout << u.a << "\n" << u.b <<std::endl;

    Tuple <int, std::string> t;
    t.a = 42;
    t.b = std::string ("Karadoc toasted sandwich") ;
    std::cout << t.toString() << std::endl;

    return 0;
}