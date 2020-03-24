/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** sysinfo.cpp
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/utsname.h>

std::pair<std::string, std::string> getSysInfo(){
    std::ifstream config("/etc/os-release");
    std::string str;
    std::string result;
    int ctr = 0;
    struct utsname name;

    if (config.fail())
        return std::make_pair("", name.release);
    while (std::getline(config, str) && ctr < 2) {
        std::string tmp = str.substr(str.find('=') + 1, std::string::npos -1);
        result += tmp.substr(tmp.find_first_not_of(" \n\r\t") , std::string::npos -1) + " ";
        result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
        ctr++;
    }
    result.pop_back();
    uname(&name);
    std::string kernel = name.release;

    return std::make_pair(result, kernel);
}
