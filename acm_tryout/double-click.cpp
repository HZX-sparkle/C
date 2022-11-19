#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
	int n = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		char s[20];
		gets(s);
		char a[20];
		gets(a);
		int ls = strlen(s) ;
		int la = strlen(a) ;
		if (ls == la) {
			printf("0\nNone\n");
		}
		else {
			int d = la - ls, j = 0 , k = 0;
			char *c = (char*)malloc(d);
			for (int i = 0; i < la; ++i)
			{
				if (s[j] != a[i])
				{
					c[k] = a[i];
					k++;
				}
				else j++;
				if (k == ls) break;
			}
			char answer[d];
			answer[0] = c[0];
			int l;
			for (int i = 1; i < d; ++i)
			{
				l = strlen(answer);
				int j = 0;
				for (j = 0; j < l; ++j)
				{
					if (c[i] == answer[j]) break;
				}
				if (j == l) answer[l] = c[i];
			}
			int m = strlen(answer);
			std::sort(answer, answer + m);
			printf("%d\n%s\n", m, answer);
		}

		/* code */
	}
}
