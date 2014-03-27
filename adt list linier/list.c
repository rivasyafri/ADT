/* NIM / Nama    : 13512036 / Riva Syafri Rachmatullah                    */
/* Nama File     : list.c                                        */
/* Topik         : ADT List Linier - First Implisit                       */
/* Tanggal       : 7 November 2013                                        */
/* Deskripsi     : Implementasi dari ADT List Linier versi First Implisit */

/* ----- File Include ----- */
#include "boolean.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* ----- Test List Kosong ----- */
boolean IsListEmpty (List L) {
    /* Kamus Lokal */
    
    /* Algoritma */
    return (First(L) == Nil);
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L) {
    /* Kamus Lokal*/

    /* Algoritma */
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X) {
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P = (address) malloc (sizeof (ElmtList));
    if (P != Nil) {
      Info(P) = X;
      Next(P) = Nil;
      return P;
    } else {
      return Nil;
    }
}

void Dealokasi (address P) {
    /* Kamus Lokal */
    
    /* Algoritma */
    free(P);
}

/* ----- Pencarian Sebuah Elemen List ----- */
address Search (List L, infotype X) {
    /* Kamus Lokal */
    address P;
    boolean Found;

    /* Algoritma */
    P = First(L);
    Found = false;
    while ((P != Nil) && (!Found)) {
      if (X == Info(P)) {
        Found = true;
      } else {
        P = Next(P);
      }
    }
    return P;
}

boolean FSearch (List L, address P) {
    /* Kamus Lokal */
    address Pcek;
    boolean ketemu;

    /* Algoritma */
    Pcek = First(L);
    ketemu = false;
    while ((Pcek != Nil)&&(!ketemu)) {
      if (Pcek == P) {
        ketemu = true;
      } else {
        Pcek = Next(Pcek);
      }
    }
    return ketemu;
}

address SearchPrec (List L, infotype X) {
    /* Kamus Lokal */
    address P;
    boolean Found;

    /* Algoritma */
    P = First(L);
    Found = false;
    if (P == Nil) {
      return Nil;
    } else {
      while ((Next(P) != Nil) && (!Found)) {
        if (X == Info(Next(P))) {
          Found = true;
        } else {
          P = Next(P);
       }
      }
    }
    if (Next(P) == Nil) {
      return Nil;
    } else {
      return P;
    }
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X) {
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil) {
      InsertFirst(L,P);
    }
}

void InsVLast (List *L, infotype X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil) {
      InsertLast(L,P);
    }
}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X) {
     /* Kamus Lokal */
    address P;

    /* Algoritma */
    DelLast(L,P);
    (*X) = Info(P);
    Dealokasi(P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P) {
    /* Kamus Lokal */

    /* Algoritma */
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter (List *L, address P, address Prec) {
  /* Kamus Lokal */

  /* Algoritma */
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLast (List *L, address P) {
    /* Kamus Lokal */
    address Last;
    
    /* Algoritma */
    Last = First(*L);
    if (First(*L) == Nil) {
      InsertFirst(L,P);
    } else {
      while (Next(Last) != Nil) {
        Last = Next(Last);
      }
      InsertAfter(L,P,Last)
    }
}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address P) {
    /* Kamus Lokal */

    /* Algoritma */
    P = First(*L);
    First(*L) = Next(First(*L));
}

void DelP (List *L, infotype X) {
  /* Kamus Lokal */
  address P, Prec;

  /* Algoritma*/
  P = Search(*L,X);
  if (P == First(*L)) {
    DelFirst(L,P);
  } else {
    Prec = SearchPrec(*L,X);
    DelAfter(L,P,Prec);
  }
}

void DelLast (List *L, address P) {
  /* Kamus Lokal */
  address Last, PrecLast;
  
  /* Algoritma */
  Last = First(*L);
  PrecLast = Nil;
  while (Next(Last) != Nil) {
    PrecLast = Last;
    Last = Next(Last);;
  }
  P = Last;
  if (PrecLast == Nil) {
    First(*L) = Nil;
  } else {
    Next(PrecLast) = Nil;
  }
}

void DelAfter (List *L, address Pdel, address Prec) {
    /* Kamus Lokal */

    /* Algoritma */
    Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(Pdel) = Nil;
}

/* Proses Semua Elemen List */
void PrintInfo (List L) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(L);
    if (P == Nil) {
      printf("List kosong\n");
    } else {
      while (Next(P) != Nil) {
        printf("%d,",Info(P));
        P = Next(P);
      }
      printf("%d\n", Info(P));
    }
}

int NbElmt (List L) {
    /* Kamus Lokal */
    address P;
    int i;

    /* Algoritma */
    i = 0;
    P = First(L);
    while (P != Nil) {
       i++;
       P = Next(P);
    }
    return i;
}

/* Prekondisi untuk Max/Min/rata-rata : List tidak kosong */
infotype Max (List L) {
    /* Kamus Lokal */
    infotype maksimum;
    address P;

    /* Algoritma */
    P = First(L);
    maksimum = Info(P);
    P = Next(P);
    while (P != Nil) {
      if (maksimum < Info(P)) {
        maksimum = Info(P);
      }
      P = Next(P);
    }
    return maksimum;
}

address AdrMax (List L) {
    /* Kamus Lokal */
    infotype maksimum;
    address P;

    /* Algoritma */
    maksimum = Max(L);
    P = Search(L,maksimum);
    return P;
}

infotype Min (List L) {
    /* Kamus Lokal */
    infotype minimum;
    address P;

    /* Algoritma */
    P = First(L);
    minimum = Info(P);
    P = Next(P);
    while (P!=Nil) {
      if (minimum>Info(P)) {
        minimum = Info(P);
      }
      P = Next(P);
    }
    return minimum;
}

address AdrMin (List L) {
    /* Kamus Lokal */
    infotype minimum;
    address P;

    /* Algoritma */
    minimum = Min(L);
    P = Search(L,minimum);
    return P;
}

float Average (List L) {
    /* Kamus Lokal */
    float sum;
    address P;

    /* Algoritma */
    P = First(L);
    sum = Info(P);
    P = Next(P);
    while (P != Nil) {
      sum += Info(P);
      P = Next(P);
    }
    return sum/NbElmt(L);
}

/* ----- Proses Terhadap List */
void DelAll (List *L) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    while (P != Nil) {
      First(*L) = Next(First(*L));
      Next(P) = Nil;
      Dealokasi(P);
      P = First(*L);
    }
}

