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
        bool getPictureFromFile(const std:: string &file);

        void setData(const std::string message);
        std::string getData() const;
    private:
        std::string data;
};


#endif /* !_PICTURE_HPP_ */