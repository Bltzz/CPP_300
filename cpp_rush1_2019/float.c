/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include <stdlib.h>
#include "new.h"

typedef struct
{
    Class base;
    float x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = (float) va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    free(this);
    return;
}

// Create additional functions here
static char *Float_str(FloatClass *this)
{
    char *str;
    size_t len = snprintf(NULL, 0,"%f", this->x);
    str = malloc(len);
    snprintf(str,len,"%f", this->x);
    return str;
}

static FloatClass *Float_addition(FloatClass *Float1, FloatClass *Float2)
{
    Object *tmp = new(Float, Float1->x + Float2->x);

    return tmp;
}

static FloatClass *Float_substraction(FloatClass *Float1, FloatClass *Float2)
{
    Object *tmp = new(Float, Float1->x - Float2->x);

    return tmp;
}

static FloatClass *Float_mul(FloatClass *Float1, FloatClass *Float2)
{
    Object *tmp = new(Float, Float1->x * Float2->x);

    return tmp;
}

static FloatClass *Float_div(FloatClass *Float1, FloatClass *Float2)
{
    Object *tmp;

    if(Float2->x == 0)
        raise("Division by 0 not possible!");
    tmp = new(Float, Float1->x / Float2->x);
    return tmp;
}

static bool Float_eq(FloatClass *Float1, FloatClass *Float2)
{
    return (Float1->x == Float2->x);
}

static bool Float_lt(FloatClass *Float1, FloatClass *Float2)
{
    return (Float1->x < Float2->x);
}

static bool Float_gt(FloatClass *Float1, FloatClass *Float2)
{
    return (Float1->x > Float2->x);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)Float_str,
        .__add__ = (binary_operator_t)Float_addition,
        .__sub__ = (binary_operator_t)Float_substraction,
        .__mul__ = (binary_operator_t)Float_mul,
        .__div__ = (binary_operator_t)Float_div,
        .__eq__ = (binary_comparator_t)Float_eq,
        .__gt__ = (binary_comparator_t)Float_gt,
        .__lt__ = (binary_comparator_t)Float_lt
    },
    .x = 0
};

const Class *Float = (Class *)&_description;