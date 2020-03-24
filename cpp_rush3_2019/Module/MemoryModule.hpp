/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** MemoryModule
*/

#ifndef MEMORYMODULE_HPP_
#define MEMORYMODULE_HPP_

#include "Module.hpp"
#include <iostream>
#include <list>

typedef struct
{
    size_t memTotal = 1;
    size_t memFree = 1;
    size_t memUsed = 1;
    size_t swapTotal = 1;
    size_t swapFree = 1;
    size_t swapUsed = 1;
} MemoryModuleInfos;

class MemoryModule : public Module
{
	public:
		MemoryModule();
		~MemoryModule();

        void draw();
        void draw(sf::RenderWindow *);

        void fillModule();
        void setValues(std::map<std::string, std::string> &);

        void initGraphicElements(size_t);
        void initGraphicElements(sf::RenderWindow *, size_t);

        void changePos(sf::RenderWindow *, size_t);
	protected:
	private:
        MemoryModuleInfos _infos;

        // SFML Graphic variables
        sf::Font _font;
        sf::Font _font_title;
        sf::RectangleShape _tile;
        std::list<sf::RectangleShape> _usage_backgrounds;
        std::list<sf::RectangleShape> _usage_front;
        std::list<sf::Text> _typeNames;
        sf::Text _moduleTitle;

        // NCURSES Graphic variables
};

#endif /* !MEMORYMODULE_HPP_ */
