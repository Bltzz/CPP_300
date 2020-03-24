/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Picture.hpp
*/

#if !defined(_PICTURE_HPPP_)
#define _PICTURE_HPPP_

#include <iostream>
#include <fstream>

class Picture {
    public:
        Picture();
        Picture(const std::string &file);
        ~Picture(){}

        void setData(const std::string message){this->data = message;}

        bool getPictureFromFile(const std:: string &file);
        std::string getData() const {return this->data;}
    private:
        std::string data;
};


#endif /* !_PICTURE_HPP_ */