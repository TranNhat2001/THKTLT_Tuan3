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

//Xuất các phần tử thuộc đường chéo song song với đường chéo chính.
void xuat_duong_cheo_song_song(int n, int** a) {
    printf("Duong cheo song song:\n");
    for (int k = 1 - n; k < n; ++k) {
        printf("Duong cheo %d:\n", k);
        for (int i = 0; i < n; ++i) {
            int j = i + k;
            if (j >= 0 && j < n) {
                printf("%4d ", a[i][j]);
            }
        }
        printf("\n");
    }
}

//Tìm phần tử max thuộc tam giác trên của đường chéo chính.
int tim_max_tam_giac_tren(int n, int** a) {
    int max = a[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

//Sắp xếp ma trận tăng dần theo kiểu zic-zắc (tăng từ trái qua phải và từ trên xuống dưới).
void sap_xep_zic_zac(int n, int** a) {
    int* temp = (int*)malloc(n * n * sizeof(int));
    int k = 0;

    // Lưu các phần tử vào mảng một chiều
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[k++] = a[i][j];
        }
    }

    // Sắp xếp mảng một chiều bằng thuật toán sắp xếp nổi bọt
    for (int i = 0; i < n * n - 1; ++i) {
        for (int j = i + 1; j < n * n; ++j) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    // Ghi lại vào ma trận theo kiểu zic-zắc
    k = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = temp[k++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; --j) {
                a[i][j] = temp[k++];
            }
        }
    }
    
}

// Hàm sắp xếp đường chéo chính
void sap_xep_duong_cheo_chinh(int n, int** a) {
    // Cấp phát bộ nhớ cho mảng duong_cheo
    int* duong_cheo = (int*)malloc(n * sizeof(int));
    if (duong_cheo == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        return;
    }

    // Lưu các phần tử của đường chéo chính vào mảng
    for (int i = 0; i < n; ++i) {
        duong_cheo[i] = a[i][i];
    }

    // Sắp xếp mảng
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (duong_cheo[i] > duong_cheo[j]) {
                int t = duong_cheo[i];
                duong_cheo[i] = duong_cheo[j];
                duong_cheo[j] = t;
            }
        }
    }

    // Ghi lại vào ma trận
    for (int i = 0; i < n; ++i) {
        a[i][i] = duong_cheo[i];
    }

    // Giải phóng bộ nhớ
    free(duong_cheo);
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
    xuat_duong_cheo_song_song(n, ma_tran);
    int max = tim_max_tam_giac_tren(n, ma_tran);
    printf("Phan tu max trong tam giac tren duong cheo chinh: %d\n", max);
    sap_xep_zic_zac(n, ma_tran);
    printf("Ma tran sau khi sap xep zic-zac:\n");
    xuat_ma_tran(n, ma_tran);
    sap_xep_duong_cheo_chinh(n, ma_tran);
    printf("Ma tran sau khi sap xep duong cheo chinh:\n");
    xuat_ma_tran(n, ma_tran);
    return 0;
}