/*
��д������������n����̬���䱣��n�������Ĵ洢����Ȼ������n���������浽�洢���С���󣬽���n��������С���������
���磺
�������£�
10�س�
10 9 8 7 6 5 4 3 2 1�س�
�����
1,2,3,4,5,6,7,8,9,10
��ʾ�����ڳ����˳�ǰ�ͷŶ�̬������ڴ�ռ䡣
*/

#include <stdio.h>
#include <algorithm>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	std::sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", arr[i]);
		if (i != n - 1) printf(",");
	}
}
