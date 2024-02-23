#ifndef DELETEPATIENTRECORD_H
#define DELETEPATIENTRECORD_H
 
void pasienPulang(int pId){
	char ch = 'a';
	int i = 0;
	int flag = 0;
	char simpanPId[7];
	int j = 0;
	int line = 0;
	int temp = 0;
	
	FILE* rekam;
	FILE* rekam1;
	FILE* dummyFile;
 
	rekam = fopen("TemporaryRecord.txt","r");
	rekam1 = fopen("TemporaryRecord.txt","r");
	dummyFile = fopen("DummyFile.txt", "a+");
 
	while((ch = fgetc(rekam))!=EOF) {
    	if(i < 7){
            simpanPId[i] = ch;
    	}
 
    	i++;
    	if(ch=='\n'){
        	i = 0;
            sscanf(simpanPId, "%d", &j);
        	if(j == pId){
            	flag = 1;
            	break;
        	}
        	line++;
    	}
	}
 
	// Jika P-ID pasien tidak ditemukan dalam rekaman
	if(flag == 0){
		printf("\n\t--------------------------------------------");
        printf("\n\n\t Maaf, P-ID yang Anda cari tidak ditemukan!\n\n", pId);
        printf("\t--------------------------------------------\n");
	}
	else{
		printf("\n\t--------------------------------------------");
        printf("\n\n\tP-ID: %d telah pulang dari rumah sakit!\n\n", pId);
        printf("\t--------------------------------------------\n");
	}
 
	while ((ch=fgetc(rekam1))!=EOF){
    	if (temp != line){
        	putc(ch, dummyFile);
    	}
    	if (ch == '\n'){
        	temp++;
    	}
	}
 
    fclose(rekam);
    fclose(rekam1);
	fclose(dummyFile);
    remove("TemporaryRecord.txt");
    rename("DummyFile.txt", "TemporaryRecord.txt");
}
 
#endif

