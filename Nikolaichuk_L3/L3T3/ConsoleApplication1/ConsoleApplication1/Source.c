#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main() {
	srand(time(NULL));
	int a[100];
	int b[100];
	int c[100];
	int amount = 0;
	int amount2 = 0;
	int number = 0;
	int number2 = 0;
	printf("Number of elements-->");
	scanf("%d", &amount);
	short dess;
	printf("Use random filling? y/n | -->");
	scanf("%s", &dess);
	if (dess == 'y') {
		for (int i = 0; i < amount; ++i)
			a[i] = rand() % 101 + (-50);
		for (int i = 0; i < amount; ++i)
			printf("%d\n", a[i]);
	}
	else {
		if (dess == 'n') {
			for (int i = 0; i < amount; ++i) {
				scanf("%d", &number);
				a[i] = number;
			}
		}
		else {
			while (1) {
				printf(" ERROR");
			}
		}
	}
	for (int i = 0; i < amount-1; i++)
		for (int j = 0; j < amount-i-1; j++)
			if (a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
	for (int i = 0; i < amount; ++i)
		printf("SORTED|%d\n", a[i]);

	printf("Number of elements-->");
	scanf("%d", &amount2);
	short dess2;
	printf("Use random filling? y/n | -->");
	scanf("%s", &dess2);
	if (dess2 == 'y') {
		for (int i = 0; i < amount2; ++i)
			b[i] = rand() % 101 + (-50);
		for (int i = 0; i < amount2; ++i)
			printf("%d\n", b[i]);
	}
	else {
		if (dess2 == 'n') {
			for (int i = 0; i < amount2; ++i) {
				scanf("%d", &number2);
				b[i] = number2;
			}
		}
		else {
			return 0;
		}
	}
	for (int i = 0; i < amount2 ; i++)
		for (int j = amount2 - 1; j > i; j--)
			if (b[j-1] < b[j]) {
				b[amount2] = b[j - 1];
				b[j-1] = b[j];
				b[j] = b[amount2];
			}
	for (int i = 0; i < amount2; ++i)
		printf("SORTED|%d\n", b[i]);
	int amount3 = amount + amount2;
	for (int i = 0; i < amount; i++)
		c[i] = a[i];
	int z = 0;
	for (int i = amount; i < amount3; i++) {
		c[i] = b[z];
		z=z+1;
	}
	for (int i = 0; i < amount3; ++i)
		printf("%d\n", c[i]);
	for (int i = 0; i < amount3; i++)
		for (int j = amount3 - 1; j > i; j--)
			if (c[j - 1] < c[j]) {
				c[amount3] = c[j - 1];
				c[j - 1] = c[j];
				c[j] = c[amount3];
			}
	for (int i = 0; i < amount3; ++i)
		printf("SORTED|%d\n", c[i]);
}
