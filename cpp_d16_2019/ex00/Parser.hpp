/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Parser.hpp
*/
#pragma once
#include <iostream>
#include <stack>

class Parser{
    public:
        Parser();
        ~Parser();
        void feed(const std::string &);
        int result() const;
        void reset();
    private:
        std::stack<int> values;
        std::stack<char> operators;
};