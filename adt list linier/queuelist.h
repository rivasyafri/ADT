/* NIM / Nama		: 13512036 / Riva Syafri Rachmatullah				*/
/* Nama File		: queuelist.h 										*/
/* Topik			: ADT Queue - Representasi List Linier				*/
/* Tanggal			: 21 November 2013									*/
/* Deskripsi		: Header dari ADT Queue Representasi List Linier 	*/

#ifndef queuelist_h
#define queuelist_h

/*	----- File Include ----- */
#include "boolean.h"
#include <stdlib.h>

/*	----- Konstanta ----- */
#define Nil NULL

/*	----- Deklarasi Tipe Bentukan ----- */
/* Tipe Info */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;
typedef struct tElmtQueue {
	infotype Info;
	address Next;
} ElmtQueue;

/*	Type Queue dengan ciri HEAD dan TAIL */
typedef struct {
	address HEAD; /* Alamat penghapusan */
	address TAIL; /* Alamat penambahan */
} Queue;

/*	----- Selektor ----- */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/*	----- Prototype manajemen memori ----- */
void Alokasi (address * P, infotype X);
/*	I.S.	: P sembarang, X terdefinisi
	F.S.	: Alamat P dialokasi, jika berhasil maka Info(P) = X
			  dan Next(P) = Nil. P = Nil jika alokasi gagal */
void Dealokasi (address * P);
/*	I.S.	: P adalah hasil alokasi, P != Nil
	F.S.	: Alamat P didealokasi, dikembalikan ke sistem */

/*	----- Predikat Pemeriksaan Kondisi Queue ----- */
boolean IsEmpty (Queue Q);
/*	Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */
int NBElmt (Queue Q);
/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/*	----- Konstruktor ----- */
void CreateEmpty (Queue * Q);
/*	I.S.	: sembarang
	F.S.	: Sebuah Q kosong terbentuk */

/*	----- Primitif Add/Delete ----- */
void Add (Queue * Q, infotype X);
/*	Proses	: Mengalokasi X dan menambahkan X pada bagian TAIL dari
			  Q jika alokasi berhasil; jika alokasi gagal Q tetap
	I.S. 	: Q mungkin kosong
	F.S. 	: X menjadi TAIL, TAIL "maju" */
void Del (Queue * Q, infotype * X);
/*	Proses	: Menghapus X pada bagian HEAD dari Q dan mendealokasi
			  elemen HEAD
	I.S.	: Q tidak mungkin kosong
	F.S.	: X = nilai elemen HEAD pd I.S., HEAD "mundur" */

/*	---- Operasi Lain ----- */
void PrintQueue (Queue Q);
/*	I.S.    : Queue mungkin kosong
	F.S.    : Jika queue tidak kosong, semua info yg disimpan pada 
			  elemen queue diprint
			  Jika queue kosong, hanya menuliskan "Queue kosong" */
void DelAll (Queue * Q);
/* 	I.S.    : Q terdefinisi, boleh kosong
	F.S.    : Jika Q tidak kosong, semua elemen queue di-delete dan 
			  didealokasi
	Proses	: Delete semua elemen queue dan alamat elemen di-dealokasi */

#endif