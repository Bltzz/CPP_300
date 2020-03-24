/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** DomesticKoala.hpp
*/
#pragma once
#include "KoalaAction.hpp"
#include <vector>
#include <iostream>

class DomesticKoala{
    public:
        typedef void(KoalaAction::*methodPointer_t)(const std::string &);
        //using methodPointer_t = void()(const std::string &);//void (const std::string &);
        explicit DomesticKoala(KoalaAction &);
        ~DomesticKoala() {}
        explicit DomesticKoala(const DomesticKoala &);
        DomesticKoala &operator=(const DomesticKoala &);

        const std::vector<methodPointer_t> *getActions() const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);
    protected:
        DomesticKoala();
        KoalaAction _action;
        std::vector<methodPointer_t> _knownAction;
};