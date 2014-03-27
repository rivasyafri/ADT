#include "boolean.h"

#ifndef adt_jam_h
#define adt_jam_h

typedef struct {
	int HH;
	int MM;
	int SS;
} JAM;

/* DEFINISI PRIMITIF */

/* KELOMPOK VALIDASI TERHADAP TIPE */
boolean IsJamValid (int H, int M, int S);
/* 	Diberikan tiga buah integer lalu diperiksa 
	kebenaran untuk dijadikan komponen jam */

/* KONSTRUKTOR */
JAM MakeJAM (int HH, int MM, int SS);
/* 	Diberikan tiga buah nteger yang sudah diperiksa kebenaran komponennya
	untuk dijadikan jam */

/* SELEKTOR */
#define GetHour(J) (J).HH
/*	Mendapatkan bagian jam (HH) dari JAM */
#define GetMinute(J) (J).MM
/*	Mendapatkan bagian menit (MM) dari JAM */
#define GetSecond(J) (J).SS
/*	Mendapatkan bagian detik (SS) dari JAM */

/* PENGUBAH NILAI KOMPONEN */
#define SetHH(J,newHH) GetHour(J)=newHH
/*	Mengubah komponen jam (HH) dari J dengan newHH */
#define SetMM(J,newMM) GetMinute(J)=newMM
/*	Mengubah komponen menit (MM) dari J dengan newMM */
#define SetSS(J,newSS) GetSecond(J)=newSS
/*	Mengubah komponen detik (SS) dari J dengan newSS */

/* KELOMPOK BACA TULIS */
void BacaJam (JAM *J);
/* 	I.S. : J tidak terdefinisi
	F.S. : J terdefinisi dan merupakan jam yang valid
	Proses : mengulangi membaca komponen H,M,S sehingga membentuk J
	yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
void TulisJam (JAM J); 
/*	I.S. : J sembarang
	F.S. : Nilai J ditulis dg format HH:MM:SS
	Proses : menulis nilai setiap komponen J ke layar */

/* KELOMPOK KONVERSI TERHADAP TYPE */
int JamToDetik (JAM J);
/*	DIberikan sebuah JAM yang lalu dikonversi ke dalam detik dengan rumus
	second=36000*hour+60*minute+second */
JAM DetikToJam (int N);
/*	Mengkonversi detik ke Jam. Jika melebihi 1 hari maka dimodulus dulu 
	dengan 86400 (jumlah detik maksimum dalam sehari) lalu dibuat JAM */

/* KELOMPOK OPERASI TERHADAP TYPE */
boolean JEQ (JAM J1, JAM J2);
/*	Mengirim true jika J1=J2 */
boolean JNEQ (JAM J1, JAM J2); 
/* 	Mengirim true jika J1!=J2 */
boolean JLT (JAM J1, JAM J2); 
/* 	Mengirim true jika J1<J2 */
boolean JGT (JAM J1, JAM J2);
/*  Mengirim true jika J1>J2 */

/* OPERATOR ARITMATIKA JAM */
JAM JPlus (JAM J1, JAM J2);
/* 	Menghasilkan J1+J2 dalam bentuk JAM */
JAM JMinus (JAM J1, JAM J2); 
/*	Menghasilkan J1-J2 dalam bentuk JAM dengan prekondisi J1>=J2 */
JAM NextDetik (JAM J);
/*	Menghasilkan JAM yang telah ditambah 1 detik */
JAM NextNDetik (JAM J, int N);
/*	Menghasilkan JAM yang telah ditambah N detik */
JAM PrevDetik (JAM J);
/*	Menghasilkan JAM yang telah dikurangi 1 detik */
JAM PrevNDetik (JAM J, int N);
/*	Menghasilkan JAM yang telah dikurangi N detik */
int Durasi (JAM Jaw, JAM Jakh);
/* Mengirim Jakh-Jaw dalam detik, dengan kalkulasi hasilnya negatif jika Jaw > JAkhir */

#endif