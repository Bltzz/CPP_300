/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** TacticalMarine.hpp
*/

#pragma once
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine{
    public:
        TacticalMarine(TacticalMarine const &tm);
        TacticalMarine();
        ~TacticalMarine();
        TacticalMarine *clone() const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;
};