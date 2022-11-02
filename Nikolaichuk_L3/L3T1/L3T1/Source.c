#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main() {
	srand(time(NULL));
	int a[100];
	int amount = 0;
	int number = 0;
	int sum = 0;
	int pol1, pol2=0;
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
				printf("    ");
				printf("%d\n", a[i]);
			}
		}
		else {
			while (1) {
				printf(" ERROR");
			}
		}
	}
	float min=a[1];
	for (int i = 0; i < amount; ++i) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	for (int i = 0; i < amount; ++i) {
		if (a[i] > 0) {
			pol1 = i;
			break;
		}	
	}	
	for (int i = amount; i <= amount; i=i-1) {
		if (a[i] > 0) {
			pol2 = i;
			break;
		}
	}
	pol1 = pol1 + 1;
	while (1) {
		if (pol1 < pol2) {
			printf("-");
			sum = sum + a[pol1];
			++pol1;
		}
		else {
			break;
		}
	}
	printf("\n SUM=%.d", sum);
	printf("\n MIN=%.f", min);
}