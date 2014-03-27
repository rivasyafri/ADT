/* NIM / Nama		: 13512036 / Riva Syafri Rachmatullah		*/
/* Nama File		: listrek.h 								*/
/* Topik			: ADT List Rekursif							*/
/* Tanggal			: 21 November 2013							*/
/* Deskripsi		: Header dari ADT List Rekursif 			*/

#ifndef listrek_h
#define listrek_h

/*	----- File Include ----- */
#include "boolean.h"
#include <stdlib.h>

/* ----- Konstanta ----- */
#define Nil NULL

/* ----- Deklarasi Tipe ----- */
typedef int infotype;
typedef struct tElmtList * address;
typedef struct tElmtList {
	infotype Info;
	address Next;
} ElmtList;
typedef address List;

/*	----- Selektor ----- */
#define Info(P) (P)->Info
#define Next(P) (P)->Next

/*	----- Manajemen Memori ----- */
address Alokasi (infotype X);
/*	Mengirimkan address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka address tidak Nil, dan misalnya
	menghasilkan P, maka Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address * P);
/*	I.S.	: P terdefinisi
	F.S.	: P dikembalikan ke sistem
	Proses	: Melakukan dealokasi/pengembalian address P */

/*	----- Primitif-Primitif Pemrosesan List ----- */
/*	----- Selektor ----- */
infotype FirstElmt (List L);
/*	Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List Tail (List L);
/*	Mengirimkan list L yang tidak kosong tanpa elemen pertamanya */

/*	----- Konstruktor ----- */
List Konso (infotype e, List L);
/*	Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
	e harus dialokasi terlebih dahulu.
	Jika alokasi e gagal, mengirimkan L */
List Konsdot (List L, infotype e);
/*	Mengirimkan list L dengan tambahan e sebagai elemen terakhir
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L */

/*	----- Predikat Pemeriksaan Kondisi ----- */
boolean IsListEmpty (List L);
/*	Mengirimkan true jika list kosong, false jika tidak kosong */
boolean IsOneElmt (List L);
/*	Mengirimkan true jika L berisi 1 elemen, false jika tidak */

/*	----- Operasi Lain ----- */
List Copy (List L);
/*	Mengirimkan salinan list L (menjadi list baru)
	Jika ada alokasi gagal, mengirimkan L */
List Concat (List L1, List L2);
/*	Mengirimkan salinan hasil konkatenasi list L1 dan L2 
	(menjadi list baru). Jika ada alokasi gagal, menghasilkan Nil */
void Printlist (List L);
/*	I.S.	: L terdefinisi.
	F.S.	: Setiap elemen list dicetak. */
int NBElmtList (List L);
/*	Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search (List L, infotype X);
/*	Mengirim true jika X adalah anggota list, false jika tidak */
void DelAll (List * L);
/*	Delete semua elemen list dan alamat elemen di-dealokasi
	I.S.    : L terdefinisi, boleh kosong
	F.S.    : Jika L tidak kosong, semua elemen list di-delete dan 
			  didealokasi */
void DelP (List * L, infotype X);
/* 	I.S.    : Sembarang
	F.S.    : Jika ada elemen list beraddress P, dengan Info(P) = X
			  Maka P dihapus dari list dan di-dealokasi
			  Jika tidak ada elemen list dengan Info(P) = X, 
			  maka list tetap.
			  List mungkin menjadi kosong karena penghapusan */

#endif