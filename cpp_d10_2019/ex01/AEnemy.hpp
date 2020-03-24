/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** AEnemy.hpp
*/
#pragma once
#include <iostream>

class AEnemy{
    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();
        virtual void takeDamage(int damage);
        std::string const getType() const;
        int getHP() const;
    protected:
        int hitPoints;
        std::string type;
};