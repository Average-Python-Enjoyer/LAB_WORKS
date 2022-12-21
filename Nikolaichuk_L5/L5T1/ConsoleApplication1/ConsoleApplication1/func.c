#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

float* memory(int n) {
    float* arr;
    arr = (float*)malloc(n * sizeof(float));
    return arr;
}
void deleting(float** arr, int* n) {
    for (int i = 0; i < (*n); i++) {
        if ((*arr)[i] == (int)(*arr)[i]) {
            for (int k = i; k < (*n) - 1; k++) {
                (*arr)[k] = (*arr)[k + 1];
            }
            (*arr)[*n - 1] = 0;
            (*n)--;
            *arr = realloc(*arr, (*n) * sizeof(float));
            i--;
        }
    }
}
void input(float* arr, float n) {
    for (int i = 0; i < n; i++) {
        printf("Number: ");
        while (scanf("%f", &arr[i]) != 1 || getchar() != '\n') {
            printf("Try entering the element again ");
            rewind(stdin);
        }
    }
}
int inputChecking() {
    float num;
    while (scanf("%f", &num) != 1 || (int)num <= 0 || num != (int)num || num > 100 || getchar() != '\n') {
        printf("Try entering the element again: ");
        rewind(stdin);
    }
    return num;
}

void output(float* arr, int n) {

    for (int i = 0; i < n; i++) {
        if (arr[i] == (int)arr[i]) {
            printf("\t|%f|", arr[i]);
        }
        else {
            printf("\t|%f| ", arr[i]);
        }
    }
    printf("\n");
}