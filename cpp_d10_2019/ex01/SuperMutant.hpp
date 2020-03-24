/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** SuperMutant.hpp
*/
#pragma once
#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
    public:
        SuperMutant();
        ~SuperMutant();
        void takeDamage(int damage) final;
};