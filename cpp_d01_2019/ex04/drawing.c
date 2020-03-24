/*
** EPITECH PROJECT, 2020
** d01_draw_me_a_square
** File description:
** working on BMP Files - now drawing a square into the bmp...
*/

#include "drawing.h"

void draw_square(uint32_t **img, point_t *origin, size_t size, uint32_t color){
    for(uint16_t counter_one = 0; counter_one < size; counter_one++){
	for(uint16_t counter_two = 0; counter_two < size; counter_two++){
	    img[origin -> x + counter_one][origin -> y + counter_two] = color;
	}
    } 
}
