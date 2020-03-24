/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"
#include <stdlib.h>
#include "new.h"

typedef struct
{
    Class base;
    char x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = (char) va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    free(this);
    return;
}

// Create additional functions here
static char *Char_str(CharClass *this)
{
    char *str;
    size_t len = snprintf(NULL, 0,"%c", this->x);
    str = malloc(len);

    snprintf(str,len,"%c", this->x);
    return str;
}

static CharClass *Char_addition(CharClass *Char1, CharClass *Char2)
{
    Object *tmp = new(Char, Char1->x + Char2->x);

    return tmp;
}

static CharClass *Char_substraction(CharClass *Char1, CharClass *Char2)
{
    Object *tmp = new(Char, Char1->x - Char2->x);

    return tmp;
}

static CharClass *Char_mul(CharClass *Char1, CharClass *Char2)
{
    Object *tmp = new(Char, Char1->x * Char2->x);

    return tmp;
}

static CharClass *Char_div(CharClass *Char1, CharClass *Char2)
{
    Object *tmp;
    if(Char2->x == 0)
        raise("Division by 0 not possible!");
    tmp = new(Char, Char1->x / Char2->x);

    return tmp;
}

static bool Char_eq(CharClass *Char1, CharClass *Char2)
{
    return (Char1->x == Char2->x);
}

static bool Char_lt(CharClass *Char1, CharClass *Char2)
{
    return (Char1->x < Char2->x);
}

static bool Char_gt(CharClass *Char1, CharClass *Char2)
{
    return (Char1->x > Char2->x);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)Char_str,
        .__add__ = (binary_operator_t)Char_addition,
        .__sub__ = (binary_operator_t)Char_substraction,
        .__mul__ = (binary_operator_t)Char_mul,
        .__div__ = (binary_operator_t)Char_div,
        .__eq__ = (binary_comparator_t)Char_eq,
        .__gt__ = (binary_comparator_t)Char_gt,
        .__lt__ = (binary_comparator_t)Char_lt
    },
    .x = 0
};

const Class *Char = (Class *)&_description;