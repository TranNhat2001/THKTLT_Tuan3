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

	_getch();

}