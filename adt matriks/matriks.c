/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: matriks.c 										*/
/* Topik		: ADT MATRIKS 										*/
/* Tanggal		: 10 Oktober 2013									*/
/* Deskripsi	: IMPLEMENTASI ADT MATRIKS							*/

/* File Include */
#include "boolean.h"
#include <stdio.h>
#include "matriks.h"

/*	KAMUS UMUM */
#define BrsMin 1
#define BrsMax 100 
#define KolMin 1 
#define KolMax 100

/*	DEFINISI PROTOTIPE PRIMITIF */
/*	Konstruktor pembentuk MATRIKS */
void MakeMATRIKS (int NB, int NK, MATRIKS *M) {
/*	Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” 
	memori 
	I.S. 	: NB dan NK adalah valid untuk memori matriks yang dibuat 
	F.S. 	: Matriks M sesuai dengan definisi di atas terbentuk */
	(*M).NBrsEff = NB;
	(*M).NKolEff = NK;
}

/*	Selektor "DUNIA MATRIKS" */
indeks GetIdxBrsMin () {
/*	Mengirimkan indeks baris minimum matriks apapun */
	return BrsMin;
}
indeks GetIdxKolMin () {
/*	Mengirimkan indeks kolom minimum matriks apapun */
	return KolMin;
}
indeks GetIdxBrsMax () {
/*	Mengirimkan indeks baris maksimum matriks apapun */
	return BrsMax;
}
indeks GetIdxKolMax () {
/*	Mengirimkan indeks kolom maksimum matriks apapun */
	return KolMax;
}
boolean IsIdxValid (int i, int j) {
/*	Mengirimkan true jika i, j adalah indeks yang valid */
	return ((i<=BrsMax)&&(i>=BrsMin)&&(j<=KolMax)&&(j>=KolMin));
}

/*	Untuk sebuah matriks M yang terdefinisi: */
indeks FirstIdxBrs (MATRIKS M) {
/*	Mengirimkan indeks baris terkecil M */
	return BrsMin;
}
indeks FirstIdxKol (MATRIKS M) {
	/*	Mengirimkan indeks kolom terkecil M */
	return KolMin;
}
indeks LastIdxBrs (MATRIKS M) {
/* 	Mengirimkan indeks baris terbesar M */
	return (M).NBrsEff;	
}
indeks LastIdxKol (MATRIKS M) {
	/*	Mengirimkan indeks kolom terbesar M */
	return (M).NKolEff;
}
int GetNBrsEff (MATRIKS M) {
/*	Mengirimkan banyaknya baris efektif M */
	return (M).NBrsEff;	
}
int GetNKolEff (MATRIKS M) {
/*	Mengirimkan banyaknya kolom efektif M */
	return (M).NKolEff;	
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j) {
/*	Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return ((i>=FirstIdxBrs(M))&&(i<=LastIdxBrs(M))&&(j>=FirstIdxKol(M))&&(j<=LastIdxKol(M)));
}
el_type GetElmt (MATRIKS M, indeks i, indeks j) {
/*	Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
	return M.Mem[i][j];
}
el_type GetElmtDiagonal (MATRIKS M, indeks i) {
/* 	Mengirimkan elemen M(i,i) */
	return M.Mem[i][i];
}

/*	Operasi mengubah nilai elemen matriks: Set / Assign */
void SetBrsEff (MATRIKS *M, int NB) {
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: Nilai M.NBrsEff diisi dengan NB */
	(*M).NBrsEff = NB;	
}
void SetKolEff (MATRIKS *M, int NK) {
/*	I.S. 	: M sudah terdefinisi
	F.S. 	: Nilai M.NKolEff diisi dengan NK */
	(*M).NKolEff = NK;	
}
void SetEl (MATRIKS *M, int i, int j, el_type X) {
/*	I.S. 	: M sudah terdefinisi 
	F.S. 	: M(i,j) bernilai X 
	Proses	: Mengisi M(i,j) dengan X */
	(*M).Mem[i][j]=X;
}

