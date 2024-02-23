#ifndef ADDPATIENTDETAILS_H
#define ADDPATIENTDETAILS_H
 
typedef struct Pasien {
	int  pId;
	char pNama[30];
	int  pUsia;
	char pPenyakit[30];
	int  pStatus;
} Pasien;
 
int displayRekamS();
int flag = 0;
int autoPId;
 
void tambahPasien(){
	int kapTerkini = displayRekamS();
	int pasienMasuk;

    printf("\nMasukkan jumlah pasien yang ingin ditambahkan : ");
    scanf("%d", &pasienMasuk);
	fflush(stdin);

	int kapasitasRS = 10;

	if (kapTerkini + pasienMasuk > kapasitasRS) {
	    printf("\n\n\t-----------------------------------------------------------");
        printf("\n\t  Rumah sakit penuh, mohon maaf atas ketidaknyamanannya!\n");
        printf("\n\t   Jumlah maksimal pasien yang dapat dimasukkan : %d", (kapasitasRS - kapTerkini));
        printf("\n\t-----------------------------------------------------------\n\n");
        printf("\n\nTekan tombol apa saja untuk melanjutkan...");
    	_getch();
    	return;
	}

	Pasien* pas = (Pasien*)calloc(pasienMasuk, sizeof(Pasien));

	FILE* catPasien;
	FILE* rekam;

	catPasien = fopen("HospitalRecord.txt", "a");
	rekam = fopen("TemporaryRecord.txt", "a");

	int id = autoPId - 2023001;
	int i;
	for (i = id; i < pasienMasuk + id; i++) {

    	// Mengassign ID pasien
    	pas[i - id].pId = autoPId;
    	autoPId++;

        system("cls"); // Clear console screen

        printf("\n\n\t\tHalo, Resepsionis!\n");
        printf("\n\t\t========================================");
        printf("\n\t\t||  Tambahkan Pasien          >>   1  ||");
        printf("\n\t\t||  Pulangkan Pasien          >>   2  ||");
        printf("\n\t\t||  Tampilkan Detail Pasien   >>   3  ||");
        printf("\n\t\t||  Perbarui Detail Pasien    >>   4  ||");
        printf("\n\t\t||  Kembali ke Menu Utama     >>   5  ||");
        printf("\n\t\t========================================");

        printf("\n\nPasien ke-%d\n", (i - id) + 1); // Menampilkan nomor pasien

        printf("\nMasukkan nama pasien : ");
        scanf("%s", pas[i - id].pNama);

    	fflush(stdin);
        printf("\nMasukkan umur pasien : ");
        scanf("%d", &pas[i - id].pUsia);

    	fflush(stdin);
        printf("\nGejala penyakit      : ");
        scanf("%s", pas[i - id].pPenyakit);

    	fflush(stdin);
        printf("\nStatus COVID pasien\n 1. Positif\n 2. Negatif ");
        printf("\nMasukkan status COVID pasien : ");
        scanf("%d", &pas[i - id].pStatus);
        printf("\n-------------------------------------------------------\n\n\n");

    	fflush(stdin);

        fprintf(catPasien, "%d %s %d %s %d %s", pas[i - id].pId, pas[i - id].pNama, pas[i - id].pUsia, pas[i - id].pPenyakit, pas[i - id].pStatus, "\n");
        fprintf(rekam, "%d %s %d %s %d %s", pas[i - id].pId, pas[i - id].pNama, pas[i - id].pUsia, pas[i - id].pPenyakit, pas[i-id].pStatus, "\n");
  		printf("\n-------------------------------------------------------\n");
		printf("\n\tP-ID dari %s adalah %d\n", pas[i - id].pNama, pas[i - id].pId);
		printf("\n\tCatatan pasien sudah terekam");
		printf("\n\n-------------------------------------------------------\n\n\n");

        printf("\n\nTekan tombol apa saja untuk melanjutkan...");
    	_getch();
	}

	FILE* tulisAutoPId;
	tulisAutoPId = fopen("autoPIdStatus.txt", "w");
    fprintf(tulisAutoPId, "%d", autoPId);
    fclose(tulisAutoPId);

	fclose(catPasien);
    fclose(rekam);
}
#endif