#include <stdio.h>
int main()
{
	int a, b = 1, c = 1;
	scanf("%d,%d,%d", &a, &b, &c);
	if (a <= 0 || b <= 0 || c <= 0) {
		printf("error");
		return 0;
	}


	if ((a + b > c) && ( a + c > b) && ( b + c > a))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}

}