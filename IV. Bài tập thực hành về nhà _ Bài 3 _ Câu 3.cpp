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

// Function to count the occurrences of digit 2 in the matrix
int countDigit2(int matrix[ROWS][COLS]) {
	int count = 0;

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			int number = matrix[i][j];
			while (number > 0) {
				if (number % 10 == 2) {
					count++;
				}
				number /= 10;
			}
		}
	}

	return count;
}

int main() {
	int matrix[ROWS][COLS];

	// Seed the random number generator
	srand(time(NULL));

	// Generate and print the random matrix
	generateRandomMatrix(matrix);
	printf("Ma tran ngau nhien:\n");
	printMatrix(matrix);

	// 3. Dem so lan chu so 2 xuat hien trong ma tran
	int countTwo = countDigit2(matrix);
	printf("So lan chu so 2 xuat hien trong ma tran: %d\n", countTwo);

	return 0;
}
