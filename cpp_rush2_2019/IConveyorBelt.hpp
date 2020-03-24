/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** IConveyorBelt.cpp
*/

#if !defined(_ICB_)
#define _ICB_
#include "Object.hpp"

class IConveyorBelt{
    public:
        virtual Object * Take() = 0;
        virtual bool Put(Object *object) = 0;
        virtual Wrap *IN() = 0;
        virtual bool OUT() = 0;
        virtual std::string const Look() const = 0;
        virtual IConveyorBelt *createConveyorBelt() {return NULL;};
};
#endif