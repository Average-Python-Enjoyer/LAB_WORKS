#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
main() {
	//printf("\nNumber of colums-->");

	printf("\nNumber of rows and cols-->");
	int row = input_check_row();
	int col = row;
	int* a = (int*)malloc(row * col * sizeof(int));
	int* b = (int*)malloc(row * col  * sizeof(int));
	fill(row, col, a);
	del(row, col, a, b);
	print_b(row, col, b);
	free(a);
	free(b);
}


