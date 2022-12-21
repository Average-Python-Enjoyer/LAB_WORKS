#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func.h"
int main()
{
    while (1) {
        printf_s("Enter Task (1-2)\n");
        int task;
        while (!scanf_s("%d", &task) || task > 2 || task < 1 || getchar() != '\n') {
            printf_s("Incorrect input!\n");
            rewind(stdin);
        }
        void (*task_run[2]) () = { task1, task2 };
        ((*task_run[task - 1])());
        printf_s("\n\n");
        rewind(stdin);
    }
}