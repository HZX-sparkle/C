/*
题 号:
110
4.7 学生管理系统
语言要求：
C++
编写学生管理系统，其中学生的信息有姓名（汉语拼音，最多20个字符），性别（男/女，用1表示男，0表示女）、
生日（19850101（年月日））、身高（以m为单位），还需要处理C语言、微积分两门课的成绩，请编写程序实现功能：
输入学生的人数和每个学生的信息；输出每门课程的总平均成绩、最高分和最低分，以及获得最高分的学生的信息。
需要注意的是某门课程最高分的学生可能不只一人。

输入输出格式要求：
	身高输出时保留两位小数，请按照例子中进行输出，请勿输出其他字符
例如：
输入：3 zhangsan 1 19910101 1.85 85 90 lisi 1 19920202 1.56 89 88 wangwu 2 19910303 1.6 89 90回车
输出：
C_average:87回车
C_max:89回车
lisi 1 19920202 1.56 89 88回车
wangwu 2 19910303 1.60 89 90回车
C_min:85回车
Calculus_average:89回车
Calculus_max:90回车
zhangsan 1 19910101 1.85 85 90回车
wangwu 2 19910303 1.60 89 90回车
Calculus_min:88回车
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM  1000
struct StuInfo {
	char name[32];
	int sex;
	char birthday[10];
	float height;
	int  score[2];
};

void process(StuInfo* p, int n)
{
	int i, j;
	int sum[2] = { 0 }, max[2], min[2];
	const char *subjectname[2] = { "C","Calculus" };


	for (j = 0; j < 2; j++)
	{
		max[j] = min[j] = p[0].score[j];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			sum[j] += p[i].score[j];
			if (max[j] < p[i].score[j])
				max[j] = p[i].score[j];
			if (min[j] > p[i].score[j])
				min[j] = p[i].score[j];
		}
	}

	for (j = 0; j < 2; j++)
	{
		printf("%s_average:%d\n", subjectname[j], sum[j] / n);
		printf("%s_max:%d\n", subjectname[j], max[j]);
		for (i = 0; i < n; i++)
		{
			if (max[j] == p[i].score[j])
				printf("%s %d %s %0.2f %d %d\n", p[i].name, p[i].sex, p[i].birthday, p[i].height, p[i].score[0], p[i].score[1]);
		}
		printf("%s_min:%d\n", subjectname[j], min[j]);
	}

}

int main()
{
	int i, n;
	StuInfo* pStu;

	scanf("%d", &n);

	if (n <= 0 && n > MAXNUM) {
		printf("error\n");
		return 0;
	}

	pStu = (StuInfo*)malloc(sizeof(StuInfo) * n);
	if (pStu == NULL) {
		printf("error\n");
		return 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%s", pStu[i].name);
		scanf("%d", &pStu[i].sex);
		scanf("%s", pStu[i].birthday);
		scanf("%f", &pStu[i].height);
		scanf("%d", &pStu[i].score[0]);
		scanf("%d", &pStu[i].score[1]);
	}

	process(pStu, n);
}