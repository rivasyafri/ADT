/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: */
/* Topik		: ADT TABEL KONTIGU IMPLISIT DINAMIK 				*/
/* Tanggal		: */
/* Deskripsi	: IMPLEMENTASI ADT TABEL KONTIGU IMPLISIT DINAMIK	*/

/* File Include */
#include "boolean.h"
#include "adttabel.h"
#include <stdlib.h>
#include <stdio.h>

/* 	Kamus Umum */  
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi */
#define ValUndef -9999 /* nilai tidak terdefinisi */

/*	KONSTRUKTOR */
void MakeEmpty (int N, TabInt *T) {
	/*	Kamus */
	int i=1;
	/*	Algoritma */
	SetSize(T,N);
	while (i<=N) {
		SetEl(T,i,ValUndef);
		i++;
	}
}

/*	--- SELEKTOR --- */
/* 	Banyaknya Elemen */
int NbElmt (TabInt T) {
	/*	Kamus */
	int jumlah=0;
	IdxType i=1;
	/*	Algoritma */
	while (i<=MaxNbEl(T)) {
		if ((T).TI[i]!=ValUndef) {
			jumlah++;
		}
		i++;
	}
	return jumlah;
}

/* 	Daya Tampung Container */
int MaxNbEl (TabInt T) {
	return (T).Size;
}


/*	Selektor Indeks */
IdxType GetFirstIdx (TabInt T) {
	/*	Kamus */
	IdxType i=1;
	/* 	Algoritma */
	while ((T).TI[i]==ValUndef) {
		i++;
	}
	return i;
}
IdxType GetLastIdx (TabInt T) {
	/*	Kamus */
	int i=0;
	/*	Algoritma */
	while ((T).TI[MaxNbEl(T)-i]==ValUndef) {
		i++;
	}
	return MaxNbEl(T)-i;
}

/* 	Menghasilkan sebuah elemen */
ElType GetElmt (TabInt T, IdxType i) {
	return (T).TI[i];
}

/*	Selektor Set */
void SetTab (TabInt Tin, TabInt *Tout) {
	/*	Kamus */
	int i=GetFirstIdx(Tin);
	/*	Algoritma */
	MakeEmpty(MaxNbEl(Tin),Tout);
	while (i<=GetLastIdx(Tin)) {
		SetEl(Tout,i,GetElmt(Tin,i));
		i++;
	}
}
void SetEl (TabInt *T, IdxType i, ElType v) {
	/*	Kamus */
	/*	Algoritma */
	(*T).TI[i] = v;
}
void SetSize (TabInt *T, IdxType N) {
	/*	Kamus */
	/*	Algoritma */
	(*T).TI = (ElType *) malloc ((N+1)* sizeof (ElType));
	(*T).Size = N;
}

/* 	--- TEST INDEKS YANG VALID --- */
boolean IsIdxValid (TabInt T, IdxType i) {
	return (i>=1)&&(i<=MaxNbEl(T));
}
boolean IsIdxEff (TabInt T, IdxType i) {
	return (i>=GetFirstIdx(T))&&(i<=GetLastIdx(T));
}

/* 	--- TEST KOSONG/PENUH --- */
/* 	Test tabel kosong */
boolean IsEmpty (TabInt T) {
	return (NbElmt(T)==0);
}

/*	Test tabel penuh */
boolean IsFull (TabInt T) {
	return (NbElmt(T)==MaxNbEl(T));
}

/*	--- BACA dan TULIS dengan INPUT/OUTPUT device --- */
/*	Mendefinisikan isi tabel dari pembacaan */
void BacaIsi (TabInt *T) {
	/*	Kamus */
	int a;
	IdxType i=1;
	/*	Algoritma */
	while (i<=MaxNbEl(*T)) {
		do {
			printf("Elemen %d : ",i);
			scanf("%d",&a);
			SetEl(T,i,a);
			i++;
		} while ((a!=ValUndef)&&(i<=MaxNbEl(*T)));
		/*	Karena rata kiri */
		while ((a==ValUndef)&&(i<=MaxNbEl(*T))) {
			SetEl(T,i,a);
			i++;
		}
	}
}
void TulisIsi (TabInt T) {
	/*	Kamus */
	IdxType i=GetFirstIdx(T);
	/*	Algoritma */
	if (IsEmpty(T)) {
		printf("Tabel kosong\n");
	} else {
		while (i<=GetLastIdx(T)) {
			printf("%d.	%d\n",i,GetElmt(T,i));
			i++;
		}
	}
}
void TulisIsiTab (TabInt T) {
	/*	Kamus */
	int j=NbElmt(T);
	IdxType i=GetFirstIdx(T);
	/*	Algoritma */
	if (j==0) {
		printf("[]");
	} else {
		printf("[");
		while (i<=GetLastIdx(T)&&(j>=1)) {
			printf("%d",GetElmt(T,i));
			if (j>1) {
				printf(", ");
			}
			j--;
			i++;
		}
		printf("]\n");
	}
}


