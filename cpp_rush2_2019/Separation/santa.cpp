/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** out_xml.cpp
*/

#include <iostream>
#include <string>
#include <fstream>

void display(std::string type, std::string toy, std::string name)
{
    std::cout << "That's a " << type << " which contains a ";
    std::cout << toy << " called " << name << " !" << std::endl;
}

void pars(char *filename)
{
    int pos = 0;
    std::string type;
    std::string toy;
    std::string name;
    std::string filepath;

    filepath.assign(filename);
    std::ifstream file(filepath);
    if (file) {
        std::string tmp;
        while(getline(file, tmp)) {
            if ((pos = tmp.find("<Type>")) != -1)
                for (int i = pos + 6; tmp[i] != '<'; i++)
                    type += tmp[i];
            if ((pos = tmp.find("<Toy>")) != -1)
                for (int i = pos + 5; tmp[i] != '<'; i++)
                    toy += tmp[i];
            if ((pos = tmp.find("<Name>")) != -1)
                for (int i = pos + 6; tmp[i] != '<'; i++)
                    name += tmp[i];
        }
        file.close();
    }
    display(type, toy, name);
}

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        pars(av[i]);
    return (0);
}