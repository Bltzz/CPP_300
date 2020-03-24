/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ITable.hpp
*/
#if !defined(_IT_)
#define _IT_
#include "Object.hpp"

class ITable{
    public:
        virtual Object * Take() = 0;
        virtual Object *Take(int type) = 0;
        virtual bool Put (Object *object) = 0;
        virtual std::string * Look() = 0;
        //virtual ITable *createTable() = 0;
};
#endif