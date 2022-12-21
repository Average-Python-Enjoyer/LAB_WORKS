#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "func.h"

main() {
	int** a;
	printf("\nNumber of rows and rows-->");
	int row = input_check_row();
	int col = row;
	mem(&a, row, col);
	fill(row, col, a);
	print(row, col, a);
	del(a, row, &col);
	printf("\n-----------------------------------\n\n");
	print(row, col, a);
	free(a);
}
