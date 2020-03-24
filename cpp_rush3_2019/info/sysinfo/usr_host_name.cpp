/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** usr_host_name.cpp
*/

#include <iostream>
#include <string>
#include <unistd.h>

std::string getUsr(){
        return getlogin();
}

std::string getHost(){
    char name[1024];
    if (gethostname(name, sizeof(name)) == -1) {
        return "";
    }
    return name;
}
