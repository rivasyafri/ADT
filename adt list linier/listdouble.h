/* NIM / Nama		 : 13512036 / Riva Syafri Rachmatullah			*/
/* Nama File		 : listdouble.h 					*/
/* Topik 		 	 : ADT List Linier - Double pointer			*/
/* Tanggal		 	 : 7 November 2013 					*/
/* Deskripsi		 : Header dari ADT List Linier versi Double Pointer 	*/

#ifndef listdouble_h
#define listdouble_h

/* ----- File Include ----- */
#include "boolean.h"

/* ----- Konstanta ----- */
#define Nil NULL /* address tidak terdefinisi */

/* ----- Tipe-tipe Bentukan ----- */
typedef int infotype; /* tipe elemen */
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype Info; /* container elemen */
	address Prev; /* container address sebelumnya */
	address Next; /* container address selanjutnya */
} ElmtList; /* container gerbong */

typedef struct {
	address First; /* First List */
	address Last; /* Last List */
} List;

/* ----- Selektor ----- */
#define Info(P) (P)->Info /* Mengakses info */
#define Next(P) (P)->Next /* Alamat selanjutnya */
#define Prev(P) (P)->Prev /* Alamat sebelumnya */
#define First(L) (L).First
#define Last(L) (L).Last

/* ----- Test List Kosong ----- */
boolean IsListEmpty (List L);
/*	Mengirim true jika list kosong, yaitu First(L) = Nil dan Last(L) = Nil */

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L);
/*	I.S.	: Sembarang
	F.S.	: Terbentuk list L kosong */

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X);
/*	Mengirimkan address hasil alokasi sebuah elemen.
	Jika alokasi berhasil, maka address tidak Nil, 
	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil,
	dan Prev(P) = Nil.
	Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* 	Melakukan dealokasi/pengembalian address P
	I.S.	: P terdefinisi
	F.S.	: P dikembalikan ke sistem */

/* ----- Pencarian Sebuah Elemen List ----- */
boolean FSearch (List L, address P);
/*	Mencari apakah ada elemen list yang beralamat P
	Mengirimkan true jika ada, false jika tidak ada */
address Search (List L, infotype X);
/*	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan address elemen tersebut
	Jika tidak ada, mengirimkan Nil */

/* ----- Primitif Berdasarkan Nilai ----- */
/* ----- Penambahan Elemen ----- */
void InsVFirst (List *L, infotype X);
/*	I.S.	: L mungkin kosong
	F.S.	: Melakukan alokasi sebuah elemen dan menambahkan elemen pertama
			  dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X);
/*	I.S.	: L mungkin kosong
	F.S.	: Melakukan alokasi sebuah elemen dan menambahkan elemen list di
			  sebelum elemen akhir bernilai X jika alokasi berhasil.
			  Jika alokasi gagal: I.S. = F.S. */

/* ----- Penghapusan Elemen ----- */
void DelVFirst (List *L, infotype *X);
/*	I.S.	: List L tidak kosong 
	F.S.	: Elemen pertama list dihapus dan nilai info disimpan pada X
			  dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X);
/*	I.S.	: List tidak kosong
	F.S.	: Elemen terakhir dihapus dan nilai info disimpan pada X
		      dan alamat elemen terakhir di-dealokasi */

/* ----- Primitif Berdasarkan Alamat ----- */
/* ----- Penambahan Elemen Berdasarkan Alamat ----- */
void InsertFirst (List *L, address P);
/*	I.S.	: Sembarang, P sudah dialokasi
	F.S.	: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec);
/*	I.S.	: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
	F.S.	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P);
/*	I.S.	: Sembarang, P sudah dialokasi
	F.S.	: P ditambahkan sebagai elemen terakhir yang baru */

/* ----- Penghapusan Sebuah Elemen ----- */
void DelFirst (List *L, address *P);
/*	I.S.	: List tidak kosong
	F.S.	: P adalah alamat elemen pertama list sebelum penghapusan
			  Elemen list berkurang satu (mungkin menjadi kosong)
			  First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P);
/*	I.S.	: List tidak kosong
	F.S.	: P adalah alamat elemen terakhir pada list sebelum penghapusan
			  Elemen list berkurang satu (mungkin menjadi kosong) */
