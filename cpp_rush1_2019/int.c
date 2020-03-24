/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"
#include <stdlib.h>
#include "new.h"

typedef struct
{
    Class base;
    int x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    free(this);
    return;
}

// Create additional functions here
static char *Int_str(IntClass *this)
{
    char *str;
    size_t len = snprintf(NULL, 0,"%d", this->x);
    str = malloc(len);
    snprintf(str,len,"%d", this->x);
    return str;
}

static IntClass *Int_addition(IntClass *Int1, IntClass *Int2)
{
    Object *tmp = new(Int, Int1->x + Int2->x);

    return tmp;
}

static IntClass *Int_substraction(IntClass *Int1, IntClass *Int2)
{
    Object *tmp = new(Int, Int1->x - Int2->x);

    return tmp;
}

static IntClass *Int_mul(IntClass *Int1, IntClass *Int2)
{
    Object *tmp = new(Int, Int1->x * Int2->x);

    return tmp;
}

static IntClass *Int_div(IntClass *Int1, IntClass *Int2)
{
    Object *tmp;
    if(Int2->x == 0)
        raise("Division by 0 not possible!");
    tmp = new(Int, Int1->x / Int2->x);

    return tmp;
}

static bool Int_eq(IntClass *Int1, IntClass *Int2)
{
    return (Int1->x == Int2->x);
}
static bool Int_lt(IntClass *Int1, IntClass *Int2)
{
    return (Int1->x < Int2->x);
}

static bool Int_gt(IntClass *Int1, IntClass *Int2)
{
    return (Int1->x > Int2->x);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)Int_str,
        .__add__ = (binary_operator_t)Int_addition,
        .__sub__ = (binary_operator_t)Int_substraction,
        .__mul__ = (binary_operator_t)Int_mul,
        .__div__ = (binary_operator_t)Int_div,
        .__eq__ = (binary_comparator_t)Int_eq,
        .__gt__ = (binary_comparator_t)Int_gt,
        .__lt__ = (binary_comparator_t)Int_lt
    },
    .x = 0
};

const Class *Int = (Class *)&_description;