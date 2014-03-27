/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036		*/
/* Nama File	: */
/* Topik		: ADT TABEL KONTIGU IMPLISIT DINAMIK 		*/
/* Tanggal		: */
/* Deskripsi	: HEADER ADT TABEL KONTIGU IMPLISIT DINAMIK	*/

/* File Include */
#include "boolean.h"
#include <stdlib.h>

#ifndef adttabel_h
#define adttabel_h

/*	Definisi elemen dan koleksi objek */
typedef int IdxType; 	/* type indeks */
typedef int ElType; 	/* type elemen tabel */
typedef struct {
	ElType *TI; 		/* memori tempat penyimpanan elemen (container)*/
	int Size; 			/* ukuran tabel */
} TabInt;
typedef struct {
	ElType max;
	ElType min;
} tuple;

/*	Tabel Kosong itu berarti semua elemen tabel berisi ValUndef */
/*	Definisi elemen pertama : T.TI[i] dengan i=1 */

/*	KONSTRUKTOR */
void MakeEmpty (int N, TabInt *T);
/*	I.S.	: kondisi bebas */
/*	F.S.	: Terbentuk tabel T kosong dengan kapasitas maksimum N 
			  dengan semua elemen bernilai ValUndef */

/*	--- SELEKTOR --- */
/* 	Banyaknya Elemen */
int NbElmt (TabInt T); 
/* 	Mengirimkan banyaknya elemen efektif tabel dan mengirimkan nol jika 
	tabel kosong */

/* 	Daya Tampung Container */
int MaxNbEl (TabInt T); 
/*	Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/*	Selektor Indeks */
IdxType GetFirstIdx (TabInt T);
/* 	Prekondisi : Tabel T tidak kosong */
/* 	Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (TabInt T);
/* 	Prekondisi : Tabel T tidak kosong */
/* 	Mengirimkan indeks elemen terakhir */

/* 	Menghasilkan sebuah elemen */
ElType GetElmt (TabInt T, IdxType i);
/* 	Prekondisi : Tabel T tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* 	Mengirimkan elemen tabel yang ke-i */

/*	Selektor Set */
void SetTab (TabInt Tin, TabInt *Tout);
/*	I.S.	: Tin terdefinisi, sembarang
   	F.S.	: Tout berisi salinan Tin */
void SetEl (TabInt *T, IdxType i, ElType v);
/* 	I.S.	: T terdefinisi, sembarang
   	F.S.	: Elemen T yang ke-i bernilai v
   	Proses	: Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetSize (TabInt *T, IdxType N);
/* 	I.S. 	: T terdefinisi, sembarang
   	F.S.	: Nilai indeks efektif T bernilai N
   	Proses	: Mengeset nilai indeks elemen efektif sehingga bernilai N */  

/* 	--- TEST INDEKS YANG VALID --- */
boolean IsIdxValid (TabInt T, IdxType i);
/*	Prekondisi : i sembarang
	Mengirimkan true jika i adalah indeks yang valid untuk ukuran tabel 
	yaitu antara indeks yang terdefinisi untuk container */
boolean IsIdxEff (TabInt T, IdxType i);
/* 	Prekondisi : i sembarang
	Mengirimkan true jika i adalah indeks yang terdefinisi untuk tabel 
	yaitu antara FirstIdx(T) ke LastIdx(T) */

/* 	--- TEST KOSONG/PENUH --- */
/* 	Test tabel kosong */
boolean IsEmpty (TabInt T);
/*	Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/*	Test tabel penuh */
boolean IsFull (TabInt T);
/*	Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/*	--- BACA dan TULIS dengan INPUT/OUTPUT device --- */
/*	Mendefinisikan isi tabel dari pembacaan */
void BacaIsi (TabInt *T);
/*	I.S.	: sembarang
	F.S.	: tabel T terdefinisi
	Proses	: membaca banyaknya elemen T dan mengisi nilainya */
