#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>



int main() {

	int op; // operatorumu burda tanýmladým çunku do while dongusunde kullandým.

	printf("LEAP YEAR OPERATIONS\n"); //Programýn baþlýgýný ekrana yazdýrdýk

	// programýn sürekli aktif kalmasi için do while döngüsünü kullandým kullanici çýkýþ iþlemi girdiyse programý sonlandýracak
	do {

		//Seçenekleri ekrana yazdýrdýk

		printf("\n-------------------------------\n");
		printf("1.Check the year entered\n");
		printf("2.Leap years between the two entered years\n");
		printf("3.How many days are there per month in the date entered\n");
		printf("4.Exit\n");
		printf("-------------------------------\n");

		// kullanicidan yapmak istedigi iþlemi aldýk
		printf("Enter the operation: ");
		scanf_s("%d", &op);

		// herhangi bi hata çýkmamasý için kullanýcýnýn girdigi iþlem dogruysa programýmýz düzgün bir þekilde çalýþmasý için koþul koydum.

		if (op <= 4 && op >= 1) {


			int year; // burda case 1 de kullandýgým yeari tanýmladým case 1 in içindede tanýmlayabilirdim
			int totalleap = 0; // case 2 de kullandýgýmýz leap sayacý 
			//switch case kullanarak programýn iþleyiþini daha güzel bi hale getirdim.
			switch (op)
			{
				/*eger girilen operator 1 ise case 1 girecek
				2 ise case 2 , 3 ise case 3, 4 ise programi sonlandiracak*/


			case 1: //girilen yýlýn artýk yýl olup olmadýgýný gösterir.
				printf("Enter a year: ");
				scanf_s("%d", &year);
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && year % 4000 != 0) {
					printf("%d is a leap year.", year);
				}
				else {
					printf("%d is not a leap year.", year);
				}
				break;
			case 2: // girilen 2 yýl arasýnda kaç tane artýk yýl oldugunu gösterir.
				int y1, y2;
				int i;


				printf("Enter the first year: ");
				scanf_s("%d", &y1);
				printf("Enter the second year: ");
				scanf_s("%d", &y2);

				if (y1 > y2) {
					for (i = y2; i <= y1; ++i) {
						if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0 && i % 4000 != 0) {
							totalleap += 1;
						}
					}
					printf("There are %d leap years between the %d and %d", totalleap, y2, y1);
				}
				else if (y2 > y1) {

					for (i = y1; i <= y2; ++i) {
						if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0 && i % 4000 != 0) {
							totalleap += 1;
						}
					}
					printf("There are %d leap years between the %d and %d", totalleap, y1, y2);
				}
				else
				{
					printf("Please enter two different years!");
				}
				break;
			case 3: // girilen yýlýn ayýnda kaç gün oldugunu gösterir.
				//burda iç içe switch case mantýgýný kullandým. her case bir ayý temsil ediyor.
				int month, year1;
				int days;
				printf("Enter a Year: ");
				scanf_s("%d", &year1);
				printf("Enter a Month: ");
				scanf_s("%d", &month);
				switch (month)
				{

				case 1: case 3: case 5: case 7:
				case 8: case 10: case 12:
					days = 31;
					break;
				case 4: case 6: case 9: case 11:
					days = 30;
					break;
				case 2:
					if (year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0 && year1 % 4000 != 0)
						days = 29;
					else
						days = 28;
					break;
				default: days = 0;
				}
				printf("there are %d days in the month you entered ", days);
				break;

				//Burada ilk switch case imden 4 girilen degerde ekrana baþarýyla çýkýþ yapýldý yazdýrýlýr.

			default: printf("Successfully logged out");




			}
		}
		else // bu else kýsmý programýn baþýnda kullanýcýnýn girdigi iþlemi kontrol ettigimiz if in else idir.
			// yani kullanýcý 1 ile 4 arasýnda bir deger girmesse hata yazdýrýr.
		{
			printf("Please enter a operations between 1 and 4");
		}





	} while (op != 4); // do-while dongusu.. programýn sürekli kendini yenilemesi için girilen degerin 4 olmamasý lazým
	//egerki 4 girildiyse çýkýþ iþlemi yapar. ve programý sonlandýrýr

	return 0;
}