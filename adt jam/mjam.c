#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "adt_jam.h"

/* VARIABEL UNIVERSAL */
JAM J1,J2;
boolean keluar;

/* HEADER */
void Tampilan();
void MasukProgram();

/* PROGRAM UTAMA */
int main () {
	keluar=false;
	while (!(keluar)) {
		Tampilan();
		MasukProgram();
	}
	return 0;
}

/* PROGRAM BANTUAN */
void Tampilan() {
	printf("------Menu------\n");
	printf("1. Baca Jam 1\n");
	printf("2. Baca Jam 2\n");
	printf("3. Tulis Jam 1\n");
	printf("4. Tulis Jam 2\n");
	printf("5. Mengubah Jam\n");
	printf("6. Mengubah Menit\n");
	printf("7. Mengubah Detik\n");
	printf("8. Jam 1 ke Detik\n");
	printf("9. Jam 2 ke Detik\n");
	printf("10. Detik ke Jam\n");
	printf("11. Apakah sama?\n");
	printf("12. Apakah beda?\n");
	printf("13. Apakah lebih kecil\n");
	printf("14. Apakah lebih besar\n");
	printf("15. Tambah\n");
	printf("16. Kurang\n");
	printf("17. NextDetik\n");
	printf("18. NextNDetik\n");
	printf("19. PrevDetik\n");
	printf("20. PrevNDetik\n");
	printf("21. Durasi\n");
	printf("22. Keluar?\n");
	printf("Pilihan anda :	");
}
void MasukProgram() {
	int a,b;
	scanf("%d",&a);
	
	switch (a) {
		case 1 : { 
					BacaJam(&J1);
					break;
				}
		case 2 : {
					BacaJam(&J2);
					break;
				}
		case 3 : {
					TulisJam(J1);	
					break;
				}
		case 4 : {
					TulisJam(J2);				
					break;
				}
		case 5 : { 
					
					printf("Masukkan jam pada jam 1 yang diubah : ");
					scanf("%d",&b);
					SetHH(J1,b);
					break; 
				}
		case 6 : { 
					
					printf("Masukkan menit pada jam 1 yang diubah : ");
					scanf("%d",&b);
					SetMM(J1,b);
					break; 
				}
		case 7 : { 
					
					printf("Masukkan detik pada jam 1 yang diubah : ");
					scanf("%d",&b);
					SetSS(J1,b);
					break; 
				}
		case 8 : {
					printf("Jam 1 itu %d detik\n",JamToDetik(J1));
					break;
				}
		case 9 : {
					printf("Jam 2 itu %d detik\n",JamToDetik(J2));
					break;
				}
		case 10 : {
					printf("Masukkan detik yang mau dikonvert : ");
					scanf("%d",&b);
					TulisJam(DetikToJam(b));
					break;
				}
		case 11 : {
					if (JEQ(J1,J2)) {
						printf("Ya\n");
					} else {
						printf("Tidak\n");
					}
					break;
				}
		case 12 : {
					if (JNEQ(J1,J2)) {
						printf("Ya\n");
					} else {
						printf("Tidak\n");
					}
					break;
				}
		case 13 : {
					if (JLT(J1,J2)) {
						printf("Ya\n");
					} else {
						printf("Tidak\n");
					}
					break;
				}
		case 14 : {
					if (JGT(J1,J2)) {
						printf("Ya\n");
					} else {
						printf("Tidak\n");
					}
					break;
				}
		case 15 : {
					TulisJam(JPlus(J1,J2));
					break;
				}
		case 16 : {
					TulisJam(JMinus(J1,J2));
					break;
				}
		case 17 : {
					TulisJam(NextDetik(J1));
					break;
				}
		case 18 : {
					printf("Masukkan jumlah detik yang mau ditambahkan : ");
					scanf("%d",&b);
					TulisJam(NextNDetik(J1,b));
					break;
				}
		case 19 : {
					TulisJam(PrevDetik(J1));
					break;
				}
		case 20 : {
					printf("Masukkan jumlah detik yang mau ditambahkan : ");
					scanf("%d",&b);
					TulisJam(PrevNDetik(J1,b));
					break;
				}
		case 21 : {
					printf("Durasinya adalah %d\n",Durasi(J1,J2));
					break;
				}
		case 22 : {
					keluar = true;
					break;
				}
	}
}