/*	Assignment  MATRIKS */
void CopyMATRIKS (MATRIKS MIn, MATRIKS *MHsl) {
/*	Melakukan assignment MHsl ← Min */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(GetNBrsEff(MIn),GetNKolEff(MIn),MHsl);
	for (i=FirstIdxBrs(MIn);i<=LastIdxBrs(MIn);i++) {
		for (j=FirstIdxKol(MIn);j<=LastIdxKol(MIn);j++) {
			SetEl(MHsl,i,j,GetElmt(MIn,i,j));
		}
	}
}

/*	KELOMPOK BACA/TULIS */
void BacaMATRIKS (MATRIKS *M, int NB, int NK) {
/*	I.S. 	: IsIdxValid(NB,NK)
	F.S. 	: M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK
			  Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya
			  dari pembacaan dengan traversal per baris */
	/*	Kamus */
	indeks i,j;
	el_type X;
	/*	Algoritma */
	MakeMATRIKS(NB,NK,M);
	for (i=1;i<=NB;i++) {
		printf("Baris ke-%d\n",i);
		for (j=1;j<=NK;j++) {
			printf("Kolom ke-%d = ",j);
			scanf("%f",&X);
			SetEl(M,i,j,X);
		}
	}
}
void TulisMATRIKS (MATRIKS M) {
/*	I.S. 	: M terdefinisi
	F.S. 	: Sama dengan I.S, dan nilai M(i,j) ditulis ke layar
			  Menulis nilai setiap indeks dan elemen M ke layar dengan 
			  traversal per baris */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++) {
		printf("[");
		for (j=FirstIdxKol(M);j<LastIdxKol(M);j++) {
			printf("%.0f ",GetElmt(M,i,j));
		}
		printf("%.0f",GetElmt(M,i,j));
		printf("]");
		printf("\n");
	}
}

/*	KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE */
MATRIKS Plus (MATRIKS M1, MATRIKS M2) {
/*	Prekondisi : M1  berukuran sama dengan M2
	Mengirim hasil penjumlahan matriks: M1 + M2 */
	/*	Kamus */
	MATRIKS M;
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M1),&M);
	for (i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++) {
		for (j=FirstIdxKol(M1);j<=LastIdxKol(M1);j++) {
			SetEl(&M,i,j,GetElmt(M1,i,j)+GetElmt(M2,i,j));
		}
	}
	return M;
}
MATRIKS minus (MATRIKS M1, MATRIKS M2) {
/*	Prekondisi : M berukuran sama dengan M
	Mengirim hasil pengurangan matriks: salinan M1 – M2 */
	/*	Kamus */
	MATRIKS M;
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M1),&M);
	for (i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++) {
		for (j=FirstIdxKol(M1);j<=LastIdxKol(M1);j++) {
			SetEl(&M,i,j,GetElmt(M1,i,j)-GetElmt(M2,i,j));
		}
	}
	return M;
}
MATRIKS Kali2Matriks (MATRIKS M1, MATRIKS M2) {
/*	Prekondisi : Ukuran baris efektif M1 = ukuran kolom efektif M2
	Mengirim hasil perkalian matriks: salinan M1 * M2 */
	/*	Kamus */
	MATRIKS M;
	el_type X;
	indeks i,j,k;
	/*	Algoritma */
	MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M2),&M);
	for (i=FirstIdxBrs(M1);i<=LastIdxBrs(M1);i++) {
		for (j=FirstIdxKol(M2);j<=LastIdxKol(M2);j++) {
			X=0;
			for (k=FirstIdxKol(M1);k<=LastIdxKol(M1);k++) {
				X+=GetElmt(M1,i,k)*GetElmt(M2,k,j);
			}
			SetEl(&M,i,j,X);
		}
	}
	return M;
}
MATRIKS kalikons (MATRIKS M, int X) {
/*	Mengirim hasil perkalian setiap elemen M dengan X */
	/*	Kamus */
	MATRIKS MK;
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&MK);
	for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++) {
		for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++) {
			SetEl(&MK,i,j,X*GetElmt(M,i,j));
		}
	}
	return MK;
}
void kalikonstanta (MATRIKS *M, int K) {
/*	Mengalikan setiap elemen M dengan K */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	for (i=FirstIdxBrs(*M);i<=LastIdxBrs(*M);i++) {
		for (j=FirstIdxKol(*M);j<=LastIdxKol(*M);j++) {
			SetEl(M,i,j,K*GetElmt(*M,i,j));
		}
	}
}

