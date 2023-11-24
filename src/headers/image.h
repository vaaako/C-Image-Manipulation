#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"


typedef struct {
	int width;
	int height;
	int padding;
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	FILE* inptr;
	FILE* outptr;
	// RGBTRIPLE (*buffer)[];
} Image;

Image* make_image(const BITMAPFILEHEADER bf, const BITMAPINFOHEADER bi, FILE* intptr, FILE* outrptr);
