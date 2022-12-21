#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "func.h"

int main() {
    int n;
    float* arr;
    printf("Amount of elements: ");
    n = inputChecking();
    arr = memory(n);
    input(arr, n);
    output(arr, n);
    deleting(&arr, &n);
    printf("\n--------------------------------\n\n");
    output(arr, n);
    free(arr);
    return 0;
}