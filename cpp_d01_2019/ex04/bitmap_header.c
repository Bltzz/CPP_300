/*
 * EPITECH PROJECT , 2019
 * The BMP Format
 * File description :
 * basic try to get a rough idea of how BMP works
*/

#include <stdio.h>
#include <string.h>  // for strlen, strcopy
#include <stdlib.h>  // for malloc
#include <unistd.h>
#include "bitmap.h"

// Values for the header
#define MAGIC_VALUE         0x4D42 


void  make_bmp_header(bmp_header_t *header , size_t  size)
{
      header->magic = MAGIC_VALUE;
      header->size = size*size*3 + sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
      header->_app1 = 0;
      header->_app2 = 0;
      header->offset = 0;

}

void  make_bmp_info_header(bmp_info_header_t *header , size_t  size)
{
      header->size = 40;
      header->width = size;
      header->height = size;
      header->planes = 0;
      header->bpp = 32;
      header->compression = 0;
      header->raw_data_size = 0;
      header->h_resolution = 0;
      header->v_resolution = 0;
      header->palette_size = 1;
      header->important_colors = 0;
    if (header->width != header->height){
    	write(2,"Lenght must be equal to width.",30);
    }
}
