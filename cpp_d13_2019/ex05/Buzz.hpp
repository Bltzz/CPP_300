/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Buzz.hpp
*/

#pragma once
#include "Toy.hpp"

class Buzz : public Toy{
    public:
        Buzz(std::string const name);
        Buzz(std::string const name, std::string const pic);
        ~Buzz(){}

        void speak(std::string const statement);
        bool speak_es(std::string const statement) override;

};