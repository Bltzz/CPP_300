/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** ex00
*/
#pragma once

#include <iostream>
#include "Victim.hpp"

class Sorcerer{
    public:
        explicit Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        std::string getName() const {return this->name;}
        std::string getTitle() const {return this->title;}
        void polymorph(const Victim &victim) const;
    protected:
        std::string name;
        std::string title;
};
        std::ostream &operator<<(std::ostream& os, Sorcerer const &s);
