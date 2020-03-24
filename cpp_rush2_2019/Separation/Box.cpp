/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Box.cpp
*/

#include "Box.hpp"

Box::Box(std::string name) : Wrap(name)
{
    _type |= BOX;
    _buff_wrap = this;
}
