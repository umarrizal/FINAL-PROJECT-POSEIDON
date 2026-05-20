#include <stdio.h>

int main() {
    int angka[5] = {1, 4, 7, 10, 20};
    int cari, ketemu = 0;

    printf("Masukkan angka yang dicari: ");
    scanf("%d", &cari);

    for (int i = 0; i < 5; i++) {
        if (angka[i] == cari) {
            printf("Angka %d berhasil ditemukan pada indeks ke-%d!\n", cari, i);
            ketemu = 1;
            break;
        }
    }

    if (!ketemu) {
        printf("Angka %d tidak ditemukan dalam array.\n", cari);
    }

    return 0;
}