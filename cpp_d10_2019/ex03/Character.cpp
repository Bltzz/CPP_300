/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Character.cpp
*/

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &tmp) : name(tmp){
    for(int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(Character const &character) : name(character.getName()) {
    for(int i = 0; i < 4; i++){
        delete (this->inventory[i]);
        this->inventory[i] = NULL;
        this->inventory[i] = character.inventory[i];
    }

}

Character::~Character(){
    for(int i = 0; i < 4; i++)
        delete (this->inventory[i]);
    delete[] inventory;


}


void Character::equip(AMateria *am){
    if (!am)
        return;
    for(int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = am;
            return;
        }
    }
}

void Character::unequip(int i){
    if (i < 4 && i >= 0)
        this->inventory[i] = NULL;
}

void Character::use(int i, ICharacter &character){
    if (i < 4 && i >= 0 && this->inventory[i] != NULL)
        this->inventory[i]->use(character);
}
