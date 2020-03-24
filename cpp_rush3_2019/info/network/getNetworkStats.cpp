/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** getNetworkStats.cpp
*/

#include <fstream>
#include <bits/stdc++.h>
#include <vector>

std::vector<size_t> explode(const std::string& str, const char& ch) {
    std::string next;
    std::vector<size_t> result;

    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ch) {
            if (!next.empty()) {
                result.push_back(std::atoi(next.c_str()));
                next.clear();
            }
        } else {
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(std::atoi(next.c_str()));
    return result;
}

std::vector<size_t> getWifiStats(){
    std::ifstream input("/proc/net/dev");
    std::string str;
    std::vector<size_t> tmp;
    if (input.fail())
        return *new std::vector<size_t>();
    while (std::getline(input, str))
        if (str.find("wlp") == 0)
            tmp = explode(str, ' ');
    std::vector<size_t> reduced;
    reduced.push_back(tmp[1]); // Recieve bytes
    reduced.push_back(tmp[2]); // packets
    reduced.push_back(tmp[4]); // drop
    reduced.push_back(tmp[9]); // Transmit bytes
    reduced.push_back(tmp[10]); // Transmit packets

    return reduced;
}

std::vector<size_t> getEthernetStats(){
    std::ifstream input("/proc/net/dev");
    std::string str;
    std::vector<size_t> tmp;
    if (input.fail())
        return *new std::vector<size_t>();
    while (std::getline(input, str))
        if (str.find("enp") == 0)
            tmp = explode(str, ' ');
    std::vector<size_t> reduced;
    reduced.push_back(tmp[1]); // Recieve bytes
    reduced.push_back(tmp[2]); // packets
    reduced.push_back(tmp[4]); // drop
    reduced.push_back(tmp[9]); // Transmit bytes
    reduced.push_back(tmp[10]); // Transmit packets

    return reduced;
}
