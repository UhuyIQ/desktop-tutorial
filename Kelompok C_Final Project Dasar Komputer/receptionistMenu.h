#ifndef RECEPTIONISTMENU_H
#define RECEPTIONISTMENU_H
 
void menuResp(char* passResp) {
	int pilihanResp;
	int dataId;
	int keluarId;
	int updateId;
 
	do {
        system("cls"); // Clear console screen
 
        printf("\n\n\tHalo, Resepsionis!\n");
        printf("\n\t========================================");
        printf("\n\t||  Tambahkan Pasien          >>   1  ||");
        printf("\n\t||  Pulangkan Pasien          >>   2  ||");
        printf("\n\t||  Tampilkan Detail Pasien   >>   3  ||");
        printf("\n\t||  Perbarui Detail Pasien    >>   4  ||");
        printf("\n\t||  Kembali ke Menu Utama     >>   5  ||");
        printf("\n\t========================================");
 
        printf("\n\n\tMasukkan pilihan anda : ");
        scanf("%d", &pilihanResp);
        printf("\n");
 
    	switch (pilihanResp) {
        	case 1:
                tambahPasien();
            	break;
        	case 2:
                printf("\n\tMasukkan ID Pasien yang ingin dipulangkan: ");
                scanf("%d", &keluarId);
  	        pasienPulang(keluarId);
            	break;
        	case 3:
                printf("\n\tMasukkan ID Pasien yang ingin ditampilkan detailnya: ");
                scanf("%d", &dataId);
                detailPasien(dataId, 0);
            	break;
        	case 4:
                printf("\n\tMasukkan ID Pasien yang ingin diperbarui detailnya: ");
                scanf("%d", &updateId);
                update_data(updateId);
            	break;
        	case 5:
                keluar();
                return;
    	}
    	printf("\n\n\tTekan tombol apa saja untuk melanjutkan...");
    	_getch();
	} while (1);
}
#endif