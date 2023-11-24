#include "headers/image.h"

Image* make_image(const BITMAPFILEHEADER bf, const BITMAPINFOHEADER bi, FILE* intptr, FILE* outrptr) {

	int width = bi.biWidth;
	int height = bi.biHeight;

	Image* image = malloc(sizeof(Image));

	// RGBTRIPLE (*tbuffer)[width] = calloc(height, width * sizeof(RGBTRIPLE));
	// image->buffer = tbuffer;


	// if(image == NULL || image->buffer == NULL) return NULL;
	if(image == NULL) return NULL;

	image->width = width;
	image->height = height;
	image->padding = (4 - (image->width * sizeof(RGBTRIPLE)) % 4) % 4;
	
	// image->data = calloc(image->height, image->width * sizeof(RGBTRIPLE));
	// RGBTRIPLE(*data)[image->width] = malloc(sizeof(Image) + image->width * sizeof(RGBTRIPLE));

	image->bf = bf;
	image-> bi = bi;

	image->inptr = intptr;
	image->outptr = outrptr;
	
	return image;
}
