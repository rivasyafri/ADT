/* NIM / Nama    : 13512036 / Riva Syafri Rachmatullah                    */
/* Nama File     : mlist.c 	                                              */
/* Topik         : ADT List Linier - First Eksplisit                      */
/* Tanggal       : 7 November 2013                                        */
/* Deskripsi     : Driver dari ADT List Linier versi First Implisit 	  */

/* ----- File Include ----- */
#include "listeks.h"
#include "boolean.h"
#include <stdio.h>

/* ----- Header Prosedur / Fungsi */
void Menu();
/* 	I.S. Layar kosong
	F.S. Layar tertulis menu-menu yang disediakan */

/* ----- Program Utama ----- */
int main () {
	/* Kamus Lokal */
	List L1, L2, L3, Lt;
	address P;
	int opt; /* untuk pilihan menu */
	int optlist; /* untuk pilihan list */
	infotype X; /* untuk pencarian alamat elemen dan penambahan elemen */
	infotype Y; /* untuk penguraman elemen */
	boolean exit; 
	float average;

	/* Algoritma */
	exit = false;
	CreateList(&L1);
	CreateList(&L2);
	CreateList(&L3);
	CreateList(&Lt);
	do {
		Menu();
		scanf("%d",&opt);
		switch (opt) {
			case 1 	:	printf("Elemen yang dicari : ");
						scanf("%d",&X);
						P = Search(L1,X);
						printf("Di L1 : 0x%x\n",P);
						P = Search(L2,X);
						printf("Di L2 : 0x%x\n",P);
						P = Search(L3,X);
						printf("Di L3 : 0x%x\n",P);
						break;
			case 2 	:	printf("Elemen yang dicari : ");
						scanf("%d",&X);
						P = SearchPrec(L1,X);
						printf("Di L1 : 0x%d\n",P);
						P = SearchPrec(L2,X);
						printf("Di L2 : 0x%d\n",P);
						P = SearchPrec(L3,X);
						printf("Di L3 : 0x%d\n",P);
						break;
			case 3 	:	printf("Elemen : ");
						scanf("%d",&X);
						printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	:	InsVFirst(&L1,X);
										break;
							case 2 	:	InsVFirst(&L2,X);
										break;
							case 3 	:	InsVFirst(&L3,X);
										break;
						}
						break;
			case 4 	:	printf("Elemen : ");
						scanf("%d",&X);
						printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	:	InsVLast(&L1,X);
										break;
							case 2 	:	InsVLast(&L2,X);
										break;
							case 3 	:	InsVLast(&L3,X);
										break;
						}
						break;
			case 5 	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	:	DelVFirst(&L1,&Y);
										break;
							case 2 	:	DelVFirst(&L2,&Y);
										break;
							case 3 	:	DelVFirst(&L3,&Y);
										break;
						}
						printf("Elemen yang dihapus : %d\n",Y);
						break;
			case 6 	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	:	DelVLast(&L1,&Y);
										break;
							case 2 	:	DelVLast(&L2,&Y);
										break;
							case 3 	:	DelVLast(&L3,&Y);
										break;
						}
						printf("Elemen yang dihapus : %d\n",Y);
						break;
			case 7 	:	printf("Elemen : ");
						scanf("%d",&Y);
						printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	:	DelP(&L1,Y);
										break;
							case 2 	:	DelP(&L2,Y);
										break;
							case 3 	:	DelP(&L3,Y);
										break;
						}
						break;
			case 8 	:	printf("List yang dipilih (1/2/3/4) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	:	PrintInfo(L1);
										break;
							case 2 	:	PrintInfo(L2);
										break;
							case 3 	:	PrintInfo(L3);
										break;
							case 4	:	PrintInfo(Lt);
										break;
						}
						break;
			case 9 	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	:	printf("%d\n",NbElmt(L1));
										break;
							case 2 	:	printf("%d\n",NbElmt(L2));
										break;
							case 3 	:	printf("%d\n",NbElmt(L3));
										break;
						}
						break;
			case 13	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	: 	DelAll(&L1);
										break;
							case 2 	:	DelAll(&L2);
										break;
							case 3 	:	DelAll(&L3);
										break;
						}
						break;
			case 14	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	: 	InversList(&L1);
										break;
							case 2 	:	InversList(&L2);
										break;
							case 3 	:	InversList(&L3);
										break;
						}
						break;
			case 15	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	: 	Lt = FInversList(L1);
										break;
							case 2 	:	Lt = FInversList(L2);
										break;
							case 3 	:	Lt = FInversList(L3);
										break;
						}
						PrintInfo(Lt);
						break;
			case 17	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	: 	CpAlokList(L1,&Lt);
										break;
							case 2 	:	CpAlokList(L2,&Lt);
										break;
							case 3 	:	CpAlokList(L3,&Lt);
										break;
						}
						break;
			case 18	:	printf("List yang dipilih (1/2/3) : ");
						scanf("%d",&optlist);
						switch (optlist) {
							case 1 	: 	Lt = FCopyList(L1);
										break;
							case 2 	:	Lt = FCopyList(L2);
										break;
							case 3 	:	Lt = FCopyList(L3);
										break;
						}
						break;
			case 19	:	Konkat1(&L1,&L2,&Lt);
						PrintInfo(Lt);
						break;
			case 20	:	Konkat(L1,L2,&Lt);
						PrintInfo(Lt);
						break;
			case 21	:	PecahList(&L1,&L2,Lt);
						printf("List 1\n");
						PrintInfo(L1);
						printf("List 2\n");
						PrintInfo(L2);
						break;
			case 22 :	exit = true; break;
		}
		system("pause");
	} while (!exit);
	DelAll(&L1);
	DelAll(&L2);
	DelAll(&L3);
	DelAll(&Lt);
	return 0;
}

/* ----- Implementasi Prosedur / Fungsi ----- */
void Menu() {
	/* Kamus Lokal */

	/* Algoritma */
	system("cls");
	printf("------ Menu ------\n\n");
	printf("1. Mencari Alamat Elemen Tertentu\n");
	printf("2. Mencari Alamat Sebelum Elemen Tertentu\n");
	printf("3. Memasukkan Suatu Elemen pada Depan List\n");
	printf("4. Memasukkan Suatu Elemen pada Belakang List\n");
	printf("5. Menghapus Elemen yang Berada di Depan List\n");
	printf("6. Menghapus Elemen yang Berada di Belakang List\n");
	printf("7. Menghapus Alamat Sesuai dengan Elemen yang Ditentukan\n");
	printf("8. Tulis Isi List\n");
	printf("9. Jumlah Elemen di List\n");
	printf("10. Elemen Maximum dan Alamatnya dalam List\n");
	printf("11. Elemen Minimum dan Alamatnya dalam List\n");
	printf("12. Rata-rata Elemen di List\n");
	printf("13. Menghapus Seluruh Elemen\n");
	printf("14. Meng-invers List\n");
	printf("15. Menghasilkan List Hasil Invers List Masukan\n");
	printf("16. Menyalin List tanpa Alokasi\n");
	printf("17. Menyalin List dengan Alokasi\n");
	printf("18. Menghasilkan List Hasil Penyalinan List Masukan\n");
	printf("19. Menyambung List tanpa Alokasi\n");
	printf("20. Menyambung List dengan Alokasi\n");
	printf("21. Memecah List\n");
	printf("22. Exit\n");
	printf("Pilihan : ");
}