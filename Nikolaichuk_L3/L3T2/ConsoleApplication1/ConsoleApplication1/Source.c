#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main() {
	srand(time(NULL));
	int a[100];
	int b[100];
	int amount = 0;
	int number = 0;
	int pol2=0;
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
			for (int i = 0; i < amount; ++i) {
				//printf("    ");
				//printf("%d\n", a[i]);
			}
		}
		else {
			while (1) {
				printf(" ERROR");
			}
		}
	}
	for (int i = amount-1; i <= amount; i = i - 1) {
		if (a[i]%2 == 0) {
			pol2 = i;
			//printf("!!!!!!!!!!!!!%d\n", pol2);
			break;
		}
	}
	for (int i = 0; i <= pol2; ++i) {
		b[i] = a[i];
		printf("!!!");
		printf("%d\n", b[i]);

	}
}