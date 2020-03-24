/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** MateriaSource.hpp
*/

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    public:
        MateriaSource();
        ~MateriaSource(){}
        virtual void learnMateria(AMateria *materia);
        virtual AMateria *createMateria(const std::string &type);
    protected:
        AMateria *inventory[4];
};