/* Nama File :	Queue.h */
/* Deskripsi :	Class Queue
				Class ini digunakan untuk merepresentasikan bentuk antrian pada dunia nyata.
				Berisi tentang prosedur dan fungsi yang diakses untuk mengelola antrian
*/

#include <iostream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H
	
/*	PENENTUAN TIPE INFOTYPE DAN ADDRESS */
	typedef int infotype; // untuk elemen
	typedef int address; //	untuk indeks tabel

class Queue{
public:
	/*	Definisi Queue kosong: Head = Nil; TAIL = Nil.
		Catatan implementasi: C[0] tidak pernah dipakai */
	
	/* 5 SEKAWAN */
	Queue();
	// Constructor 
	/*	I.S.	: Bebas
		F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue
		Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak 100 */
	Queue(int MaxEl);
	// Constructor Berparameter
	/*	I.S.	: MaxEl terdefinisi
		F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue sesuai MaxEl
		Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak MaxEl */
	Queue(const Queue& Q);
	// Copy Constructor
	/*	I.S.	: Q terdefinisi
		F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue sesuai Q.MaxEl
		Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak Q.MaxEl */
	Queue& operator=(const Queue& Q);
	// Operasi Operator =
	/*	I.S.	: Q terdefinisi
		F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue sesuai Q.MaxEl
		Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak Q.MaxEl */
	~Queue();
	// Destructor
	/*	Proses 	: Mengembalikan memori Q
		I.S.	: Objek berclass Queue ada
		F.S.	: Objek dihapus dari memori dengan tabel penyimpanan didealokasi */

	/*	SELEKTOR */
	address Head();
	// Mengambil alamat head pada variabel berclass Queue
	address Tail();
	// Mengambil alamat tail pada variabel berclass Queue
	infotype InfoHead();
	// Mengambil isi dari alamat head pada variabel berclass Queue
	infotype InfoTail();
	// Mengambil isi dari alamat tail pada variabel berclass Queue
	int MaxEl();
	// Mengambil N yang ada pada variabel berclass Queue

	/*	PREDIKAT */
	bool IsEmpty ();
	/*	Mengirim true jika Q kosong */
	bool IsFull ();
	/*	Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung MaxEl elemen */
	int Count ();
	/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

	/*	OPERASI - OPERASI DASAR QUEUE */
	void Add (infotype X);
	/*	Proses 	: Menambahkan X pada variabel berclass Queue dengan aturan FIFO
		I.S.	: Variabel berclass Queue mungkin kosong dan tabel penampung elemen TIDAK penuh 
		F.S.	: X menjadi TAIL yang baru, TAIL "maju".
				  Jika TAIL baru = MaxEl + 1, maka TAIL diset = 1. */
	infotype Del ();
	/*	Proses 	: Menghapus elemen pertama pada variabel berclass Queue dengan aturan FIFO 
		I.S.	: Variabel berclass Queue tidak kosong
		F.S.	: X = nilai elemen HEAD pada I.S., Jika Queue masih isi : HEAD "maju".
				  Jika HEAD baru menjadi MaxEl + 1, maka HEAD diset = 1;
				  Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
	infotype DelJockey();

	/*	INPUT OUTPUT */
	friend ostream& operator<<(ostream &output, const Queue& Q) {
		if (Q.HEAD != 0) {
			output << "{";
			output << Q.Q[Q.HEAD];
			int i = Q.HEAD + 1;
			while (i != Q.TAIL) {
				output << "," << Q.Q[i];
				i++;
				if (i == Q.N+1) {
					i = 1;
				}
			}
			output << "}" << endl;
		} else {
			output << "{}" << endl;
		}
		return output;
	}

private:
	static const int Nil = 0;
	infotype *Q; /* tabel penyimpanan elemen */
	address HEAD; /* alamat penghapusan */
	address TAIL; /* alamat penambahan */
	int N; /* maksimum banyaknya elemen queue */
};

#endif
