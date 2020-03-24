/*
** EPITECH PROJECT, 2019
** cpp_rush2_2019
** File description:
** Interface for Elf
*/

#if !defined(_IELF_)
#define _IELF_
#include <iostream>
#include "Object.hpp"

class IElf
{
public:
    virtual bool startToWork() = 0;
    virtual std::string const getName() const = 0;

protected:
    virtual bool boxIsAvailable() = 0;
    virtual bool paperIsAvailable() = 0;
    virtual bool toyIsAvailable() = 0;
    virtual bool giftIsAvailable() = 0;
    virtual bool checkSpaceOnTable() = 0;

    virtual std::string *look() = 0;

    virtual Object * takeToy() = 0;
    virtual Object * takeGift() = 0;
    virtual Object * takePaper() = 0;

    virtual void makeAGift() = 0;
    virtual void TakeAWrap() = 0;

};

#endif