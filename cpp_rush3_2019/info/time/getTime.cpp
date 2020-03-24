/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** getTime.cpp
*/

#include <string>
#include <iostream>
#include <ctime>

std::string getTime(){
    time_t current = time(0);
    std::string current_time_to_str(ctime(&current));

    return current_time_to_str;
}