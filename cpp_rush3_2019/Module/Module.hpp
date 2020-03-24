/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Module
*/

#ifndef MODULE_HPP_
#define MODULE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

class Module {
	public:
		Module();
		virtual ~Module();

        void setPos(int x, int y) {
            this->_x = x;
            this->_y = y;
        }

        int getPosX() const { return this->_x; };
        int getPosY() const { return this->_y; };

        int getHeight() const { return this->_height; };

        virtual void draw() = 0;
        virtual void draw(sf::RenderWindow *) = 0;

        virtual void initGraphicElements(size_t) = 0;
        virtual void initGraphicElements(sf::RenderWindow *, size_t) = 0;

        virtual void fillModule() = 0;
        virtual void changePos(sf::RenderWindow *, size_t) = 0;

	protected:
        int _x = 0;
        int _y = 0;
        void setHeight(int &height) { this->_height = height; };
        int _height = 0;
	private:
};

#endif /* !MODULE_HPP_ */
