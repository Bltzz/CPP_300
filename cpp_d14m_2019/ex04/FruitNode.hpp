/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** FruitNode.hpp
*/

#pragma once
#include "Fruit.hpp"

class FruitNode{
    public:
        Fruit *current;
        FruitNode *next;
};