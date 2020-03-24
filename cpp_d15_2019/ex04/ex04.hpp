/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ex05.hpp
*/

#pragma once

template <typename T>
bool equal(T const &a, T const &b); //{
//     if (a == b)
//         return true;
//     return false;
// }

template <typename T>
class Tester{
    public:
        Tester();
        ~Tester();
        bool equal(T const &t, T const &t2);
};