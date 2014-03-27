/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: mesinkar.c 										*/
/* Topik		: ADT MESIN KATA									*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: IMPLEMENTASI MESIN KARAKTER						*/

#ifndef MESINKAR_C
#define MESINKAR_C
#include <assert.h>
#include <fcnt1.h>
#include <stdio.h>
#include “boolean.h”
#include “mesinkar.h”

/*define states*/
char CC;
#define Pita_karakter “pitakar.txt”
static int_handle;

void START(void){
/*I.S. sembarang */
/*F.S. CC adalah karakter pertama pita */
/*    JIka CC==MARK, EOP menyala (True) */
/*    JIka CC != MARK, EOP padam (False) */
	_handle=open(Pita_karakter,O_RDONLY);
	assert(handle!=-1);
	assert(read(_handle,&CC,1)!=-1);
}

void ADV(void){
/*I.S. CC != MARK */
/*F.S. CC adalah karakter berikutnya dari CC pada I.S. */
/*    Jika CC==MARK, EOP menyala (true) */
	assert(!EOP());
	assert(read(_handle,&CC,1)!=-1);
	if (CC==MARK) {
		assert(close(_handle)!=-1);
	}
}

boolean EOP(void){
	/*	true jika CC==MARK */
	return (CC==MARK);
}
#endif