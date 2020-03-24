/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/
#include "ex05.hpp"


int float_to_int(double const& f) {
    return static_cast <int>(f);
}
int main(){
    array <int> a(4);
    a[3] = 1;
    const auto b = a;
    b.dump();
    array <bool> c;
    c.dump();
    c[2] = true;
    c.dump();
    //a = c.convertTo <int>(& float_to_int);
    a.dump();
}