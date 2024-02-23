#ifndef UPDATEPATIENTDETAILS_H
#define UPDATEPATIENTDETAILS_H
 
void update_data(int PID) {
 
	// Mengecek dalam rekam sementara
	char ch = 'a';
	int i = 0;
	int flag = 0;
	char simpanPID[7];
 
	FILE* rekam;
	rekam = fopen("TemporaryRecord.txt", "r");
 
	int j = 0;
	int line = 0;
	int temp = 0; 
 
	while ((ch = fgetc(rekam)) != EOF) {
    	if (i < 7) {
        	simpanPID[i] = ch;
    	}
 
    	i++;
    	if (ch == '\n') {
        	i = 0;	
            sscanf(simpanPID, "%d", &j);
        	if (j == PID) {
            	flag = 1;
            	break;
        	}
        	line++;
    	}
	}
 
	// Jika ID pasien tidak ditemukan dalam rekam
	if (flag == 0) {
		printf("\n\n\t-----------------------------------------------------------");
        printf("\n\n\t Maaf, P-ID: %d tidak ada dalam Catatan Pasien Aktif!\n", PID);
        printf("\n\t-----------------------------------------------------------\n\n");
        fclose(rekam);
    	return;
	}
 
    fclose(rekam);
 
 
	// Mengecek dalam rekam permanen
	char ch2 = 'a';
	int i2 = 0;
	int flag2 = 0;
	char simpanPID2[7];
 
	FILE* rekam2;
	rekam2 = fopen("HospitalRecord.txt", "r");
 
	int j2 = 0;
	int line2 = 0;
	int temp2 = 0;
 
	while ((ch2 = fgetc(rekam2)) != EOF) {
    	if (i2 < 7) {
            simpanPID2[i2] = ch2;
    	}
 
    	i2++;
    	if (ch2 == '\n') {
        	i2 = 0;
            sscanf(simpanPID2, "%d", &j2);
        	if (j2 == PID) {
            	flag2 = 1;
            	break;
        	}
        	line2++;
    	}
	}

	fclose(rekam2);
 
	// Mengambil input
	char namabaru[30];
	int umurbaru;
	char penyakitbaru[30];
	int statusbaru;
 
    printf("\n\t-------------------------------------------------------\n");
	printf("\n\tMasukkan nama pasien: ");
    scanf("%s", namabaru);
 
	fflush(stdin);
	printf("\n\tMasukkan umur pasien: ");
    scanf("%d", &umurbaru);
 
	fflush(stdin);
	printf("\n\tMasukkan gejala yang dialami pasien: ");
    scanf("%s", penyakitbaru);
 
	fflush(stdin);
	printf("\n\tStatus COVID pasien\n\t 1. Positif\n\t 2. Negatif ");
	printf("\n\tMasukkan status COVID pasien : ");
    scanf("%d", &statusbaru);
 
    printf("\n");
 
	// Untuk rekam permanen
	FILE* rekam1;
	FILE* dummyFile;
	rekam1 = fopen("TemporaryRecord.txt", "r");
	dummyFile = fopen("DummyFile.txt", "a+");
 
	// Untuk rekam permanen
	FILE* rekam12;
	FILE* dummyFile2;
	rekam12 = fopen("HospitalRecord.txt", "r");
	dummyFile2 = fopen("DummyFile2.txt", "a+");

 
	int as = 1;
	while ((ch = fgetc(rekam1)) != EOF) {
    	if (temp != line) {
        	putc(ch, dummyFile);
    	}
    	else if (temp == line && as == 1) {
            fprintf(dummyFile, "%d %s %d %s %d %s", PID, namabaru, umurbaru, penyakitbaru, statusbaru, "\n");
        	as++;
    	}
 
    	if (ch == '\n') {
        	temp++;
    	}
	}
 
	fclose(rekam1);
	fclose(dummyFile);
    remove("TemporaryRecord.txt");
    rename("DummyFile.txt", "TemporaryRecord.txt");
 	
	fflush(stdin);

	int as2 = 1;
	while ((ch2 = fgetc(rekam12)) != EOF) {
    	if (temp2 != line2) {
        	putc(ch2, dummyFile2);
    	}
    	else if (temp2 == line2 && as2 == 1) {
            fprintf(dummyFile2, "%d %s %d %s %d %s", PID, namabaru, umurbaru, penyakitbaru, statusbaru, "\n");
        	as2++;
    	}
 
    	if (ch2 == '\n') {
   	     temp2++;
    	}
	}
 
	fclose(rekam12);	
    fclose(dummyFile2);
    remove("HospitalRecord.txt");
    rename("DummyFile2.txt", "HospitalRecord.txt");
 
	fflush(stdin);
	
	printf("\n\t---------------------------------------------------------------------\n");
	printf("\n\t Detail P-Id: %d berhasil diperbarui dalam Catatan Rumah Sakit!\n", PID);
	printf("\n\t---------------------------------------------------------------------\n");
}
 
#endif

