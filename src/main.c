#include <stdio.h>
#include <stdlib.h>

#include "headers/image.h"
#include "headers/file_man.h" // File
#include "headers/image_man.h" // Image manipulation

int main(int argc, char *argv[]) {
	/**
	 * Open and create files */
	// Ensure proper usage
	if (argc != 3) {
		printf("Usage: colorize <infile> <outfile>\n");
		return 1;
	}

	// Open input file
	FILE* inptr = open_file(argv[1], "r");
	if(inptr == NULL) return EXIT_FAILURE;


	// Read infile's BITMAPFILEHEADER
	BITMAPFILEHEADER bf;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

	// Read infile's BITMAPINFOHEADER
	BITMAPINFOHEADER bi;
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

	// Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
	// if(is_bmp(bf, bi) == 1) {
	// 	close_files(inptr, NULL);
	// 	return EXIT_FAILURE;
	// };

	// Create output file after checking if is supported file format
	FILE* outptr = open_file(argv[2], "w");
	if(outptr == NULL) return EXIT_FAILURE;



	/**
	 * Make Image Buffer*/
	int width = bi.biWidth;
	int height = abs(bi.biHeight);

	// int width = 416;
	// int height = 416;

	printf("=> Image size: %dx%d\n", width, height);

	// Allocate memory for image
	RGBTRIPLE (*buffer)[width] = calloc(height, width * sizeof(RGBTRIPLE));
	if(buffer == NULL) {
		printf("Not enough memory to store image buffer\n");
		close_files(inptr, outptr);
		return EXIT_FAILURE;
	}

	// Determine padding for scanlines
	int padding =  (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

	// Iterate over infile's scanlines
	iterate(width, height, padding, buffer, inptr);



	/**
	 * Make changes */
	// colorize(width, height, buffer);
	// random_color(width, height, buffer);
	sort_pixels(width, height, buffer);



	/**
	 *  Write changes and close */
	write_and_close(width, height, padding, buffer, bf, bi, inptr, outptr);
	// write_and_close(image, buffer);

	return 0;
}
