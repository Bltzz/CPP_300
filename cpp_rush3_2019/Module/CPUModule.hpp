/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPUModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include "Module.hpp"
#include <list>

typedef struct
{
    std::string title = "";
    double usage = 1.0f;
    size_t _active_time = 1;
    size_t _idle_time = 1;
    std::string model_name = "";
    // active and idle time need to be initialized at  the beginning of the program
} CPUModuleInfos;

class CPUModule : public Module
{
	public:
		CPUModule();
		~CPUModule();

        void draw();
        void draw(sf::RenderWindow *);

        void initValues(std::vector<std::vector<std::string>> &stat);
        void fillModule();
        void setValues(std::vector<std::map<std::string, std::string>> &, std::vector<std::vector<std::string>> &);

        void setBar(sf::RenderWindow *, int, int, int, int, size_t, sf::Font *, CPUModuleInfos *);
        void changeSinglePos(sf::RenderWindow *, int, int, int, int, size_t);

        void initGraphicElements(size_t);
        void initGraphicElements(sf::RenderWindow *, size_t);
        void changePos(sf::RenderWindow *win, size_t moduleNb);
	protected:
	private:
        std::vector<CPUModuleInfos> _infos;

        // SFML Graphic variables
        sf::Text _moduleTitle;
        sf::RectangleShape _tile;
        std::list<sf::RectangleShape> _usage_backgrounds;
        std::list<sf::RectangleShape> _usage_front;
        std::list<sf::Text> _cpu_names;
        sf::Font _font;
        sf::Font _font_title;

        // NCURSES Graphic variables
        std::string _module_name = "CPU Usage";
        int _num_CPU = 0;
};

#endif /* !CPUMODULE_HPP_ */
