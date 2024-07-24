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

// Function to find and print the minimum elements in the matrix
void printMinimumElements(int matrix[ROWS][COLS]) {
	int min = matrix[0][0];

	// Find the minimum element in the matrix
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
	}

	// Print all occurrences of the minimum element
	printf("Cac phan tu cuc tieu cua ma tran:\n");
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (matrix[i][j] == min) {
				printf("%d ", matrix[i][j]);
			}
		}
	}
	printf("\n\n");
}

int main() {
	int matrix[ROWS][COLS];

	// Seed the random number generator
	srand(time(NULL));

	// Generate and print the random matrix
	generateRandomMatrix(matrix);
	printf("Ma tran ngau nhien:\n");
	printMatrix(matrix);

	// 4. Xuất các phần tử cực tiểu của ma trận
	printMinimumElements(matrix);

	return 0;
}
