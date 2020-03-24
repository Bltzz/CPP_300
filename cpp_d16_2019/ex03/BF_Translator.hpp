/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** BF_Translator.hpp
*/

#ifndef BF_TRANSLATOR_HPP
    #define BF_TRANSLATOR_HPP

#include <unordered_map>
#include <iostream>
#include <fstream>

class BF_Translator{
typedef void (BF_Translator::*bf_command)();
    public:
        BF_Translator();
        ~BF_Translator() {}

        int translate(std::string const &, std::string const &);
    private:
        void writeHeader();
        void writeEndOfFile();

        void incrPtr();
        void decrPtr();
        void mvPtrForward();
        void mvPtrBack();
        void printToStdOut();
        void readFromInput();
        void jumpToInstr();
        void jumpToMatching();

    private:
        std::fstream in;
        std::fstream out;
        std::unordered_map<char, bf_command> func;
};

#endif  //BF_TRANSLATOR_HPP//