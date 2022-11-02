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
	int sumA = 0, sumB = 0, temp = 0;
	for (j = 1; j < col; j++)
	{
		for (i = 0; i < row; i++) 
		{
			if (a[i][j - 1] < 0 && a[i][j - 1] % 2) {
				sumA += labs(a[i][j - 1]);
			}
			if (a[i][j] < 0 && a[i][j] % 2) 
				sumB += labs(a[i][j]); 
		}
		if (sumA > sumB) 
		{
			for (i = 0; i < row; i++) 
			{
				temp = a[i][j]; 
				a[i][j] = a[i][j - 1];
				a[i][j - 1] = temp;
			}
			j = 0;
		}
		sumA = 0; 
		sumB = 0;
	}
	printf("\n");
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("|%d|\t", a[i][j]);
		printf("\n");
	}
	int flag = 0;
	int col2 = 0;
	sumA = 0;
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row; i++)
		{
			if (a[i][j] < 0 ) {
				col2 = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			for (i = 0; i < row; i++) {
				sumA += (a[i][col2]);
			}
			flag = 0;
			printf("SUM:%d\n", sumA);
			sumA = 0;
		}
		else {
			printf("SUM:---\n");
		}
	}
}