void InversList (List *L) {
    /* Kamus Lokal */
    address P, Pt;
    
    /* Algoritma */
    CreateList(&Lt);
    if (P != Nil) {
      while (Next(P) != Nil) {
        Pt = Next(P);
        DelAfter(L,P,Pt);
        InsertFirst(L,Pt);
      }
    }
}

List FInversList (List L) {
    /* Kamus Lokal */
    List Li;
    address P, Pt;
    boolean gagal;

    /* Algoritma */
    gagal = false;
    CreateList(&Li);
    P = First(L);
    while ((P != Nil) && (!gagal)) {
      Pt = Alokasi(Info(P));
      if (Pt != Nil) {
        InsertFirst(&Li, Pt);
        P = Next(P);
      } else {
        DelAll(&Li);
        gagal = true;
      }
    }
    return Li;
}

void CopyList (List L1, List *L2) {
    /* Kamus Lokal */

    /* Algoritma */
    First(*L2) = First(L1);
}

List FCopyList (List L) {
    /* Kamus Lokal */
    address P, Pt;
    List Lt;
    boolean gagal;

    /* Algoritma */
    gagal = false;
    CreateList(&Lt);
    P = First(L);
    while ((P != Nil)&&(!gagal)) {
      Pt = Alokasi(Info(P));
      if (Pt != Nil) {
        InsertLast(&Lt,Pt);
        P = Next(P);
      } else {
        gagal = true;
        DelAll(&Lt);
      }
    }
    return Lt;
}

void CpAlokList (List Lin, List *Lout) {
    /* Kamus Lokal */
    address P, Pt;
    boolean gagal;

    /* Algoritma */
    CreateList(Lout);
    gagal = false;
    P = First(Lin);
    while ((P != Nil)&&(!gagal)) {
      Pt = Alokasi(Info(P));
      if (Pt != Nil) {
        InsertLast(Lout,Pt);
        P = Next(P);
      } else {
        gagal = true;
        DelAll(Lout);
      }
    }
}

void Konkat (List L1, List L2, List *L3) {
    /* Kamus Lokal */
    address P, Pt;
    boolean gagal;

    /* Algoritma */
    CreateList(L3);
    gagal = false;
    P = First(L1);
    while ((P != Nil)&&(!gagal)) {
      Pt = Alokasi(Info(P));
      if (Pt != Nil) {
        InsertLast(L3,Pt);
        P = Next(P);
      } else {
        gagal = true;
        DelAll(L3);
      }
    }
    if (!gagal) {
      P = First(L2);
      while ((P != Nil)&&(!gagal)) {
        Pt = Alokasi(Info(P));
        if (Pt != Nil) {
          InsertLast(L3,Pt);
          P = Next(P);
        } else {
          gagal = true;
          DelAll(L3);
        }
      }
    }
}

void Konkat1 (List *L1, List *L2, List *L3) {
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L1);
    CreateList(L3);
    First(*L3) = First(*L1);
    if (P != Nil) {
      while (Next(P) != Nil) {
        P = Next(P);
      } 
    }
    Next(P) = First(*L2);
    CreateList(L1);
    CreateList(L2);
}

void PecahList (List *L1, List *L2, List L) {
    /* Kamus Lokal */
    address P, Pt;
    boolean gagal;
    int i, N;


    /* Algoritma */
    CreateList(L1);
    CreateList(L2);
    gagal = false;
    i = 1;
    N = NbElmt(L)/2;
    P = First(L);
    while (P != Nil)&&(!gagal) {
      Pt = Alokasi(Info(P));
      if (i <= N) {
        if (Pt != Nil) {
          InsertLast(L1,Pt);
          P = Next(P);
          i++;
        } else {
          gagal = true;
          DelAll(L1);
        }
      } else {
        if (Pt != Nil) {
          InsertLast(L2,Pt);
          P = Next(P);
          i++;
        } else {
          gagal = true;
          DelAll(L2);
        }
      }
    }
}