/*	--- OPERATOR ARITMATIKA --- */
/*	Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... */
TabInt PlusTab (TabInt T1,  TabInt T2) {
	/*	Kamus */
	TabInt T;
	IdxType i=1;
	/*	Algoritma */
	MakeEmpty(MaxNbEl(T1),&T);
	while (i<=MaxNbEl(T)) {
		if ((GetElmt(T1,i)!=ValUndef)&&(GetElmt(T2,i)!=ValUndef)) {
			SetEl(&T,i,GetElmt(T1,i)+GetElmt(T2,i));
		} else {
			SetEl(&T,i,ValUndef);
		}
		i++;
	}
	return T;
}
TabInt MinusTab (TabInt T1, TabInt T2){
	/*	Kamus */
	TabInt T;
	IdxType i=1;
	/*	Algoritma */
	MakeEmpty(MaxNbEl(T1),&T);
	while (i<=MaxNbEl(T)) {
		if ((GetElmt(T1,i)!=ValUndef)&&(GetElmt(T2,i)!=ValUndef)) {
			SetEl(&T,i,GetElmt(T1,i)-GetElmt(T2,i));
		} else {
			SetEl(&T,i,ValUndef);
		}
		i++;
	}
	return T;
}
TabInt KaliTab (TabInt T1, TabInt T2) {
	/*	Kamus */
	TabInt T;
	IdxType i=1;
	/*	Algoritma */
	MakeEmpty(MaxNbEl(T1),&T);
	while (i<=MaxNbEl(T)) {
		if ((GetElmt(T1,i)!=ValUndef)&&(GetElmt(T2,i)!=ValUndef)) {
			SetEl(&T,i,GetElmt(T1,i)*GetElmt(T2,i));
		} else {
			SetEl(&T,i,ValUndef);
		}
		i++;
	}
	return T;
}
TabInt KaliKons (TabInt Tin, ElType c){
	/*	Kamus */
	TabInt T;
	IdxType i=1;
	/*	Algoritma */
	MakeEmpty(MaxNbEl(Tin),&T);
	while (i<=MaxNbEl(T)) {
		if ((GetElmt(Tin,i)!=ValUndef)) {
			SetEl(&T,i,c*GetElmt(Tin,i));
		} else {
			SetEl(&T,i,ValUndef);
		}
		i++;
	}
	return T;
}

