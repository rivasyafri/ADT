/* NIM / Nama		: 13512036 / Riva Syafri Rachmatullah		*/
/* Nama File		: listrek.c 								*/
/* Topik			: ADT List Rekursif							*/
/* Tanggal			: 21 November 2013							*/
/* Deskripsi		: Implementasi dari ADT List Rekursif 		*/

/*	----- File Include ----- */
#include "boolean.h"
#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>

/*	----- Manajemen Memori ----- */
address Alokasi (infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi (address * P) {
	/* Kamus Lokal */

	/* Algoritma */
	free(*P);
}

/*	----- Primitif-Primitif Pemrosesan List ----- */
/*	----- Selektor ----- */
infotype FirstElmt (List L) {
	/* Kamus Lokal */

	/* Algoritma */
	return Info(L);
}

List Tail (List L) {
	/* Kamus Lokal */

	/* Algoritma */
	return Next(L);
}

/*	----- Konstruktor ----- */
List Konso (infotype e, List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Alokasi(e);
	if (P == Nil) {
		return L;
	} else {
		Next(P) = L;
		return P;
	}
}

List Konsdot (List L, infotype e) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (IsListEmpty(L)) { /* Basis - 0 */
		return Alokasi(e);
	} else if (Next(L) = Nil) { /* Basis - 1 */
		Next(L) = Alokasi(e);
	} else { /* Rekurens */
		P = Konsdot(Tail(L),e)
	}
	return L;
}

/*	----- Predikat Pemeriksaan Kondisi ----- */
boolean IsListEmpty (List L) {
	/* Kamus Lokal */

	/* Algoritma */
	return (L == Nil);
}

boolean IsOneElmt (List L) {
	/* Kamus Lokal */
	boolean check;

	/* Algoritma */
	check = false;
	if (L != Nil) {
		if (Tail(L) == Nil) {
			check = true;
		}
	}
	return check;
}

/*	----- Operasi Lain ----- */
List Copy (List L) {
	/* Kamus Lokal */
	
	/* Algoritma */
	if (IsListEmpty(L)) { /* Basis - 0 */
		return Nil;
	} else { /* Rekurens */
		return Konso(FirstElmt(L),Copy(Tail(L)));
	}
}

List Concat (List L1, List L2) {
	/* Kamus Lokal */

	/* Algoritma */
	if (IsListEmpty(L1)) { /* Basis - 0 */
		return Copy(L2);
	} else { /* Rekurens */
		return Konso(FirstElmt(L1),Concat(Tail(L1),L2));
	}
}

void Printlist (List L) {
	/* Kamus Lokal */

	/* Algoritma */
	if (IsListEmpty(L)) { /* Basis - 0 */
		
	} else if (IsOneElmt(L)) { /* Basis - 1 */
		printf("%d\n",FirstElmt(L));
	} else { /* Rekurens */
		printf("%d ",FirstElmt(L));
		Printlist(Tail(L));
	}
}

int NBElmtList (List L) {
	/* Kamus Lokal */

	/* Algoritma */
	if (IsListEmpty(L)) { /* Basis - 0 */
		return 0;
	} else { /* Rekurens */
		return 1 + NBElmtList(Tail(L));
	}
}

boolean Search (List L, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	if (IsListEmpty(L)) { /* Basis - 0 */
		return false;
	} else { /* Rekurens */
		if (FirstElmt(L) == X) {
			return true;
		} else {
			return Search(Tail(L),X);
		}
	}
}

void DelAll (List * L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (IsListEmpty(*L)) { /* Basis - 0 */

	} else { /* Rekurens */
		P = (*L);
		(*L) = Tail(*L);
		Next(P) = Nil;
		Dealokasi(&P);
		DelAll(L);
	}
}

void DelP (List * L, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (IsListEmpty(*L)) { /* Basis - 0 */
		
	} else if (FirstElmt(*L) == X) { /* Basis Ketemu */
		P = (*L);
		(*L) = Tail(*L);
		Next(P) = Nil;
		Dealokasi(&P);
	} else { /* Rekurens */
		DelP(Tail(L),X);
	}
}