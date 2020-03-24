/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PapaXmasConveyorBelt.hpp
*/
#if !defined(_CONVOYOR_BLET_)
#define _CONVOYOR_BLET_
#include <iostream>
#include <list>
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"


#include "IConveyorBelt.hpp"

void convert(int kdo, int toy, std::string name);

class PapaXmasConveyorBelt : public IConveyorBelt {
    public:
        PapaXmasConveyorBelt() ;
        //~PapaXmasConveyorBelt() override;
        Object *Take();
        bool isAvailable() {return (_obj == NULL);}
        bool Put(Object *object);
        Wrap *IN();
        bool OUT();
        std::string const Look() const;
    protected:
        Object *_obj;
};
IConveyorBelt *createConveyorBelt();

#endif