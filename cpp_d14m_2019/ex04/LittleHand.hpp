/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** LittleHand.hpp
*/

#pragma once
#include "FruitBox.hpp"
#include "Coconut.hpp"
#include "Mixer.hpp"
#include "Lime.hpp"
#include "Banana.hpp"

class LittleHand {
    public:
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
        static FruitBox *const *organizeCoconut(Coconut const * const *coconuts);
        static void plugMixer(MixerBase &mixer);
        static void injectVitamin(Fruit &f, int quantity);
};