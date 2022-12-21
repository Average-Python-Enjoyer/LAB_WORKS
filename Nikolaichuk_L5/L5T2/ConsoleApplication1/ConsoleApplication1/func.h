#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int input_check();
int input_check_row();

void fill_rand(int row, int col, int* a);
void fill_manual(int row, int col, int* a);
void print(int row, int col, int* a);
void print_b(int row, int col, int* b);
void fill(int row, int col, int* a);
void del(int row, int col, int* a, int* b);
int** mem_a(int col, int row);
int** mem_b(int col, int row);
void del_a(int* a, int row);
void del_b(int* b, int row);
#endif //UNTITLED_FUNCTIONS_H