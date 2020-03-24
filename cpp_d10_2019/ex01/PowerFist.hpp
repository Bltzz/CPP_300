/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PowerFist.hpp
*/

#pragma once
#include "AWeapon.hpp"

class PowerFist : public AWeapon{
    public:
        PowerFist();
        ~PowerFist(){}
        void attack() const;
};