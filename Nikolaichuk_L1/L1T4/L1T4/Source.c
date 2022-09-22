#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
main() {
	int a;
	char x[][5] = {"one","two","three","four","five","six","seven","eight","nine","ten"};
	scanf("%d", &a);
	printf(x[a-1]);
}