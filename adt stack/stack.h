/* NIM / Nama	: 13512036 / Riva Syafri Rachmatullah				*/
/* Nama File	: stack.h											*/
/* Topik		: ADT STACK - Statis								*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: HEADER ADT STACK 									*/

/*	Modul ADT STACK - Statis */
/*	Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik 
	dan ukuran sama dengan TOP adalah alamat elemen puncak. */

/*	FILE INCLUDE */
#include "boolean.h"

#ifndef stack_h
#define stack_h

/*	KONSTANTA */
#define Nil 0 /* Nil adalah stack dengan elemen kosong */
#define MaxEl 10

/*	PENDEKLARASIAN TIPE */
typedef int infotype;
typedef int address; /* indeks tabel */
/*	Contoh deklarasi variabel bertype stack dengan ciri TOP :
	Versi I : dengan menyimpan tabel dan alamat top secara eksplisit */
typedef struct {
	infotype T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP; /* alamat TOP : elemen puncak */
} Stack;
/*	Definisi stack S kosong : S.TOP = Nil
	Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl]
	Jika S adalah Stack maka akses elemen :
	S.T[(S.TOP)] untuk mengakses elemen TOP
	S.TOP adalah alamat elemen TOP
	Definisi akses dengan Selektor : Isilah dengan selektor yang tepat */

/*	----- Prototype ----- */
/*	Konstruktor/Kreator */
void CreateEmpty (Stack *S);
/*	I.S.	: Sembarang
	F.S.	: Membuat sebuah stack S yang kosong berkapasitas MaxEl dengan indeksnya 
			  antara 1..MaxEl
	Ciri stack kosong : TOP bernilai Nil */

/*	----- Predikat Untuk test keadaan KOLEKSI ----- */
boolean IsEmpty (Stack S);
/*	Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S);
/*	Mengirim true jika tabel penampung nilai elemen stack penuh */

/*	----- Operator Dasar Stack ----- */
void Push (Stack *S, infotype X);
/*	Menambahkan X sebagai elemen Stack S.
	I.S.	: S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. 	: X menjadi TOP yang baru, TOP bertambah 1 */
void Pop (Stack *S, infotype X);
/*	Menghapus X dari Stack S.
	I.S. 	: S  tidak kosong
	F.S.	: X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif