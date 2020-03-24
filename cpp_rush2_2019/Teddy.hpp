/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Teddy
*/

#if !defined(_TEDDY_HPP_)
#define _TEDDY_HPP_

#include "Toy.hpp"

class Teddy : public Toy
{
    public:
        Teddy(std::string name);
        void isTaken() override;
    protected:
};

#endif /* !TEDDY_HPP_ */
