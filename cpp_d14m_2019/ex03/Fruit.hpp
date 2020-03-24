/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Fruit.hpp
*/
#pragma once

#include <iostream>

class Fruit{
    public:
        Fruit(std::string name, int vit);
        virtual ~Fruit() {}
        Fruit &operator=(const Fruit &f);

        std::string getName() const {return this->name;}
        int getVitamins() const {return this->_vitamins;}
    protected:
        std::string name;
        int _vitamins;
};