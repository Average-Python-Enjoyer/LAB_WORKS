#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
main() {
	int a, b, c;
	float g, s;
	printf("A B C-->");
	scanf("%d%d%d", &a, &b, &c);
	if (a != 0 && b != 0 && c != 0) {
		g = sqrt((a * b * c), 3);
		printf ("SREDNEE GEOMETRICHESKOE = %f", g);
	}
	else {
		s = (a+b+c)/3;
		printf("SREDNEE ARIFMETICHESKOR = %f", s);
	}

}