/*	KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS */
boolean EQ (MATRIKS M1, MATRIKS M2) {
/*	Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan 
	untuk setiap i,j yang merupakan indeks baris dan kolom
	M1(i,j) = M2(i,j) */
	/*	Kamus */
	boolean cek=true;
	indeks i,j;
	/*	Algoritma */
	if (NBElmt(M1)!=NBElmt(M2)) {
		cek=false;
	} else {
		i=FirstIdxBrs(M1);
		while ((i<=LastIdxBrs(M1))&&(cek)) {
			j=FirstIdxKol(M1);
			while ((j<=LastIdxKol(M1))&&(cek)) {
				if (GetElmt(M1,i,j)!=GetElmt(M2,i,j)) {
					cek=false;
				}
				j++;
			}
			i++;
		}
	}
	return cek;
}
boolean NEQ (MATRIKS M1, MATRIKS M2) {
/*	Mengirimkan true jika not EQ(M1,M2) */
	return (!EQ(M1,M2));	
}
boolean EQSize (MATRIKS M1, MATRIKS M2) {
/*	Mengirimkan true jika ukuran efektif matriks M1 sama dengan 
	ukuran efektif M2 yaitu GetNBrsEff(M1) = GetNBrsEff (M2) dan 
	GetNKolEff (M1) = GetNKolEff (M2) */
	return ((GetNBrsEff(M1)==GetNBrsEff(M2))&&(GetNKolEff(M1)==GetNKolEff(M2)));
}
boolean IsLess (MATRIKS M1, MATRIKS M2) {
/*	Mengirimkan true jika ukuran efektif M1 < ukuran efektif M2 */
	return ((GetNBrsEff(M1)<GetNBrsEff(M2))||(GetNKolEff(M1)<GetNKolEff(M2)));
}

/*	Operasi lain */
int NBElmt (MATRIKS M) {
/*	Mengirimkan banyaknya elemen M */
	return LastIdxKol(M)*LastIdxBrs(M);
}

