/* Nama / NIM	: Riva Syafri Rachmatullah / 13512036				*/
/* Nama File	: */
/* Topik		: ADT TABEL KONTIGU IMPLISIT DINAMIK 				*/
/* Tanggal		: */
/* Deskripsi	: DRIVER ADT TABEL KONTIGU IMPLISIT DINAMIK			*/

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "adttabel.h"
void Pause();
int main()
{
	TabInt T1,T2;
	ElType X;
	IdxType id;
	int opt,i,a;
	char *menu[] = {
		"1.  Tambahkan T1 dan T2",
		"2.  Kurangkan T1 dengan T2",
		"3.  Kalikan T1 dan T2",
		"4.  Kali dengan Konstanta",
		"5.  Cari index Elemen",
		"6.  Apakah ada elemen X?",
		"7.  Nilai max dan min",
		"8.  Apakah Ismetris?",
		"9.  Sorting",
		"10. Tambahkan Elemen di akhir",
		"11. Tambahkan Elemen di sembarang tempat",
		"12. Hapus Elemen di akhir",
		"13. Hapus Elemen di sembarang tempat",
		"0.  Exit",
		""
	};
	system("cls");
	scanf("%d",&a);
	MakeEmpty(a,&T1);
	scanf("%d",&a);
	MakeEmpty(a,&T2);
	BacaIsi(&T1);
	BacaIsi(&T2);
	do {
		system("cls");
		printf("Isi Tabel\n");
		printf("T1 = ");TulisIsiTab(T1);printf("\n");
		printf("T2 = ");TulisIsiTab(T2);printf("\n");
		printf("%d %d\n",NbElmt(T1),NbElmt(T2));
		printf("%d %d\n",MaxNbEl(T1),MaxNbEl(T2));
		i = 0;
		while(strcmp(menu[i],"")!=0){
			printf("%s\n",menu[i]);
			i++;
		}
		printf("Masukan pilihan = ");scanf("%d",&opt);
		system("cls");
		switch(opt){
			case 1 :
				TulisIsiTab(PlusTab(T1,T2));printf("\n");
				break;
			case 2 :
				TulisIsiTab(MinusTab(T1,T2));printf("\n");
				break;
			case 3 :
				TulisIsiTab(KaliTab(T1,T2));printf("\n");
				break;
			case 4 :
				scanf("%d",&X);
				TulisIsiTab(KaliKons(T1,X));printf("\n");
				TulisIsiTab(KaliKons(T2,X));printf("\n");
				break;
			case 5 :
				scanf("%d",&X);
				TulisIsiTab(T1);printf("\n");
				TulisIsiTab(T2);printf("\n");
				printf("%d %d %d %d\n",Search1(T1,X),Search2(T1,X),SearchB(T1,X),SearchSentinel(T1,X));
				printf("%d %d %d %d\n",Search1(T2,X),Search2(T2,X),SearchB(T2,X),SearchSentinel(T2,X));
				break;
			case 6 :
				break;
			case 7 :
				TulisIsiTab(T1);printf("Max = %d(%d), Min = %d(%d)\n",ValMax(T1),IdxMaxTab(T1),ValMin(T1),IdxMinTab(T1));
				TulisIsiTab(T2);printf("Max = %d(%d), Min = %d(%d)\n",ValMax(T2),IdxMaxTab(T2),ValMin(T2),IdxMinTab(T2));
				break;
			case 8 :
				printf("%d %d",IsSimetris(T1),IsSimetris(T2));
				break;
			case 9 :
				scanf("%d",&X);
				if (X==1){
					MaxSortDesc(&T1);
					MaxSortDesc(&T2);
				}else{
					InsSortAsc(&T1);
					InsSortAsc(&T2);
				}
				break;
			case 10 :
				scanf("%d",&X);
				AddAsLastEl(&T1,X);
				AddAsLastEl(&T2,X);
				break;
			case 11 :
				scanf("%d",&X);
				scanf("%d",&id);
				AddEli(&T1,X,id);
				AddEli(&T2,X,id);
				break;
			case 12 :
				DelLastEl(&T1,&X);
				printf("%d ",X);
				DelLastEl(&T2,&X);
				printf("%d\n",X);
				break;
			case 13 :
				scanf("%d",&id);
				DelEli(&T1,id,&X);
				printf("%d ",X);
				DelEli(&T2,id,&X);
				printf("%d\n",X);
			default : break;
		}
		Pause();
	}while (opt!=0);
	Dealokasi(&T1);
	Dealokasi(&T2);
	return 0;
}
void Pause()
{
    char c;
    do {
    	printf("Press enter to continue... ");
        scanf("%c",&c);
        scanf("%c",&c);
    } while (c != '\n');
}