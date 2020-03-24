/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** InfoModule
*/

#ifndef INFOMODULE_HPP_
#define INFOMODULE_HPP_
#include "Module.hpp"

class InfoModule : public Module
{
	public:
		InfoModule();
		~InfoModule();

    	void draw(){}
        void draw(sf::RenderWindow *);

        void initGraphicElements(size_t){}
        void initGraphicElements(sf::RenderWindow *, size_t tmp = 0);
        void fillModule(){}
        void changePos(sf::RenderWindow *, size_t){}
	protected:
	private:
        // SFML Graphic variables
        sf::RectangleShape _tile;
        sf::Font _font;
        sf::Text _infoDesc;
};

#endif /* !INFOMODULE_HPP_ */
