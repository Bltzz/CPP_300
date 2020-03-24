/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** GiftPaper.cpp
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(std::string name) : Wrap(name)
{
    _type |= G_PAPER;
    _buff_wrap = this;
}
