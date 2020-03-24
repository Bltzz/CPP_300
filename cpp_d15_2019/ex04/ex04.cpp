/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ex04.cpp
*/

#include "ex04.hpp"
#include <iostream>

template <> Tester<int>::Tester(){}
template <> Tester<float>::Tester(){}
template <> Tester<double>::Tester(){}
template <> Tester<std::string>::Tester(){}

template <> Tester<int>::~Tester(){}
template <> Tester<float>::~Tester(){}
template <> Tester<double>::~Tester(){}
template <> Tester<std::string>::~Tester(){}

template <> bool Tester<int>::equal(int const &t, int const &t2){return t == t2;}
template <> bool Tester<double>::equal(double const &t, double const &t2){return t == t2;}
template <> bool Tester<float>::equal(float const &t, float const &t2){return t == t2;}
template <> bool Tester<std::string>::equal(std::string const &t, std::string const &t2){return (t.compare(t2) == 0);}

template <> bool equal(int const &t, int const &t2){return t == t2;}
template <> bool equal(double const &t, double const &t2){return t == t2;}
template <> bool equal(float const &t, float const &t2){return t == t2;}
template <> bool equal(std::string const &t, std::string const &t2){return (t.compare(t2) == 0);}
