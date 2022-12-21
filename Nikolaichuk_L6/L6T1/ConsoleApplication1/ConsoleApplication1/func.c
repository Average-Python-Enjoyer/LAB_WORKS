#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#include "func.h"
int amount_elements() {
    int amount;
    printf("Amount of elements:");
    while (scanf_s("%d", &amount) != 1 || amount <= 0 || getchar() != ('\n')) {
        printf("Amount of elements:");
        rewind(stdin);
    }
    return amount;
}
void fill_rand(int* a, int amount) {
    //printf("%d", amount);
    srand(time(NULL));
    for (int i = 0; i < amount; i++)
    {
        a[i] = 100 - (rand() % 200);
    }
}
void fill_manual(int* a, int amount) {
    for (int i = 0; i < amount; i++) {
        printf("Enter number -> ");
        while (scanf_s("%d", &a[i]) != 1 || getchar() != ('\n')) {
            printf("Wrong input. Retry: ");
            rewind(stdin);
        }
    }
}
void fill(int* a, int amount) {
    int fl = 0;
    printf("Use random filling? (1)");
    while (scanf_s("%d", &fl) != 1 || getchar() != ('\n')) {
        printf("Wrong input. Retry: ");
        rewind(stdin);
    }

    if (fl == 1) {
        fill_rand(a, amount);
    }
    else {
        fill_manual(a, amount);
    }
}
void print(int* a, int amount)
{
    for (int i = 0; i < amount; i++) {
        printf("|%d| ", a[i]);
    }
}

int find_pos(int* a, int amount)
{
    int pos = 0;

    for (int i = 0; i < amount; i++)
    {
        while (a[i] % 2 == 0 && a[i] > 0)
        {
            pos++;
            break;
        }
    }
    return pos;
}

void shell_sort(int* a, int pos)
{
    printf("\n");;
    for (int i = pos / 2; i > 0; i = i / 2)
    {
        for (int j = i; j < pos; j++)
        {
            for (int k = j - i; k >= 0; k = k - i)
            {
                if (a[k + i] >= a[k])
                    break;
                else
                {
                    int tmp = a[k];
                    a[k] = a[k + i];
                    a[k + i] = tmp;
                }
            }
        }
    }
}

void shell_sort_reverse(int* a, int amount) {
    int i, j, k, tmp;
    for (i = amount / 2; i > 0; i = i / 2)
    {
        for (j = i; j < amount; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (a[k + i] <= a[k])
                    break;
                else
                {
                    tmp = a[k];
                    a[k] = a[k + i];
                    a[k + i] = tmp;
                }
            }
        }
    }
}

void mod_a(int* a, int amount)
{
    int total = 0;
    for (int i = 0; i < amount; i++)
    {
        if (a[i] % 2 != 0 || a[i] < 0)
        {
            for (int j = i + 1; j < amount; j++)
            {
                if (a[j] % 2 == 0 && a[j] > 0)
                {
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
    }
}

void bubble_sort(int* a, int amount) {
    for (int i = 0; i < amount - 1; i++) {
        for (int j = (amount - 1); j > i; j--) {
            if (a[j - 1] > a[j]) {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void shell_time(int* a, int pos)
{
    clock_t t;
    t = clock();
    shell_sort(a, pos);
    clock_t end = clock();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("\nSHELL took %f seconds to execute \n", time_taken);
}

void bubble_time(int* a, int pos)
{
    clock_t t;
    t = clock();
    bubble_sort(a, pos);
    clock_t end = clock();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("\nBUBBLE took %f seconds to execute \n", time_taken);
}

void shell_time_rev(int* a, int pos)
{
    clock_t t;
    t = clock();
    shell_sort(a, pos);
    clock_t end = clock();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("SHELL REVERSE took %f seconds to execute \n", time_taken);
}