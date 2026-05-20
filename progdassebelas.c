#include <stdio.h>

typedef enum {
    FANTASY,
    ROMANCE,
    COMEDY,
    SLICE_OF_LIFE
} Genre;

typedef union {
    int bulat;
    float desimal;
} Rating;

typedef struct {
    char judul[51];
    Genre genre;
    Rating rating;
} Buku;

const char *genreToString(Genre g) {
    switch (g) {
        case FANTASY: return "FANTASY";
        case ROMANCE: return "ROMANCE";
        case COMEDY: return "COMEDY";
        case SLICE_OF_LIFE: return "SLICE OF LIFE";
        default: return "UNKNOWN";
    }
}

int main() {
    int n;
    printf("Masukkan jumlah buku = ");
    scanf("%d", &n);
    printf("\n");

    Buku db[n];

    for (int i = 0; i < n; i++) {
        printf("=== Input data buku ke-%d ===\n", i + 1);

        printf("Judul: ");
        scanf(" %[^\n]", db[i].judul);

        int pilihanGenre;
        printf("Pilih genre (0=FANTASY,1=ROMANCE,2=COMEDY,3=SLICE OF LIFE) = ");
        scanf("%d", &pilihanGenre);
        db[i].genre = (Genre)pilihanGenre;

        printf("Rating (0.0 - 5.0) : ");
        scanf("%f", &db[i].rating.desimal);

        printf("\n");
    }

    printf("=== Hasil Data Buku ===\n\n");

    for (int i = 0; i < n; i++) {
        printf("Judul  : %s\n", db[i].judul);
        printf("Genre  : %s\n", genreToString(db[i].genre));

        if (db[i].rating.desimal == (int)db[i].rating.desimal) {
            printf("Rating : %d\n", (int)db[i].rating.desimal);
        } else {
            printf("Rating : %.2f\n", db[i].rating.desimal);
        }

        printf("\n");
    }

    return 0;
}