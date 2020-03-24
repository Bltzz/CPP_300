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

        virtual void speak(std::string statement);
        void setName(std::string const &name);
        bool setAscii(std::string const &file);
        Toy &operator<<(std::string);
        Toy &operator=(const Toy &t);
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        Picture getPicture() const {return this->pic;}

    private:
        ToyType const type;
        std::string name;
        Picture pic;
};
std::ostream &operator<<(std::ostream& os, Toy const &t);



#endif /* !_TOY_HPP_ */
