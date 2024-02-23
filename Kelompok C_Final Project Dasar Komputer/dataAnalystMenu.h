#ifndef DATAANALYSTMENU_H
#define DATAANALYSTMENU_H
 
void menuDA(char* passDA) {
	int pilihanDA;
	int cariPId;
 
	do {
        system("cls"); // Clear console screen
 
        printf("\n\n\tHalo, Data Analyst!\n");
        printf("\n\t=================================================================");
        printf("\n\t||  Jumlah Pasien Tetap                             >>   1  ||");
        printf("\n\t||  Jumlah Pasien Sementara                         >>   2  ||");
        printf("\n\t||  Cari Detail Pasien dalam catatan rumah sakit    >>   3  ||");
        printf("\n\t||  Cari Detail Pasien dalam catatan pasien aktif   >>   4  ||");
        printf("\n\t||  Jumlah pasien COVID aktif                       >>   5  ||");
        printf("\n\t||  Kembali ke Menu Utama                           >>   6  ||");
        printf("\n\t=================================================================");
 
        printf("\n\n\tMasukkan pilihan anda : ");
        scanf("%d", &pilihanDA);
        printf("\n");
 
    	switch (pilihanDA) {
        	case 1:
                displayRekamT();
            	break;
        	case 2:
                displayRekamS();
            	break;
        	case 3:
                printf("\n\tMasukkan ID Pasien yang ingin dicari detailnya dalam catatan rumah sakit: ");
                scanf("%d", &cariPId);
                detailPasien(cariPId, 0);
          	  break;
        	case 4:
                printf("\n\tMasukkan ID Pasien yang ingin dicari detailnya dalam catatan pasien aktif: ");
                scanf("%d", &cariPId);
                detailPasien(cariPId, 1);
            	break;
 	       case 5:
                Hitung_Covid();
            	break;
        	case 6:
                keluar();
                return;
    	}
        printf("\n\n\tTekan tombol apa pun untuk melanjutkan...");
    	_getch();
	} while (1);
}
#endif