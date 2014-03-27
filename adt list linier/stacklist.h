/* NIM / Nama		: 13512036 / Riva Syafri Rachmatullah				*/
/* Nama File		: stacklist.h 										*/
/* Topik			: ADT STACK - Representasi List Linier				*/
/* Tanggal			: 21 November 2013									*/
/* Deskripsi		: Header dari ADT STACK Representasi List Linier 	*/

#ifndef stacklist_h
#define stacklist_h

/*	File Include */
#include "boolean.h"
#include <stdlib.h>

/*	Konstanta */
#define Nil NULL

/*	Deklarasi Tipe */
typedef int infotype;
typedef struct tElmtStack * address;
typedef struct tElmtStack {
	infotype Info;
	address Next;
} ElmtStack;
typedef struct {
	address TOP;
} Stack;

/*	Selektor */
#define TOP(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/*	----- Prototype ----- */
/*	----- Konstruktor/Kreator ----- */
void CreateEmpty (Stack * S);
/*	I.S.	: Sembarang
	F.S.	: Membuat sebuah stack S yang kosong
			  Ciri stack kosong : TOP bernilai Nil */

/*	----- Prototype Manajemen Memori ----- */
void Alokasi (address * P, infotype X);
/*	I.S.	: P Sembarang, X terdefinisi
	F.S. 	: Alamat P dialokasi, jika berhasil maka Info(P) = X dan 
			  Next(P) = Nil. P = Nil jika alokasi gagal */
void Dealokasi (address * P);
/*	I.S.	: P adalah hasil alokasi, P != Nil
	F.S.	: Alamat P didealokasi, dikembalikan ke sistem */

/*	----- Predikat untuk Test Keadaan ----- */
boolean IsEmpty (Stack S);
/*	Mengirim true jika Stack kosong */

/*	----- Operator Dasar Stack ----- */
void Push (Stack * S, infotype X);
/*	I.S.	: S mungkin kosong
	F.S.	: X menjadi TOP yang baru, jika alokasi elemen baru
			  berhasil. Jika alokasi gagal, S tetap.
	Proses	: Menambahkan X sebagai elemen Stack S. */
void Pop (Stack * S, infotype * X);
/*	I.S. 	: S tidak kosong
	F.S.	: X adalah nilai elemen TOP yang lama, elemen top yang
			  lama didealokasi, TOP(S) = Next(TOP(S)).
	Proses	: Menghapus X dari Stack S. */

/*	---- Operasi Lain ----- */
void PrintStack (Stack S);
/*	I.S.    : Stack mungkin kosong
	F.S.    : Jika stack tidak kosong, semua info yg disimpan pada 
			  elemen stack diprint
			  Jika stack kosong, hanya menuliskan "Stack kosong" */
int NbElmt (Stack S);
/*	Mengirimkan banyaknya elemen stack; mengirimkan 0 jika stack kosong */
void PopAll (Stack * S);
/* 	I.S.    : S terdefinisi, boleh kosong
	F.S.    : Jika S tidak kosong, semua elemen stack di-delete dan 
			  didealokasi
	Proses	: Delete semua elemen stack dan alamat elemen di-dealokasi */
void InversStack (Stack * S);
/*	I.S.    : S terdefinisi, boleh kosong
	F.S.    : Elemen stack S dibalik :
			  Elemen terakhir menjadi elemen pertama, dan seterusnya.
			  Membalik elemen stack, tanpa melakukan alokasi/dealokasi. */

#endif