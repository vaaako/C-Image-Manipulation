#pragma once

#include "bmp.h"

// colorize image
void colorize(int width, int height, RGBTRIPLE buffer[height][width]);
void random_color(int width, int height, RGBTRIPLE buffer[height][width]);
void sort_pixels(int width, int height, RGBTRIPLE buffer[height][width]);

