/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** FruitBox.hpp
*/

#pragma once
#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int len);
        ~FruitBox();
        int nbFruits();
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();

    protected:
        int size;
        int numFruit;
        FruitNode *listOfFruit;

};