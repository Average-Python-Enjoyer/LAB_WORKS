#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "func.h"

void mem(int*** a, int row, int col)
{
	(*a) = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
	{
		(*a)[i] = (int*)malloc(sizeof(int) * col);
	}
}
//int input_check()
//{
//	int col;
//	while (scanf_s("%d", &col) != 1 || getchar() != '\n')
//	{
//		printf("wrong input\n");
//		rewind(stdin);
//
//	}
//	return col;
//}
int input_check_row()
{
	int row;
	while (scanf_s("%d", &row) != 1 || getchar() != '\n')
	{
		printf("wrong input\n");
		rewind(stdin);

	}
	return row;
}
void fill_rand(int row, int col, int** a) {
	srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = 10 - (rand() % 20);
		}
	}

}
void fill_manual(int row, int col, int** a) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("Enter %d %d element:\n", i + 1, j + 1);
			while (scanf_s("%d", &a[i][j]) != 1 || getchar() != '\n')
			{
				printf("Incorrect input. Repeat!");
				rewind(stdin);
			}
		}
	}
}
void print(int row, int col, int** a) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("\t|%d| ", a[i][j]);
		printf("\n");
	}
}
void fill(int row, int col, int** a) {
	int fl = 0;
	printf("\nUse random filling? (1) ");
	while (scanf_s("%d", &fl) != 1 || getchar() != ('\n')) {
		printf("Wrong input. Retry: ");
		rewind(stdin);
	}
	printf("\n");
	if (fl == 1) {
		fill_rand(row, col, a);
	}
	else {
		fill_manual(row, col, a);
	}
}
void del(int** a, int row, int* col) {
	for (int i = 0; i < row; i++) {
		for (int k = *col - i; k < *col; k++) {
			a[i][k - 1] = a[i][k];
		}
	}
	(*col)--;
	for (int j = 0; j < row; ++j) {
		a[j] = (int*)realloc(a[j], (*col) * sizeof(int));
	}
}