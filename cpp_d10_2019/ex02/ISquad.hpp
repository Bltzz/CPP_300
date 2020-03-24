/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ISquad.hpp
*/

#pragma once

#include "ISpaceMarine.hpp"

class ISquad {
    public:
        virtual ~ISquad() {}
        virtual int getCount() const = 0;
        virtual ISpaceMarine *getUnit(int) = 0;
        virtual int push(ISpaceMarine*) = 0;
    };