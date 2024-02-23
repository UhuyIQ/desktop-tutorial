
#ifndef TEMPORARYCOUNTOFPATIENTS_H
#define TEMPORARYCOUNTOFPATIENTS_H
 
extern int autoPId;
 
int displayRekamS() {
	int jumlahPasien = 0;
	char ch = 'a';
	FILE* rekam;
	rekam = fopen("TemporaryRecord.txt", "r");
 
	while ((ch = fgetc(rekam)) != EOF) {
    	if (ch == '\n') {
            jumlahPasien++;
 	   }
	}
 
    printf("\n\t-----------------------------------------------------------");
    printf("\n\n\t   Jumlah pasien yang berada di rumah sakit saat ini: %d \n\n", jumlahPasien);
    printf("\t-----------------------------------------------------------\n\n");
	
    fclose(rekam);
 
	return jumlahPasien;
}
 
#endif



