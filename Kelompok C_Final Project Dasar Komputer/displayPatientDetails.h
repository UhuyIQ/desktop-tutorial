#ifndef DISPLAYPATIENTDETAILS_H
#define DISPLAYPATIENTDETAILS_H
 
void detailPasien(int pId, int flag1) {
	char ch = 'a';
	int i = 0;
	int flag = 0;
	char simpanPId[7];
	char simpan[100];
	int ruang = 1;
	int j = 0;
	int line = 0;
	int temp = 0;
	
	FILE* rekam;
	FILE* rekam1;
 
	// Masukkan 0 untuk mencari di catatan rumah sakit
	// Masukkan 1 untuk mencari di catatan sementara
	if (flag1 == 0) {
    	rekam = fopen("HospitalRecord.txt", "r");
 	    rekam1 = fopen("HospitalRecord.txt", "r");
	}
	else {
    	rekam = fopen("TemporaryRecord.txt", "r");
        rekam1 = fopen("TemporaryRecord.txt", "r");
	}
 
	while ((ch = fgetc(rekam)) != EOF) {
    	if (i < 7) {
            simpanPId[i] = ch;
    	}
    	i++;
    	if (ch == '\n') {
        	i = 0;
        	int j;
            sscanf(simpanPId, "%d", &j);
        	if (j == pId) {
            	flag = 1;
            	break;
        	}
        	line++;
    	}
	}
	int it = 0;
	while ((ch = fgetc(rekam1)) != EOF) {
    	if (temp == line) {
            simpan[it] = ch;
        	it++;
  	  }
    	if (ch == '\n') {
        	temp++;
    	}
	}
 
	// Jika P-ID pasien tidak ditemukan dalam rekaman
	if (flag == 0) {
        printf("\n\t--------------------------------------------");
        printf("\n\n\t Maaf, P-ID yang Anda cari tidak ditemukan!\n\n", pId);
        printf("\t--------------------------------------------\n");
	}
	else {
        printf("\n\t--------------------------------------------");
        printf("\n\n\t\tP-ID: ");
    	
    	for (i = 0; i <= it; i++) {
        	if (simpan[i] == ' ' && ruang == 1) {
                ruang++;
                printf("\n\t\tNama pasien  \t: ");
        	}
        	else if (simpan[i] == ' ' && ruang == 2) {
                ruang++;
                printf("\n\t\tUsia     	: ");
        	}
        	else if (simpan[i] == ' ' && ruang == 3) {
                ruang++;
                printf("\n\t\tPenyakit 	: ");
        	}
        	else if (simpan[i] == ' ' && ruang == 4) {
                ruang++;
                printf("\n\t\tStatus COVID \t: ");
        	}
        	else {
        		if (simpan[i] != '\x10') {  // Memeriksa karakter tidak dikenal
            	printf("%c", simpan[i]);
				}
        	}
    	}
        printf("\n\t--------------------------------------------");
        printf("\n\n\tP-ID: %d berhasil ditampilkan!\n\n", pId);
	}
    fclose(rekam);
    fclose(rekam1);
}
#endif