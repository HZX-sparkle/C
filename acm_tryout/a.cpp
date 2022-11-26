#include <stdio.h>
#include <string.h>

int main()
{
	char str[8] = {0};
	int n = 0, date = 0;
	scanf("%s", str);
	scanf("%d", &n);
	if (str[5] == '1')
	{
		n = 0;
	}
	else {
		date = (str[6] - 48) * 10 + str[7] - 48;
		if (date % 7 == 1) n *= 50;
		else n = 0;
	}
	printf("%d", n);
	return 0;
}
