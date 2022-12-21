#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func.h"



int main(int argc, char** argv) {
    if (argc == 1) {
        printf("\n !USE CONSOLE!\n");
        return;
    }
    char** arr2 = memory(argc);
    int* size = memory1(argc);
    fill_and_copy(argc, arr2, argv, &size);
    merge_sort(&arr2, &size, 0, argc - 2);
    print(argc, arr2);
    free_mem(arr2, size, argc);
    printf("argc:%d", argc);
}
