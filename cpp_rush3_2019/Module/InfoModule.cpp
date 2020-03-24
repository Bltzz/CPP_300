/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** InfoModule
*/

#include "InfoModule.hpp"

InfoModule::InfoModule()
{
}

InfoModule::~InfoModule()
{
}

void fillModule()
{
    return;
}

void InfoModule::initGraphicElements(sf::RenderWindow *window, size_t useless)
{
    (void) useless;
    _tile = *new sf::RectangleShape(sf::Vector2f(sf::Vector2f(window->getSize().x, 30)));
    _tile.setFillColor(sf::Color::Transparent);
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness(2);
    _tile.setPosition(0, window->getSize().y - 30);
    _font = *new sf::Font;
    _font.loadFromFile("ressources/Quicksand.ttf");
    _infoDesc = sf::Text("F11, F12: \"Feeling Lucky\" Editor Mode\t\t\tESC: Close Window", _font, 20);
    _infoDesc.setOrigin(_infoDesc.getGlobalBounds().width / 2, _infoDesc.getGlobalBounds().height / 2);
    _infoDesc.setPosition(window->getSize().x / 2, window->getSize().y - 5 - _infoDesc.getGlobalBounds().height);

}

void InfoModule::draw(sf::RenderWindow *win)
{
    win->draw(_tile);
    win->draw(_infoDesc);
}
