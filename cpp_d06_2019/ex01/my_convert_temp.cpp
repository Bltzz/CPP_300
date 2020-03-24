/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** ex01
*/

#include "my_convert_temp.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

void my_convert_temp::calc_fahr_to_cel(double fahrenheit)
{
    double celsius = ((fahrenheit) - 32.0)*5/9;
    celsius = round(celsius * 1000.0) / 1000.0;
    std::cout << "\t" << celsius << "\t" << "Celsius" << std::endl;
}

void my_convert_temp::calc_cel_to_fahr(double celsius)
{
    double fahrenheit = celsius * 9/5 + 32.0;
    fahrenheit = round(fahrenheit * 1000.0) / 1000.0;
    std::cout << "\t" << fahrenheit << "\t" << "Fahrenheit" << std::endl;
}

int main(void)
{
    double temp;
    std::string scale;
    my_convert_temp Cast;
    std::string tmp;
    std::string celsius = "Celsius";
    std::string fahrenheit = "Fahrenheit";
    std::cin >> tmp;
    std::cin >> scale;

    try
    {
        temp = std::stod(tmp);
        if (scale.empty())
            exit (1);
        if (celsius.compare(scale) == 0)
            Cast.calc_cel_to_fahr(temp);
        if (fahrenheit.compare(scale) == 0)
            Cast.calc_fahr_to_cel(temp);
        else exit (1);
    }
    catch(std::exception e){
        exit(1);
    }
    return 0;
}
