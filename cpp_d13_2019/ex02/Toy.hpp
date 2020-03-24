/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Toy.hpp
*/

#if !defined(_TOY_HPP_)
#define _TOY_HPP_

#include "Picture.hpp"
#include <iostream>

class Toy{
    public:
        enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};
        Toy();
        Toy(ToyType const type, std::string name, std::string const pic);
        Toy(Toy const &t);

        virtual ~Toy();
        Toy &operator=(const Toy &t);

        void setName(std::string const &name);
        bool setAscii(std::string const &file);

        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;

    private:
        ToyType const type;
        std::string name;
        Picture pic;
};



#endif /* !_TOY_HPP_ */
