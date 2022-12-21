#define _CRT_SECURE_NO_WARNINGS
#include "func.h"

int str_len(const char* arr) {
    int i = 0;
    while (arr[i] != '\0')
        i++;
    return i;
}

void str_copy(char* arr1, char** arr2) {
    int strlen = str_len(arr1), i = 0;
    (*arr2) = (char*)calloc(strlen + 1, sizeof(char));
    while (arr1[i] != '\0') {
        (*arr2)[i] = arr1[i];
        i++;
    }
    (*arr2)[i] = '\0';
}

int if_letter(char arr1) {

    if ((arr1 >= 'a' && arr1 <= 'z') || (arr1 >= 'A' && arr1 <= 'Z'))
        return 1;

    return 0;

}

void erase(char** arr, int* size, int pos) {
    for (int i = pos; i < *size - 1; i++)
        (*arr)[i] = (*arr)[i + 1];
    (*size) -= 1;
    *arr = (char*)realloc(*arr, (*size + 1) * sizeof(char));
    (*arr)[*size] = '\0';
}

void remove1(char** arr) {

    int i = 0; //,k=0;
    int size = str_len(*arr);
    while ((*arr)[i] == ' ') {
        erase(arr, &size, i);
    }

    i = size - 1;
    while ((*arr)[i] == ' ') {
        erase(arr, &size, i);
        i--;
    }

    i = 1;
    while (i < size) {
        i++;

        if ((*arr)[i] == ' ') {
            i++;
            while ((*arr)[i] == ' ') {
                erase(arr, &size, i);
            }
        }
    }


}

int find_word(char** arr2) {

    remove1(arr2);

    int i = 0, cnt = 0, cnt1 = 0;
    while ((*arr2)[i] != '\0') {
        if (!if_letter((*arr2)[i])) {
            if (cnt % 2 == 0) {
                cnt1++;

            }
            cnt = 0;
        }
        else {

            cnt++;
        }
        i++;
    }
    if (cnt % 2 == 0) {
        cnt1++;
    }

    return cnt1;

}

void merge(char*** arr, int** size, int left, int mid, int right) {

    int l = left, r = mid + 1;
    int len = right - left + 1;
    int* temp_size = (int*)calloc(len, sizeof(int));
    char** temp_arr = (char**)calloc(len, sizeof(char*));
    int index = 0;
    while ((l <= mid) && (r <= right)) {
        if ((*size)[l] > (*size)[r]) {
            temp_size[index] = (*size)[l];
            temp_arr[index] = (*arr)[l];
            l++;
        }
        else {
            temp_size[index] = (*size)[r];
            temp_arr[index] = (*arr)[r];
            r++;

        }
        index++;
    }
    for (int i = l; i <= mid; i++) {
        temp_size[index] = (*size)[i];
        temp_arr[index] = (*arr)[i];
        index++;
    }
    for (int i = r; i <= right; i++) {
        temp_arr[index] = (*arr)[i];
        temp_size[index] = (*size)[i];
        index++;
    }

    for (int i = 0; i < len; i++) {
        (*size)[left + i] = temp_size[i];
        (*arr)[left + i] = temp_arr[i];
    }
    free(temp_size);
    free(temp_arr);

}

void merge_sort(char*** arr, int** size, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        merge_sort(arr, size, left, mid);
        merge_sort(arr, size, mid + 1, right);
        merge(arr, size, left, mid, right);

    }
}

void print_string(char* arr) {
    int i = 0;
    while (arr[i] != '\0') {
        printf("%c", arr[i]);
        i++;
    }
    printf("\n");
}

void free_mem(char** arr2, int* size, int argc) {
    for (int i = 0; i < argc - 1; i++) {
        free(arr2[i]);
    }
    free(size);
    free(arr2);
}

char** memory(int argc) {
    char** arr2 = (char**)calloc((argc - 1), sizeof(char*));
    return arr2;
}

int* memory1(int argc) {
    int* size = (int*)calloc((argc - 1), sizeof(int));
    return size;
}

void fill_and_copy(int argc, char** arr2, char** argv, int** size) {
    for (int i = 1; i < argc; i++) {
        str_copy(argv[i], &arr2[i - 1]);
        (*size)[i - 1] = find_word(&arr2[i - 1]);
        printf("%d\n%s\n", (*size)[i - 1], arr2[i - 1]);
    }
    printf("\n\n");

}

void print(int argc, char** arr2) {

    for (int i = 0; i < argc - 1; i++) {
        print_string(arr2[i]);

    }
}