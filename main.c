#include <stdio.h>
#include <string.h>
#define MAX_MENU       10
#define MAX_TRANSAKSI  100

struct Menu {
    int    id;
    char   nama[50];
    float  harga_jual;
    float  hpp;         
    int    stok;
};
 
struct Transaksi {
    int   no;
    int   id_menu;
    char  nama_menu[50];
    int   jumlah;
    float total_bayar;
    float total_hpp;
    float laba;
};
 
struct Menu      daftar_menu[MAX_MENU];
struct Transaksi riwayat[MAX_TRANSAKSI];
int jumlah_menu       = 0;
int jumlah_transaksi  = 0;
 
void garis() {
    printf("----------------------------------------\n");
}
void tambah_menu() {
    if (jumlah_menu >= MAX_MENU) {
        printf("Menu sudah penuh! Maksimal %d menu.\n", MAX_MENU);
        return;
    }
 
    struct Menu m;
    m.id = jumlah_menu + 1;
 
    printf("\nMasukkan nama menu   : ");
    getchar(); 
    fgets(m.nama, 50, stdin);
    m.nama[strcspn(m.nama, "\n")] = '\0';
 
    printf("Harga jual (Rp)      : ");
    scanf("%f", &m.harga_jual);
 
    printf("HPP per porsi (Rp)   : ");
    scanf("%f", &m.hpp);
 
    printf("Stok awal (porsi)    : ");
    scanf("%d", &m.stok);
 
    daftar_menu[jumlah_menu] = m;
    jumlah_menu++;
 
    printf("\n[OK] Menu berhasil ditambahkan!\n");
}

void tampilkan_menu() {

    garis();
    printf("  DAFTAR MENU\n");
    garis();

    if (jumlah_menu == 0) {
        printf("Belum ada menu.\n");
        garis();
        return;
    }

    printf("%-4s %-20s %10s %10s %6s\n",
           "ID",
           "Nama Menu",
           "Harga",
           "HPP",
           "Stok");

    garis();

    int i;

    for (i = 0; i < jumlah_menu; i++) {

        printf("%-4d %-20s Rp%8.0f Rp%8.0f %5d\n",
               daftar_menu[i].id,
               daftar_menu[i].nama,
               daftar_menu[i].harga_jual,
               daftar_menu[i].hpp,
               daftar_menu[i].stok);
    }

    garis();
}



void catat_pesanan() {

    if (jumlah_menu == 0) {
        printf("Belum ada menu! Tambah menu dulu.\n");
        return;
    }

    if (jumlah_transaksi >= MAX_TRANSAKSI) {
        printf("Data transaksi penuh!\n");
        return;
    }

    tampilkan_menu();

    int id_pilih;

    printf("Pilih ID menu : ");
    scanf("%d", &id_pilih);



    int index = -1;
    int i;

    for (i = 0; i < jumlah_menu; i++) {

        if (daftar_menu[i].id == id_pilih) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Menu tidak ditemukan!\n");
        return;
    }

    int jumlah;

    printf("Jumlah porsi  : ");
    scanf("%d", &jumlah);

    if (jumlah <= 0) {
        printf("Jumlah tidak valid!\n");
        return;
    }

    if (jumlah > daftar_menu[index].stok) {

        printf("Stok tidak cukup! Sisa stok: %d\n",
               daftar_menu[index].stok);

        return;
    }



    daftar_menu[index].stok -= jumlah;



    struct Transaksi t;

    t.no = jumlah_transaksi + 1;

    t.id_menu = daftar_menu[index].id;

    strcpy(t.nama_menu,
           daftar_menu[index].nama);

    t.jumlah = jumlah;

    t.total_bayar =
        daftar_menu[index].harga_jual * jumlah;

    t.total_hpp =
        daftar_menu[index].hpp * jumlah;

    t.laba =
        t.total_bayar - t.total_hpp;


    riwayat[jumlah_transaksi] = t;

    jumlah_transaksi++;


    garis();

    printf("  STRUK PESANAN #%d\n",
           t.no);

    garis();

    printf("  Menu     : %s\n",
           t.nama_menu);

    printf("  Jumlah   : %d porsi\n",
           t.jumlah);

    printf("  Total    : Rp %.0f\n",
           t.total_bayar);

    garis();

    printf("[OK] Pesanan berhasil dicatat!\n");
}

void laporan_harian() {
    garis();
    printf("  LAPORAN HARIAN\n");
    garis();

    if (jumlah_transaksi == 0) {
        printf("Belum ada transaksi.\n");
        garis();
        return;
    }

    float total_pendapatan = 0;
    float total_hpp        = 0;
    float total_laba       = 0;
    int   total_porsi      = 0;

    printf("%-4s %-20s %5s %13s %10s\n",
           "No", "Menu", "Qty", "Pendapatan", "Laba");
    garis();

    int i;
    for (i = 0; i < jumlah_transaksi; i++) {
        printf("%-4d %-20s %5d Rp%9.0f Rp%8.0f\n",
               riwayat[i].no,
               riwayat[i].nama_menu,
               riwayat[i].jumlah,
               riwayat[i].total_bayar,
               riwayat[i].laba);

        total_pendapatan += riwayat[i].total_bayar;
        total_hpp        += riwayat[i].total_hpp;
        total_laba       += riwayat[i].laba;
        total_porsi      += riwayat[i].jumlah;
    }

    garis();
    printf("Total porsi terjual : %d\n",      total_porsi);
    printf("Total pendapatan    : Rp %.0f\n", total_pendapatan);
    printf("Total HPP           : Rp %.0f\n", total_hpp);
    printf("Laba kotor          : Rp %.0f\n", total_laba);

    float margin = 0;
    if (total_pendapatan > 0) {
        margin = ((float)total_laba / (float)total_pendapatan) * 100;
    }

    printf("Margin laba         : %.1f%%\n", margin);
    garis();

    printf("Status performa     : ");
    if (margin >= 20) {
        printf("SEHAT - Bisnis berjalan baik!\n");
    } else if (margin >= 10) {
        printf("WASPADA - Margin tipis, perlu efisiensi.\n");
    } else {
        printf("KRITIS - Evaluasi harga dan biaya!\n");
    }

    garis();
}