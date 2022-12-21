#define _CRT_SECURE_NO_WARNINGS
#include "func.h"

main() {
	int** a;
	printf("\nNumber of rows-->");
	int row = input_check2();
	printf("\nNumber of cols-->");
	int col = input_check();
	mem(&a, row, col);
	fill(row, col, a);
	print(row, col, a);

	sort(row, col,a);
	printf("\n------------------------------------------------------------\n\n");
	print(row, col, a);
	free(a);
}