void TulisIsi (TabInt T);
/*	Proses 	: Menuliskan isi tabel dengan traversal
	I.S.	: T boleh kosong
	F.S.	: Jika T tidak kosong maka indeks dan elemen tabel ditulis 
			  berderet ke bawah
			  Jika T kosong maka hanya menulis "Tabel kosong" */
void TulisIsiTab (TabInt T);
/*	Proses 	: Menuliskan isi tabel dengan traversal, tabel ditulis 
			  di antara kurung siku; antara dua elemen dipisahkan dengan 
			  separator "koma"
	I.S. 	: T boleh kosong
	F.S. 	: Jika T tidak kosong: [e1, e2, ... ,en]
	Contoh 	: Jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30]
			  Jika tabel kosong : menulis [] */

/*	--- OPERATOR ARITMATIKA --- */
/*	Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... */
TabInt PlusTab (TabInt T1,  TabInt T2);
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
	Mengirimkan  T1 + T2 */
TabInt MinusTab (TabInt T1, TabInt T2);
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
	Mengirimkan T1 - T2 */
TabInt KaliTab (TabInt T1, TabInt T2);
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
	Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang 
	sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c);
/*	Prekondisi : Tin tidak kosong
	Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/*	--- OPERATOR RELASIONAL --- */
/*	Operasi pembandingan tabel : < =, > */
boolean IsEQ (TabInt T1, TabInt T2);
/*	Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2
	dan semua elemennya sama */
boolean IsLess (TabInt T1, TabInt T2);
/*	Mengirimkan true jika T1 < T2, yaitu : sesuai dg analogi 'Ali' < Badu';
	maka [0, 1] < [2, 3] */