/*	--- OPERATOR RELASIONAL --- */
/*	Operasi pembandingan tabel : < =, > */
boolean IsEQ (TabInt T1, TabInt T2) {
	/*	Kamus */
	boolean a=true;
	IdxType i=GetFirstIdx(T1);
	/*	Algoritma */
	if ((MaxNbEl(T1)!=MaxNbEl(T2))&&(NbElmt(T1)!=NbElmt(T2))) {
		a=false;
	} else {
		while (i<=GetLastIdx(T1)) {
			if ((T1).TI[i]!=(T2).TI[i]) {
				/* 	Tidak menggunakan GetElmt karena masukan i tidak berada 
					di antara FirstIdx..LastIdx melainkan bisa diluar itu */
				a=false;
			}
			i++;
		}
	}
	return a;
}
boolean IsLess (TabInt T1, TabInt T2) {
	/*	Kamus */
	boolean a=true;
	IdxType i=GetFirstIdx(T1),j;
	/*	Algoritma */
	if (NbElmt(T1)<=NbElmt(T2)) {
		j=GetLastIdx(T1);
	} else {
		j=GetLastIdx(T2);
	}
	while ((i<=j)&&(a)) {
		if (GetElmt(T1,i)>GetElmt(T2,i)) {
			a=false;
		}
		i++;
	}
	return a;
}
/*	--- SEARCHING --- */
/*	Tabel boleh kosong */
IdxType Search1 (TabInt T, ElType X) {
	/*	Kamus */
	IdxType i;
	/*	Algoritma */
	if ((NbElmt(T)==0)||(!SearchB(T,X))) {
		return IdxUndef;
	} else {
		i=GetFirstIdx(T);
		while ((i<=GetLastIdx(T))&&(GetElmt(T,i)!=X)) {
			i++;
		}
		return i;
	}
}
IdxType Search2 (TabInt T, ElType X) {
	/*	Kamus */
	boolean Found=false;
	IdxType i;
	/*	Algoritma */
	if (NbElmt(T)==0) {
		return IdxUndef;
	} else {
		i=GetFirstIdx(T);
		while ((i<=GetLastIdx(T))&&(!Found)) {
			if (GetElmt(T,i)==X) {
				Found=true;
			} else {
				i++;
			}
		}
		if (Found) {
			return i;
		} else {
			return IdxUndef;
		}
	}
}
boolean SearchB (TabInt T, ElType X) {
	/*	Kamus */
	IdxType i;
	boolean Found=false;
	/*	Algoritma */
	if (NbElmt(T)!=0) {
		i=GetFirstIdx(T);
		while (i<=GetLastIdx(T)) {
			if (GetElmt(T,i)==X) {
				Found=true;
			}
			i++;
		}
	}
	return Found;
}
boolean SearchSentinel (TabInt T, ElType X) {
	/*	Kamus */
	IdxType i=MaxNbEl(T);
	/*	Algoritma */
	T.TI[0]=X;
	while (T.TI[i]!=X) {
		/*	Tidak menggunakan GetElmt karena i berada diluar IdxEff */
		i--;
	}
	return (i>0);
}
/* 	--- NILAI EKSTREM --- */
ElType ValMax (TabInt T) {
	/*	Kamus */
	ElType a=GetElmt(T,GetFirstIdx(T));
	IdxType i=GetFirstIdx(T)+1;
	/*	Algoritma */
	while (i<=GetLastIdx(T)) {
		if (a<GetElmt(T,i)) {
			a=GetElmt(T,i);
		}
		i++;
	}
	return a;
}
ElType ValMin (TabInt T) {
	/*	Kamus */
	ElType a=GetElmt(T,GetFirstIdx(T));
	IdxType i=GetFirstIdx(T)+1;
	/*	Algoritma */
	while (i<=GetLastIdx(T)) {
		if (a>GetElmt(T,i)) {
			a=GetElmt(T,i);
		}
		i++;
	}
	return a;
}
/*	Mengirimkan indeks elemen bernilai ekstrem */
IdxType IdxMaxTab (TabInt T) {
	/*	Kamus */
	/*	Algoritma */
	return SearchSentinel(T,ValMax(T));
}
IdxType IdxMinTab (TabInt T) {
	/*	Kamus */
	/*	Algoritma */
	return SearchSentinel(T,ValMin(T));
}

/*  --- OPERASI LAIN --- */
void CopyTab (TabInt Tin,TabInt *Tout) {
	/*	Kamus */
	int i=GetFirstIdx(Tin);
	/*	Algoritma */
	MakeEmpty(MaxNbEl(Tin),Tout);
	while (i<=GetLastIdx(Tin)) {
		SetEl(Tout,i,GetElmt(Tin,i));
		i++;
	}
}
TabInt InverseTab (TabInt T) {
	/*	Kamus */
	TabInt T1;
	IdxType i=GetFirstIdx(T);
	/*	Algoritma */
	if (IsEmpty(T)) {
		return T;
	} else {
		MakeEmpty(MaxNbEl(T),&T1);
		while (i<=GetLastIdx(T)) {
			SetEl(&T1,GetLastIdx(T)-i+1,GetElmt(T,i));
			i++;
		}
		return T1;
	}
}
boolean IsSimetris (TabInt T) {
	/*	Kamus */
	IdxType i;
	/*	Algoritma */
	return IsEQ(T,InverseTab(T));
}

/*	--- SORTING --- */
void MaxSortDesc (TabInt *T) {
	/*	Kamus */
	IdxType i,j,imaks;
	ElType Temp;
	/*	Algoritma */
	if (!IsEmpty(*T)) {
		i=GetFirstIdx(*T);
		while (i<GetLastIdx(*T)) {
			imaks=i;
			j=i+1;
			while (j<=GetLastIdx(*T)) {
				if (GetElmt(*T,imaks)<GetElmt(*T,j)) {
					imaks=j;
				}
				j++;
			}
			Temp = GetElmt(*T,i);
			SetEl(T,i,GetElmt(*T,imaks));
			SetEl(T,imaks,Temp);
			i++;
		}
	}
}
void InsSortAsc (TabInt *T) {
	/*	Kamus */
	IdxType i,j;
	ElType Temp;
	/*	Algoritma */
	if (!IsEmpty(*T)) {
		i=GetFirstIdx(*T)+1;
		while (i<=GetLastIdx(*T)) {
			Temp=GetElmt(*T,i);
			j=i-1;
			while ((Temp<GetElmt(*T,j))&&(j>1)) {
				SetEl(T,j+1,GetElmt(*T,j));
				j--;
			}
			if (Temp>=GetElmt(*T,j)) {
				SetEl(T,j+1,Temp);
			} else if (Temp<GetElmt(*T,j)) {
				SetEl(T,j+1,GetElmt(*T,j));
				SetEl(T,j,Temp);
			}
			i++;
		}
	}
}

