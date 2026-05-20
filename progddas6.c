#include <stdio.h>
#include <stdlib.h>

int main() {
    //input limit dan batas trigonacci
    int limit;
    printf("Masukan batas maksimal: ");
    scanf("%d" , &limit);

    //alokasikan array dan error handling, variable awal size = 0 dan capacity = 3
    int capacity = 3;
    int size = 0;
    int *trib = (int *)malloc(capacity * sizeof(int));

    if (trib == NULL){
        printf("Error : malloc gagal mengalokasikan memori. \n");
        return 1;
    }
    
    //inisialisasi awal trigonacci
    int a = 1, b = 1, c = 2;

    //simpan selama masih kurang dari limit
    while (a < limit) {
        //jika kapasitas penuh realloc, kasih error handling
        if (size >= capacity) {
            //capacity bertambah tiap loop
            capacity += 1;
            int * temp = (int *) realloc(trib ,  capacity * sizeof(int));

            if (temp == NULL){
                printf("Error: realloc gagal mengalokasikan memori. \n");
                free(trib);
                return 1;
            }
            trib = temp;
        }
        //hitung Trigonacci berikutnya
        trib[size] = a;
        size++;

        int next = a + b + c;
        a = b;
        b = c;
        c = next;
    }

    //output array
    printf("deret Trigonacci: [");
    for (int i = 0 ; i < size ; i++){
        printf("%d" , trib[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    printf("\njumlah elemen: %d\n", size);
    //free memory
    free(trib);
    return 0;
}
