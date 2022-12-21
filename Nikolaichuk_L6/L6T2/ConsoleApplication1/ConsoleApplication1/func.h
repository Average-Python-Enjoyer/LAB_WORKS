#ifndef INC_5_1_FUNCTIONS_H
#define INC_5_1_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void mem(int*** a, int row, int col);
int input_check();
int input_check2();
void fill_rand(int row, int col, int** a);
void fill_manual(int row, int col, int** a);
void print(int row, int col, int** a);
void fill(int row, int col, int** a);
int min_element(int* a, int col);
void sort(int row, int col, int** a);

#endif //INC_5_1_FUNCTIONS_H