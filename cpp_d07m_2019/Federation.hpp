/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** header ex00
*/

#pragma once

#include <iostream>
#include "WarpSystem.hpp"

namespace Federation{
    namespace Starfleet{
        class Captain{
            private:
                std::string _name;
                int _age;
            public:
                Captain(std::string name);
                std::string getName(){return this->_name;}
                int getAge(){return this->_age;}
                void setAge(int age){this->_age = age;}
        };

        class Ship {
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *core;
                Federation::Starfleet::Captain *captain;
            public:
                Ship(int length, int width, std::string name, short maxWarp);
                int getLength() {return this->_length;}
                int getWidth() {return this->_width;}
                std::string getName(){return this->_name;}
                short getMaxWarp(){return this->_maxWarp;}
                void setupCore(WarpSystem::Core *);
                void checkCore();
                void promote(Captain *captain);
        };

        class Ensign{
            private:
                std::string name;
            public:
                explicit Ensign(std::string name);
        };
    }
    class Ship
    {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *core;
        public:
            Ship(int length, int width, std::string name);
            int getLength() {return this->_length;}
            int getWidth() {return this->_width;}
            std::string getName(){return this->_name;}
            short getMaxWarp(){return this->_maxWarp;}
            void setupCore(WarpSystem::Core *);
            void checkCore();
    };
}
