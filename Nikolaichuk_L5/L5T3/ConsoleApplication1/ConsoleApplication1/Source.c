#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
int main() {
    int rows = 1, cols = 1;
    row_count(&rows);
    int** a = mem(rows, cols);
    fill(a, rows, &cols);
    printf("\n-----------------------------\n");
    print(a, rows);
    copy(&a, rows);
    printf("\n-----------------------------\n");
    print(a, rows);
    free(a);
}