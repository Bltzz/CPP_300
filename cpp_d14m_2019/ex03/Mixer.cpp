/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Mixer.cpp
*/

#include "Mixer.hpp"

// Mixer::Mixer() {
//      this->_plugged = false;
//      this->_mixfunc = nullptr;
// }

int Mixer::mix(FruitBox &fruits) const {
    if (this->isPlugged()){
    int count_vitamins = 0;
    // if (!&fruits)
    //     return 0;
    for (int i = 0; i < fruits.nbFruits(); i++){
        count_vitamins += fruits.pickFruit()->getVitamins();
    }
    return count_vitamins;
    } else return 0;
}

