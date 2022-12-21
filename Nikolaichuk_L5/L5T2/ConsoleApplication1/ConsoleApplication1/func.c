#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "func.h"
int** memory(int n, int m) {
	int** a;
	a = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)calloc(m, sizeof(int));
	}
	if (a == NULL) {
		printf("Memory allocation failed.");
		exit(1);
	}
	return a;
}
int input_check()
{
	int col;
	while (scanf_s("%d", &col) != 1 || getchar() != '\n')
	{
		printf("wrong input\n");
		rewind(stdin);

	}
	return col;
}
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
//void colrowcount1() {
//	printf("\nNumber of colums-->");
//	fflush(stdin);
//	int col = input_check();
//}
//void colrowcount2() {
//	printf("\nNumber of rows-->");
//	fflush(stdin);
//	int row = input_check2();
//}
void fill_rand(int row, int col, int* a) {
	srand(time(0));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			*(a + i * col + j) = rand() % 11 + (-5);
	}
}
void fill_manual(int row, int col, int* a) {
	int number;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("\nNumbers->");
			scanf("%d", &number);
			*(a + i * col + j) = number;
		}
	}
}
void print(int row, int col, int* a) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("|%d|\t", *(a + i * col + j));
		printf("\n");
	}
}
void print_b(int row, int col, int* b) {
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < col - 1; ++j)
			printf("|%d|\t", *(b + i * col + j));
		printf("\n");
	}
	for (int i = col; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("|%d|\t", *(b + i * col + j));
		printf("\n");
	}
}
void fill(int row, int col, int* a) {
	short dess;
	while (1) {
		printf("Use random filling? y/n | -->");
		scanf("%s", &dess);
		if (dess == 'y') {
			fill_rand(row, col, a);
			print(row, col, a);
			break;
		}
		else {
			if (dess == 'n') {
				fill_manual(row, col, a);
				print(row, col, a);
				break;
			}
			else {
				printf("Incorrect input! Try again!");
				continue;
			}
		}
	}
}
void del(int row, int col, int* a, int* b) {
	int m = col;
	printf("\n--------------------------");
	printf("\n");
	int flag = row - col;
	for (int i = 0; i < row - flag; i++) {
		for (int k = m - i; k < m; k++) {

			*(a + i * col + k - 1) = *(a + i * col + k);
			//printf("|!|");
			col--;
			for (int j = 0; j < col; ++j) {
				a[j] = (int*)realloc(a[j], (col) * sizeof(int));
			}
		}
	}
	--m;
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < col - 1; ++j) {
			*(b + i * col + j) = *(a + i * col + j);
		}
	}
	for (int i = col; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			*(b + i * col + j) = *(a + i * col + j);
		}
	}
}
//int** mem_a(int col, int row) {
//	int** a;
//	a= (int**)calloc(row, sizeof(int*));
//	for (int i = 0; i < row; i++) {
//		a[i] = (int*)calloc(col, sizeof(int));
//	}
//	return a;
//}
//int** mem_b(int col, int row) {
//	int** b ;
//	b= (int**)calloc(row, sizeof(int*));
//	for (int i = 0; i < row; i++) {
//		b[i] = (int*)calloc(col-1, sizeof(int));
//	}
//	return b;
//}
void del_a(int* a, int row) {
	for (int i = 0; i < row; ++i) free(a[i]);
	free(a);
}
void del_b(int* b, int row) {
	for (int i = 0; i < row; ++i) free(b[i]);
	free(b);
}