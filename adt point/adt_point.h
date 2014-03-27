#include "boolean.h"

#ifndef adt_point_h
#define adt_point_h

/* DEFINISI ABSTRACT DATA TYPE POINT */
typedef struct {
	float X;
	float Y;
} POINT;

/* DEFINISI PROTOTIPE PRIMITIF */

/* KONSTRUKTOR MEMBENTUK POINT */
POINT MakePOINT (float X, float Y); 
/* 	Membentuk sebuah POINT dari komponen-komponennya */

/* SELEKTOR POINT */
#define GetAbsis(P) (P).X 
/* 	Mengirimkan komponen absis dari P */
#define GetOrdinat(P) (P).Y 
/* 	Mengirimkan komponen ordinat dari P */

/* SET NILAI KOMPONEN */
#define SetAbsis(P,newX) GetAbsis(P)=newX
/* 	Mengubah nilai komponen absis dari P dengan newX*/
#define SetOrdinat(P,newY) GetOrdinat(P)=newY 
/* 	Mengubah nilai komponen ordinat dari P dengan newY*/

/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS */
void BacaPOINT (POINT *P); 
/*	Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT 
	P berdasarkan dari nilai absis dan ordinat tersebut
	I.S. Sembarang
	F.S. P terdefinisi */
void TulisPOINT (POINT P);
/*	Nilai P ditulis ke layar dengan format "(X,Y)"
	I.S. P terdefinisi
	F.S. P tertulis di layer dengan format "(X,Y)" */

/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE */
POINT plus (POINT P1, POINT P2);
/* 	Menghasilkan POINT yang bernilai P1+P2 dengan operasi penjumlahan 
	vector */
POINT minus (POINT P1, POINT P2); 
/*	Menghasilkan POINT yang bernilai P1-P2 dengan spesifikasi pengurangan 
	dua buah POINT */
float dot (POINT P1, POINT P2);
/* 	Operasi perkalian P1.P2 : melakukan operasi dot product; 
	P1.P2=[x1,y2].[x2,y2] */
float cross (POINT P1, POINT P2);
/*	Operasi perkalian P1xP2 : melakukan operasi cross product;
	P1xP2=[x1,y1]T x [x2,y2]T yang menghasilkan determinan */

/* KELOMPOK OPERASI RELASIONAL TERHADAP POINT */
boolean EQ (POINT P1, POINT P2);
/* 	Mengirimkan true jika P1 = P2 */
boolean NEQ (POINT P1, POINT P2); 
/* 	Mengirimkan true jika P1 != P2 */
boolean lebihkecil (POINT P1, POINT P2); 
/* 	Mengirimkan true jika P1 < P2 */
boolean lebihbesar (POINT P1, POINT P2); 
/*	Mengirimkan true jika P1 > P2 */

/* KELOMPOK MENENTUKAN DI MANA P BERADA */
boolean IsOrigin (POINT P);
/* 	Menghasilkan true jika P berada di titik origin */
boolean IsOnSbX (POINT P);
/* 	Menghasilkan true jika P berada di sumbu X */
boolean IsOnSbY (POINT P);
/* 	Menghasilkan true jika P berada di sumbu Y */
int Kuadran (POINT P); 
/* 	Menghasilkan kuadran dari P : 1,2,3, atau 4 */

/* KELOMPOK OPERASI LAIN TERHADAP TYPE */
POINT NextX (POINT P);
/* 	Absis ditambah 1 */
POINT NextY (POINT P); 
/* 	Ordinat ditambah 1 */
POINT PlusDelta (POINT P, float deltaX, float deltaY); 
/* 	P=[Absis(P)+deltaX,Ordinat(P)+deltaY] */
POINT MirrorOf (POINT P, boolean SbX, boolean SbY); 
/* 	Menghasilkan salinan P yang dicerminkan tergantung nilai SbX dan SbY */
float Jarak0 (POINT P); 
/*	Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2);
/*	Menghitung panjang garis yang dibentuk P1 dan P2 */
void Geser (POINT *P, float deltaX, float deltaY); 
/*	P digeser sebesar deltaX dan deltaY */
void GeserKeSbX (POINT *P); 
/*	P digeser ke sumbu X */
void GeserKeSbY (POINT *P); 
/*	P digeser ke sumbu Y */
void Mirror (POINT *P, boolean SbX, boolean SbY); 
/* 	Mencerminkan P yang bergantung pada nilai SbX atau SbY */
void Putar (POINT *P, float Sudut); 
/*	P diputar sebesar Sudut derajat */

#endif