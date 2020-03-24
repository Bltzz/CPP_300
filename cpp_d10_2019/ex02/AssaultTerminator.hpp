/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** AssaultTerminator.hpp
*/

#pragma once
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine{
    public:
        AssaultTerminator();
        AssaultTerminator(AssaultTerminator const &as);
        ~AssaultTerminator();
        AssaultTerminator *clone() const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;
};