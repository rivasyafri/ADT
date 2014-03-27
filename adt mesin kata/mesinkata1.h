/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: mesinkata1.h 										*/
/* Topik		: ADT MESIN KATA									*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: HEADER MESIN KATA									*/

#ifndef mesinkata1_h
#define mesinkata1_h

/*	Mesin lain yang dipakai */
#include "mesinkar1.h"
/*	File Include */
#include "boolean.h"

#ifndef BLANK
 #define BLANK ' '
 #endif

/* 	Konstanta */
#define NMax 50 /* jumlah maksimum karakter suatu kata */

/*	Definisi Type Kata */
typedef struct {
	char TabKata[NMax+1];
	int length;
} Kata;
/*	TabKata adalah tepat penampung/container kata
	Length menyatakan panjangnya kata */

/*	Primitif-Primitif Mesin Kata */
void Ignore_Blank (void); 
/*	Mengabaikan satu atau beberapa BLANK
	I.S.	: CC sembarang
	F.S. 	: CC ≠ BLANK atau CC = MARK */
void STARTKATA (void);
/*	I.S.	: CC sembarang
	F.S.	: EndKata = true, dan CC = Mark, atau EndKata = false,
			  CKata adalah kata yang sudah diakuisisi,
			  CC karakter pertama sesudah karakter terakhir kata */
void ADVKATA (void);
/*	I.S.	: EndKata = false; CC adalah karakter sesudah karakter terakhir dari kata
			  yang sudah diakuisisi
	F.S.	: Jika CC = MARK, maka EndKata = true atau EndKata = false,
			  CKata adalah kata terakhir yang sudah diakuisisi;
			  CC karakter pertama sesudah karakter terakhir kata */
void SalinKata (void);
/*	Mengakuisisi kata, menyimpan dalam CKata
	I.S.	: CC adalah karakter pertama dari kata
	F.S.	: CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi NMax,
			  sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah karakter 
			  sesudah karakter terakhir yang diakuisisi */  

/*	Operasi Lain */
boolean IsKataSama (Kata K1, Kata K2);
/*	Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama 
	dan urutan karakter yang menyusun kata juga sama */

#endif