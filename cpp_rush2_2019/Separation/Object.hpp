/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Object
*/

#if !defined(_OBJECT_HPP_)
#define _OBJECT_HPP_

#include <iostream>


class Toy;
class Wrap;
class LittlePony;
class Teddy;

enum type_t {
    TOY = 1 << 1,
    PONNY = 1 << 2,
    TEDDY = 1 << 3,
    WRAP = 1 << 4,
    BOX = 1 << 5,
    G_PAPER = 1 << 6,
};

class Object
{
	public:
		Object(std::string name = "");
		virtual void isTaken() = 0;
		std::string getName() const { return this->_name; }
		int getType() const { return this->_type; }
		Object &operator=(const Object &obj);
        std::string type_to_str();
        Toy *ret_buff_toy() {return _buff_toy;}
        Wrap *ret_buff_wrap() {return _buff_wrap;}
	protected:
    	std::string _name;
		int _type;
		bool _taken;
		bool _wraped;
        Toy *_buff_toy = NULL;
        Wrap *_buff_wrap = NULL;
};

Object **MyUnitTests();

#endif /* !OBJECT_HPP_ */
