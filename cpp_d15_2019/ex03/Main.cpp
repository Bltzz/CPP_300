/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/

#include "ex03.hpp"
#include <iostream>

int main(){
    int tab[] = {11, 3, 89, 42};
    foreach(tab, print<int>, 4);
    std::string tab2[] = { "j'", "aime", "les", "templates", "!" };
    foreach(tab2, print<>, 5);
    return  0;
}
