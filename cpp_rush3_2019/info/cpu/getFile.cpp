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
#include <vector>
#include "getInfo.hpp"
#include <ncurses.h>

std::vector<line_t> get_cpu_info()
{
    std::ifstream file("/proc/cpuinfo");

    std::vector<line_t> info;
    if (file.fail())
        return info;
    std::string str;
    line_t map;
    while (std::getline(file, str)) {
        if (str.find(':') != std::string::npos && str.substr(0, str.find(':')) == "processor\t") {
            info.push_back(map);
            map.clear();
        }
        if (str.find(':') != std::string::npos) {
            std::string tmp = str.substr(0, str.find(':'));
            std::string tmp2 = str.substr(str.find(':'), std::string::npos);
            if (tmp2.size() > 2)
                tmp2 = tmp2.substr(2, std::string::npos);
            map[tmp.substr(0, tmp.find_last_not_of(" \n\r\t") + 1)] = tmp2;
        }
    }
    info.push_back(map);
    return info;
}

std::string getVal(std::vector<line_t> *info, const std::string &key, int cpuNumber)
{
    std::string str = "";
    std::for_each(info->begin(), info->end(), [key, cpuNumber, &str](line_t &m) {
        if (m["processor"] == std::to_string(cpuNumber))
            str = m[key];
    });
    return str;
}
