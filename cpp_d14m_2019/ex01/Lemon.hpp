/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Lemon.hpp
*/
#pragma once
#include "Fruit.hpp"

class Lemon : public Fruit {
    public:
        Lemon();
        Lemon(std::string name, int vitamins);
        ~Lemon(){}
};