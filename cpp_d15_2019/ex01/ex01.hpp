/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ex01.hpp
*/

#pragma once
#include <cstring>

template<typename T>
int compare(T const &a, T const &b){
    if (a == b)
        return (0);
    if (a < b)
        return (-1);
    return (1);
}

template<>
int compare(char * const &a, char* const &b){
    int tmp = std::strcmp(a, b);
    if (tmp > 0)
        return (-1);
    if (tmp < 0)
        return 1;
    return 0;
}

template <typename T, typename U>
int compare(T const &t, U const &u){
    int tmp = std::strncmp(t, u);
    if (tmp > 0)
        return (-1);
    if (tmp < 0)
        return 1;
    return 0;
}