#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
main() {
	int x1, y1, x2, y2;
	float r;
	printf("X1 Y1 X2 Y2-->");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	r = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	printf("distance-->%.2f", r);
}