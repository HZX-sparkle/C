/*
编写程序，输入整数n，动态分配保存n个整数的存储器，然后输入n个整数保存到存储器中。最后，将这n个整数从小到大输出。
例如：
输入如下：
10回车
10 9 8 7 6 5 4 3 2 1回车
则输出
1,2,3,4,5,6,7,8,9,10
提示：请在程序退出前释放动态分配的内存空间。
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
