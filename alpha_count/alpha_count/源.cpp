#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* str = (char*)malloc(50);
	scanf("%s", str);
	int a = 0, d = 0;

	for (int i = 0; i <= 49; i++)
	{
		if (*(str + i) == 'a')
		{
			a++;
			continue;
		}

		if (*(str + i) == 'd')
		{
			d++;
		}
	}

	printf("a:%d,d:%d", a, d);

}