/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** MixerBase.hpp
*/
#pragma once
#include "FruitBox.hpp"

class MixerBase{
    public:
        MixerBase();
        int mix(FruitBox &fruits) const;
    protected:
        bool _plugged;
        int (* _mixfunc)(FruitBox &fruits);
};