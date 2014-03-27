#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "adt_point.h"

/* VARIABEL UNIVERSAL */
POINT P1,P2;
boolean keluar;

/* HEADER */
void Tampilan();
void MasukProgram();

/* PROGRAM UTAMA */
int main () {
	keluar=false;
	while (!(keluar)) {
		Tampilan();
		MasukProgram();
	}
	return 0;
}

/* PROGRAM BANTUAN */
void Tampilan() {
	printf("------Menu------\n");
	printf("1. Baca Point 1\n");
	printf("2. Baca Point 2\n");
	printf("3. Tulis Point 1\n");
	printf("4. Tulis Point 2\n");
	printf("5. Pertambahan Point\n");
	printf("6. Pengurangan Point\n");
	printf("7. Fungsi Dot\n");
	printf("8. Fungsi Cross\n");
	printf("9. Apakah berada di titik tengah (0,0) ?\n");
	printf("10. Apakah di sumbu X?\n");
	printf("11. Apakah di sumbu Y?\n");
	printf("12. Apakah sama?\n");
	printf("13. Apakah beda?\n");
	printf("14. Apakah lebih kecil?\n");
	printf("15. Apakah lebih besar?\n");
	printf("16. Cek Kuadran\n");
	printf("17. Next X dari Point\n");
	printf("18. Next Y dari Point\n");
	printf("19. Fungsi Cek Point dengan perubahan Delta\n");
	printf("20. Apakah mirror dari suatu Point?\n");
	printf("21. Jarak Point dari titik (0,0)\n");
	printf("22. Panjang Point 1 dengan Point 2\n");
	printf("23. Geser sesuai input\n");
	printf("24. Geser ke sumbu x\n");
	printf("25. Geser ke sumbu y\n");
	printf("26. Mirror\n");
	printf("27. Putar sesuai sudut yang dikehendaki\n");
	printf("28. Set Absis P1\n");
	printf("29. Set Ordinat P1\n");
	printf("30. Exit\n");
	printf("Pilihan anda :	");
}
void MasukProgram() {
	int a;
	float b,c;
	int d,e;
	scanf("%d",&a);
	switch (a) {
	case 1 : { 
				BacaPOINT(&P1);
				break;
			}
	case 2 : {
				BacaPOINT(&P2);
				break;
			}
	case 3 : {
				TulisPOINT(P1);
				break;
			}
	case 4 : {
				TulisPOINT(P2);
				break;
			}
	case 5 : { 
				TulisPOINT(plus(P1,P2));
				break; 
		}
	case 6 : { 
				TulisPOINT(minus(P1,P2));
				break; 
			}
	case 7 : { 
				printf("%.2f\n",dot(P1,P2));
				break; 
			}
	case 8 : {
				printf("%.2f\n",cross(P1,P2));
				break;
			}
	case 9 : {
				if (IsOrigin(P1)) {
					printf("Ya\n");
				} else {
					printf("Tidak\n");
				}
				break;
			}
	case 10 : {
				if (IsOnSbX(P1)) {
					printf("Ya\n");
				} else {
					printf("Tidak\n");
				}
				break;
			}
	case 11 : {
				if (IsOnSbY(P1)) {
					printf("Ya\n");
				} else {
					printf("Tidak\n");
				}
				break;
			}
	case 12 : {
				if (EQ(P1,P2)) {
					printf("Ya\n");
				} else {
					printf("Tidak\n");
				}
				break;
			}
	case 13 : {
				if (NEQ(P1,P2)) {
					printf("Ya\n");
				} else {
					printf("Tidak\n");
				}
				break;
			}
	case 14 : {
				if (lebihkecil(P1,P2)) {
					printf("Ya\n");
				} else {
					printf("Tidak\n");
				}
				break;
			}
	case 15 : {
				if (lebihbesar(P1,P2)) {
					printf("Ya\n");
				} else {
					printf("Tidak\n");
				}
				break;
			}
	case 16 : {
				printf("Titik berada di kuadran %d\n",Kuadran(P1));
				break;
			}
	case 17 : {
				TulisPOINT(NextX(P1));
				break;
			}
	case 18 : {
				TulisPOINT(NextY(P1));
				break;
			}
	case 19 : {
				scanf("%f %f",&b,&c);
				TulisPOINT(PlusDelta(P1,b,c));
				break;
			}
	case 20 : {
				scanf("%d %d",&d,&e);
				TulisPOINT(MirrorOf(P1,d,e));
				break;
			}
	case 21 : {
				printf("Jarak dari (0,0) adalah %.2f\n",Jarak0(P1));
				break;
			}
	case 22 : {
				printf("Panjang P1 ke P2 adalah %.2f\n",Panjang(P1,P2));
				break;
			}
	case 23 : {
				scanf("%f %f",&b,&c);
				Geser(&P1,b,c);
				break;
			}
	case 24 : {
				GeserKeSbX(&P1);
				break;
			}
	case 25 : {
				GeserKeSbY(&P1);
				break;
			}
	case 26 : {
				scanf("%d %d",&d,&e);
				Mirror(&P1,d,e);
				break;
			}
	case 27 : {
				scanf("%f",&b);
				Putar(&P1,b);
				break;
			}
	case 28 : {
				scanf("%d",&b);
				SetAbsis(P1,b);
				break;
			}
	case 29 : {
				scanf("%d",&b);
				SetOrdinat(P1,b);
				break;
			}
	case 30 : {
				keluar = true;
				break;
			}
	}
}