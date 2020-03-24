/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string name) : Toy(name)
{
    _type |= PONNY;
    _buff_toy =this;
}

void LittlePony::isTaken()
{
    _taken = true;
    std::cout << "yo man" << std::endl;
}