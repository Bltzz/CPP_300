/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PapaXmasTable.hpp
*/

#if !defined(_TABLE_)
#define _TABLE_

#include <iostream>
#include <array>
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "ITable.hpp"

class PapaXmasTable : public ITable
{
    public:
        PapaXmasTable();
        Object **getTable();
        std::string *Look();
        Object *Take();
        Object *Take(int type);
        bool Put(Object *object);
        void fillStringArray();

    protected:

        std::string _names[11];
        Object *_objOnTable[11];
};
ITable *createTable();

#endif