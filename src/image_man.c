#include "headers/image_man.h"
#include "headers/bmp.h"

#include <complex.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int row[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (row[j] > row[j + 1]) {
				// Swap the elements if they are in the wrong order
				int temp = row[j];
				row[j] = row[j + 1];
				row[j + 1] = temp;
			}
		}
	}
}

void printArray(int arr[][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}




void colorize(int width, int height, RGBTRIPLE buffer[height][width]) {
	// Change all black pixels to a color of your choosing
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			buffer[i][j].rgbtBlue  = 202 / 255;
			// buffer[i][j].rgbtGreen = 23 / 255;
			// buffer[i][j].rgbtRed   = 115 / 255;
			// printf(" %dx%d", i, j);
		}
	}

	// printf("\n");
}


void random_color(int width, int height, RGBTRIPLE buffer[height][width]) {
	srand(time(NULL));
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			// buffer[height - i][width - j] = buffer[i][j];
			switch (rand() % 3 + 1) {
				case 1:
					buffer[i][j].rgbtRed   = rand() % 255 + 1;
					break;
				case 2:
					buffer[i][j].rgbtGreen = rand() % 255 + 1;
					break;
				case 3:
					buffer[i][j].rgbtBlue  = rand() % 255 + 1;
					break;
			}
			
			// buffer[i][j].rgbtRed   = rand() % 255 + 1;
			// buffer[i][j].rgbtGreen = rand() % 255 + 1;
			// buffer[i][j].rgbtBlue  = rand() % 255 + 1;
			// printf(" %dx%d / %dx%d", height - i, width - j, i, j);
		}
	}

}

void sort_pixels(int width, int height, RGBTRIPLE buffer[height][width]) {
	int sorted[height][width];
	// int sorted[width][height]; // To sort vertically

	// int color_total = 0;
	for(int i = 0; i < height; i++) {
		// printf("color_total: %d\n", color_total);
		for(int j = 0; j < width; j++) {
			int color_total = 0;

			/* Half upside down */
			// buffer[height - i][width - j] = buffer[i][j];
			// buffer[i][j] = buffer[height - i][width - j];

			// buffer[i][j] = buffer[height - i][j]; // Water reflex
			// buffer[height - i][j] = buffer[i][j]; // Bottom reflex

			// buffer[i][width - j] = buffer[i][j]; // ojjo
			// buffer[i][j] = buffer[i][width - j]; // ojjo

			// buffer[i][j] = buffer[rand() % height + 1][rand() % width + 1];
			// buffer[rand() % height + 1][rand() % width + 1] = buffer[i][j];

			
			/* Normal */
			color_total += buffer[i][j].rgbtRed;
			color_total += buffer[i][j].rgbtGreen;
			color_total += buffer[i][j].rgbtBlue; 

			/* Upside down */
			// color_total += buffer[height - i][j].rgbtRed;
			// color_total += buffer[height - i][j].rgbtGreen;
			// color_total += buffer[height - i][j].rgbtBlue; 

			/* Damage (1 - High damage / 3 - No damage) */
			// sorted[i][j] = color_total;
			// sorted[i][j] = color_total / 3;

			// printf(" %dx%d / %dx%d", height - i, width - j, i, j);
		}
	}

	/* Sort pixels */
	// for(int i = 0; i < height; i++) {
	// 	bubbleSort(sorted[i], width);
	// }


	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			// buffer[i][j].rgbtRed = sorted[i][j];
			// buffer[i][j].rgbtGreen = sorted[i][j];
			// buffer[i][j].rgbtBlue = sorted[i][j];

			/* Magenta effect */
			// buffer[i][j].rgbtRed = sorted[i][j] / 1;
			// buffer[i][j].rgbtGreen = sorted[i][j] / 3;
			// buffer[i][j].rgbtBlue = sorted[i][j] / 2;

			/* Cool purple effect */
			buffer[i][j].rgbtRed = sorted[i][j] / 2;
			buffer[i][j].rgbtGreen = sorted[i][j] / 3;
			buffer[i][j].rgbtBlue = sorted[i][j];
		}
	}
}


