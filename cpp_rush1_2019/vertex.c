/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"
#include <stdlib.h>

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static VertexClass *Vertex_add(VertexClass *a, VertexClass *b)
{
    VertexClass *res = new(Vertex, a->x + b->x, a->y + b->y, a->z + b->z);

    return res;
}

static VertexClass *Vertex_minus(VertexClass *a, VertexClass *b)
{
    VertexClass *res = new(Vertex, a->x - b->x, a->y - b->y, a->z - b->z);

    return res;
}

static void Vertex_dtor(VertexClass *this)
{
    free(this);
    return;
}

// Create additional functions here
static char *Vertex_str(VertexClass *this)
{
    size_t len = snprintf(NULL, 0,"<%s (%d, %d, %d)>\n", this->base.__name__,
    this->x, this->y, this->z);
    char *str = malloc(len);
    snprintf(str,len,"<%s (%d, %d, %d)>\n", this->base.__name__,
    this->x, this->y, this->z);
    return str;
}
static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_minus,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Vertex = (const Class *)&_description;