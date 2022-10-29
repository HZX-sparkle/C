#include <stdio.h>
#include <stdlib.h>
int main()
{
	int count = 0;
	int target = 0;
	scanf("%d", &count);
	int* array = (int*)malloc(count);
	for (int i = 0; i <= count; i++)
	{
		scanf("%d", array+i);
		if (getchar() == '\n')
			break;
	}
    
	scanf("%d", &target);
	int max = count-1;
	int min = 0;
	int mid;
	do {
		mid = (max + min) / 2;
		if (target < array[mid]) {
			max = mid - 1;
		}
		else { min = mid + 1; }
	} while (array[mid] != target);

	printf("%d", mid + 1);
	
}