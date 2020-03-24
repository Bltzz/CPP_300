/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** applyConfig.cpp
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "config.hpp"

std::vector<std::string> get_disp(std::string toParse)
{
    std::vector<std::string> res;
    if (toParse.size() < 1)
        return res;
    std::string add = toParse.substr(0, toParse.find(','));
    res.push_back(add);
    if (add.size() == toParse.size())
        return res;
    std::string tmp = toParse.substr(toParse.find(',') + 1, std::string::npos);
    std::vector<std::string> rec = get_disp(tmp);
    res.insert(res.end(), rec.begin(), rec.end());
    return res;
}

bool is_disp(std::vector<std::string> disp, std::string str)
{
    for (size_t i = 0; i < disp.size(); i++)
        if (disp.at(i) == str)
            return true;
    return false;
}

line_t apply_config(config_t config)
{
    std::ifstream file(config["file"]);

    std::string separator = config["separator"];
    std::vector<std::string> toDisplay = get_disp(config["to_display"]);
    line_t map;
    if (file.fail())
        return map;
    std::string str;
    while (std::getline(file, str)) {
        std::string tmp = str.substr(0, str.find(separator));
        if (is_disp(toDisplay, tmp) && str.size() > tmp.size() + 1)
            map[tmp] = str.substr(str.find(separator) + 1, std::string::npos);
    }
    return map;
}