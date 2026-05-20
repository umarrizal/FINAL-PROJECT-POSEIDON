#include <stdio.h>

int main() {
    int R, C;
    
    printf("Masukkan ukuran Booster Box (R C): ");
    scanf("%d %d", &R, &C);
    
    if (R < 2 || C < 2) {
        printf("Ukuran box terlalu kecil! Standar Cluster Emas minimal 2x2.\n");
        return 0;
    }
    
    float box[R][C];
    
    printf("Masukkan berat pack (gram):\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%f", &box[i][j]);
        }
    }
    

    float maxSum = -1.0;
    int bestRow = 0, bestCol = 0;
    
    for (int i = 0; i <= R - 2; i++) {
        for (int j = 0; j <= C - 2; j++) {
            float sum = box[i][j] + box[i][j+1] +
                        box[i+1][j] + box[i+1][j+1];
            if (sum > maxSum) {
                maxSum = sum;
                bestRow = i;
                bestCol = j;
            }
        }
    }
    
    printf("Cluster Emas ditemukan pada (Baris %d, Kolom %d)!\n", bestRow, bestCol);
    printf("Total Berat: %.2f gram\n", maxSum);
    printf("Isi Cluster:\n");
    printf("%.2f %.2f\n", box[bestRow][bestCol], box[bestRow][bestCol+1]);
    printf("%.2f %.2f\n", box[bestRow+1][bestCol], box[bestRow+1][bestCol+1]);
    
    return 0;
}