#ifdef Euklides
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>


unsigned long long int rek(unsigned long long int a, unsigned long long int b) {
	if (b == 0) {
		return a;
	}
	else {
		return rek(b, a % b);
	}
}

int main()
{
	unsigned long long int a, b, c;
	while (scanf("%llu\t%llu", &a, &b) != EOF) {
		c = rek(a, b);
		printf("%llu\n", c);
	}
	return 0;
}

#endif