/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** getHeap
*/

#include <vector>
#include <string>
#include "list_fs/list_fs.hpp"
#include <algorithm>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

std::vector<std::string> getHeap()
{
    std::string path = "/sys/class/thermal/";
    std::vector<std::string> fslist = list_fs(path);
    std::vector<std::string> list;

    std::for_each(fslist.begin(), fslist.end(), [&list, &path](std::string &name) {
        if (strstr(name.c_str(), "thermal_zone")) {
            std::string nam = path + name + "/temp";
            std::string line;
            std::ifstream stream(nam);

            std::getline(stream, line);
            std::istringstream iss(line);
            list.push_back(iss.str());
            stream.close();
        }
    });
    return list;
}