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
        virtual ~Fruit() {}
        Fruit &operator=(const Fruit &f);

        std::string getName() const {return this->name;}
        int getVitamins() const {return this->_vitamins;}
    protected:
        Fruit(std::string name, int vit);
        std::string name;
        int _vitamins;
};