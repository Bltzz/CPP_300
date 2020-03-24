/*
** EPITECH PROJECT, 2019
** cpp_d06_2019_ex00
** File description:
** ex00
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "my_cat.hpp"

void my_cat::cat_file_std_out(std::ifstream &file_checked, char *argv)
{
    int STR_LENGHT = 256;
    char tmp;

    if (!file_checked.is_open())
        std::cerr << "my_cat: " << argv << ": No such file or directory\n" << std::endl;
    while (file_checked.get(tmp)){
        std::cout << tmp;
    }
}

int main(int argc, char *argv[])
{
    my_cat cat;

    if (argc == 1){
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (-1);
    }
    for (int i = 1; i < argc; i++){
        std::ifstream file;
        file.open(argv[i], std::ifstream::in);
        cat.cat_file_std_out(file, argv[i]);
        file.close();
    }

}