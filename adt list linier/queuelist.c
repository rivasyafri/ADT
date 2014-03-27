/* NIM / Nama		: 13512036 / Riva Syafri Rachmatullah					*/
/* Nama File		: queuelist.c 											*/
/* Topik			: ADT Queue - Representasi List Linier					*/
/* Tanggal			: 21 November 2013										*/
/* Deskripsi		: Implementasi dari ADT Queue Representasi List Linier 	*/

/*	----- File Include ----- */
#include "boolean.h"
#include "queuelist.h"
#include <stdlib.h>
#include <stdio.h>

/*	----- Prototype manajemen memori ----- */
void Alokasi (address * P, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	(*P) = (address) malloc (sizeof (ElmtQueue));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address * P) {
	/* Kamus Lokal */

	/* Algoritma */
	free(*P);
}

/*	----- Predikat Pemeriksaan Kondisi Queue ----- */
boolean IsEmpty (Queue Q) {
	/* Kamus Lokal */

	/* Algoritma */
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NBElmt (Queue Q) {
	/* Kamus Lokal */
	address P;
	int N;
	
	/* Algoritma */
	P = Head(Q);
	N = 0;
	while (P != Nil) {
		N = N + 1;
		P = Next(P);
	}
	return N;
}

/*	----- Konstruktor ----- */
void CreateEmpty (Queue * Q) {
	/* Kamus Lokal */

	/* Algoritma */
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/*	----- Primitif Add/Delete ----- */
void Add (Queue * Q, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = P;
			Tail(*Q) = P;
		} else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	}
}

void Del (Queue * Q, infotype * X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	(*X) = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q) == Nil) {
		Tail(*Q) = Nil;
	}
	Dealokasi(&P);
}

/*	---- Operasi Lain ----- */
void PrintQueue (Queue Q) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Head(Q);
	if (P == Nil) {
		printf("Stack kosong\n");
	} else {
		printf("[%d",Info(P));
		P = Next(P);
		while (P != Nil) {
			printf(", %d",Info(P));
			P = Next(P);
		}
		printf("]\n");
	}
}

void DelAll (Queue * Q) {
	/* Kamus Lokal */
	infotype X;

	/* Algoritma */
	while (!IsEmpty(*Q)) {
		Del(Q,&X);
	}
}
