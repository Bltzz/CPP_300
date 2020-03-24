/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex00
*/

#include "ex00.h"
#include <stdio.h>
#include <stdlib.h>

static void koala_initializer(koala_t *this, char *name, char is_a_legend){
    printf("----\n");
    this->m_is_a_legend = is_a_legend;
    printf("Building Cthulhu\n");
    this->m_parent.m_name = name;
    this->m_parent.m_power = is_a_legend == 1 ? 42 : 0;
    printf("Building %s\n", this->m_parent.m_name);
}
static void cthulhu_initializer(cthulhu_t *this){
    printf("----\n");
    this->m_name = "Cthulhu";
    this->m_power = 42;
    printf("Building Cthulhu\n");
}

cthulhu_t *new_cthulhu(){
    cthulhu_t *new;

    new = malloc(sizeof(cthulhu_t));
    cthulhu_initializer(new);
    return new;
}

koala_t *new_koala(char *name, char is_a_legend){
    koala_t *new;
    new = malloc(sizeof(koala_t));
    koala_initializer(new, name, is_a_legend);
    return new;
}

void print_power(cthulhu_t *this){
    printf("Power => %i\n", this->m_power);
}

void  attack(cthulhu_t *this){
    if (this->m_power >= 42){
        this->m_power -=42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}
void  sleeping(cthulhu_t *this){
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

void eat(koala_t *this){
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}

/*
int main()
{
    koala_t *_lkoala = new_koala("Legend", 1);
    koala_t *_nlkoala = new_koala("NotLegend", 0);
    cthulhu_t *_cthulhu = new_cthulhu();
    printf("----Start ----\n");
    print_power(_cthulhu);
    print_power (&_lkoala ->m_parent);
    print_power (&_nlkoala ->m_parent);
    attack(_cthulhu);
    attack (&_lkoala ->m_parent);
    attack (&_nlkoala ->m_parent);
    eat(_nlkoala);
    attack(_cthulhu);
    sleeping(_cthulhu);
    print_power(_cthulhu);
    attack (&_nlkoala ->m_parent);
    return 0;
}
*/