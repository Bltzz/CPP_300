/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** header for ex01
*/

#pragma once

#include <fstream>

struct my_convert_temp
{
    void calc_fahr_to_cel(double fahrenheit);
    void calc_cel_to_fahr(double celsius);
    void check_for_dir(std::ifstream file);
};