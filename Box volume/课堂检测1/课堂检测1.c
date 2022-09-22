#include <stdio.h>

int main()
{
	int length, width, height;
	scanf("%d %d %d", &length, &width, &height);
	int v = length * width * height;
	printf("v=%d", v);

	return 0;

}