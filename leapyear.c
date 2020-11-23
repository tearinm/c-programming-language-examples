#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>



int main() {

	int op; // operatorumu burda tan�mlad�m �unku do while dongusunde kulland�m.

	printf("LEAP YEAR OPERATIONS\n"); //Program�n ba�l�g�n� ekrana yazd�rd�k

	// program�n s�rekli aktif kalmasi i�in do while d�ng�s�n� kulland�m kullanici ��k�� i�lemi girdiyse program� sonland�racak
	do {

		//Se�enekleri ekrana yazd�rd�k

		printf("\n-------------------------------\n");
		printf("1.Check the year entered\n");
		printf("2.Leap years between the two entered years\n");
		printf("3.How many days are there per month in the date entered\n");
		printf("4.Exit\n");
		printf("-------------------------------\n");

		// kullanicidan yapmak istedigi i�lemi ald�k
		printf("Enter the operation: ");
		scanf_s("%d", &op);

		// herhangi bi hata ��kmamas� i�in kullan�c�n�n girdigi i�lem dogruysa program�m�z d�zg�n bir �ekilde �al��mas� i�in ko�ul koydum.

		if (op <= 4 && op >= 1) {


			int year; // burda case 1 de kulland�g�m yeari tan�mlad�m case 1 in i�indede tan�mlayabilirdim
			int totalleap = 0; // case 2 de kulland�g�m�z leap sayac� 
			//switch case kullanarak program�n i�leyi�ini daha g�zel bi hale getirdim.
			switch (op)
			{
				/*eger girilen operator 1 ise case 1 girecek
				2 ise case 2 , 3 ise case 3, 4 ise programi sonlandiracak*/


			case 1: //girilen y�l�n art�k y�l olup olmad�g�n� g�sterir.
				printf("Enter a year: ");
				scanf_s("%d", &year);
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && year % 4000 != 0) {
					printf("%d is a leap year.", year);
				}
				else {
					printf("%d is not a leap year.", year);
				}
				break;
			case 2: // girilen 2 y�l aras�nda ka� tane art�k y�l oldugunu g�sterir.
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
			case 3: // girilen y�l�n ay�nda ka� g�n oldugunu g�sterir.
				//burda i� i�e switch case mant�g�n� kulland�m. her case bir ay� temsil ediyor.
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

				//Burada ilk switch case imden 4 girilen degerde ekrana ba�ar�yla ��k�� yap�ld� yazd�r�l�r.

			default: printf("Successfully logged out");




			}
		}
		else // bu else k�sm� program�n ba��nda kullan�c�n�n girdigi i�lemi kontrol ettigimiz if in else idir.
			// yani kullan�c� 1 ile 4 aras�nda bir deger girmesse hata yazd�r�r.
		{
			printf("Please enter a operations between 1 and 4");
		}





	} while (op != 4); // do-while dongusu.. program�n s�rekli kendini yenilemesi i�in girilen degerin 4 olmamas� laz�m
	//egerki 4 girildiyse ��k�� i�lemi yapar. ve program� sonland�r�r

	return 0;
}