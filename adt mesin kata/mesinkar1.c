/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: mesinkar1.c 										*/
/* Topik		: ADT MESIN KATA									*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: IMPLEMENTASI MESIN KARAKTER						*/

#ifndef MESINKAR_C 
#define MESINKAR_C 
#include  <assert.h> 
#include  <fcntl.h> 
#include  <stdio.h> 
#include "boolean.h" 
#include "mesinkar1.h" 

/* definisi states  */ 
char CC; 

/* definisi pita  */ 
static char Pita_karakter[63]  = "pitakar.txt"; 
static FILE *FILEKU; 
static int retval; 

void START(void)  {
/*	I.S.	: sembarang
	F.S.	: CC adalah karakter pertama pita
	Jika CC==MARK, EOP menyala  (true)
	Jika CC  != MARK, EOP padam  (false)  */
	FILEKU = fopen(Pita_karakter,"r"); 
	retval = fscanf(FILEKU,"%c",&CC);
} 

void ADV(void)  {
/*	I.S.	: CC  != MARK
	F.S.	: CC adalah karakter berikutnya dari CC pada I.S.
	Jika CC==MARK, EOP menyala  (true)  */
	retval = fscanf(FILEKU,"%c",&CC)  ; 
	if (CC==MARK)  { 
		fclose(FILEKU); 
	}
} 

boolean EOP()  { 
/* true jika CC  == MARK  */ 
	return (CC==MARK); 
} 

#endif 