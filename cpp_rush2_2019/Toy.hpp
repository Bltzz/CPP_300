/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Toy
*/

#if !defined(_TOY_HPP_)
#define _TOY_HPP_

#include "Object.hpp"

class Toy : public Object
{
    public:
        Toy(std::string name);
        Toy(const Toy &t);
        void setTaken(bool taken);
    protected:
};

#endif /* !TOY_HPP_ */
