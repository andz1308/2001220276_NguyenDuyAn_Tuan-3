#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
// Hàm tạo ma trận vuông a có cấp n và chứa số nguyên ngẫu nhiên
void generateMatrix(int n, int a[][MAX]) {
	time_t now = time(NULL);
	unsigned long long timestamp = static_cast<unsigned long long>(now);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100; // Số nguyên ngẫu nhiên trong khoảng 0-99
		}
	}
}

// Hàm xuất các phần tử trên đường chéo chính của ma trận vuông
void printMainDiagonal(int n, int a[][MAX]) {
	printf("Cac phan tu tren duong cheo chinh:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
	printf("\n");
}

// Hàm xuất các phần tử thuộc đường chéo song song với đường chéo chính
void printSecondaryDiagonal(int n, int a[][MAX]) {
	printf("Cac phan tu tren duong cheo song song voi duong cheo chinh:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i][n - i - 1]);
	}
	printf("\n");
}

// Hàm tìm phần tử lớn nhất thuộc tam giác trên của đường chéo chính
int findMaxAboveMainDiagonal(int n, int a[][MAX]) {
	int max = a[0][1]; // Giả sử phần tử đầu tiên trong tam giác trên là max
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}

// Hàm sắp xếp ma trận theo kiểu zic-zắc
void sortZigZag(int n, int a[][MAX]) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			// Sắp xếp tăng dần
			for (int j = 0; j < n - 1; j++) {
				for (int k = 0; k < n - j - 1; k++) {
					if (a[i][k] > a[i][k + 1]) {
						int temp = a[i][k];
						a[i][k] = a[i][k + 1];
						a[i][k + 1] = temp;
					}
				}
			}
		}
		else {
			// Sắp xếp giảm dần
			for (int j = 0; j < n - 1; j++) {
				for (int k = 0; k < n - j - 1; k++) {
					if (a[i][k] < a[i][k + 1]) {
						int temp = a[i][k];
						a[i][k] = a[i][k + 1];
						a[i][k + 1] = temp;
					}
				}
			}
		}
	}
}

// Hàm sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sortMainDiagonal(int n, int a[][MAX]) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][i] > a[j][j]) {
				int temp = a[i][i];
				a[i][i] = a[j][j];
				a[j][j] = temp;
			}
		}
	}
}

int main() {
	int n= 5;
	int a[5][MAX];

	// Bước 1: Tạo và xuất ma trận vuông a
	generateMatrix(n, a);

	// Bước 2: Xuất các phần tử trên đường chéo chính
	printMainDiagonal(n, a);

	// Bước 3: Xuất các phần tử thuộc đường chéo song song với đường chéo chính
	printSecondaryDiagonal(n, a);

	// Bước 4: Tìm phần tử max thuộc tam giác trên của đường chéo chính
	int maxAboveMainDiagonal = findMaxAboveMainDiagonal(n, a);
	printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", maxAboveMainDiagonal);

	// Bước 5: Sắp xếp ma trận tăng dần theo kiểu zic-zắc
	sortZigZag(n, a);
	printf("Ma tran sau khi sap xep tang dan theo kieu zic-zac:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Bước 6: Sắp xếp đường chéo chính tăng dần từ trên xuống dưới
	sortMainDiagonal(n, a);
	printf("Ma tran sau khi sap xep duong cheo chinh tang dan tu tren xuong duoi:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
