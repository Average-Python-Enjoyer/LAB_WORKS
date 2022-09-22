#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
main() {
	int a,x1,x2,b,c,punishment;
	punishment = 2;
	printf("!!!INPUT 11 AND OLNY THEN 27!!!-->");
	scanf("%d%d", &b, &c);
	if (b != 11 || c != 27) {
		while (1) {
			printf("NEXT TIME INPUT CORRECT NUMBERS");
			printf("%d", punishment);
			punishment *=99999999999999999;

		}
	}
	a = 11 + 27;
	x1 = a / 10;
	x2 = a - x1*10;
	printf("ETO CIFRI %d\n AND %d\n", x1, x2);
	printf("A 27 + 11 = 38 | ZADANIE NEPONATNOE");
}