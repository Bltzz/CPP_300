/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** getStat.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "getInfo.hpp"

std::vector<std::string> get_usage(std::string first, std::string line)
{
    std::vector<std::string> vec;
    vec.push_back(first);
    if (line.size() < 1)
        return vec;
    std::string tmp = line.substr(0, line.find_first_of(" \r\n\t"));
    std::vector<std::string> vecTmp;
    if (line == line.substr(line.find_first_of(" \r\n\t") + 1, std::string::npos))
        vecTmp = get_usage(tmp, "");
    else
        vecTmp = get_usage(tmp, line.substr(line.find_first_of(" \r\n\t") + 1, std::string::npos));
    vec.insert(vec.end(), vecTmp.begin(), vecTmp.end());
    return vec;
}

std::vector<std::vector<std::string>> get_stat_info()
{
    std::ifstream config("/proc/stat");

    std::vector<std::vector<std::string>> stat;
    if (config.fail())
        return stat;
    std::string str;
    while (std::getline(config, str)) {
        if (str.substr(0, 4) == "cpu ") {
            std::string tmp = str.substr(0, 4);
            stat.push_back(get_usage(tmp, str.substr(5, std::string::npos)));
        } else if (str.substr(0, 3) == "cpu") {
            std::string tmp = str.substr(0, str.find(' '));
            stat.push_back(get_usage(tmp, str.substr(str.find(' ') + 1, std::string::npos)));
        } else
            break;
    }
    return stat;
}

size_t get_idle_time(std::vector<std::string> &var)
{
    return  atoi(var[4].c_str()) + atoi(var[5].c_str());
}

size_t get_active_time(std::vector<std::string> &var)
{
    return  atoi(var[1].c_str()) +
            atoi(var[2].c_str()) +
            atoi(var[3].c_str()) +
            atoi(var[6].c_str()) +
            atoi(var[7].c_str()) +
            atoi(var[8].c_str()) +
            atoi(var[9].c_str());
}
