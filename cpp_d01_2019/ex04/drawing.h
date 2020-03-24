/*
** EPITECH PROJECT, 2020
** d01_draw_me_a_square
** File description:
** working on BMP Files + editing a square to the BMP.
*/
#pragma once


#include <stdint.h>
#include <sys/types.h>

typedef struct point_s 
{
    uint32_t x;
    uint32_t y;
} point_t;

void draw_square(uint32_t **img, point_t *origin, size_t size, uint32_t color);
