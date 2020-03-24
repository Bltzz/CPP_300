/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ISpaceMarine.hpp
*/

#pragma once

class ISpaceMarine {
    public:
        virtual ISpaceMarine *clone() const = 0;
        virtual ~ISpaceMarine() {}
        virtual void battleCry() const = 0;
        virtual void rangedAttack() const = 0;
        virtual void meleeAttack() const = 0;
};
