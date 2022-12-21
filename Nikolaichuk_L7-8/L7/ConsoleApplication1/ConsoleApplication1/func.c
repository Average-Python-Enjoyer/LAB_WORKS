#define _CRT_SECURE_NO_WARNINGS

#include "func.h"
char* get_string()
{
    int num = 256;
    char* string = (char*)calloc(num, sizeof(char));
    char ch;
    int pos = 0;
    while (1)
    {
        ch = getchar();
        if (ch == '\n')
        {
            string[pos] = '\0';
            string = (char*)realloc(string, (pos + 1) * sizeof(char));
            return string;
        }

        string[pos] = ch;
        pos++;
        if (pos == 256)
            string = (char*)realloc(string, (pos + 1) * sizeof(char));
    }
}

int str_len(char* str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int k_len() {
    int len = 0;
    while (scanf_s("%d", &len) != 1 || len <= 0 || getchar() != ('\n')) {
        printf("Amount of elements:");
        rewind(stdin);
    }
    return len;
}



void task1() {
    printf_s("Enter string:\n");
    char* string = get_string();
    //removeExtraSpaces(string);
    //printf("String now: %s", string);
    printf("Enter k:\n");
    int k = k_len();
    int strSize = str_len(string) + 1;
    int startPos = 0;
    for (int i = 0; i < strSize; i++) {
        if (string[i] == ' ' || string[i] == '\t' || string[i] == '\0') {
            if (i - startPos > k) {
                char* temp = (char*)malloc((strSize - (i - startPos)) * sizeof(char));
                memmove(temp, string, (startPos) * sizeof(char));
                memmove(temp + startPos - 1, (string)+i, (strSize - i) * sizeof(char));
                string = temp;
                strSize -= (i - startPos);
                i = 0;
                startPos = 0;
            }
            startPos = i + 1;
            continue;
        }
    }
    printf("String after delete: %s", string);
}

void task2() {
    printf_s("Enter string: ");
    char* string = get_string();
    printf("Enter k:\n");
    char k = getchar();
    int total = 0;
    int str_size = str_len(string) + 1;
    for (int i = 0; i < str_size; i++)
    {
        if (string[i] == k)
        {
            total++;
            if (total % 2 == 0) {
                for (int j = i; j < str_size; j++)
                {
                    string[j] = string[j + 1];
                }
                str_size--;
                i--;
            }
        }
    }
    printf("String now: %s", string);
    free(string);
}