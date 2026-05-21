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


    // Struk
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
