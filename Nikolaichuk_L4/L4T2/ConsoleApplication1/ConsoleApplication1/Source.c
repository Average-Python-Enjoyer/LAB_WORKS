#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
main() {
	srand(time(NULL));
	int col, i, row, number = 0;
	int j = 0;
	int a[100][100];
	printf("Number of colums-->");
	scanf("%d", &col);
	printf("Number of rows-->");
	scanf("%d", &row);
	short dess;
	printf("Use random filling? y/n | -->");
	scanf("%s", &dess);
	if (dess == 'y') {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j)
				a[i][j] = rand() % 11 + (-5);
		}
	}
	else {
		if (dess == 'n') {
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
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
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("|%d|\t", a[i][j]);
		printf("\n");
	}
	printf("----------------------------------------------\n");
	int flag = 0;
	for (int i = 0; (i < row); i++) {
		for (int j = 0; j < col; j++)
			if (a[i][j] > 0) {
				flag ++;
				break;
			}
	}
	if (flag == row)
		for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			a[i][j] = -a[i][j], printf("|%d|\t ", a[i][j]);
		printf("\n");
	}
	else printf("No < 0 elements detected");

}