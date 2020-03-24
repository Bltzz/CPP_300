/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/

#include <iostream>
#include <memory>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main(){
    std::unique_ptr <Toy> b(new Buzz("buzziiiii"));
    std::unique_ptr <Toy > wood(new Woody("wood"));
    std::unique_ptr <Toy > t(new Toy(Toy::ALIEN, "ET", "alien.txt"));
    b->speak("To the code, and beyond !!!!!!!!");
    wood->speak("There's a snake in my boot.");
    t->speak("the claaaaaaw");

    Toy a(Toy::BASIC_TOY, "REX", "rex.txt");
    std::cout  << a;
    a << "\\o/";
    std::cout  << a;
    std::cout << "####################################################################" <<std::endl;

    Woody w("wood");
    if (w.setAscii("file_who_does_not_exist.txt") ==  false){
        auto e = w.getLastError();
        if (e.type == Toy::Error::PICTURE){
            std::cout << "Error in " << e.where() << ": " << e.what() <<std::endl;
        }
    }
    if (w.speak_es("Woody does not have spanish mode") == false){
        auto e = w.getLastError();
        if (e.type == Toy::Error::SPEAK){
            std::cout << "Error in " << e.where() << ": " << e.what() <<std::endl;
        }
    }if (w.speak_es("Woody does not have spanish mode") ==  false){
        auto e = w.getLastError();
        if (e.type == Toy::Error::SPEAK){
            std::cout << "Error in " << e.where() << ": " << e.what() <<std::endl;
        }
    }
}