void DelAfter (List *L, address *Pdel, address Prec);
/*	I.S.	: List tidak kosong. Prec adalah anggota list.
	F.S.	: Menghapus Next(Prec) dengan Pdel adalah alamat elemen list
			  yang dihapus

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L);
/*	I.S.	: List mungkin kosong
	F.S.	: Jika list tidak kosong, semua info yg disimpan pada elemen
			  list diprint
			  Jika list kosong, hanya menuliskan "list kosong" */

/* ----- Operasi Lain ----- */
address SearchPrec (List L, infotype X);
/* 	Mengirimkan address elemen sebelum elemen yang nilainya = X
	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan address Prec, dengan
	Next(Prec) = P dan Info(P) = X
	Jika tidak ada, mengirimkan Nil
	Jika P adalah elemen pertama, maka mengirimkan Nil
	Search dengan spesifikasi seperti ini menghindari traversal ulang 
	jika setelah Search akan dilakukan operasi lain */
void DelP (List *L, address *P);
/*	I.S.	: Sembarang
	F.S.	: Jika ada elemen list beraddress P,
			  Maka P dihapus dari list dan di-dealokasi
			  Jika tidak ada elemen list dengan Info(P) = X, 
			  maka list tetap.
			  List mungkin menjadi kosong karena penghapusan */
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/* ----- Proses Terhadap List */
void DelAll (List *L);
/* 	Delete semua elemen list dan alamat elemen di-dealokasi
	I.S.     : L terdefinisi, boleh kosong
	F.S.     : Jika L tidak kosong, semua elemen list di-delete dan 
			   didealokasi */
void InversList (List *L);
/* I.S.     : L terdefinisi, boleh kosong
	F.S.     : Elemen list L dibalik :
				  Elemen terakhir menjadi elemen pertama, dan seterusnya.
				  Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
List FInversList (List L);
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen
	list. Alokasi mungkin gagal. Jika alokasi gagal, hasilnya list kosong
	dan semua elemen yang terlanjur di-alokasi, harus didealokasi. */ 
List FCopyList (List L);
/* Mengirimkan list yang merupakan salinan L dengan melakukan alokasi
	elemen baru. Jika ada alokasi gagal, hasilnya list kosong dan semua 
	elemen yang terlanjur dialokasi, harus didealokasi. */
void CpAlokList (List Lin, List *Lout);
/* I.S.     : Lout sembarang, Lin terdefinisi.
	F.S.     : Jika semua alokasi berhasil, maka Lout berisi hasil copy 
				  Lin. Jika ada alokasi yang gagal, maka Lout = Nil dan 
				  semua elemen yang terlanjur dialokasi, didealokasi */
void Konkat (List L1, List L2, List *L3);
/* I.S.     : L1 dan L2 terdefinisi, boleh kosong.
	F.S.     : L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 dan L2
				  Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi 
				  L1 dan L2. Jika ada alokasi yang gagal, semua elemen yang 
				  sudah dialokasi harus didealokasi dan L3 = Nil. Konkatenasi
				  dua buah list : L1 dan L2 menghasilkan L3 yang "baru". 
				  Elemen L3 adalah hasil alokasi elemen yang "baru". Jika
				  ada alokasi yang gagal, maka L3 harus bernilai Nil dan 
				  semua elemen yang pernah dialokasi harus didealokasi. */
void Konkat1 (List *L1, List *L2, List *L3);
/* I.S.     : L1 dan L2 sembarang
	F.S.     : L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 dan L2
				  Konkatenasi dua buah list : 
				  L1 dan L2  menghasilkan L3 yang baru (dengan elemen list
				  L1 dan L2) dan L1 serta L2 menjadi list kosong.
				  Tidak ada alokasi/dealokasi pada prosedur ini */
void PecahList (List *L1, List *L2, List L);
/* I.S.     : L mungkin kosong
	F.S.     : Berdasarkan L, dibentuk dua buah list L1 dan L2
				  L tidak berubah : untuk membentuk L1 dan L2 harus alokasi.
				  L1 berisi separuh elemen L dan L2 berisi sisa elemen L.
				  Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2. */

#endif