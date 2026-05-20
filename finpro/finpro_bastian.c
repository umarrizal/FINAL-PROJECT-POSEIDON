// ===== Fungsi Laporan Harian =====
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
 
    printf("%-4s %-20s %5s %12s %10s\n",
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
 
    // Klasifikasi performa sederhana
    float margin = 0;
    if (total_pendapatan > 0) {
        margin = (total_laba / total_pendapatan) * 100;
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

