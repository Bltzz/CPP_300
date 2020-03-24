/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Container.hpp
*/

#pragma once
#include <iostream>
#include <bits/stdc++.h>

template<typename T>
void aff(T const &data){
    std::cout << "Value: " << data << std::endl;
}

template<typename T>
void add(T &data){
    data++;
}

template <typename T, template<typename, typename> class cont>
class contain{
    public:
        void push(T value){
            _container.push_back(value);
        }

        void aff(){
            std::for_each(_container.begin(), _container.end(), &::aff<T>);
        }

        void add(){
            std::for_each(_container.begin(), _container.end(), &::add<T>);
        }

    private:
         cont<T, std::allocator<T> > _container;
        T _value;
};