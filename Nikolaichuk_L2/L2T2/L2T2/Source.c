#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
float x(int n) {
    float x = 0;
    for (; 0 < n; --n) {
        x += 1.0 / n;
    }
    return x;
}
int main()
{
    int m, n;
    printf("input 'm' and 'n' (m < n): ");
    if ((scanf("%d%d", &m, &n) == 2) && (m < n)) { 
        printf("x=%f\n", x(n));   
    }
    return 0;
}