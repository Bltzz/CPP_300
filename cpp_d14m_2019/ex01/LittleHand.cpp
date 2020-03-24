/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** LittleHand.cpp
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes){
    FruitBox new_unsorted(unsorted.nbFruits());
    Fruit *fruit;

    while ((fruit = unsorted.pickFruit())){
        if (fruit->getName().compare("lemon")){
            if (lemons.putFruit(fruit))
                new_unsorted.putFruit(fruit);
        }
        else if (fruit->getName().compare("banana")){
            if (bananas.putFruit(fruit))
                new_unsorted.putFruit(fruit);
        }
        else if (fruit->getName().compare("lime")){
            if (limes.putFruit(fruit))
                new_unsorted.putFruit(fruit);
        }
        else new_unsorted.putFruit(fruit);
    }
    while ((fruit = new_unsorted.pickFruit()))
        unsorted.putFruit(fruit);
}
