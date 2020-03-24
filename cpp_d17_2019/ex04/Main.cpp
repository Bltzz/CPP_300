/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/

#include "Container.hpp"
#include <bits/stdc++.h>
#include <list>

int main(){
    contain<char, std::list> test;
    test.push('t');
    test.aff();
    test.add();
    test.aff();
    contain <int, std::vector> test2;
    test2.push(1);
    test2.aff();
    test2.add();
    test2.aff();
    return 0;
}