/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/
#include <iostream>
#include "Banana.hpp"
#include "Coconut.hpp"
#include "LittleHand.hpp"
#include "Lemon.hpp"
#include "FruitBox.hpp"

int main(){
    Lemon l;
    Coconut c;

    std::cout << l.getVitamins() << std::endl;
    LittleHand::injectVitamin(l, 42);
    std::cout << l.getVitamins() << std::endl;

    std::cout << c.getVitamins() << std::endl;
    LittleHand::injectVitamin(c, 2);
    std::cout << c.getVitamins() << std::endl;
    return 0;
}