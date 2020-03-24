/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** header for ex01
*/
#include "WarpSystem.hpp"

namespace Borg
{
    class Ship {
        private:
            int _size;
            short _maxWarp;
            WarpSystem::Core *core;
        public:
            Ship();
            short getMaxWarp(){return this->_maxWarp;}
            void setupCore(WarpSystem::Core *core){this->core = core;}
            void checkCore();
    };
}