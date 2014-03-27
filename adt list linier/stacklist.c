/* NIM / Nama		: 13512036 / Riva Syafri Rachmatullah						*/
/* Nama File		: stacklist.c 												*/
/* Topik			: ADT STACK - Representasi List Linier						*/
/* Tanggal			: 21 November 2013											*/
/* Deskripsi		: Implementasi dari ADT STACK Representasi List Linier 	*/

/*	File Include */
#include "boolean.h"
#include "stacklist.h"
#include <stdlib.h>
#include <stdio.h>

/*	----- Prototype ----- */
/*	----- Konstruktor/Kreator ----- */
void CreateEmpty (Stack * S) {
	/* Kamus Lokal */

	/* Algoritma */
	TOP(*S) = Nil;
}

/*	----- Prototype Manajemen Memori ----- */
void Alokasi (address * P, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	(*P) = (address) malloc (sizeof (ElmtStack));
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

/*	----- Predikat untuk Test Keadaan ----- */
boolean IsEmpty (Stack S) {
	/* Kamus Lokal */

	/* Algoritma */
	return (TOP(S) == Nil);
}

/*	----- Operator Dasar Stack ----- */
void Push (Stack * S, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		Next(P) = TOP(*S);
		TOP(*S) = P;
	}
}

void Pop (Stack * S, infotype * X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = TOP(*S);
	(*X) = Info(P);
	TOP(*X) = Next(TOP(*X));
	Next(P) = Nil;
	Dealokasi(&P);
}

/*	---- Operasi Lain ----- */
void PrintStack (Stack S) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = TOP(S);
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

int NbElmt (Stack S) {
	/* Kamus Lokal */
	address P;
	int N;

	/* Algoritma */
	P = TOP(S);
	N = 0;
	while (P != Nil) {
		N = N + 1;
		P = Next(P);
	}
	return N;
}

void PopAll (Stack * S) {
	/* Kamus Lokal */
	infotype X;

	/* Algoritma */
	while (!IsEmpty(*S)) {
		Pop(S,&X);
	}
}

void InversStack (Stack * S) {
	/* Kamus Lokal */
	Stack S1;
	infotype X;

	/* Algoritma */
	while (!IsEmpty(*S)) {
		Pop(S,&X);
		Push(&S1,X);
	}
	TOP(*S) = TOP(S1);
}
