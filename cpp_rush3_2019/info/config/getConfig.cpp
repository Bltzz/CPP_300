/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** getFile.cpp
*/

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include "config.hpp"

config_t get_config(const std::string &path)
{
    std::ifstream config(path);

    config_t map;
    if (config.fail())
        return map;
    std::string str;
    while (std::getline(config, str))
        map[str.substr(0, str.find(':'))] = str.substr(str.find(':') + 1, std::string::npos);
    return map;
}

bool check_config(config_t config)
{
    if (config.find("file") == config.end())
        return false;
    if (config.find("separator") == config.end())
        return false;
    if (config.find("to_display") == config.end())
        return false;
    return true;
}
