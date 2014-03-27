#include "boolean.h"
#include "adt_point.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define phi 3.14

/* DEFINISI PROTOTIPE PRIMITIF */

/* KONSTRUKTOR MEMBENTUK POINT */
POINT MakePOINT (float X, float Y) {
	POINT P;
	SetAbsis(P,X);
	SetOrdinat(P,Y);
	return P;
} // Membentuk sebuah POINT dari komponen-komponennya

/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS */
void BacaPOINT (POINT *P) {
	float x,y;
	scanf("%f %f",&x,&y);
	SetAbsis((*P),x);
	SetOrdinat((*P),y);
} // Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P
void TulisPOINT (POINT P) {
	printf("(%.2f,%.2f)\n",GetAbsis(P),GetOrdinat(P));
} // Menulis P dengan format "(X,Y)"

/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE */
POINT plus (POINT P1, POINT P2) {
	POINT P;
	SetAbsis(P,GetAbsis(P1)+GetAbsis(P2));
	SetOrdinat(P,GetOrdinat(P1)+GetOrdinat(P2));
	return P;
} // Menghasilkan POINT yang bernilai P1+P2 dengan operasi penjumlahan vector
POINT minus (POINT P1, POINT P2) {
	POINT P;
	SetAbsis(P,GetAbsis(P1)-GetAbsis(P2));
	SetOrdinat(P,GetOrdinat(P1)-GetOrdinat(P2));
	return P;
} // Menghasilkan POINT yang bernilai P1-P2 dengan spesifikasi pengurangan dua buah POINT
float dot (POINT P1, POINT P2) {
	return GetAbsis(P1)*GetAbsis(P2) + GetOrdinat(P1)*GetOrdinat(P2);
} // Operasi perkalian P1.P2 : melakukan operasi dot product; P1.P2=[x1,y2].[x2,y2]
float cross (POINT P1, POINT P2) {
	return GetAbsis(P1)*GetOrdinat(P2) - GetOrdinat(P1)*GetAbsis(P2);
} // Operasi perkalian P1xP2 : melakukan operasi cross product; P1xP2=[x1,y1]T x [x2,y2]T

/* KELOMPOK OPERASI RELASIONAL TERHADAP POINT */
boolean EQ (POINT P1, POINT P2) {
	return ((GetAbsis(P1))==(GetAbsis(P2))) && ((GetOrdinat(P1))==(GetOrdinat(P2)));
} // Mengirimkan true jika P1 = P2
boolean NEQ (POINT P1, POINT P2){
	return ((GetAbsis(P1))!=(GetAbsis(P2))) || ((GetOrdinat(P1))!=(GetOrdinat(P2)));
} // Mengirimkan true jika P1 != P2
boolean lebihkecil (POINT P1, POINT P2) {
	return ((GetAbsis(P1))<(GetAbsis(P2))) && ((GetOrdinat(P1))<(GetOrdinat(P2)));
} // Mengirimkan true jika P1 < P2
boolean lebihbesar (POINT P1, POINT P2) {
	return ((GetAbsis(P1))>(GetAbsis(P2))) && ((GetOrdinat(P1))>(GetOrdinat(P2)));
} // Mengirimkan true jika P1 > P2

/* KELOMPOK MENENTUKAN DI MANA P BERADA */
boolean IsOrigin (POINT P) {
	return (GetAbsis(P)==0)&&(GetOrdinat(P)==0);
}
boolean IsOnSbX (POINT P) {
	return (GetOrdinat(P)==0);
}
boolean IsOnSbY (POINT P) {
	return (GetAbsis(P)==0);
}
int Kuadran (POINT P) {
	if ((GetAbsis(P)>0)&&(GetOrdinat(P)>0)) {
		return 1;
	} else if ((GetAbsis(P)>0)&&(GetOrdinat(P)<0)) {
		return 4;
	} else if ((GetAbsis(P)<0)&&(GetOrdinat(P)>0)) {
		return 2;
	} else if ((GetAbsis(P)<0)&&(GetOrdinat(P)<0)) {
		return 3;
	}
} // Menghasilkan kuadran dari P : 1,2,3, atau 4

/* KELOMPOK OPERASI LAIN TERHADAP TYPE */
POINT NextX (POINT P) {
	return MakePOINT(GetAbsis(P)+1,GetOrdinat(P));
} // Absis ditambah 1
POINT NextY (POINT P) {
	return MakePOINT(GetAbsis(P),GetOrdinat(P)+1);
} // Ordinat ditambah 1
POINT PlusDelta (POINT P, float deltaX, float deltaY) {
	return MakePOINT(GetAbsis(P)+deltaX,GetOrdinat(P)+deltaY);
} // P=[Absis(P)+deltaX,Ordinat(P)+deltaY]
POINT MirrorOf (POINT P, boolean SbX, boolean SbY) {
	POINT Point = P;
	if (SbX) {
		SetOrdinat(Point,-GetOrdinat(P));
	}
	if (SbY) {
		SetAbsis(Point,-GetAbsis(P));
	}
	return Point;
} // Menghasilkan salinan P yang dicerminkan tergantung nilai SbX dan SbY
float Jarak0 (POINT P) {
	return sqrt((GetAbsis(P))*(GetAbsis(P))+(GetOrdinat(P))*(GetOrdinat(P)));
} // Menghitung jarak P ke (0,0)
float Panjang (POINT P1, POINT P2) {
	return sqrt((GetAbsis(P1)-GetAbsis(P2))*(GetAbsis(P1)-GetAbsis(P2))+(GetOrdinat(P1)-GetOrdinat(P2))*(GetOrdinat(P1)-GetOrdinat(P2)));
} // Menghitung panjang garis yang dibentuk P1 dan P2
void Geser (POINT *P, float deltaX, float deltaY) {
	SetAbsis(*P,GetAbsis(*P)+deltaX);
	SetOrdinat(*P,GetAbsis(*P)+deltaY);
} // P digeser sebesar deltaX dan deltaY
void GeserKeSbX (POINT *P) {
	SetOrdinat(*P,0);
} // P digeser ke sumbu X
void GeserKeSbY (POINT *P) {
	SetAbsis(*P,0);
} // P digeser ke sumbu Y
void Mirror (POINT *P, boolean SbX, boolean SbY) {
	if (SbX) {
		SetOrdinat(*P,-GetOrdinat(*P));
	}
	if (SbY) {
		SetAbsis(*P,-GetAbsis(*P));
	}
} // Mencerminkan P yang bergantung pada nilai SbX atau SbY
void Putar (POINT *P, float Sudut) {
	float Radian,x,y;
	Radian=(Sudut*phi)/180;
	/* fungsi cos dan sin membaca dengan sudut radial bukan derajat */
	x=GetAbsis(*P);
	y=GetOrdinat(*P);
	SetAbsis(*P,cos(Radian)*x - sin(Radian)*y);
	SetOrdinat(*P,sin(Radian)*x + cos(Radian)*y);
} // P diputar sebesar Sudut derajat