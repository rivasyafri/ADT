/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: mmesinkata1.c										*/
/* Topik		: ADT MESIN KATA									*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: DRIVER MESIN KATA									*/

/* Mesin yang dipakai  */
#include "mesinkar1.h"
#include "mesinkata1.h"
/*	File Include */
#include "boolean.h"
#include <stdio.h>

/* Kamus global  */
extern char CC;
extern Kata CKata;
extern boolean EndKata;

/* Program Utama */
int main() {
	/* Kamus */
	Kata KataWHILE;
	int NWhile=0;
	/* ALgoritma */
	KataWHILE.length=5;
	KataWHILE.TabKata[1]='w';
	KataWHILE.TabKata[2]='h';
	KataWHILE.TabKata[3]='i';
	KataWHILE.TabKata[4]='l';
	KataWHILE.TabKata[5]='e';
	STARTKATA();
	while ((!EndKata)&&(!EOP())) {
		ADVKATA();
		if (IsKataSama(CKata,KataWHILE)) {
			NWhile++;
		}
	}
	printf("%d",NWhile);
	return 0;
}

