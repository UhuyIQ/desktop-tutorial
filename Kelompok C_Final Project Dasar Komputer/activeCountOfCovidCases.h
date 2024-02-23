#ifndef ACTIVECOUNTOFCOVIDCASES_H
#define ACTIVECOUNTOFCOVIDCASES_H
 
extern int autoPId;
 
int Hitung_Covid() {
	int Pasien_Covid = 0;
	FILE* rekam;
	rekam = fopen("TemporaryRecord.txt", "r");
 
	if (rekam == NULL) {
        printf("Gagal membuka file\n");
    	return 0;
	}
 
	char line[100];
 
	while (fgets(line, sizeof(line), rekam)) {
    	char lastChar = line[strlen(line) - 3]; // Mengambil karakter sebelum '\n'
 
    	if (lastChar == '1') {
            Pasien_Covid++;
    	}
	}
 
    printf("\n\t-----------------------------------------------------------");
    printf("\n\n\t Jumlah pasien positif COVID yang berada di rumah sakit: %d \n\n", Pasien_Covid);
    printf("\t-----------------------------------------------------------\n\n\n");
 
    fclose(rekam);
 
	return Pasien_Covid;
}
#endif


