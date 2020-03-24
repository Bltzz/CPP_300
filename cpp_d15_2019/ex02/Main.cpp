/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/

#include "ex02.hpp"

int main()
{
    int tab [2] = {3, 0};
    int minimum = templateMin(tab , 2);
    std::cout << "templateMin(tab , 2) = " << minimum  << std::endl;
    minimum = nonTemplateMin(tab , 2);
    std::cout << "nonTemplateMin(tab , 2) = " << minimum  << std::endl;
    return 0;
}
