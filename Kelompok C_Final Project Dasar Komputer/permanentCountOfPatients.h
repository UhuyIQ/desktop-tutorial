#ifndef PERMANENTCOUNTOFPATIENTS_H
#define PERMANENTCOUNTOFPATIENTS_H
 
extern int autoPId;
 
void displayRekamT(){
	int totalPasien = autoPId - 2023001;
    printf("\n\t-----------------------------------------------------------");
    printf("\n\n\t\tTotal catatan medis pasien yang direkam : %d\n\n", totalPasien);
    printf("\t-----------------------------------------------------------\n\n");
}
 
#endif

