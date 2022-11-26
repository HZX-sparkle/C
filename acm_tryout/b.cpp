#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int main()
{
	int n = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int sum;
		scanf("%d", &sum);
		int *mem = (int*)malloc(sum * sizeof(int));
		int *arr = (int*)malloc((sum - 1) * sizeof(int));
		for (int j = 0; j < sum; j++)
		{
			scanf("%d", &mem[j]);
		}
		std::sort(mem, mem + sum);
		for (int j = 0; j < sum - 1; j++)
		{
			arr[j] = mem[j + 1] - mem[j];
		}
		std::sort(arr, arr + sum - 1);
		printf("%d\n", arr[0]);
	}
}