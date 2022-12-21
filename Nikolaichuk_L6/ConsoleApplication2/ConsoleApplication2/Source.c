#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input_array1(int n, int* mas)
{
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 101 - 50;
    }
}
void output_array1(int n, int* mas)
{
    for (int i = 0; i < n; i++)
    {
        if ((mas[i] > 0) && (mas[i] % 2 == 0))
            printf(" \033[38;5;043m%3i\033[0m", mas[i]);
        else
            printf(" %3i", mas[i]);
    }
    printf("\n");
}
int amount_elements() {
    int n;
    printf("Amount of elements:");
    while (scanf_s("%d", &n) != 1 || n <= 0 || getchar() != ('\n')) {
        printf("Amount of elements:");
        rewind(stdin);
    }
    return n;
}
void extra_array(int n, int* mas, int** dop_array, int* size)
{
    (*size) = 1;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > 0 && mas[i] % 2 == 0)
            (*size)++;
    }
    if ((*size) != 1)
    {
        int* copy = (int*)realloc(*dop_array, (*size) * sizeof(int));
        if (copy != NULL)
        {
            *dop_array = copy;
        }
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (mas[i] > 0 && mas[i] % 2 == 0)
            {
                (*dop_array)[p] = mas[i];
                p++;
            }
        }
    }
    (*size)--;
}


void shell_sort(int n, int* mas)
{
    clock_t t;
    t = clock();
    int step, i, j, temp;
    for (step = n / 2; step > 0; step /= 2)
    {
        for (i = step; i < n; i++)
        {
            for (j = i; j >= step; j -= step)
            {
                if (mas[j] < mas[j - step])
                {
                    temp = mas[j];
                    mas[j] = mas[j - step];
                    mas[j - step] = temp;
                }
                else
                    break;
            }
        }
    }
    clock_t end = clock();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nSHELL took %f seconds to execute \n", time_taken);
}
void fill_rand(int* mas, int n) {
    //printf("%d", amount);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        mas[i] = 100 - (rand() % 200);
    }
}
void sort_elements(int n, int* mas, int* dop_mas)
{
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > 0 && mas[i] % 2 == 0)
        {
            mas[i] = dop_mas[p];
            p++;
        }
    }
}
void copy_arr(int* mas,int* mas2, int n) {
    for (int i = 0; i < n; ++i) {
        mas2[i] = mas[i];
    }
}
void bubble_sort(int n, int* mas) {
    clock_t t;
    t = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = (n - 1); j > i; j--) {
            if (mas[j - 1] > mas[j]) {
                int temp = mas[j - 1];
                mas[j - 1] = mas[j];
                mas[j] = temp;
            }
        }
    }
    clock_t end = clock();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nBUBBLE took %f seconds to execute \n", time_taken);
}

void shell_sort_reverse(int size, int *mas) {
    clock_t t;
    t = clock();
    int i, j, k, tmp;
    for (i = size / 2; i > 0; i = i / 2)
    {
        for (j = i; j < size; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (mas[k + i] <= mas[k])
                    break;
                else
                {
                    tmp = mas[k];
                    mas[k] = mas[k + i];
                    mas[k + i] = tmp;
                }
            }
        }
    }
    clock_t end = clock();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\nSHELL REVERSE took %f seconds to execute \n", time_taken);
}

main() {
    int n = amount_elements();
    int size;
    int* mas = NULL;
    int* dop_mas = NULL;
    mas = (int*)calloc(n, sizeof(int));
    fill_rand(mas, n);
    printf(" ARRAY:\n");
    //output_array1(n, mas);
    printf(" _____________________________________________________________________\n");

    extra_array(n, mas, &dop_mas, &size);
    shell_sort(size, dop_mas);

    
    printf(" SHELL SORT:\n");
    sort_elements(n, mas, dop_mas);
    //output_array1(n, mas);
    printf(" _____________________________________________________________________\n");
 

    extra_array(n, mas, &dop_mas, &size);
    bubble_sort(size,dop_mas);
    sort_elements(n, mas, dop_mas);
    printf(" BUBBLE SORT:\n");
    //output_array1(n, mas);
    printf(" _____________________________________________________________________\n");


    extra_array(n, mas, &dop_mas, &size);
    shell_sort_reverse(size, dop_mas);
    sort_elements(n, mas, dop_mas);
    printf(" SHELL REVERSE SORT:\n");
    //output_array1(n, mas);
    printf(" _____________________________________________________________________\n");

}