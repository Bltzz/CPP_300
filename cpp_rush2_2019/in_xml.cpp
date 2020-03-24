/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** out.cpp
*/

#include <string>
#include <fstream>
#include <dirent.h>
#include "Object.hpp"

int len_dir(const char *path)
{
    int i = 0;

    DIR *dir;
    dirent_t ele;

    if ((dir = opendir(path)) == NULL) {
        std::cout << "Folder gift not found." << std::endl;
        exit (84);
    }
    ele = readdir(dir);
    while (ele != NULL) {
        i++;
        ele = readdir(dir);
    }
    closedir(dir);
    return(i);
}

std::string *dir_name(const char *path, bool mod_point)
{
    errno = 0;

    std::string *names = new std::string[(len_dir(path) + 1)];
    DIR *dir = opendir(path);
    dirent_t ele = readdir(dir);
    int i = 0;

    if (errno != 0)
        return (NULL);
    while (ele != NULL) {
        if (!mod_point && ele->d_name[0] != '.')
            names[i++] = std::string(ele->d_name);
        ele = readdir(dir);
    }
    names[i] = "";
    closedir(dir);
    return names;
}

int get_max(void)
{
    std::string *cap_name =  dir_name("./gift/", 0);
    int ret = 0;
    int i = 0;

    for (; cap_name[i] != ""; i++);
    return (i + 1);
}

int inxml(std::string kdo, std::string toy, std::string name)
{

    std::string filename = "gift" + std::to_string(get_max()) + ".xml";
    std::ofstream file("gift/" + filename);

    if(file) {
        file << "<?xml version='1.0'?>" << std::endl;
        file << "<Body>" << std::endl;
        file << "    <Type>" << kdo << "</Type>" << std::endl;
        file << "    <Toy>" << toy << "</Toy>" << std::endl;
        file << "    <Name>" << name << "</Name>" << std::endl;
        file << "</Body>" << std::endl;
        file.close();
    } else
        std::cerr << "Can't open the file" << std::endl;
    return (0);
}

void convert(int kdo, int toy, std::string name)
{
    std::string gift;
    std::string toys;

    if (kdo == 0)
        gift = "gift";
    if (kdo == 1)
        gift = "gift in a box";
    if (kdo == 2)
        gift = "gift packed up";
    if (kdo == 3)
        gift = "gift in a packed up box";
    if (toy == 0)
        toys = "Teddy";
    if (toy == 1)
        toys = "LittlePony";
    inxml(gift, toys, name);
}