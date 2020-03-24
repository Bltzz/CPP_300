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

using line_t = std::map<std::string, std::string>;

line_t get_mem_info()
{
    std::ifstream config("/proc/meminfo");

    line_t map;
    if (config.fail())
        return map;
    std::string str;
    while (std::getline(config, str)) {
        std::string tmp = str.substr(str.find(':') + 1, std::string::npos);
        tmp = tmp.substr(tmp.find_first_not_of(" \n\r\t"), std::string::npos);
        if (tmp.size() > 3 && tmp.substr(tmp.size() - 3, std::string::npos) == " kB")
            tmp = tmp.substr(0, tmp.size() - 3);
        map[str.substr(0, str.find(':'))] = tmp;
    }
    return map;
}
