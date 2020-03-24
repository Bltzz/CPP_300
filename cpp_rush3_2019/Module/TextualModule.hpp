/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TextualModule
*/

#ifndef TextualMODULE_HPP_
#define TextualMODULE_HPP_

#include "Module.hpp"
#include <iostream>
#include <list>

using sysStats = std::pair<std::string, std::string>;
using usrStats = std::pair<std::string, std::string>;

typedef struct
{
    std::string os;
    std::string kernel;
    std::string usr;
    std::string host;
    std::string date;
} TextualModuleInfos;

class TextualModule : public Module
{
	public:
		TextualModule();
		~TextualModule();

        void draw();
        void draw(sf::RenderWindow *);

        void fillModule();
        void initModule();
        void setValues(sysStats sys, usrStats usr, std::string date);

        void initGraphicElements(size_t);
        void initGraphicElements(sf::RenderWindow *, size_t);

        void changePos(sf::RenderWindow *, size_t);
	protected:
	private:
        TextualModuleInfos _infos;

        // SFML Graphic variables
        sf::Font _font;
        sf::Font _font_title;
        sf::RectangleShape _tile;
        std::list<sf::Text> _userInfo;
        sf::Text _moduleTitle;

        // NCURSES Graphic variables
};

#endif /* !TextualMODULE_HPP_ */
