#include <stdio.h>
#include <string.h>

#define MAX_TIKET  50
#define MAX_NAMA   50
#define MAX_MODEL  30
#define ID_AWAL    1001

/* === TODO 1 [Easy] ===
    Definisikan enum bernama "Kategori" dengan anggota:
    Fisik, Driver, Overheating, Mati_Total
*/

typedef enum {
    Fisik,
    Driver,
    Overheating,
    Mati_Total
} Kategori;


/* === TODO 2 [Easy] ===
    Definisikan union bernama "BiayaEstimasi" dengan dua field:
    - harga_pasti : int    (digunakan jika kategori BUKAN Mati_Total)
    - harga_range : float  (digunakan jika kategori Mati_Total)
*/

typedef union {
    int   harga_pasti;
    float harga_range;
} BiayaEstimasi;


/* === TODO 3 [Easy] ===
    Definisikan struct bernama "InfoGPU" (gunakan typedef) dengan field:
    - model : char array maks 30 karakter
    - vram  : int
*/

typedef struct {
    char model[MAX_MODEL];
    int  vram;
} InfoGPU;


/* === TODO 4 [Easy] ===
    Definisikan struct bernama "Tiket" (gunakan typedef) dengan field:
    - id_tiket      : int
    - nama_pelanggan: char array maks 50 karakter
    - gpu           : bertipe InfoGPU (struct bersarang)
    - kategori      : bertipe Kategori (enum)
    - biaya         : bertipe BiayaEstimasi(union)
    - selesai       : int  (0 = belum, 1 = selesai)
*/

typedef struct {
    int          id_tiket;
    char         nama_pelanggan[MAX_NAMA];
    InfoGPU      gpu;
    Kategori     kategori;
    BiayaEstimasi biaya;
    int          selesai;
} Tiket;

// Helper: konversi enum Kategori -> string
const char* namaKategori(Kategori k) {
    switch (k) {
        case Fisik:       return "Fisik";
        case Driver:      return "Driver";
        case Overheating: return "Overheating";
        case Mati_Total:  return "Mati Total";
    default:          return "Tidak Diketahui";
    }
}

// Fungsi: input satu tiket
Tiket inputTiket(int id) {
    Tiket t;
    int pilihan;

    t.id_tiket = id;

    printf("  Nama Pelanggan  : ");
    scanf(" %[^\n]", t.nama_pelanggan);

    /* === TODO 5 [Medium] ===
        Input data GPU (struct tersarang):
        - Minta input model GPU, simpan ke t.gpu.model
        Format : " Model GPU        : "
        - Minta input VRAM (int), simpan ke t.gpu.vram
        Format : " VRAM (GB)       : "
    */
    /* ... isi di sini ... */

    printf("  Model GPU       : ");
    scanf(" %[^\n]", t.gpu.model);
    printf("  VRAM (GB)       : ");
    scanf("%d", &t.gpu.vram);



    printf(" Kategori           : [0] Fisik  [1] Driver  [2] Overheating  [3] Mati Total\n");
    printf(" Pilih              : ");
    scanf("%d", &pilihan);
    t.kategori = (Kategori) pilihan;

    /* === TODO 6 [Medium] ===
        Input biaya estimasi via union, sesuai kategori:
        - Jika BUKAN Mati_Total:
            Format : " Estimasi Biaya  : Rp "
            Baca int, simpan ke t.biaya.harga_pasti
        - Jika Mati_Total:
            Format : " Estimasi Biaya  : Rp "
            Baca float, simpan ke t.biaya.harga_range
            Setelah input, cetak: "   (estimasi, bisa berubah)\n"
    */
    /* ... isi di sini ... */

    printf("  Estimasi Biaya  : Rp ");
    if (t.kategori != Mati_Total) {
        scanf("%d", &t.biaya.harga_pasti);
    } else {
        scanf("%f", &t.biaya.harga_range);
        printf("   (estimasi, bisa berubah)\n");
    }

    printf("  Sudah Selesai?  : [0] Belum  [1] Selesai\n");
    printf("  Pilih           : ");
    scanf("%d", &t.selesai);

    return t;
}

// Fungsi: tampilkan satu tiket
void tampilTiket(Tiket t) {
    printf("\n  [ID:%d] %s\n", t.id_tiket, t.nama_pelanggan);
    printf("  GPU             : %s (%d GB VRAM)\n", t.gpu.model, t.gpu.vram);
    printf("  Kategori        : %s\n", namaKategori(t.kategori));

    if (t.kategori != Mati_Total) {
        printf("  Estimasi Biaya  : Rp %d (pasti)\n", t.biaya.harga_pasti);
    } else {
        printf("  Estimasi Biaya  : Rp %.2f (estimasi)\n", t.biaya.harga_range);
    }

    printf("  Status          : %s\n", t.selesai ? "Selesai" : "Belum selesai");
}

/* === TODO 7 [Hard] ===
    Implementasikan fungsi di bawah ini.

    Fungsi menerima array Tiket dan jumlah elemen n.
    Fungsi menghitung TOTAL pendapatan dari tiket yang memenuhi
    DUA syarat sekaligus:
        1. Status selesai == 1
        2. Kategori BUKAN Mati_Total  (harga_pasti saja yang valid)

    Tiket yang belum selesai, atau bertipe Mati_Total, DIABAIKAN.
    Kembalikan total sebagai long long (untuk jaga-jaga nilai besar 😋).

    Hint:
    - Gunakan loop, cek dua kondisi dengan &&
    - Akumulasi ke variabel total bertipe long long
*/
long long hitungTotalPendapatan(Tiket data[], int n) {
    /* ... isi di sini ... */
    long long total = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].selesai == 1 && data[i].kategori != Mati_Total) {
            total += data[i].biaya.harga_pasti;
        }
    }
    return total;
}

// MAIN
int main() {
    Tiket data[MAX_TIKET];
    int n;

    printf(" ===== ENDVIDIA SERVICE CENTER =====\n");
    printf("Masukkan jumlah tiket (maks %d): ", MAX_TIKET);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n=== Input Tiket ke-%d ===\n", i + 1);
        data[i] = inputTiket(ID_AWAL + i);
    }

    printf("\n\n === DAFTAR TIKET SERVIS ===");
    for (int i = 0; i < n; i++) {
        tampilTiket(data[i]);
    }

    printf("\n\n === TOTAL PENDAPATAN ===\n");
    long long total = hitungTotalPendapatan(data, n);

    // === TODO 8 [Easy] ===
    // Print total pendapatan

    printf("  Total : Rp %lld\n", total);

    // === TODO 9 [...] ===
    // Akhiri program 😹

    return 0;
}