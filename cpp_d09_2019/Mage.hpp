/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex03
*/

#pragma once

#include "Character.hpp"

class Mage : virtual public Character {
    public:
        explicit Mage(const std::string &name, int level);
        int CloseAttack();
        virtual int RangeAttack();
        void RestorePower();

        //std::string getWeappon(){return this->weapon_name;}
    protected:
        //std::string

};