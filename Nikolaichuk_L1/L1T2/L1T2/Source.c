#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
main() {
	int a,b, c;
	printf("a b c-->");
	scanf("%d%d%d", &a, &b, &c);
	if (a == b || a == c || b == c) {
		printf("YES");

	}
	else {
		printf("NO");
	}

}