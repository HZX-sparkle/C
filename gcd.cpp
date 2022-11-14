#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, c, r = 1;
	scanf("%d %d", &a, &b);
	c = a * b;
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r);
	printf("%d,%d", a, c / a);
	//system("pause");
	return 0;
}