/*	--- SEARCHING --- */
/*	Tabel boleh kosong */
IdxType Search1 (TabInt T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X
	Jika tidak ada, mengirimkan IdxUndef
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong
	Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X
	Jika tidak ada, mengirimkan IdxUndef
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong
	Memakai skema search DENGAN boolean Found */
boolean SearchB (TabInt T, ElType X); 
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan true, jika tidak ada menghasilkan false
	Memakai Skema search DENGAN boolean */
boolean SearchSentinel (TabInt T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada menghasilkan Indeks yang dicari
	jika tidak ada menghasilkan IdxUndef
	dengan metoda sequential search dengan sentinel
	Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam
	Bahasa C yang tidak dipakai dalam definisi tabel
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */ 

/* 	--- NILAI EKSTREM --- */
ElType ValMax (TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan nilai minimum tabel */

/*	Mengirimkan indeks elemen bernilai ekstrem */
IdxType IdxMaxTab (TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum 
	pada tabel */
IdxType IdxMinTab (TabInt T);
/*	Prekondisi : Tabel tidak kosong 
	Mengirimkan indeks i dengan elemen ke-i nilai minimum pada tabel

/*  --- OPERASI LAIN --- */
void CopyTab (TabInt Tin,TabInt *Tout);
/*	I.S.	: sembarang
	F.S.	: Tout berisi salinan dari Tin (elemen dan ukuran identik)
	Proses 	: Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T);
/*	Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : 
	elemen pertama menjadi terakhir,
	elemen kedua menjadi elemen sebelum terakhir, dst.. 
	Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (TabInt T);
/*	Menghasilkan true jika tabel simetrik. Tabel disebut simetrik jika:
    elemen pertama = elemen terakhir,
    elemen kedua = elemen sebelum terakhir, dan seterusnya
    Tabel kosong adalah tabel simetris */

/*	--- SORTING --- */
void MaxSortDesc (TabInt *T); 
/*	I.S.	: T boleh kosong
	F.S. 	: T elemennya terurut menurun dengan Maximum Sort
	Proses 	: mengurutkan T sehingga elemennya menurun/mengecil
			  tanpa menggunakan tabel kerja */
void InsSortAsc (TabInt *T);
/*	I.S.	: T boleh kosong
	F.S. 	: T elemennya terurut menaik dengan Insertion Sort
	Proses 	: mengurutkan T sehingga elemennya menaik/membesar 
			  tanpa menggunakan tabel kerja */

/*	--- MENAMBAH ELEMEN --- */
/*	Menambahkan elemen terakhir */
void AddAsLastEl (TabInt *T, ElType X);
/*	Menambahkan X sebagai elemen terakhir tabel
	I.S.	: Tabel boleh kosong, tetapi tidak penuh
	F.S. 	: X adalah elemen terakhir T yang baru
	Proses 	: Menambahkan sebagai elemen ke-i yang baru */
void AddEli (TabInt *T, ElType X, IdxType i);
/*	Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
	terhadap elemen yang sudah ada
	I.S. 	: Tabel tidak kosong dan tidak penuh dengan i adalah indeks
			  yang valid.
	F.S. 	: X adalah elemen ke-i T yang baru
	Proses 	: Geser elemen ke-i+1 s.d. terakhir dengan mengisi elemen ke-i
			  dengan X */  

/*	--- MENGHAPUS ELEMEN --- */
void DelLastEl (TabInt *T, ElType *X);
/*	Menghapus elemen terakhir tabel
	I.S. 	: Tabel tidak kosong
	F.S. 	: X adalah nilai elemen terakhir T sebelum penghapusan, 
			  Banyaknya elemen tabel berkurang satu. 
			  Tabel T mungkin menjadi kosong */
void DelEli(TabInt *T, IdxType i, ElType *X);
/*	Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas
	I.S. 	: Tabel tidak kosong, i adalah indeks efektif yang valid
	F.S. 	: Elemen T berkurang satu. Banyaknya elemen tabel berkurang
			  satu. Tabel T mungkin menjadi kosong
	Proses 	: Geser elemen ke-i+1 s.d. elemen terakhir. Kurangi elemen 
			  efektif tabel */

/*	--- TABEL DENGAN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) --- */
void AddElUnik (TabInt *T, ElType X);
/*	Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen
	unik
	I.S.	: Tabel boleh kosong, tetapi tidak penuh dan semua elemennya 
			  bernilai unik, tidak terurut
	F.S. 	: Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
			  jika belum ada elemen yang bernilai X. 
			  Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
			  dan dituliskan pesan "nilai sudah ada"
	Proses 	: Cek keunikan dengan sequential search dengan sentinel 
			  kemudian tambahkan elemen jika belum ada */

/*	--- TABEL DENGAN ELEMEN TERURUT MEMBESAR --- */
IdxType SearchUrut (TabInt T, ElType X);
/*	Prekondisi	: Tabel boleh kosong. Jika tidak kosong, elemen terurut 
				  membesar.
	mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan
	mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
ElType Max (TabInt T);
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai maksimum pada tabel */
ElType Min (TabInt T);
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai minimum pada tabel */
tuple MaxMin (TabInt T);
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai maksimum dan minimum pada tabel */
void Add1Urut (TabInt *T, ElType X);
/*	Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel
	Nilai dalam tabel tidak harus unik.
	I.S.	: Tabel boleh kosong, boleh penuh. Jika tabel isi, 
			  elemennya terurut membesar.
	F.S.	: Jika tabel belum penuh, menambahkan X.
			  Jika tabel penuh, maka tabel tetap.
	Proses 	: Search tempat yang tepat sambil geser 
			  Insert X pada tempat yang tepat tersebut tanpa mengganggu 
			  keterurutan */
void Del1Urut (TabInt *T, ElType X);
/*	Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan
	I.S. 	: Tabel tidak kosong 
	F.S.	: Jika ada elemen tabel bernilai X, maka banyaknya elemen 
			  tabel berkurang satu.
			  Jika tidak ada yang bernilai X, tabel tetap.
			  Setelah penghapusan, elemen tabel tetap kontigu!
	Proses	: Search indeks ke-i dengan elemen ke-i=X.
			  Delete jika ada. */

/*	Dealokasi Memori */
void Dealokasi (TabInt *T);
/* 	I.S 	: Tabel T Terdefinisi
	F.S 	: Alokasi memori Tabel T dihilangkan */

#endif