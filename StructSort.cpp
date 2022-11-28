#include <stdio.h>
#include <algorithm>

typedef struct Person {
	int no;
	int age;
	int height;
} per;

bool cmp(per a, per b)
{
	if (a.no != b.no) return a.no < b.no;
	else if (a.age != b.age) return a.age < b.age;
	else return a.height < b.height;
}

void sort(Person *p, int n)
{
	if (p == NULL || n < 1)
	{
		printf("error");
		return;
	}
	std::sort(p, p + n, cmp);
};

int main()
{
	per arr[10];
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &arr[i].no, &arr[i].age, &arr[i].height);
	}
	sort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d %d\n", arr[i].no, arr[i].age, arr[i].height);
	}
}
