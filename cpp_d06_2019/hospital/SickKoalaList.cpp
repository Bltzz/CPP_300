/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** ex05
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala){
    this->koala = koala;
    this->next = NULL;
}
SickKoalaList::~SickKoalaList(){
}

bool SickKoalaList::isEnd(){
    return (this->next == NULL);
}

void SickKoalaList::append(SickKoalaList *list){
    SickKoalaList *tmp = this;

    // if (this == NULL){
    //     this->koala = list->koala;
    //     this->next = list->next;
    // }
    while (tmp->next != NULL && tmp != NULL)
        tmp = tmp->next;
    tmp->next = list;
}

SickKoalaList SickKoalaList::remove(SickKoalaList *list){
    SickKoalaList *tmp = this;
    SickKoalaList *to_remove;

    if (tmp != NULL){
        if (tmp == list)
            tmp = NULL;
        while (tmp->next != NULL && tmp->next != list) {
            tmp = tmp->next;
        }
        if (tmp->next != NULL && tmp->next == list){
            to_remove = tmp->next;
            tmp->next = to_remove->next;
            to_remove->koala = NULL;
            to_remove = NULL;
        }
    }
    return *this;
}

SickKoalaList SickKoalaList::removeFromName(std::string name){
    SickKoalaList *tmp;
    SickKoalaList *to_remove;

    tmp = this;
    if (tmp != NULL){
        while ((tmp->next != NULL && tmp->koala->getName() != name && tmp->next->koala->getName() != name) || tmp->next->koala == NULL) {
            tmp = tmp->next;
        }
        if (tmp->next != NULL && tmp->next->koala->getName() == name){
            to_remove = tmp->next;
            tmp->next = to_remove->next;
            to_remove->koala = NULL;
            to_remove = NULL;
        }
    }
    return *this;
}

SickKoala *SickKoalaList::getContent(){
    return (this->koala);
}

SickKoalaList *SickKoalaList::getNext(){
    return (this->next);
}
void SickKoalaList::dump(){
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    while (tmp != NULL){
        if (tmp->koala == NULL)
            std::cout << "[nullptr]";
        else std::cout << tmp->koala->getName();
        if (tmp->next != NULL)
            std::cout << ", ";
        else std::cout << ". " <<std::endl;
        tmp = tmp->next;
    }
}

int main(){
    size_t tmp = 12345;
    KoalaDoctor KD("TOM");
    //KoalaNurse *KN1 = new KoalaNurse(tmp);
    SickKoala *K1 = new SickKoala("Steve");
    SickKoala *K2 = new SickKoala("Vladi");
    SickKoalaList KL(K1);
    SickKoalaList KL2(K2);
    KL.append(&KL2);

    KL.dump();
    //delete KN1;
    delete K1;
    return 0;
}