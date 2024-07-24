#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to generate a random matrix
void generateRandomMatrix(int matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			matrix[i][j] = rand() % 100;  // Random numbers between 0 and 99
		}
	}
}

// Function to print a matrix
void printMatrix(int matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

// Function to swap two rows in a matrix
void swapRows(int matrix[ROWS][COLS], int row1, int row2) {
	for (int j = 0; j < COLS; ++j) {
		int temp = matrix[row1][j];
		matrix[row1][j] = matrix[row2][j];
		matrix[row2][j] = temp;
	}
}

// Function to sort matrix rows (odd rows ascending, even rows descending)
void sortMatrixRows(int matrix[ROWS][COLS]) {
	// Bubble sort
	for (int i = 0; i < ROWS - 1; ++i) {
		for (int j = 0; j < ROWS - i - 1; ++j) {
			// Odd indexed row (i.e., 1st, 3rd, 5th, ...) in ascending order
			if (j % 2 == 0) {
				if (matrix[j][0] > matrix[j + 1][0]) {
					swapRows(matrix, j, j + 1);
				}
			}
			else { // Even indexed row (i.e., 2nd, 4th, 6th, ...) in descending order
				if (matrix[j][0] < matrix[j + 1][0]) {
					swapRows(matrix, j, j + 1);
				}
			}
		}
	}
}

int main() {
	int matrix[ROWS][COLS];

	// Seed the random number generator
	srand(time(NULL));

	// Generate and print the random matrix
	generateRandomMatrix(matrix);
	printf("Ma tran ngau nhien:\n");
	printMatrix(matrix);

	// 5. Sap xep ma tran theo yeu cau: le tang, chan giam
	sortMatrixRows(matrix);
	printf("Ma tran sau khi sap xep:\n");
	printMatrix(matrix);

	return 0;
}
