#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

//Tạo/xuất ma trận vuông a chứa số nguyên ngẫu nhiên có cấp n>=5.
void tao_ma_tran(int n, int** a) {
    srand(time_t(NULL));  // Khởi tạo seed cho số ngẫu nhiên
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 100;  // Sinh số ngẫu nhiên từ 0 đến 99
        }
    }
}

void xuat_ma_tran(int n, int** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

//Xuất các phần tử trên đường chéo chính.
void xuat_duong_cheo_chinh(int n, int** a) {
    printf("Duong cheo chinh:\n");
    for (int i = 0; i < n; ++i) {
        printf("%4d ", a[i][i]);
    }
    printf("\n");
}

int main() {
    int n = 5;  // Kích thước của ma trận

    // Cấp phát bộ nhớ cho ma trận
    int** ma_tran = new int* [n];
    for (int i = 0; i < n; ++i) {
        ma_tran[i] = new int[n];
    }

    tao_ma_tran(n, ma_tran);
    printf("Ma tran:\n");
    xuat_ma_tran(n, ma_tran);
    xuat_duong_cheo_chinh(n, ma_tran);
    return 0;
}