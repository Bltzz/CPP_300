/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ex02.hpp
*/

#pragma once
#include <iostream>

int min(int const a, int const b){
    std::cout << "non-template min" << std::endl;
    if (a > b)
        return b;
    return a;
}
template<typename T>
T min(T const a, T const b){
    std::cout << "template min" << std::endl;
    if (a > b)
        return b;
    return a;
}

template <typename T>
T templateMin(T const *arr, int const size){
    T tmp = arr[0];
    if (size == 2)
        return min<T>(arr[0], arr[1]);
    for (int i = 0; i < size; i++){
        tmp = min<T>(tmp, arr[i]);
    }
    return tmp;
}

int nonTemplateMin(int const *arr, int const size){
    int tmp = arr[0];
    if (size == 2)
        return min(arr[0], arr[1]);
    for (int i = 0; i < size; i++){
        tmp = min(tmp, arr[i]);
    }
    return tmp;
}