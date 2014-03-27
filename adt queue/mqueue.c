/* NIM / Nama	: 13512036 / Riva Syafri Rachmatullah 				*/
/* Nama File	: mqueue.c 											*/
/* Topik		: ADT QUEUE 										*/
/* Tanggal		: 17 Oktober 2013									*/
/* Deskripsi	: DRIVER ADT QUEUE									*/

/*	File Include */
#include "queue.h"
#include "boolean.h"
#include <stdio.h>

/*	Header Prosedur dan Fungsi */
void menu();

/*	Program Utama */
int main() {
	/* Kamus */
	Queue Q;
	int MaxEl,opt;
	infotype X;
	boolean exit=false;
	/* Algoritma */
	printf("Panjang Queue = ");
	scanf("%d",&MaxEl);
	CreateEmpty(&Q,MaxEl);
	do {
		menu();
		scanf("%d",&opt);
		switch (opt) {
			case 1 	: 	if (IsEmpty(Q)) {
							printf("Queue kosong.\n");
						} else {
							printf("Queue tidak kosong.\n");	
							printf("Jumlah elemen = %d\n",Count(Q));
							printf("Jumlah maksimum elemen = %d\n",MaxEl(Q));
						}
						printf("\n");
						break;
			case 2 	:	if (IsFull(Q)) {
							printf("Queue penuh.\n");
						} else {
							printf("Queue tidak penuh.\n");
							printf("Jumlah elemen = %d\n",Count(Q));
							printf("Jumlah maksimum elemen = %d\n",MaxEl(Q));
						}
						printf("\n");
						break;
			case 3	: 	printf("Masukkan masukan yang mau ditambah ke queue = ");
						scanf("%d",&X);
						Add(&Q,X);
						printf("\n");
						break;
			case 4	:	Del(&Q,&X);
						printf("\n");
						break;
			case 5	:	printf("Ukuran yang diinginkan = ");
						scanf("%d",&MaxEl);
						CreateEmpty(&Q,MaxEl);
						printf("\n");
						break;
			case 6	:	printf("Bye.\n");
						exit=true;
						break;
		}
	} while (!exit);
	DeAlokasi(&Q);
}

/*	Realisasi Prosedur dan Fungsi */
void menu() {
	/* Kamus */
	/* Algoritma */
	printf("1. Cek Kosong\n");
	printf("2. Cek Penuh\n");
	printf("3. Cek void Add\n");
	printf("4. Cek void Del\n");
	printf("5. Perbarui Queue\n");
	printf("6. Exit\n");
	printf("\n");
	printf("Pilihan = ");
}