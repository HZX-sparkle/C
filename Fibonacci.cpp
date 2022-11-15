#include <stdio.h>
int main()
{
	int n, a = 1, b = 1;
	scanf("%d", &n);
	if (n > 2)
		for (int i = 0; i < n - 2; i++)
		{
			int t = b;
			b = a + b ;
			a = t;
		}
	printf("%d", b);
	return 0;
}