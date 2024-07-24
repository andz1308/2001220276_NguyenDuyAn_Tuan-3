#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5


void generateRandomMatrix(int matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			matrix[i][j] = rand() % 100;  
		}
	}
}

void printMatrix(int matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}


int findMaxOnBoundary(int matrix[ROWS][COLS]) {
	int max = matrix[0][0]; 

	
	for (int j = 0; j < COLS; ++j) {
		if (matrix[0][j] > max) {
			max = matrix[0][j];
		}
	}

	
	for (int j = 0; j < COLS; ++j) {
		if (matrix[ROWS - 1][j] > max) {
			max = matrix[ROWS - 1][j];
		}
	}

	
	for (int i = 1; i < ROWS - 1; ++i) {
		if (matrix[i][0] > max) {
			max = matrix[i][0];
		}
	}

	
	for (int i = 1; i < ROWS - 1; ++i) {
		if (matrix[i][COLS - 1] > max) {
			max = matrix[i][COLS - 1];
		}
	}

	return max;
}

int main() {
	int matrix[ROWS][COLS];

	
	srand(time(NULL));

	
	generateRandomMatrix(matrix);
	printf("Ma tran ngau nhien:\n");
	printMatrix(matrix);

	// 2. Tìm phần tử lớn nhất trên biên của ma trận
	int maxBoundary = findMaxOnBoundary(matrix);
	printf("Phan tu lon nhat tren bien cua ma tran: %d\n", maxBoundary);

	return 0;
}
