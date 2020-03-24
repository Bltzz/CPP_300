/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** ex00
*/
#pragma once
#include <iostream>

class Victim{
    public:
        explicit Victim(std::string name);
        ~Victim();
        std::string getName() const {return this->name;}
        virtual void getPolymorphed()const;

    protected:
        std::string name;
};
        std::ostream &operator<<(std::ostream& os, Victim const &v);
