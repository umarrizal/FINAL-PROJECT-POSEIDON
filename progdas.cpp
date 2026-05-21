// ===== Tampilkan Menu Utama =====
void tampilkan_menu_utama() {
    garis();
    printf("  SISTEM MANAJEMEN USAHA KULINER\n");
    garis();
    printf("  1. Tambah Menu\n");
    printf("  2. Lihat Daftar Menu\n");
    printf("  3. Catat Pesanan\n");
    printf("  4. Laporan Harian\n");
    printf("  0. Keluar\n");
    garis();
    printf("  Pilihan: ");
}
 
// ===== Main =====
int main() {
    int pilihan;
 
    printf("\nSelamat datang di Program Manajemen Kuliner!\n");
 
    do {
        tampilkan_menu_utama();
        scanf("%d", &pilihan);
        printf("\n");
 
        switch (pilihan) {
            case 1:
                tambah_menu();
                break;
            case 2:
                tampilkan_menu();
                break;
            case 3:
                catat_pesanan();
                break;
            case 4:
                laporan_harian();
                break;
            case 0:
                printf("Terima kasih! Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak ada, coba lagi.\n");
        }
 
        printf("\n");
 
    } while (pilihan != 0);
 
    return 0;
}




