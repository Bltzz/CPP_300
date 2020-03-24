/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 01
*/

#include <stdarg.h>
#include "new.h"
#include "object.h"
#include "raise.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Object *tmp;
    va_list va_list_passed;

    if (!class)
        raise("No class");
    va_start(va_list_passed, class);
    tmp = va_new(class, &va_list_passed);
    va_end(va_list_passed);
    return tmp;
}

Object *va_new(const Class *class, va_list* ap)
{
    void *tmp;

    if(class == NULL || !(class->__size__))
        raise("Class or size unknown");
    tmp = malloc(class->__size__);
    if(tmp == NULL)
        raise("Memory Allocation failed");
    if (memcpy(tmp, class, class->__size__) == NULL)
        raise("Out  of memory");
    if(tmp == NULL)
        raise("Failes while creating the Object");
    if(((Class *)tmp)->__ctor__ != NULL)
        ((Class *)tmp)->__ctor__(tmp, ap);
    return tmp;
}

void delete(Object *ptr)
{
    if((Class *)ptr != NULL)
        if (((Class *)ptr)->__dtor__)
	        ((Class *)ptr)->__dtor__(ptr);
}