/* NIM / Nama		 : 13512036 / Riva Syafri Rachmatullah			        */
/* Nama File		 : list.h                                           */
/* Topik 		     : ADT List Linier - First Implisit                 */
/* Tanggal			 : 27 Oktober 2013                                  */
/* Deskripsi		 : Header dari ADT List Linier versi First Implisit */

#ifndef list_h
#define list_h

/* ----- File Include ----- */
#include "boolean.h"

/* ----- Konstanta ----- */
#define Nil NULL

/* ----- Tipe-tipe bentukan ----- */
typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype Info;
	address Next;
} ElmtList;
typedef address List

/* ----- Cara Pemanggilan ----- */
/* Jika L : List dan P : address (address untuk traversal), 
   maka penulisan :
   First(L) menjadi L
   Next(P)  menjadi P↑.Next
   Info(P)  menjadi P↑.Info
*/  

/* ----- Selektor ----- */
#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define First(L) (L)

/* ----- Test List Kosong ----- */
boolean IsListEmpty (List L);
/* Mengirim true jika list kosong */

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L);
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, 
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */

/* ----- Pencarian Sebuah Elemen List ----- */
address Search (List L, infotype X);
/* Mencari apakah ada elemen list dengan Info(P) = X
   Jika ada, mengirimkan address elemen tersebut
   Jika tidak ada, mengirimkan Nil */
boolean FSearch (List L, address P);
/* Mencari apakah ada elemen list yang beralamat P
   Mengirimkan true jika ada, false jika tidak ada */
address SearchPrec (List L, infotype X);
/* Mengirimkan address elemen sebelum elemen yang nilainya = X
   Mencari apakah ada elemen list dengan Info(P) = X
   Jika ada, mengirimkan address Prec, dengan
   Next(Prec) = P dan Info(P) = X
   Jika tidak ada, mengirimkan Nil
   Jika P adalah elemen pertama, maka mengirimkan Nil
   Search dengan spesifikasi seperti ini menghindari traversal ulang 
   jika setelah Search akan dilakukan operasi lain */

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X);
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen 
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVLast (List *L, infotype X);
/* I.S. 	: L mungkin kosong 
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu 
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X);
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X);
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P);
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec);
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P);
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelP (List *L, infotype X);
/* I.S.     : Sembarang
   F.S.     : Jika ada elemen list beraddress P, dengan Info(P) = X
              Maka P dihapus dari list dan di-dealokasi
              Jika tidak ada elemen list dengan Info(P) = X, 
              maka list tetap.
              List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang 
              lama, jika ada */
void DelAfter (List *L, address *Pdel, address Prec);
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) : 
              Pdel adalah alamat elemen list yang dihapus

/* Proses Semua Elemen List */
void PrintInfo (List L);
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/* Prekondisi untuk Max/Min/rata-rata : List tidak kosong */
infotype Max (List L);
/* Mengirimkan nilai Info(P) yang maksimum */
address AdrMax (List L);
/* Mengirimkan address P, dengan Info(P) yang bernilai maksimum */
infotype Min (List L);
/* Mengirimkan nilai Info(P) yang minimum */
address AdrMin (List L);
/* Mengirimkan address P, dengan Info(P) yang bernilai minimum */
real Average (List L);
/* Mengirimkan nilai rata-rata Info(P) */

/* ----- Proses Terhadap List */
void DelAll (List *L);
/* Delete semua elemen list dan alamat elemen di-dealokasi
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
void CopyList (List *L1, List *L2);
/* I.S.     : L1 terdefinisi, L2 sembarang.
   F.S.     : L2 = L1
              L1 dan L2 "menunjuk" kepada list yang sama.
              Tidak ada alokasi/dealokasi elemen baru. */
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

