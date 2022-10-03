#include <stdio.h>
int main()
{
	char a[50];
	char b[50];

	scanf("%s %s", a, b);
	int min;
	if (sizeof(a) < sizeof(b)) {
		min = sizeof(a);
	}
	else {
		min = sizeof(b);
	}
	int i = 0;
	
		for (i = 0; i<min ; i++) {
			if (a[i] == b[i])
			{
				if (65 <= a[i] && a[i] <= 122)//a[i]代表的是字母
					printf("%c", a[i]);
				else break;
			}
		}
	
	
	return 0;

}