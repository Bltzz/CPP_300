/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** ex00
*/

#pragma once

namespace WarpSystem {
    class QuantumReactor
    {
        private:
            bool _stability;
        public:
            QuantumReactor();
            bool isStable(){return this->_stability;}
            void setStability(bool stability);
    };
    class Core
    {
        private:
            QuantumReactor *_coreReactor;
        public:
            Core(QuantumReactor *coreReactor);
            QuantumReactor *checkReactor(){return this->_coreReactor;}
    };
}