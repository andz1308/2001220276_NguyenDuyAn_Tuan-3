#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

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

// Function to check if a number is odd
int isOdd(int number) {
	return number % 2 != 0;
}

// Function to check if all elements in a column are odd
int allOddInColumn(int matrix[ROWS][COLS], int col) {
	for (int i = 0; i < ROWS; ++i) {
		if (!isOdd(matrix[i][col])) {
			return 0; // Not all elements are odd
		}
	}
	return 1; // All elements are odd
}

// Function to print columns where all elements are odd
void printColumnsWithAllOdd(int matrix[ROWS][COLS]) {
	printf("Cac cot chi chua so le:\n");
	int found = 0; // Flag to check if at least one such column is found
	for (int j = 0; j < COLS; ++j) {
		if (allOddInColumn(matrix, j)) {
			found = 1;
			for (int i = 0; i < ROWS; ++i) {
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	if (!found) {
		printf("Khong co cot nao chi chua so le.\n");
	}
	printf("\n");
}

int main() {
	int matrix[ROWS][COLS];

	// Seed the random number generator
	srand(time(NULL));

	// Generate and print the random matrix
	generateRandomMatrix(matrix);
	printf("Ma tran ngau nhien:\n");
	printMatrix(matrix);

	// 1. Xuất các cột chỉ chứa số lẻ
	printColumnsWithAllOdd(matrix);

	return 0;
}
