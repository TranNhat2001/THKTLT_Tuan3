#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    
#include <conio.h>

#define MAX_RANDOM 100  

// Hàm tạo và xuất ma trận a chứa các phần tử ngẫu nhiên
void generateRandomMatrix(int **a, int m, int n) {
	srand(time_t(NULL));  // Khởi tạo seed cho hàm rand()

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = rand() % (MAX_RANDOM + 1);  // Phần tử ngẫu nhiên từ 0 đến MAX_RANDOM
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm tính và xuất tổng giá trị từng dòng
void sumRows(int **a, int m, int n) {
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += a[i][j];
		}
		printf("Tong gia tri cua dong %d: %d\n", i, sum);
	}
}
// Hàm xuất phần tử lớn nhất trên từng cột
void maxInColumns(int **a, int m, int n) {
	for (int j = 0; j < n; ++j) {
		int max_value = a[0][j];
		for (int i = 1; i < m; ++i) {
			if (a[i][j] > max_value) {
				max_value = a[i][j];
			}
		}
		printf("Phan tu lon nhat tren cot %d: %d\n", j, max_value);
	}
}

// Hàm main 
int main() {
	int m, n;
	printf("Nhap so hang m: ");
	scanf_s("%d", &m);
	printf("Nhap so cot n: ");
	scanf_s("%d", &n);

	// Khởi tạo ma trận a có m dòng và n cột
	int **a = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; ++i) {
		a[i] = (int *)malloc(n * sizeof(int));
	}

	// Gọi hàm tạo và xuất ma trận ngẫu nhiên
	printf("4.1.1.Ma tran ngau nhien a:\n");
	generateRandomMatrix(a, m, n);
	printf("\n");
	// Gọi các hàm khác
	printf("\n4.1.2.\n");
	sumRows(a, m, n);
	printf("\n4.1.3.\n");
	maxInColumns(a, m, n);

	_getch();

}