/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Wrap.cpp
*/

#include "Wrap.hpp"

Wrap::Wrap(std::string name) : Object(name)
{
    _type = WRAP;
    _gift = NULL;
}

Object *Wrap::openMe()
{
    Object *get = _gift;
    _isOpen = 1;
    _gift = NULL;
    if (get == NULL)
        std::cerr << "Nothing in this warp" << std::endl;
    return get;
}

bool Wrap::wrapMeThat(Object &obj)
{
    if (!isGift() && _isOpen) {
        this->isTaken();
        obj.isTaken();
        _gift = &obj;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return true;
    } else
        std::cerr << "Warp alredy paked or closed" << std::endl;
    return false;
}

void Wrap::isTaken()
{
    _taken = 1;
    std::cout << "whistles while working" << std::endl;
}

bool Wrap::isGift()
{
    return (_gift != NULL);
}

bool Wrap::closeMe()
{
    if (_isOpen && (_type & BOX)) {
        _isOpen = false;
        return true;
    } else
        std::cerr << "Alredy closed or not a box" << std::endl;
    return false;
}