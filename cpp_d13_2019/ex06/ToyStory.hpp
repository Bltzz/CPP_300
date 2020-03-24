/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ToyStory.hpp
*/

#pragma once
#include <iostream>
#include "Toy.hpp"

class ToyStory{
    public:
        static void tellMeAStory(std::string const &filename, Toy &toy1, bool (Toy::*func1)(const std::string string), Toy &toy2, bool (Toy::*func2)(const std::string string));
};