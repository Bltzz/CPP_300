/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex02
*/

#pragma once

#include "Warrior.hpp"

class Hunter : virtual public Warrior {
    public:
        explicit Hunter(const std::string &name, int level, std::string weapon = "sword");
        int RangeAttack();
        void RestorePower();
};