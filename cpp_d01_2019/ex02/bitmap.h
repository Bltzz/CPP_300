/*
** EPITECH PROJECT, 2020
** d01_The_BMP_Format
** File description:
** working on BMP Files
*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#pragma once

typedef struct __attribute__((packed)) bmp_header_s {
    uint16_t magic;              // Magic identifier: 0x4d42
    uint32_t size;              // File size in bytes
    uint16_t _app1;         // Not used
    uint16_t _app2;         // Not used
    uint32_t offset;            // Offset to image data in bytes from beginning of file
} bmp_header_t;

typedef struct __attribute__((packed)) bmp_info_header_s {
    int32_t size;
    int32_t width;
    int32_t height;
    int16_t planes;
    int16_t bpp;
    int32_t compression;
    int32_t raw_data_size;
    int32_t h_resolution;
    int32_t v_resolution;
    uint32_t palette_size;
    uint32_t important_colors;
} bmp_info_header_t;

void  make_bmp_header(bmp_header_t *header , size_t  size);
void  make_bmp_info_header(bmp_info_header_t *header , size_t  size);


