/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include <stdlib.h>
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    free(this);
    return;
}

// Create additional functions here
static char *Point_str(PointClass *this)
{
    char *str;
    size_t len = snprintf(NULL, 0,"<%s (%d, %d)>\n", this->base.__name__, this->x, this->y);
    str = malloc(len);
    snprintf(str,len,"<%s (%d, %d)>\n", this->base.__name__, this->x, this->y);
    return str;
}

static PointClass *Point_addition(PointClass *point1, PointClass *point2)
{
    Object *tmp = new(Point, point1->x + point2->x, point1->y + point2->y);

    return tmp;
}

static PointClass *Point_substraction(PointClass *point1, PointClass *point2)
{
    Object *tmp = new(Point, point1->x - point2->x, point1->y - point2->y);

    return tmp;
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)Point_str,
        .__add__ = (binary_operator_t)Point_addition,
        .__sub__ = (binary_operator_t)Point_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (Class *)&_description;