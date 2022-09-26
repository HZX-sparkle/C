#include <stdio.h>

int main()
{
	double d, m,rest;
	scanf_s("%lf %lf", &d, &m);

	const double total = 6.0;

	if (d + m < total) {
		rest = d + m - 0.03 * 12;
	}
	else {
		rest = d + m - 0.1 * 12;
	}

	printf("%f\n", rest);

	return 0;
}