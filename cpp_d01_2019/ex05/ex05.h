/*
** EPITECH PROJECT, 2020
** d01_fork_this_seriously
** File description:
** get to know sizes, unions and structs 
*/

#include <stdint.h>
#pragma once

typedef union bar
{
    uint16_t foo;
    uint16_t bar;
} bar_t;

typedef struct struct_s
{
    uint16_t foo;
    bar_t bar;
} struct_t;

typedef union foo_s
{
    uint32_t bar;
    struct_t foo;
} foo_t;

