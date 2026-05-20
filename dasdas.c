#include <stdio.h>
#include <string.h>

#define MAX_KARYAWAN 100
#define MAX_NAMA     50

typedef enum {
/* === TODO 1 ===
  Definisikan enum bernama "Departemen" dengan anggota:
  HR, Engineering, Finance, Marketing
*/
HR, Engineering, Finance, Marketing
} Departemen;

typedef enum {
/* === TODO 2 ===
  Definisikan enum bernama "StatusKerja" dengan anggota:
  FullTime, PartTime, Intern
*/
FullTime, PartTime, Intern
} StatusKerja;

typedef union {
/* === TODO 3 ===
  Definisikan union bernama "Gaji" yang memiliki dua field:
  - bulanan  : int    (untuk FullTime & PartTime)
  - per_jam  : float  (untuk Intern)
*/
int bulanan;
float per_jam;
} Gaji;

/* === TODO 4 ===
  Definisikan struct bernama "Karyawan" menggunakan typedef
  sehingga bisa dipakai langsung tanpa kata kunci "struct".
  Struct harus memiliki field:
  - nama        : char array maks 50 karakter
  - departemen  : bertipe Departemen  (enum)
  - status      : bertipe StatusKerja (enum)
  - gaji        : bertipe Gaji        (union)
  - tahun_masuk : int
*/
typedef struct{
    char nama[MAX_NAMA];
    Departemen departemen;
    StatusKerja status;
    Gaji gaji;
    int tahun_masuk;
} Karyawan;

// Helper: konversi enum Departemen -> string 
const char* namaDepartemen(Departemen d) {
  switch (d) {
    case HR:          return "HR";
    case Engineering: return "Engineering";
    case Finance:     return "Finance";
    case Marketing:   return "Marketing";
    default:          return "Tidak Diketahui";
  }
}

// Helper: konversi enum StatusKerja -> string
const char* namaStatus(StatusKerja s) {
  switch (s) {
    case FullTime: return "Full-Time";
    case PartTime: return "Part-Time";
    case Intern:   return "Intern";
    default:       return "Tidak Diketahui";
  }
}

// Fungsi: input satu karyawan 
Karyawan inputKaryawan() {
  Karyawan k;
  int pilihan;

  printf("  Nama          : ");
  scanf(" %[^\n]", k.nama);

  /* === TODO 5 ===
  Tampilkan pilihan departemen kepada user:
    0 = HR
    1 = Engineering
    2 = Finance
    3 = Marketing
  Baca input pilihan, lalu simpan ke field k.departemen
  */
  printf("  Departemen    : [0] HR  [1] Engineering  [2] Finance  [3] Marketing\n");
  printf("  Pilih         : ");
  /* ... Baca input pilihan ... */
  scanf("%d" , &pilihan);
  k.departemen = (Departemen)pilihan;

  /* === TODO 6 ===
  Tampilkan pilihan status kerja kepada user:
    0 = FullTime
    1 = PartTime
    2 = Intern
  Baca input pilihan, lalu simpan ke field k.status
  */
  printf("  Status Kerja  : [0] Full-Time  [1] Part-Time  [2] Intern\n");
  printf("  Pilih         : ");
  /* ... Baca input pilihan ... */
  scanf("%d" , &pilihan);
  k.status = (StatusKerja)pilihan;

  /* === TODO 7 ===
  Isi field gaji pada union sesuai status karyawan:
    - Jika FullTime atau PartTime:
      Minta input gaji bulanan (int), simpan ke k.gaji.bulanan
    - Jika Intern:
      Minta input gaji per jam (float), simpan ke k.gaji.per_jam
  Gunakan if-else atau switch.
  */
  if (k.status == FullTime || k.status == PartTime) {
    // ... Lanjutkan yh ...
    printf("  Gaji bulanan   : Rp ");
    scanf("%d" , &k.gaji.bulanan);
  } else {
    printf ("  Gaji per jam   : Rp ");
    scanf("%f" , &k.gaji.per_jam);
  }

  printf("  Tahun Masuk   : ");
  scanf("%d", &k.tahun_masuk);

  return k;
}

// Fungsi: tampilkan satu karyawan
void tampilKaryawan(Karyawan k, int nomor) {
  printf("\n  [%d] %s\n", nomor, k.nama);
  printf(" Departemen     : %s\n", namaDepartemen(k.departemen));
  printf(" Status         : %s\n", namaStatus(k.status));

  /* === TODO 8 ===
  Tampilkan gaji sesuai status karyawan:
    - Jika FullTime atau PartTime -> cetak k.gaji.bulanan
      Format: " Gaji      : Rp %d / bulan\n"
    - Jika Intern -> cetak k.gaji.per_jam
      Format: " Gaji      : Rp %.2f / jam\n"
  */
  /* ... Mirip seperti TODO 7 ... */
  if (k.status == FullTime || k.status == PartTime) {
    printf(" Gaji bulanan   : Rp %d / bulan\n " , k.gaji.bulanan);
  } else {
    printf (" Gaji per jam   : Rp %.2f / bulan\n" , k.gaji.per_jam);
  }

    printf("Tahun Masuk  : %d\n", k.tahun_masuk);
}

// Fungsi: cari indeks karyawan dengan gaji bulanan tertinggi
int cariGajiTertinggi(Karyawan data[], int n) {
  int idx_tertinggi = -1;
  int gaji_max = -1;

  for (int i = 0; i < n; i++) {
    if (data[i].status == Intern) continue; /* skip intern */

    if (data[i].gaji.bulanan > gaji_max) {
      gaji_max      = data[i].gaji.bulanan;
      idx_tertinggi = i;
    }
  }

  return idx_tertinggi;
}

// MAIN
int main() {
  Karyawan data[MAX_KARYAWAN];
  int n;

  printf(" ===== SISTEM DATA KARYAWAN ===== \n");

  printf("Masukkan jumlah karyawan (maks %d): ", MAX_KARYAWAN);
  scanf("%d", &n);

  /* === TODO 9 ===
  Buat loop untuk mengisi array data[] sebanyak n karyawan.
  Setiap iterasi:
    - Cetak header "=== Input Karyawan ke-X ===" (X = nomor urut mulai 1)
    - Panggil inputKaryawan() dan simpan hasilnya ke data[i]
  */
  /* ... isi di sini ... */
  for (int i = 0 ; i < n ; i++){
    printf("\n === Input Karyawan ke-%d ===\n" , i + 1);
    data[i] = inputKaryawan();
  }

  // Tampilkan semua karyawan
  printf(" === DAFTAR KARYAWAN === \n");
  for (int i = 0; i < n; i++) {
      tampilKaryawan(data[i], i + 1);
  }

  // Tampilkan gaji tertinggi
  printf(" === GAJI BULANAN TERTINGGI === \n");

  int idx = cariGajiTertinggi(data, n);
  if (idx == -1) {
      printf("  Tidak ada karyawan Full-Time / Part-Time.\n");
  } else {
      printf("  Karyawan : %s\n", data[idx].nama);
      printf("  Gaji     : Rp %d / bulan\n", data[idx].gaji.bulanan);
  }

  printf("\n");

  // === TODO 10 ===
  // akhiri program 😹
  return 0;
}