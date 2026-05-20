#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matriks1[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriks2[ROWS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int hasil[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }

    printf("Matriks 1:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matriks1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks 2:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matriks2[i][j]);
        }
        printf("\n");
    }

    printf("\nHasil Penjumlahan Matriks:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }

    return 0;
}