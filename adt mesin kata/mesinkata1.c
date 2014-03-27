/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: mesinkata1.c 										*/
/* Topik		: ADT MESIN KATA									*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: IMPLEMENTASI MESIN KATA							*/

#ifndef mesinkata1_c
#define mesinkata1_c

/*	Mesin lain yang dipakai */
#include "mesinkata1.h"
/*	File Include */ 
#include "boolean.h"
#include <stdio.h>

/*	Definisi State Mesin Kata */
boolean EndKata=false; /* penanda akhir akuisisi kata */
Kata CKata; /* kata yang sudah diakuisisi dan akan diproses */
extern char CC;

/*	Primitif-Primitif Mesin Kata */
void Ignore_Blank (void) {
/*	Mengabaikan satu atau beberapa BLANK
	I.S.	: CC sembarang
	F.S. 	: CC ≠ BLANK atau CC = MARK */
	/*	Kamus */
	/*	Algoritma */
	while ((CC==BLANK)&&(!EOP())) {
		ADV();
	}
}
void STARTKATA (void) {
/*	I.S.	: CC sembarang
	F.S.	: EndKata = true, dan CC = Mark, atau EndKata = false,
			  CKata adalah kata yang sudah diakuisisi,
			  CC karakter pertama sesudah karakter terakhir kata */
	/*	Kamus */
	/*	Algoritma */
	START();
	Ignore_Blank();
	if (EOP()) {
		EndKata=true;
	} else {
		EndKata=false;
		SalinKata();
	}
}
void ADVKATA (void) {
/*	I.S.	: EndKata = false; CC adalah karakter sesudah karakter terakhir dari kata
			  yang sudah diakuisisi
	F.S.	: Jika CC = MARK, maka EndKata = true atau EndKata = false,
			  CKata adalah kata terakhir yang sudah diakuisisi;
			  CC karakter pertama sesudah karakter terakhir kata */
	/*	Kamus */
	/*	Algoritma */
	Ignore_Blank();
	if (EOP()) {
		EndKata=true;
	} else {
		SalinKata();
	}
}  
void SalinKata (void) {
/*	Mengakuisisi kata, menyimpan dalam CKata
	I.S.	: CC adalah karakter pertama dari kata
	F.S.	: CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi NMax,
			  sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah karakter 
			  sesudah karakter terakhir yang diakuisisi */  
	/*	Kamus */
	int i=1;
	/*	Algoritma */
	for (;;) {
		CKata.TabKata[i]=CC;
		ADV();
		if (EOP()||(CC==BLANK)||(i==NMax)) {
			break;
		} else {
			i++;
		}
	}
	if (i==NMax) { /* abaikan sisa kata */
		while ((CC!=BLANK)&&(!EOP())) {
			ADV();
		}
	}
	CKata.length=i;
}

/*	Operasi Lain */
boolean IsKataSama (Kata K1, Kata K2) {
/*	Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama 
	dan urutan karakter yang menyusun kata juga sama */
	/*	Kamus */
	int i=1;
	/*	Algoritma */
	if (K1.length==K2.length) {
		while ((i<K1.length)&&(K1.TabKata[i]==K2.TabKata[i])) {
			i++;
		}
		return (K1.TabKata[i]==K2.TabKata[i]);
	} else {
		return (K1.length==K2.length);
	}
}

#endif