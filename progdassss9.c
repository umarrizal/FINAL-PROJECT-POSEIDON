#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 2;
    int size = 0;
    float *data = (float *)malloc(capacity * sizeof(float));

    printf("=== Sensor LDR - Running Average ===\n");
    printf("(masukkan -1 untuk stop)\n\n");

    while (1) {
        float lux;
        printf("lux ke-%d: ", size + 1);
        scanf("%f", &lux);

        if (lux == -1) break;
        if (size == capacity) {
            capacity *= 2;
            data = (float *)realloc(data, capacity * sizeof(float));
            printf("[kapasitas array diperbesar menjadi %d slot]\n", capacity);
        }

        data[size] = lux;
        size++;

        float sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        float avg = sum / size;
        printf("running average : %.2f lux\n\n", avg);
    }


    printf("\n=== Hasil Pembacaan Sensor ===\n");
    float total = 0;
    for (int i = 0; i < size; i++) {
        printf("Data ke-%d : %.2f lux\n", i + 1, data[i]);
        total += data[i];
    }
    printf("Rata-rata akhir : %.2f lux\n", total / size);
    printf("Total data      : %d\n", size);

    free(data);
    return 0;
}