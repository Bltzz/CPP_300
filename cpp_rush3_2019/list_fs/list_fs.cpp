/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** listModules
*/

#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <algorithm>

std::vector<std::string> list_files(const std::string &path)
{
    unsigned char isFile = 0x8;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path.c_str());
    std::vector<std::string> list;

    while ((entry = readdir(dir)))
        if (entry->d_type == isFile)
            list.push_back(entry->d_name);
    return list;
}

std::vector<std::string> list_dir(const std::string &path)
{
    unsigned char isDir = 0x4;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path.c_str());
    std::vector<std::string> list;

    while ((entry = readdir(dir)))
        if (entry->d_type == isDir)
            list.push_back(entry->d_name);
    return list;
}

std::vector<std::string> list_fs(const std::string &path)
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path.c_str());
    std::vector<std::string> list;

    if (!dir)
        return list;
    while ((entry = readdir(dir)))
        list.push_back(entry->d_name);
    return list;
}