/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex03
*/

#pragma once

#include "Mage.hpp"

class Priest : virtual public Mage {
    public:
        explicit Priest(const std::string &name, int level);
        int CloseAttack();
        void Heal();
};