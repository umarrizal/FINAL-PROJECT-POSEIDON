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
