/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** NetworkModule.hpp
*/

#ifndef NETWORKMODULE_HPP
    #define NETWORKMODULE_HPP

#include "Module/Module.hpp"
#include <list>
using Stats = std::vector<size_t>;

typedef struct
{
    double inPercent = 0;
    double outPercent = 0;
    double inPercentPack = 0;
    double outPercentPack = 0;
    std::string type = "";
    size_t received_bytes = 0;
    size_t received_packets = 0;
    size_t received_drops = 0;
    size_t transmitted_bytes = 0;
    size_t transmitted_packets = 0;
} NetworkModuleInfos;

class NetworkModule : public Module{
    public:
        NetworkModule();
        ~NetworkModule();
        void draw();
        void draw(sf::RenderWindow *);

        void fillModule();
        void initModule();
        void setValues(Stats &, std::string type);

        void initGraphicElements(size_t);
        void initGraphicElements(sf::RenderWindow *, size_t);

        void changePos(sf::RenderWindow *win, size_t moduleNb);

        private:
            NetworkModuleInfos _infos;

            sf::Font _font;
            sf::Font _font_title;
            sf::RectangleShape _tile;
            std::list<sf::Text> _netInfo;
            sf::Text _moduleTitle;

};

#endif