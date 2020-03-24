/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** MateriaSource.cpp
*/

#include "MateriaSource.hpp"


MateriaSource::MateriaSource(){
      for(int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

void MateriaSource::learnMateria(AMateria *materia){
    if (!materia)
        return;
    for (int i = 0; i < 4; i++)
        if (!this->inventory[i]) {
            this->inventory[i] = materia;
            return;
        }
}

AMateria *MateriaSource::createMateria(const std::string &type){
    for (int i = 0; i < 4; i++)
        if (this->inventory[i] && this->inventory[i]->getType() == type)
            return this->inventory[i]->clone();
    return NULL;
}
