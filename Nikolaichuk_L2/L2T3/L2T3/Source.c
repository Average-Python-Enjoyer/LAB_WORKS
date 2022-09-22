#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main() {

	int f1, f2, f3, f, n;
	f1 = 1;
	f2 = 1;

	f = 2;
	printf("!!!ENTER ONLY FIBONACHI NUMBERS!!!->");
	scanf("%d", &n);
	if (n <= 1) {
		exit(0);
	}
	while (f < n) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		f3 = f + f2;
	}
	
	printf("F-1=%d | ", f1);
	printf("F=%d | ", n);
	f = f1 + f2;
	f1 = f2;
	f2 = f;
	f3 = f;
	printf("F+1=%d | ", f3);
	
}