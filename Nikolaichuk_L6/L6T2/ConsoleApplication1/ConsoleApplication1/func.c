#define _CRT_SECURE_NO_WARNINGS

#include "func.h"

void mem(int*** a, int row, int col)
{
	(*a) = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
	{
		(*a)[i] = (int*)malloc(sizeof(int) * col);
	}
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
int input_check2()
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

int min_element(int* a, int col)
{
	int min = a[0];
	for (int i = 0; i < col; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}
void sort(int row, int col, int** a) {
	int i, j;
	int* key;
	for (i = 1; i < row; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && min_element(a[j], col) < min_element(key, col))
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}