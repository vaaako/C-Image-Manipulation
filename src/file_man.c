#include "headers/file_man.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void close_files(FILE* inptr, FILE* outrptr) {
void close_files(FILE* inptr, FILE* outrptr) {
	fclose(inptr);
	if(outrptr != NULL) fclose(outrptr); // Just close if is not null
}


FILE* open_file(const char* file_dir, const char* protcol) {
	FILE* fileptr = fopen(file_dir, protcol);
	if(fileptr == NULL) {
		printf(
			(strcmp(protcol, "W")==0) ? "Could not create" : "Could not open %s\n", // If protocol is "w" change message
			file_dir);
		return NULL;
	}

	return fileptr;
}

int is_bmp(const BITMAPFILEHEADER bf, const BITMAPINFOHEADER bi) {
	if(bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
		bi.biBitCount != 24 || bi.biCompression != 0) {
		// close_files(inptr, outptr);
		printf("Unsupported file format\n");
		return 1;
	}

	return 0;
}


void iterate(const int width, const int height, const int padding, RGBTRIPLE buffer[height][width], FILE* inptr) {
	// Iterate over infile's scanlines
	for(int i = 0; i < height; i++) {	
		fread(buffer[i], sizeof(RGBTRIPLE), width, inptr); // Read row into pixel array
		fseek(inptr, padding, SEEK_CUR); // Skip over padding
	}
}


void write_and_close(const int width, const int height, const int padding, RGBTRIPLE buffer[height][width], BITMAPFILEHEADER bf, BITMAPINFOHEADER bi, FILE* inptr, FILE* outptr) {
	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr); // Write outfile's BITMAPFILEHEADER
	fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr); // Write outfile's BITMAPINFOHEADER

	// Write new pixels to outfile
	for(int i = 0; i < height; i++) {
		// Write row to outfile
		fwrite(buffer[i], sizeof(RGBTRIPLE), width, outptr);

		// Write padding at end of row
		for(int k = 0; k < padding; k++) {
			fputc(0x00, outptr);
		}
	}

	
	free(buffer); // Free memory for image
	close_files(inptr, outptr);
}
