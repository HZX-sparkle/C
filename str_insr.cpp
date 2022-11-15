#include<stdio.h>
#include<string.h>
int main()

{
	char a[20] = "cehiknqtw"; char s[] = "fbla";

	int i, k, j;

	for (k = 0; s[k] != '\0'; k++)

	{

		j = 0;

		while ( a[j] <= s[k] && a[j] != '\0') j++;

		for (i = strlen(a) + k - 1; i >= j; i--)
		{
			a[i + 1] = a[i];
		}
		a[j] = s[k];


	}

	puts(a);

	return 0;
}
