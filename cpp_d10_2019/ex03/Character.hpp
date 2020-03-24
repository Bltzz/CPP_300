/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Character.hpp
*/

#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter{
    public:
        Character(std::string const &tmp);
        Character(Character const &character);
        ~Character();

        virtual std::string const & getName() const {return this->name;}
        virtual void equip(AMateria *am);
        virtual void unequip(int i);
        virtual void use(int i, ICharacter &character);
    protected:
        AMateria *inventory[4];
        std::string const name;
};