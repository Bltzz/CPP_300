/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PlasmaRifle.hpp
*/

#pragma once
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon{
    public:
        PlasmaRifle();
        ~PlasmaRifle(){}
        void attack() const;
};