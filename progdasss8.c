#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;

    int *arr = (int *) calloc(n, sizeof(int));
    if (arr == NULL) { printf("Alokasi gagal!\n"); return 1; }

    printf("Isi awal (calloc): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);  
    printf("\n");

    arr[0] = 5; arr[1] = 10; arr[2] = 15;


    int new_n = 5;
    arr = (int *) realloc(arr, new_n * sizeof(int));
    if (arr == NULL) { printf("Realloc gagal!\n"); return 1; }

    arr[3] = 20; arr[4] = 25;

    printf("Isi setelah realloc: ");
    for (int i = 0; i < new_n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}