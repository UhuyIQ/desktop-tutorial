#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "receptionistMenu.h"
#include "dataAnalystMenu.h"
#include "addPatientDetails.h"
#include "updatePatientDetails.h"
#include "deletePatientRecord.h"
#include "displayPatientDetails.h"
#include "activeCountOfCovidCases.h"
#include "permanentCountOfPatients.h"
#include "temporaryCountOfPatients.h"
#include "onExit.h"

// Variable global untuk memberikan ID Pasien baru
extern int autoPId;

int main() {
    // Membuka file autoPId untuk mendapatkan entri terakhir
    FILE* readAutoPId;
    readAutoPId = fopen("autoPIdStatus.txt", "r");
    fscanf(readAutoPId, "%d", &autoPId);
    fclose(readAutoPId);

    // Variabel untuk menyimpan pilihan pada switch-case
    int pilihan;
    char psForR, psForDA;
    char inputpassResp[20], inputpassDA[20];
    char passResp[14] = "a", passDA[14] = "b";
    int psauthR = 0, psauthDA = 0, i = 0;

    do {
        system("cls"); // Clear console screen

        printf("\n\t    Selamat datang di Sistem Manajemen Pasien COVID-19");
        printf("\n\t\t=======================================");
        printf("\n\t\t||  Masuk sebagai Resepsionis >>  1  ||");
        printf("\n\t\t||  Masuk sebagai Analis Data >>  2  ||");
        printf("\n\t\t||  Keluar                    >>  3  ||");
        printf("\n\t\t=======================================");

        printf("\n\nMasukkan pilihan anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (psauthR == 0) {
                    printf("\nMasukkan Password : ");
                    int i = 0;
                    while ((psForR = _getch()) != 13) {
                        inputpassResp[i] = psForR;
                        i++;
                        printf("*");
                    }
                    inputpassResp[i] = '\0';

                    if (strcmp(inputpassResp, passResp) == 0) {
                        psauthR = 1;
                        fflush(stdin);
                    } else {
                        printf("\n\nMaaf, Password Salah!");
                        printf("\nTekan enter untuk melanjutkan...");
                        fflush(stdin);
                        getchar(); 
                        // Menunggu pengguna menekan tombol enter sebelum melanjutkan
                        break;
                    }
                }
                menuResp(passResp);
                break;

            case 2:
                if (psauthDA == 0) {	
                    printf("\nMasukkan Password : ");
                    int i = 0;
                    while ((psForDA = _getch()) != 13) {
                        inputpassDA[i] = psForDA;
                        i++;
                        printf("*");
                    }
                    inputpassDA[i] = '\0';

                    if (strcmp(inputpassDA, passDA) == 0) {
                        psauthDA = 1;
                        fflush(stdin);
                    } else {
                        printf("\n\nMaaf, Password Salah!");
                        printf("\nTekan enter untuk melanjutkan...");
                        fflush(stdin);
                        getchar(); 
                        break;
                    }
                }
                menuDA(passDA);
                break;

            case 3:
                printf("\nTerima kasih telah menggunakan program ini!\n\n");
                break;
        }
    } while (pilihan != 3);
    return 0;
}