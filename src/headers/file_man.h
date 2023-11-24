#pragma once

#include "bmp.h"
#include "image.h"
#include <stdio.h>

/* IO */
void close_files(FILE* inptr, FILE* outrptr);
FILE* open_file(const char* file_dir, const char* protocol);

/* Image Checks */
// int is_bmp(const Image image);
int is_bmp(const BITMAPFILEHEADER bf, const BITMAPINFOHEADER bi);
void iterate(const int width, const int height, const int padding, RGBTRIPLE buffer[height][width], FILE* inptr);
void write_and_close(const int width, const int height, const int padding, RGBTRIPLE buffer[height][width], BITMAPFILEHEADER bf, BITMAPINFOHEADER bi, FILE* inptr, FILE* outptr);


// void iterate(Image* image);
// void write_and_close(Image* image);