/*	KELOMPOK TEST TERHADAP MATRIKS */
boolean IsBujurSangkar (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks dengan ukuran baris dan kolom
	sama */
	return LastIdxKol(M)==LastIdxBrs(M);	
}
boolean IsSymetri (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
	dan untuk setiap elemen M, M(i,j)=M(j,i) */
	/*	Kamus */
	boolean cek=true;
	indeks i,j;
	/*	Algoritma */
	if (!IsBujurSangkar(M)) {
		cek=false;
	} else {
		i=FirstIdxBrs(M);
		while ((i<=LastIdxBrs(M))&&(cek)) {
			j=FirstIdxKol(M);
			while ((j<=LastIdxKol(M))&&(cek)) {
				if (GetElmt(M,i,j)!=GetElmt(M,j,i)) {
					cek=false;
				}
				j++;
			}
			i++;
		}
	}
	return cek;
}
boolean IsSatuan (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) 
	dan setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal
	bernilai 0 */
	/*	Kamus */
	boolean cek=true;
	indeks i,j;
	/*	Algoritma */
	if (!IsBujurSangkar(M)) {
		cek=false;
	} else {
		i=FirstIdxBrs(M);
		while ((i<=LastIdxBrs(M))&&(cek)) {
			j=FirstIdxKol(M);
			while ((j<=LastIdxKol(M))&&(cek)) {
				if ((i==j)&&(GetElmtDiagonal(M,i)!=1)) {
					cek=false;
				} else if (GetElmt(M,i,j)!=0) {
					cek=false;
				}
				j++;
			}
			i++;
		}
	}
	return cek;
}
boolean IsSparse (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks sparse: matriks “jarang” dengan
	definisi: hanya maksimal 5% dari memori matriks yang efektif bukan
	bernilai 0 */
	/*	Kamus */
	float percent=0,jumlah=0;
	indeks i,j;
	/*	Algoritma */
	for (i=FirstIdxBrs(M);i<=GetNBrsEff(M);i++) {
		for (j=FirstIdxKol(M);j<=GetNKolEff(M);j++) {
			if (M.Mem[i][j]!=0) {
				jumlah++;
			}
		}
	}
	percent=jumlah/(GetNBrsEff(M)*GetNKolEff(M));
	return percent<=0.05;
}
MATRIKS Invers1f (MATRIKS M) {
/*	Menghasilkan salinan M dg setiap elemen "di-invers", yaitu dinegasikan */
	/*	Kamus */
	indeks i,j;
	MATRIKS MI;
	/*	Algoritma */
	MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&MI);
	for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++) {
		for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++) {
			SetEl(&MI,i,j,-GetElmt(M,i,j));
		}
	}
	return MI;
}
MATRIKS Inversf (MATRIKS M) {
/*	Menghasilkan salinan M dg setiap elemen "di-invers", yaitu di-invers
	sesuai dengan aturan inversi matriks */
	/*	Kamus */
	MATRIKS MOBE,MI;
	float pengurang,pembagi;
	indeks i,j,k;
	/*	Algoritma */
	/*	Menggunakan Operasi Baris Elementer AI~OBE~I'A */
	MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M)*2,&MOBE);
	MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&MI);
	for (j=FirstIdxBrs(M);j<=LastIdxBrs(M);j++) {
		for (i=FirstIdxKol(M);i<=LastIdxKol(M)*2;i++) {
			if (i<=LastIdxKol(M)) {
				SetEl(&MOBE,j,i,GetElmt(M,j,i));
			} else if (i==j+LastIdxKol(M)) {
				SetEl(&MOBE,j,i,1);
			} else {
				SetEl(&MOBE,j,i,0);
			}
		}
	}
	for (i=FirstIdxBrs(MOBE);i<=LastIdxBrs(MOBE);i++) {
		for (j=FirstIdxKol(MOBE);j<=i;j++) {
			if (i==j) {
				pembagi=GetElmt(MOBE,i,j);
				for (k=j;k<=LastIdxKol(MOBE);k++) {
					SetEl(&MOBE,i,k,GetElmt(MOBE,i,k)/pembagi);
				}
			} else {
				pengurang=-GetElmt(MOBE,i,j)/GetElmtDiagonal(MOBE,j);
				for (k=j;k<=LastIdxKol(MOBE);k++) {
					SetEl(&MOBE,i,k,GetElmt(MOBE,i,k)+GetElmt(MOBE,j,k)*pengurang);
				}
			}	
		}
	}
	for (i=LastIdxBrs(MOBE)-1;i>=FirstIdxBrs(MOBE);i--) {
		for (j=LastIdxKol(MOBE)/2;j>i;j--) {
			pengurang=-GetElmt(MOBE,i,j)/GetElmtDiagonal(MOBE,j);
			for (k=FirstIdxKol(MOBE);k<=LastIdxKol(MOBE);k++) {
				SetEl(&MOBE,i,k,GetElmt(MOBE,i,k)+GetElmt(MOBE,j,k)*pengurang);
			}
		}
	}
	for (j=FirstIdxBrs(MOBE);j<=LastIdxBrs(MOBE);j++) {
		for (i=(LastIdxKol(MOBE)/2)+1;i<=LastIdxKol(MOBE);i++) {
			SetEl(&MI,j,i-(LastIdxKol(MOBE)/2),GetElmt(MOBE,j,i));
		}
	}
	return MI;
}
MATRIKS InversLaplacef (MATRIKS M) {
/*	Menghasilkan salinan M dg setiap elemen "di-invers", yaitu di-invers
	sesuai dengan aturan inversi matriks */
	/*	Menggunakan Cofactor matrix */
	/*	adj(A) adalah transpose dari cofactor matrix */
	/*	Invers adalah (1/determinan(A))*adj(A) */
	/*	Kamus */
	indeks i,j,k,l,m,n;
	MATRIKS MLaplace,MK;
	float d;
	/*	Algoritma */
	d=1/DeterminanLaplace(M);
	MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&MLaplace);
	MakeMATRIKS(GetNBrsEff(M)-1,GetNKolEff(M)-1,&MK);
	for (i=FirstIdxBrs(M);i<=LastIdxBrs(M);i++) {
		for (j=FirstIdxKol(M);j<=LastIdxKol(M);j++) {			
			for (k=i+1;k<i+LastIdxBrs(M);k++) {
				if (k>LastIdxBrs(M)) {
					m=k%LastIdxBrs(M);
					for (l=j+1;l<j+LastIdxKol(M);l++) {
						if (l>LastIdxKol(M)) {
							n=l%LastIdxBrs(M);
							SetEl(&MK,k-i,l-j,GetElmt(M,m,n));
						} else {
							SetEl(&MK,k-i,l-j,GetElmt(M,m,l));
						}
						n++;
					}
				} else {
					for (l=j+1;l<j+LastIdxKol(M);l++) {
						if (l>LastIdxKol(M)) {
							n=l%LastIdxBrs(M);
							SetEl(&MK,k-i,l-j,GetElmt(M,k,n));
						} else {
							SetEl(&MK,k-i,l-j,GetElmt(M,k,l));
						}
						n++;
					}	
				}
				m++;
			}
			SetEl(&MLaplace,i,j,d*DeterminanLaplace(MK));
		}
	}
	Transpose(&MLaplace);
	return MLaplace;
}
float DeterminanLaplace (MATRIKS M) {
/*	Prekondisi: IsBujurSangkar(M)
	Menghitung nilai determinan M */
	/*	Kamus */
	MATRIKS MK;
	indeks i,j,k,l,m;
	float determinan=0;
	/*	Algoritma */
	/*	Menggunakan Laplace Formula */
	if ((LastIdxBrs(M)==2)&&(LastIdxKol(M)==2)) { /* Basis */
		return GetElmtDiagonal(M,1)*GetElmtDiagonal(M,2)-GetElmt(M,2,1)*GetElmt(M,1,2);
	} else { /* Rekurens */
		MakeMATRIKS(GetNBrsEff(M)-1,GetNKolEff(M)-1,&MK);
		for (i=FirstIdxKol(M);i<=LastIdxKol(M);i++) {
			l=1;
			for (j=i+1;j<i+LastIdxKol(M);j++) {
				if (j>LastIdxKol(M)) {
					m=j%LastIdxKol(M);
					for (k=FirstIdxBrs(M)+1;k<=LastIdxBrs(M);k++) {
						SetEl(&MK,k-1,l,GetElmt(M,k,m));
					}
				} else {
					for (k=FirstIdxBrs(M)+1;k<=LastIdxBrs(M);k++) {
						SetEl(&MK,k-1,l,GetElmt(M,k,j));
					}
				}
				l++;
			}
			determinan+=GetElmt(M,1,i)*DeterminanLaplace(MK);
		}
		return determinan;
	}
}
float Determinan (MATRIKS M) {
/*	Prekondisi: IsBujurSangkar(M)
	Menghitung nilai determinan M */
	/*	Kamus */
	MATRIKS MOBE;
	float pengurang,determinan=1;
	indeks i,j,k;
	/*	Algoritma */
	/*	Menggunakan Operasi Baris Elementer */
	MakeMATRIKS(GetNBrsEff(M),GetNKolEff(M),&MOBE);
	CopyMATRIKS(M,&MOBE);
	for (i=FirstIdxKol(M);i<=LastIdxKol(M);i++) {
		SetEl(&MOBE,FirstIdxBrs(M),i,GetElmt(M,FirstIdxBrs(M),i));
	}
	for (i=FirstIdxBrs(M)+1;i<=LastIdxBrs(M);i++) {
		for (j=FirstIdxKol(M);j<i;j++) {
			pengurang=(-GetElmt(MOBE,i,j))/GetElmtDiagonal(MOBE,j);
			for (k=j;k<=LastIdxKol(M);k++) {
				SetEl(&MOBE,i,k,GetElmt(MOBE,i,k)+GetElmt(MOBE,j,k)*pengurang);
			}	
		}
	}
	for (i=FirstIdxBrs(MOBE);i<=LastIdxBrs(MOBE);i++) {
		determinan=determinan*GetElmtDiagonal(MOBE,i);
	}
	return determinan;
}
void Invers1(MATRIKS *M) {
/*	I.S.	: M terdefinisi
	F.S.	: M di-invers, yaitu setiap elemennya dinegasikan */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	for (i=FirstIdxBrs(*M);i<=LastIdxBrs(*M);i++) {
		for (j=FirstIdxKol(*M);j<=LastIdxKol(*M);j++) {
			SetEl(M,i,j,-GetElmt(*M,i,j));
		}
	}
}
void Invers(MATRIKS *M) {
/*	I.S.	: M terdefinisi
	F.S.	: M "di-invers", yaitu diproses sesuai dengan aturan invers
			  matriks */
	/*	Kamus */
	MATRIKS MOBE;
	float pengurang,pembagi;
	indeks i,j,k;
	/*	Algoritma */
	/*	Menggunakan Operasi Baris Elementer AI~OBE~I'A */
	MakeMATRIKS(GetNBrsEff(*M),GetNKolEff(*M)*2,&MOBE);
	for (j=FirstIdxBrs(*M);j<=LastIdxBrs(*M);j++) {
		for (i=FirstIdxKol(*M);i<=LastIdxKol(*M)*2;i++) {
			if (i<=LastIdxKol(*M)) {
				SetEl(&MOBE,j,i,GetElmt(*M,j,i));
			} else if (i==j+LastIdxKol(*M)) {
				SetEl(&MOBE,j,i,1);
			} else {
				SetEl(&MOBE,j,i,0);
			}
		}
	}
	for (i=FirstIdxBrs(MOBE);i<=LastIdxBrs(MOBE);i++) {
		for (j=FirstIdxKol(MOBE);j<=i;j++) {
			if (i==j) {
				pembagi=GetElmt(MOBE,i,j);
				for (k=j;k<=LastIdxKol(MOBE);k++) {
					SetEl(&MOBE,i,k,GetElmt(MOBE,i,k)/pembagi);
				}
			} else {
				pengurang=-GetElmt(MOBE,i,j)/GetElmtDiagonal(MOBE,j);
				for (k=j;k<=LastIdxKol(MOBE);k++) {
					SetEl(&MOBE,i,k,GetElmt(MOBE,i,k)+GetElmt(MOBE,j,k)*pengurang);
				}
			}	
		}
	}
	for (i=LastIdxBrs(MOBE)-1;i>=FirstIdxBrs(MOBE);i--) {
		for (j=LastIdxKol(MOBE)/2;j>i;j--) {
			pengurang=-GetElmt(MOBE,i,j)/GetElmtDiagonal(MOBE,j);
			for (k=FirstIdxKol(MOBE);k<=LastIdxKol(MOBE);k++) {
				SetEl(&MOBE,i,k,GetElmt(MOBE,i,k)+GetElmt(MOBE,j,k)*pengurang);
			}
		}
	}
	for (j=FirstIdxBrs(MOBE);j<=LastIdxBrs(MOBE);j++) {
		for (i=(LastIdxKol(MOBE)/2)+1;i<=LastIdxKol(MOBE);i++) {
			SetEl(M,j,i-(LastIdxKol(MOBE)/2),GetElmt(MOBE,j,i));
		}
	}
	TulisMATRIKS(*M);
}
void Transpose (MATRIKS *M) {
/*	I.S.	: M terdefinisi dan IsBujurSangkar(M)
	F.S.	: M "di-transpose", yaitu setiap elemen M(i,j) ditukar 
			  nilainya dengan elemen M(j,i) */
	/*	Kamus */
	MATRIKS M1;
	indeks i,j;
	el_type temp;
	/*	Algoritma */
	MakeMATRIKS(GetNKolEff(*M),GetNBrsEff(*M),&M1);
	for (i=FirstIdxBrs(*M);i<=LastIdxBrs(*M);i++) {
		for (j=FirstIdxKol(*M);j<=LastIdxKol(*M);j++) {
			SetEl(&M1,j,i,GetElmt(*M,i,j));
		}
	}
	CopyMATRIKS(M1,M);
}
