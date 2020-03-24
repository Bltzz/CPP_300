/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** LittleHand.cpp
*/

#include "LittleHand.hpp"
#include <memory>

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

FruitBox *const *LittleHand::organizeCoconut(Coconut const * const *coconuts){
    FruitBox **arrOfFruitBoxes = nullptr;

    int i = 0;
    int j = 0;
    while (coconuts[j]){
        arrOfFruitBoxes[i] = new FruitBox(6);
        while (arrOfFruitBoxes[i]->nbFruits() <= 6){
            arrOfFruitBoxes[i]->putFruit(const_cast<Coconut*> (coconuts[j]));
            j++;
        }
        i++;
    }
    arrOfFruitBoxes[i+1] = nullptr;
    return arrOfFruitBoxes;
}

void LittleHand::plugMixer(MixerBase &mixer){
    Mixer &tmp = reinterpret_cast<Mixer &>(mixer);
    if (!tmp.isPlugged())
        tmp.setPlug(true);
}

void LittleHand::injectVitamin(Fruit &f, int quantity){
    struct InTheMatrixFruit{
        virtual ~InTheMatrixFruit() = default;
        std::string name;
        int vitamins = 0;
    };
    auto &tmp =  reinterpret_cast<InTheMatrixFruit &> (f);
    tmp.vitamins = quantity;
}


