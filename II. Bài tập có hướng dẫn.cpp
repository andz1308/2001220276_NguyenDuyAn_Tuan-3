#include <stdio.h>
#include <conio.h>
#define MAX 100
int GTNN_DongI(int a[][100], int m, int n, int dong) {
	// Hàm tìm giá trị nhỏ nhất trên dòng dong của ma trận a
	int min = a[dong][0];
	for (int j = 1; j < n; j++) {
		if (a[dong][j] < min) {
			min = a[dong][j];
		}
	}
	return min;
}

int GTLN_CotJ(int a[][100], int m, int n, int cot) {
	// Hàm tìm giá trị lớn nhất trên cột cot của ma trận a
	int max = a[0][cot];
	for (int i = 1; i < m; i++) {
		if (a[i][cot] > max) {
			max = a[i][cot];
		}
	}
	return max;
}

int GTLN_DongI(int a[][100], int m, int n, int dong) {
	// Hàm tìm giá trị lớn nhất trên dòng dong của ma trận a
	int max = a[dong][0];
	for (int j = 1; j < n; j++) {
		if (a[dong][j] > max) {
			max = a[dong][j];
		}
	}
	return max;
}

int GTNN_CotJ(int a[][100], int m, int n, int cot) {
	// Hàm tìm giá trị nhỏ nhất trên cột cot của ma trận a
	int min = a[0][cot];
	for (int i = 1; i < m; i++) {
		if (a[i][cot] < min) {
			min = a[i][cot];
		}
	}
	return min;
}

//a.Giải thuật tìm phần tử điểm yên ngựa của ma trận a.
void timDiemYenNgua(int a[][100], int m, int n) {
	for (int i = 0; i<m; i++)
	for (int j = 0; j<n; j++)
	if ((a[i][j] == GTNN_DongI(a, m, n, i) && a[i][j] == GTLN_CotJ(a, m, n, j))
		|| (a[i][j] == GTLN_DongI(a, m, n, i) && a[i][j] == GTNN_CotJ(a, m, n, j)))
		printf("%5d", a[i][j]);
}
//b.Giải thuật tìm phần tử hoàng hậu của mảng a
int xetDuongCheo(int a[][100], int dong, int cot, int i, int j) {
	int k, h; //k: dong, h: cot
	for (k = i, h = j; k >= 0 && h<cot; k--, h++)
	if (a[k][h] > a[i][j])
		return 0;
	for (k = i + 1, h = j - 1; k<dong && h >= 0; k++, h--)
	if (a[k][h] > a[i][j])
		return 0;
	for (k = i - 1, h = j - 1; k >= 0 && h >= 0; k--, h--)
	if (a[k][h] > a[i][j])
		return 0;
	for (k = i + 1, h = j + 1; k<dong && h<cot; k++, h++)
	if (a[k][h] > a[i][j])
		return 0;
	return 1;
}
int xetCotDong(int a[][100], int dong, int cot, int i, int j) {
	for (int k = 0; k<dong; k++)
	if (a[k][j]>a[i][j])
		return 0;
	for (int k = 0; k<cot; k++)
	if (a[i][k]>a[i][j])
		return 0;
	return 1;
}
int xetTongQuat(int a[][MAX], int dong, int cot, int i, int j) {
	if (xetCotDong(a, dong, cot, i, j) == 1)
	if (xetDuongCheo(a, dong, cot, i, j) == 1)
		return 1;
	return 0;
}

int main() {
	int a[MAX][MAX];
	int m, n;

	// Nhập số hàng và số cột của ma trận
	printf("Nhap so hang m: ");
	scanf_s("%d", &m);
	printf("Nhap so cot n: ");
	scanf_s("%d", &n);

	// Nhập ma trận a
	printf("Nhap ma tran %dx%d:\n", m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}

	// Tìm và in ra các phần tử điểm yên ngựa của ma trận a
	printf("Cac phan tu diem yen ngua cua ma tran la: ");
	timDiemYenNgua(a, m, n);
	printf("\n");

	// Tìm và in ra các phần tử hoàng hậu của ma trận a
	printf("Cac phan tu hoang hau cua ma tran la:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (xetTongQuat(a, m, n, i, j)) {
				printf("a[%d][%d] = %d\n", i, j, a[i][j]);
			}
		}
	}

	return 0;
}