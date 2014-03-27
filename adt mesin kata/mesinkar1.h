/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: mesinkar1.h 										*/
/* Topik		: ADT MESIN KATA									*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: HEADER MESIN KARAKTER								*/

#ifndef MESINKAR1_H
#define MESINKAR1_H

/*	File Include */
#include "boolean.h"

#ifndef MARK
#define MARK '.'
#endif

void START(void);
/*	I.S.	: sembarang
	F.S.	: CC adalah karakter pertama pita
	Jika CC==MARK, EOP menyala  (true)
	Jika CC  != MARK, EOP padam  (false)  */

void ADV(void); 
/*	I.S.	: CC  != MARK
	F.S.	: CC adalah karakter berikutnya dari CC pada I.S.
	Jika CC==MARK, EOP menyala  (true)  */

boolean EOP(void);
/* 	true jika CC  == MARK  */

#endif