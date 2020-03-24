/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** find.hpp
*/
#pragma once
#include <algorithm>

template<typename T>
auto do_find(T &t, int i){
    return std::find(t.begin(), t.end(), i);
};
