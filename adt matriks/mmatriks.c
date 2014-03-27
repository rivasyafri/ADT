/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: mmatriks.c										*/
/* Topik		: ADT MATRIKS 										*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: DRIVER ADT MATRIKS								*/

#include "matriks.h"

int main () {
	/* Kamus */
	MATRIKS M1,M2;
	int NBar1, NKol1, NBar2, NKol2;
	int pil;
	
	/* Algoritma */
	printf("Matriks 1\n");
	printf("Ukuran efektif baris (%d-%d) = ", BrsMin, BrsMax); //Asumsi: Masukan ukuran baris selalu benar
	scanf("%d",&NBar1);
	printf("Ukuran efektif kolom (%d-%d) = ", KolMin, KolMax); //Asumsi: Masukan ukuran kolom selalu benar
	scanf("%d",&NKol1);
	BacaMATRIKS(&M1,NBar1,NKol1);
	printf("Matriks 2\n");
	printf("Ukuran efektif baris (%d-%d) = ", BrsMin, BrsMax); //Asumsi: Masukan ukuran baris selalu benar
	scanf("%d",&NBar2);
	printf("Ukuran efektif kolom (%d-%d) = ", KolMin, KolMax); //Asumsi: Masukan ukuran kolom selalu benar
	scanf("%d",&NKol2);
	BacaMATRIKS(&M2,NBar2,NKol2);
	TulisMATRIKS(M1);
	printf("\n");
	TulisMATRIKS(M2);
	printf("%f\n",Determinan(M1));
	printf("%f\n",DeterminanLaplace(M2));
	TulisMATRIKS(Inversf(M1));
	TulisMATRIKS(Plus(M1,M2));
	TulisMATRIKS(Kali2Matriks(M1,M2));
	return 0;
}