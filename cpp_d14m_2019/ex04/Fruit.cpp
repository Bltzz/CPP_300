/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string name, int vit){
    this->name = name;
    this->_vitamins = vit;
}



Fruit &Fruit::operator=(const Fruit &f){
    this->name = f.getName();
    this->_vitamins = f._vitamins;
    return *this;
}