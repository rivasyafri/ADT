/* NIM / Nama		 : 13512036 / Riva Syafri Rachmatullah				*/
/* Nama File		 : listdouble.c 						*/
/* Topik 		 : ADT List Linier - Double pointer				*/
/* Tanggal		 : 7 November 2013 						*/
/* Deskripsi		 : Implementasi dari ADT List Linier versi Double Pointer 	*/

/* ----- File Include ----- */
#include "boolean.h"
#include "listdouble.h"
#include <stdio.h>
#include <stdlib.h>

/* ----- Test List Kosong ----- */
boolean IsListEmpty (List L) {
	/* Kamus Lokal */

	/* Algoritma */
	return ((First(L) == Nil) && (Last(L) == Nil));
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L) {
	/* Kamus Lokal */

	/* Algoritma */
	First(*L) = Nil;
	Last(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}

void Dealokasi (address *P) {
	/* Kamus Lokal */

	/* Algoritma */
	free(*P);
}

/* ----- Pencarian Sebuah Elemen List ----- */
boolean FSearch (List L, address P) {
	/* Kamus Lokal */
	address Pt;
	boolean Found;

	/* Algoritma */
	Pt = First(L);
	Found = false;
	while ((Pt != Nil) && (!Found)) {
		if (Pt == P) {
			Found = true;
		} else {
			Pt = Next(Pt);
		}
	}
	return Found;
}

address Search (List L, infotype X) {
	/* Kamus Lokal */
	address P;
	boolean Found;

	/* Algoritma */
	P = First(L);
	Found= false;
	while ((P != Nil) && (!Found)) {
		if (Info(P) == X) {
			Found = true;
		} else {
			P = Next(P);
		}
	}
	return P;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* ----- Penambahan Elemen ----- */
void InsVFirst (List *L, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Alokasi(X);
	if (P != Nil) {
		InsertFirst(L,P);
	}
}

void InsVLast (List *L, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Alokasi(X);
	if (P != Nil) {
		InsertLast(L,P);
	}
}

/* ----- Penghapusan Elemen ----- */
void DelVFirst (List *L, infotype *X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	*X = Info(First(*L));
	DelFirst(L,&P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	*X = Info(Last(*L));
	DelLast(L,&P);
	Dealokasi(&P);
}

/* ----- Primitif Berdasarkan Alamat ----- */
/* ----- Penambahan Elemen Berdasarkan Alamat ----- */
void InsertFirst (List *L, address P) {
	/* Kamus Lokal */

	/* Algoritma */
	if (!IsListEmpty(*L)) {
		Next(P) = First(*L);
		Prev(First(*L)) = P;
	} else {
		Last(*L) = P;
	}
	First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec) {
	/* Kamus Lokal */

	/* Algoritma */
	Next(P) = Next(Prec);
	Prev(Next(Prec)) = P;
	Prev(P) = Prec;
	Next(Prec) = P;
}

void InsertLast (List *L, address P) {
	/* Kamus Lokal */

	/* Algoritma */
	if (!IsListEmpty(*L)) {
		Prev(P) = Last(*L);
		Next(Last(*L)) = P;
	} else {
		First(*L) = P;
	}
	Last(*L) = P;
}

/* ----- Penghapusan Sebuah Elemen ----- */
void DelFirst (List *L, address *P) {
	/* Kamus Lokal */

	/* Algoritma */
	*P = First(*L);
	First(*L) = Next(*P);
	if (First(*L) != Nil) {
		Prev(First(*L)) = Nil;	
	} else {
		Last(*L) = Nil;
	}
	Next(*P) = Nil;
}

void DelLast (List *L, address *P) {
	/* Kamus Lokal */

	/* Algoritma */
	*P = Last(*L);
	Last(*L) = Prev(*P);
	if (Last(*L) != Nil) {
		Next(Last(*L)) = Nil;	
	} else {
		First(*L) = Nil;
	}
	Prev(*P) = Nil;
}

void DelAfter (List *L, address *Pdel, address Prec) {
	/* Kamus Lokal */

	/* Algoritma */
	if (Last(*L) == Next(Prec)){
		DelLast(L,Pdel);
	} else {
		*Pdel = Next(Prec);
		Next(Prec) = Next(*Pdel);
		Prev(Next(*Pdel)) = Prec;
		Prev(*Pdel) = Nil;
		Next(*Pdel) = Nil;
	}
}

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(L);
	if (P == Nil) {
		printf("List kosong\n");
	} else {
		printf("[%d",Info(P));
		P = Next(P);
		while (P != Nil) {
			printf(", %d",Info(P));
		}
		printf("]\n");
	}
}

/* ----- Operasi Lain ----- */
address SearchPrec (List L, infotype X) {
	/* Kamus Lokal */
	address P;
	boolean Found;

	/* Algoritma */
	P = First(L);
	Found = false;
	if (P == Nil) {
		return Nil;
	} else {
		while ((Next(P) != Nil) && (!Found)) {
			if (X == Info(Next(P))) {
				Found = true;
			} else {
				P = Next(P);
			}
		}
	}
	if (Next(P) == Nil) {
		return Nil;
	} else {
		return P;
	}
}

void DelP (List *L, address *P) {
	/* Kamus */
	address Pt, Prec;
	boolean Found;

	/* Algoritma */
	Pt = First(*L);
	Prec = Nil;
	while ((Pt != Nil) && (!Found)) {
		if (Pt == (*P)) {
			Found = true;
		} else {
			Prec = Pt;
			Pt = Next(Pt);
		}
	}
	if (Prec == Nil) {
		DelFirst(L,P);
		Dealokasi(P);
	} else {
		DelAfter(L,P,Prec);
		Dealokasi(P);
	}
}

int NbElmt (List L) {
	/* Kamus Lokal */
	address P;
	int N;

	/* Algoritma */
	P = First(L);
	N = 0;
	while (P != Nil) {
		N = N + 1;
		P = Next(P);
	}
	return N;
}

/* ----- Proses Terhadap List ----- */
void DelAll (List *L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	while (!IsListEmpty(*L)) {
		DelFirst(L,&P);
		Dealokasi(&P);
	}
}

void InversList (List *L) {
	/* Kamus Lokal */
	address P, Temp;

	/* Algoritma */
	P = First(*L);
	if (!IsListEmpty(*L)) {
		Temp = First(*L);
		First(*L) = Last(*L);
		Last(*L) = Temp;
	}
	while (P != Nil) {
		Temp = Next(P);
		Next(P) = Prev(P);
		Prev(P) = Temp;
		P = Temp;
	}
}

List FInversList (List L) {
	/* Kamus Lokal */
	address P, Temp;
	List L1;
	boolean fail;

	/* Algoritma */
	fail = false;
	P = First(L);
	CreateList(&L1);
	while ((P != Nil) && (!fail)) {
		Temp = Alokasi(Info(P));
		if (Temp != Nil) {
			InsertFirst(&L1,Temp);
			P = Next(P);
		} else {
			DelAll(&L1);
			fail = true;
		}
	}
	return L1;
}

List FCopyList (List L) {
	/* Kamus Lokal */
	address P, Temp;
	List L1;
	boolean fail;

	/* Algoritma */
	fail = false;
	CreateList(&L1);
	P = First(L);
	while ((P != Nil) && (!fail)) {
		Temp = Alokasi(Info(P));
		if (Temp != Nil) {
			InsertLast(&L1,Temp);
			P = Next(P);
		} else {
			fail = true;
			DelAll(&L1);
		}
	}
	return L1;
}

void CpAlokList (List Lin, List *Lout) {
	/* Kamus Lokal */
	address P, Pt;
	boolean gagal;

	/* Algoritma */
	CreateList(Lout);
	gagal = false;
	P = First(Lin);
	while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(Lout,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(Lout);
		}
	}
}

void Konkat (List L1, List L2, List *L3) {
	/* Kamus Lokal */
	address P, Pt;
	boolean gagal;

	/* Algoritma */
	CreateList(L3);
	gagal = false;
	P = First(L1);
	while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(L3,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(L3);
		}
	}
	if (!gagal) {
		P = First(L2);
		while ((P != Nil)&&(!gagal)) {
			Pt = Alokasi(Info(P));
			if (Pt != Nil) {
				InsertLast(L3,Pt);
				P = Next(P);
			} else {
				gagal = true;
				DelAll(L3);
			}
		}
	}
}

void Konkat1 (List *L1, List *L2, List *L3) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(*L1);
	CreateList(L3);
	First(*L3) = First(*L1);
	if (P != Nil) {
		while (Next(P) != Nil) {
			P = Next(P);
		}
	}
	Next(P) = First(*L2);
	CreateList(L1);
	CreateList(L2);
}

void PecahList (List *L1, List *L2, List L) {
	/* Kamus Lokal */
	address P, Pt;
	boolean gagal;
	int i, N;

	/* Algoritma */
	CreateList(L1);
	CreateList(L2);
	gagal = false;
	i = 1;
	N = NbElmt(L)/2;
	P = First(L);
	while ((P != Nil) && (!gagal)) {
		Pt = Alokasi(Info(P));
		if (i <= N) {
			if (Pt != Nil) {
				InsertLast(L1,Pt);
				P = Next(P);
				i++;
			} else {
				gagal = true;
				DelAll(L1);
			}
		} else {
			if (Pt != Nil) {
				InsertLast(L2,Pt);
				P = Next(P);
				i++;
			} else {
				gagal = true;
				DelAll(L2);
			}
		}
	}
}