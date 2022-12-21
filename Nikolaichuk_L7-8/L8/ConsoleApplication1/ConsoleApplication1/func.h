#ifndef INC_5_1_FUNCTIONS_H
#define INC_5_1_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int str_len(const char* arr);
void str_copy(char* arr1, char** arr2);
int if_letter(char arr1);
void erase(char** arr, int* size, int pos);
void remove1(char** arr);
int find_word(char** arr2);
void merge(char*** arr, int** size, int left, int mid, int right);
void merge_sort(char*** arr, int** size, int left, int right);
void print_string(char* arr);
void free_mem(char** arr2, int* size, int argc);
char** memory(int argc);
int* memory1(int argc);
void fill_and_copy(int argc, char** arr2, char** argv, int** size);
void print(int argc, char** arr2);

#endif //INC_5_1_FUNCTIONS_H