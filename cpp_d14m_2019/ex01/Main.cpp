/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/
#include <iostream>
#include "Banana.hpp"
#include "Lemon.hpp"
#include "FruitBox.hpp"

int main(){
    Lemon l;
    Banana b;
    FruitBox fb(3);
    std::cout << l.getVitamins() << std::endl;
    // std::cout << b->getVitamins() << std::endl;
    // std::cout << l->getName() << std::endl;
    // std::cout << b->getName () << std::endl;
    fb.putFruit(&l);
    fb.putFruit(&b);

    std::cout << fb.pickFruit()->getName() <<std::endl;


    return  0;
}