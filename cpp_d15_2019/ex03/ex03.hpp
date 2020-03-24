/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ex03.hpp
*/

#pragma once
#include <iostream>


template<typename T>
void foreach(T *arr, void(&func)(T const &t), int size){
    for (int i = 0; i < size; i++){
        func(arr[i]);
    }
}


template <typename T>
void print(T const &t){
    std::cout << t << std::endl;
}