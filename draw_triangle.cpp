#include <stdio.h>
#include <stdlib.h>
int main()
{
	int length, i;
	scanf("%d", &length);
	if (length % 2 == 0 || length < 1 || length > 80)
	{
		printf("error");
		return 0;
	}
	i = length / 2 + 1;
	for (int j = 1; j <= i; j++)
	{
		for (int k = 1; k <= length / 2 - j + 1; k++) {
			printf(" ");
		}
		for (int k = 1; k <= j * 2 - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}