/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Picture.cpp
*/

#include "Picture.hpp"

Picture::Picture(){
    this->data = "";
}

Picture::Picture(const std::string &file){
    this->getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std:: string &file){
    try {
        std::ifstream stream(file.c_str());
        if (!stream.is_open()){
            this->setData("ERROR");
            return false;
        }
        std::string tmp = "";
        this->setData("");
        while (getline(stream, tmp, '\0'))
            this->setData(this->getData() + tmp);
        stream.close();
        return true;
    }catch (std::exception &e){
        this->setData("ERROR");
        return false;
    }
}


