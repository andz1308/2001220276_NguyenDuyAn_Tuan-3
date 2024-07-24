#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Hàm tạo ma trận ngẫu nhiên từ 0 đến k
void TaoMaTran(int a[][MAX], int m, int n, int k) {
	srand(time(NULL)); // Khởi tạo seed cho hàm rand()

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (k + 1);
		}
	}
}

// Hàm xuất ma trận
void XuatMaTran(int a[][MAX], int m, int n) {
	printf("Ma tran %dx%d:\n", m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm tính và xuất tổng giá trị từng dòng
void TongDong(int a[][MAX], int m, int n) {
	printf("\nTong gia tri tung dong:\n");
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		printf("Tong dong %d: %d\n", i + 1, sum);
	}
}

// Hàm xuất phần tử lớn nhất trên từng cột
void MaxCot(int a[][MAX], int m, int n) {
	printf("\nPhan tu lon nhat tren tung cot:\n");
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Cot %d: %d\n", j + 1, max);
	}
}

// Hàm xuất các phần tử ở biên trên, dưới, trái, phải của ma trận
void BienTranPhaiTraiDuoi(int a[][MAX], int m, int n) {
	printf("\nCac phan tu tren bien:\n");
	for (int j = 0; j < n; j++) {
		printf("%5d", a[0][j]); // Biên trên
	}
	for (int i = 1; i < m; i++) {
		printf("%5d", a[i][n - 1]); // Biên phải
	}
	if (m > 1) {
		for (int j = n - 2; j >= 0; j--) {
			printf("%5d", a[m - 1][j]); // Biên dưới
		}
	}
	if (n > 1 && m > 2) {
		for (int i = m - 2; i > 0; i--) {
			printf("%5d", a[i][0]); // Biên trái
		}
	}
	printf("\n");
}

// Hàm kiểm tra phần tử có phải là cực đại không
int LaCucDai(int a[][MAX], int m, int n, int i, int j) {
	int isMax = 1;
	if (i > 0 && a[i][j] <= a[i - 1][j]) {
		isMax = 0;
	}
	if (i < m - 1 && a[i][j] <= a[i + 1][j]) {
		isMax = 0;
	}
	if (j > 0 && a[i][j] <= a[i][j - 1]) {
		isMax = 0;
	}
	if (j < n - 1 && a[i][j] <= a[i][j + 1]) {
		isMax = 0;
	}
	return isMax;
}

// Hàm xuất các phần tử cực đại
void CacCucDai(int a[][MAX], int m, int n) {
	printf("\nCac phan tu cuc dai:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (LaCucDai(a, m, n, i, j)) {
				printf("%5d", a[i][j]);
			}
			else {
				printf("     ");
			}
		}
	}
	printf("\n");
}

// Hàm kiểm tra phần tử có phải là hoàng hậu không
int LaHoangHau(int a[][MAX], int m, int n, int i, int j) {
	int isQueen = 1;
	for (int k = 0; k < m; k++) {
		if (a[k][j] > a[i][j]) {
			isQueen = 0;
			break;
		}
	}
	if (isQueen) {
		for (int k = 0; k < n; k++) {
			if (a[i][k] > a[i][j]) {
				isQueen = 0;
				break;
			}
		}
	}
	return isQueen;
}

// Hàm xuất các phần tử hoàng hậu
void CacHoangHau(int a[][MAX], int m, int n) {
	printf("\nCac phan tu hoang hau:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (LaHoangHau(a, m, n, i, j)) {
				printf("%5d", a[i][j]);
			}
			else {
				printf("     ");
			}
		}
	}
	printf("\n");
}

// Hàm kiểm tra phần tử có phải là điểm yên ngựa không
int LaDiemYenNgua(int a[][MAX], int m, int n, int i, int j) {
	int isSaddle = 1;
	if (a[i][j] != a[i][j]) {
		isSaddle = 0;
	}
	if (a[i][j] != a[i][j]) {
		isSaddle = 0;
	}
	return isSaddle;
}

// Hàm xuất các phần tử là điểm yên ngựa
void CacDiemYenNgua(int a[][MAX], int m, int n) {
	printf("\nCac phan tu diem yen ngua:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (LaDiemYenNgua(a, m, n, i, j)) {
				printf("%5d", a[i][j]);
			}
			else {
				printf("     ");
			}
		}
	}
	printf("\n");
}

// Hàm xuất các phần tử thuộc dòng chỉ chứa số chẵn
void DongChiChuaSoChan(int a[][MAX], int m, int n) {
	printf("\nDong chi chua so chan:\n");
	for (int i = 0; i < m; i++) {
		int allEven = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				allEven = 0;
				break;
			}
		}
		if (allEven) {
			for (int j = 0; j < n; j++) {
				printf("%5d", a[i][j]);
			}
			printf("\n");
			return; // Chỉ cần in ra dòng đầu tiên chứa số chẵn
		}
	}
}

// Hàm sắp xếp các dòng của mảng tăng dần
void SapXepTangTheoDong(int a[][MAX], int m, int n) {
	printf("\nMa tran sau khi sap xep tang theo tung dong:\n");
	for (int i = 0; i < m; i++) {
		// Sắp xếp mảng con từ a[i][0] đến a[i][n-1]
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i][j] > a[i][k]) {
					// Hoán đổi giá trị
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}

	// In ma trận sau khi sắp xếp
	XuatMaTran(a, m, n);
}

int main() {
	int m, n, k;

	printf("Nhap so hang m: ");
	scanf_s("%d", &m);
	printf_s("Nhap so cot n: ");
	scanf_s("%d", &n);
	printf("Nhap gia tri ngau nhien toi da k: ");
	scanf_s("%d", &k);

	int a[MAX][MAX];

	// Tạo và xuất ma trận ngẫu nhiên
	TaoMaTran(a, m, n, k);
	XuatMaTran(a, m, n);

	// Tính và xuất tổng giá trị từng dòng
	TongDong(a, m, n);

	// Xuất phần tử lớn nhất trên từng cột
	MaxCot(a, m, n);

	// Xuất các phần tử ở biên trên, dưới, trái, phải của ma trận
	BienTranPhaiTraiDuoi(a, m, n);

	// Xuất các phần tử cực đại
	CacCucDai(a, m, n);

	// Xuất các phần tử hoàng hậu
	CacHoangHau(a, m, n);

	// Xuất các phần tử là điểm yên ngựa
	CacDiemYenNgua(a, m, n);

	// Xuất dòng chỉ chứa số chẵn
	DongChiChuaSoChan(a, m, n);

	// Sắp xếp mảng theo từng dòng và xuất kết quả
	SapXepTangTheoDong(a, m, n);

	return 0;
}