/*	--- MENAMBAH ELEMEN --- */
/*	Menambahkan elemen terakhir */
void AddAsLastEl (TabInt *T, ElType X) {
	/*	Kamus */
	/*	Algoritma */
	if (IsEmpty(*T)) {
		SetEl(T,1,X);
	} else if (!IsFull(*T)) {
		SetEl(T,GetLastIdx(*T)+1,X);
	}
}
void AddEli (TabInt *T, ElType X, IdxType i) {
	/*	Kamus */
	IdxType j;
	/*	Algoritma */
	if ((!IsFull(*T))&&(!IsEmpty(*T))&&(IsIdxValid(*T,i))) {
		j=GetLastIdx(*T);
		while (j>=i) {
			SetEl(T,j+1,GetElmt(*T,j));
			if (j==i) {
				SetEl(T,j,X);
			}
			j--;
		}
	}
}

/*	--- MENGHAPUS ELEMEN --- */
void DelLastEl (TabInt *T, ElType *X) {
	/*	Kamus */
	/*	Algoritma */
	*X=GetElmt(*T,GetLastIdx(*T));
	SetEl(T,GetLastIdx(*T),ValUndef);
}
void DelEli(TabInt *T, IdxType i, ElType *X) {
	/*	Kamus */
	IdxType j=i;
	/*	Algoritma */
	*X=GetElmt(*T,i);
	if (IsIdxValid(*T,i)) {
		while (j<=GetLastIdx(*T)) {
			if (j==MaxNbEl(*T)) {
				SetEl(T,j,ValUndef);
			} else {
				SetEl(T,j,GetElmt(*T,j+1));
			}
			j++;
		}
	}
}

/*	--- TABEL DENGAN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) --- */
void AddElUnik (TabInt *T, ElType X) {
	/*	Kamus */
	/*	Algoritma */
	if ((!IsFull(*T))&&(!SearchB(*T,X))) {
		SetEl(T,GetLastIdx(*T)+1,X);
	} else if (SearchB(*T,X)) {
		printf("nilai sudah ada");
	}
}

/*	--- TABEL DENGAN ELEMEN TERURUT MEMBESAR --- */
IdxType SearchUrut (TabInt T, ElType X) {
	/*	Kamus */
	/*	Algoritma */
	if ((IsEmpty(T))||(!SearchB(T,X))) {
		return IdxUndef;
	} else {
		return Search1(T,X);
	}
}
ElType Max (TabInt T) {
	return GetElmt(T,GetLastIdx(T));
}
ElType Min (TabInt T) {
	return GetElmt(T,GetFirstIdx(T));
}
tuple MaxMin (TabInt T){
	tuple mm;
	mm.max=Max(T);
	mm.min=Min(T);
	return mm;
}
void Add1Urut (TabInt *T, ElType X) {
	/*	Kamus */
	IdxType i,j;
	boolean pas=false;
	/*	Algoritma */
	if (IsEmpty(*T)) {
		SetEl(T,1,X);
	} else if (!IsFull(*T)) {
		i=GetFirstIdx(*T);
		j=GetLastIdx(*T);
		if (NbElmt(*T)!=1) {
			while ((i<=j)&&(!pas)) {
				if (GetElmt(*T,i)>=X) {
					pas=true;
				} else {
					i++;
				}
			}
			while (j>=i) {
				if (j>i) {
					SetEl(T,j+1,GetElmt(*T,j));
				} else {
					SetEl(T,j+1,GetElmt(*T,j));
					SetEl(T,j,X);
				}
				j--;
			}
		} else {
			if (GetElmt(*T,i)<=X) {
				SetEl(T,i+1,GetElmt(*T,i));
				SetEl(T,i,X);
			} else {
				SetEl(T,i+1,X);
			}
		}
	}
}
void Del1Urut (TabInt *T, ElType X) {
	/*	Kamus */
	IdxType i;
	/*	Algoritma */
	if (SearchB(*T,X)) {
		i=Search1(*T,X);
		while (i<GetLastIdx(*T)) {
			SetEl(T,i,GetElmt(*T,i+1));
			i++;
		}
		SetEl(T,i,ValUndef);
	}
}

/*	DEALOKASI */
void Dealokasi (TabInt *T) {
	free ((*T).TI);
}