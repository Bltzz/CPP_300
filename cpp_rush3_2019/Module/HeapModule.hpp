/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** HeapModule
*/

#ifndef HeapModule_HPP_
#define HeapModule_HPP_

#include "Module.hpp"
#include <list>

typedef struct
{
    double temperature;
    // active and idle time need to be initialized at  the beginning of the program
} HeapModuleInfos;

class HeapModule : public Module
{
	public:
		HeapModule();
		~HeapModule();

        void draw();
        void draw(sf::RenderWindow *);

        void initValues(std::vector<std::vector<std::string>> &stat);
        void fillModule();
        void setValues(std::vector<std::string> &);

        void initGraphicElements(size_t);
        void initGraphicElements(sf::RenderWindow *, size_t);
        void changePos(sf::RenderWindow *win, size_t moduleNb);
	protected:
	private:
        std::vector<HeapModuleInfos> _infos;

        // SFML Graphic variables
        sf::Font _font_title;
        sf::Font _font;
        sf::Text _moduleTitle;
        sf::RectangleShape _tile;
        std::list<sf::Text> _tempCelsius;

        // NCURSES Graphic variables
};

#endif /* !HeapModule_HPP_ */
