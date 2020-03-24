/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** RadScorpion.hpp
*/
#pragma once
#include "AEnemy.hpp"

class RadScorpion : public AEnemy {
    public:
        RadScorpion();
        ~RadScorpion();
        void takeDamage(int damage) override;
};