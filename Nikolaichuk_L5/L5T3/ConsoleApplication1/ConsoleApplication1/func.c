#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "func.h"

void row_count(int* rows) {
    printf("Number of rows:");
    while (scanf_s("%d", rows) != 1 || *rows <= 0 || getchar() != ('\n')) {
        printf("Number of rows:");
        rewind(stdin);
    }
}
int** mem(int rows, int cols) {
    int** a;
    a = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        a[i] = (int*)calloc(rows, sizeof(int));
    }
    return a;
}
int cols_count(int** a, int row) {
    int cols = 1;
    for (int i = 0;; i++) {
        if (a[row][i] != -100) {
            cols++;
        }
        else {
            break;
        }
    }
    return cols;
}
void print(int** a, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols_count(a, i); j++) {
            if (a[i][j] != -100)
                printf("|%d|\t", a[i][j]);
        }
        printf("|-100|\t");
        printf("\n");
    }
}
void fill(int** a, int rows, int* cols) {
    for (int i = 0; i < rows; i++) {
        int breakk = 0;
        for (int j = 0; j < *cols && breakk == 0; j++) {
            printf("Number-->");
            while (scanf_s("%d", &a[i][j]) != 1 || getchar() != '\n') {
                if (a[i][j] == -100) {
                    break;
                }
                printf("Wrong input:");
                rewind(stdin);
            }
            if (a[i][j] == -100) {
                breakk = 1;
                if (i != rows - 1) {
                    printf("!Next row!\n");
                }
            }
            else {
                (*cols)++;
                a[i] = (int*)realloc(a[i], (*cols) * sizeof(int));
            }
        }
    }
}
void copy(int*** a, int rows) {
    for (int i = 0; i < rows; i++) {
        int col = cols_count(*a, i);
        if ((i + 1) % 2 == 0 && col != 0) {
            for (int j = 0; j < col;) {
                if ((*a)[i][j] % 2 != 0) {
                    col++;

                    (*a)[i] = (int*)realloc((*a)[i], col * sizeof(int));

                    for (int k = col - 1; k > j; k--) {
                        (*a)[i][k] = (*a)[i][k - 1];
                    }
                    j += 2;
                }
                else {
                    j++;
                }
            }
        }
    }
}