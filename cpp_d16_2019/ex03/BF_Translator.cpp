/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** BF_Translator.cpp
*/
#include "BF_Translator.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <exception>

//constr: defining hash-Map a.k.a. unsorteded map
BF_Translator::BF_Translator(){
    func['+'] = &BF_Translator::incrPtr;
    func['-'] = &BF_Translator::decrPtr;
    func['>'] = &BF_Translator::mvPtrForward;
    func['<'] = &BF_Translator::mvPtrBack;
    func['.'] = &BF_Translator::printToStdOut;
    func[','] = &BF_Translator::readFromInput;
    func['['] = &BF_Translator::jumpToInstr;
    func[']'] = &BF_Translator::jumpToMatching;
}

int BF_Translator::translate(std::string const &_in, std::string const &_out){
    try{
        bf_command command;
        char com;

        this->in.open(_in.data(), std::ios::in);
        this->out.open(_out.data(), std::ios::trunc | std::ios::out);
        if (!this->in.is_open() || !this->out.is_open())
            throw std::runtime_error("Not openable");
        writeHeader();
        while (!this->in.eof()){
            //read char  by char
            com = this->in.get();
            command = func[com];

            if (command)
                (this->*command)();
            else if(!isspace(com) && com != (-1))
                throw std::invalid_argument("invalid Argument");
        }
        writeEndOfFile();
        this->out.flush();
        this->out.close();
        this->in.close();
        return 0;
    } catch (...) {
        this->in.close();
        this->out.close();
        return (-42);
    }
}

void BF_Translator::writeHeader(){
	out << "#include <stdio.h>\n"
        << "#define MEMORY_MAX 60*1024\n\n"
		<< "int main(void) {\n"
		<< "char array[MEMORY_MAX] = {0};\n"
        << "char *ptr=array;\n";
}

void BF_Translator::incrPtr(){
    out << "++*ptr;\n";
}

void BF_Translator::decrPtr(){
    out << "--*ptr;\n";
}

void BF_Translator::mvPtrForward(){
    out << "++ptr;\n";
}

void BF_Translator::mvPtrBack(){
    out << "--ptr;\n";
}

void BF_Translator::printToStdOut(){
    out << "putchar(*ptr);\n";
}

void BF_Translator::readFromInput(){
    out << "*ptr=getchar();\n";
}

void BF_Translator::jumpToInstr(){
    out << "while (*ptr){;\n";
}

void BF_Translator::jumpToMatching(){
    out << "};\n";
}

void BF_Translator::writeEndOfFile(){
    out << "}\n //have fun with you NOW readable Code :)";
}
