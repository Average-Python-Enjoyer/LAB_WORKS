#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int colrow, half, i, number = 0;
int j, sum = 0;
int a[100][100];

void fill() {
	printf("Number of colums and rows(MUST BE KRATNO 2)-->");
	scanf("%d", &colrow);
	if (colrow % 2 == 0) {

	}
	else {
		while (1) {
			printf(" ERROR");
		}
	}
	short dess;
	printf("Use random filling? y/n | -->");
	scanf("%s", &dess);
	if (dess == 'y') {
		for (int i = 0; i < colrow; ++i) {
			for (int j = 0; j < colrow; ++j)
				a[i][j] = rand() % 11 + (-5);
		}
	}
	else {
		if (dess == 'n') {
			for (int i = 0; i < colrow; ++i) {
				for (int j = 0; j < colrow; ++j) {
					printf("Numbers->");
					scanf("%d", &number);
					a[i][j] = number;
				}
			}
		}
		else {
			while (1) {
				printf(" ERROR");
			}
		}
	}
}
main() {
	srand(time(NULL));
	fill();
	for (int i = 0; i < colrow; ++i) {
		for (int j = 0; j < colrow; ++j)
			printf("|%d|\t", a[i][j]);
		printf("\n");
	}
	half = colrow / 2;

	for (int i = 0; i < half; ++i) {
		for (j = half; j < colrow; ++j) {
			sum += a[i][j];
		}
		
	}
	printf("SUM:%d", sum);
}
