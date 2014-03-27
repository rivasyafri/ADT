#include "boolean.h"
#include "adt_jam.h"
#include <stdlib.h>
#include <stdio.h>

/* DEFINISI PRIMITIF */

/* KELOMPOK VALIDASI TERHADAP TIPE */
boolean IsJamValid (int H, int M, int S) {
	return ((H>=0)&&(H<=23)&&(M>=0)&&(M<=59)&&(S>=0)&&(S<=59));
}

/* KONSTRUKTOR */
JAM MakeJAM (int HH, int MM, int SS) {
	JAM J;
	SetHH(J,HH);
	SetMM(J,MM);
	SetSS(J,SS) ;
	return J;
}

/* KELOMPOK BACA TULIS */
void BacaJam (JAM *J) {
	int h,m,s;
	do {
		scanf("%d %d %d",&h,&m,&s);
	} while (!(IsJamValid(h,m,s)));
	(*J)=MakeJAM(h,m,s);
} //Menghasilkan selalu J yang valid
void TulisJam (JAM J) {
	printf("%02d:%02d:%02d\n",GetHour(J),GetMinute(J),GetSecond(J));
} //Menulis nilai setiap komponen J ke layar

/* KELOMPOK KONVERSI TERHADAP TYPE */
int JamToDetik (JAM J) {
	return GetHour(J)*3600 + GetMinute(J)*60 + GetSecond(J);
}
JAM DetikToJam (int N) {
	JAM J;
	if (N<0) {
		N=86400+N;
	} else {
		N=N%86400;
	}
	SetHH(J,N/3600);
	SetMM(J,(N%3600)/60);
	SetSS(J,(N%60));
	return J;
}

/* KELOMPOK OPERASI TERHADAP TYPE */
boolean JEQ (JAM J1, JAM J2) {
	return JamToDetik(J1)==JamToDetik(J2);
} //Mengirim true jika J1=J2
boolean JNEQ (JAM J1, JAM J2) {
	return JamToDetik(J1)!=JamToDetik(J2);
} //Mengirim true jika J1!=J2
boolean JLT (JAM J1, JAM J2) {
	return JamToDetik(J1)<JamToDetik(J2);
} //Mengirim true jika J1<J2
boolean JGT (JAM J1, JAM J2) {
	return JamToDetik(J1)>JamToDetik(J2);
} //Mengirim true jika J1>J2

/* OPERATOR ARITMATIKA JAM */
JAM JPlus (JAM J1, JAM J2) {
	return DetikToJam(JamToDetik(J1)+JamToDetik(J2));
}
JAM JMinus (JAM J1, JAM J2) {
	return DetikToJam(JamToDetik(J1)-JamToDetik(J2));
}
JAM NextDetik (JAM J) {
	return DetikToJam((JamToDetik(J))+1);
}
JAM NextNDetik (JAM J, int N) {
	return DetikToJam(JamToDetik(J)+N);
}
JAM PrevDetik (JAM J) {
	return DetikToJam((JamToDetik(J))-1);
}
JAM PrevNDetik (JAM J, int N) {
	return DetikToJam(JamToDetik(J)-N);
}
int Durasi (JAM Jaw, JAM Jakh) {
	return JamToDetik(Jakh)-JamToDetik(Jaw);
} //Mengirim Jakh-Jaw dalam detik, dengan kalkulasi hasilnya negatif jika Jaw > JAkhir