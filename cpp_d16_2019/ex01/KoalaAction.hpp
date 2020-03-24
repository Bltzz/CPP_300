/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** KoalaAction.hpp
*/

#pragma once
#include <iostream>

class KoalaAction{
    public:
        void eat(const std::string &s){
            std::cout << "I eat: " << s <<std::endl;
        }
        void goTo(const std::string &s){
            std::cout << "I go to: " << s <<std::endl;
        }
        void sleep(const std::string &s){
            std::cout << "I sleep, and dream of: " << s <<std::endl;
        }
        void reproduce(const std::string &s){
            std::cout << "I attempt to reproduce with: " << s <<std::endl;
        }
};