/*
�� ��:
110
4.7 ѧ������ϵͳ
����Ҫ��
C++
��дѧ������ϵͳ������ѧ������Ϣ������������ƴ�������20���ַ������Ա���/Ů����1��ʾ�У�0��ʾŮ����
���գ�19850101�������գ�������ߣ���mΪ��λ��������Ҫ����C���ԡ�΢�������ſεĳɼ������д����ʵ�ֹ��ܣ�
����ѧ����������ÿ��ѧ������Ϣ�����ÿ�ſγ̵���ƽ���ɼ�����߷ֺ���ͷ֣��Լ������߷ֵ�ѧ������Ϣ��
��Ҫע�����ĳ�ſγ���߷ֵ�ѧ�����ܲ�ֻһ�ˡ�

���������ʽҪ��
	������ʱ������λС�����밴�������н��������������������ַ�
���磺
���룺3 zhangsan 1 19910101 1.85 85 90 lisi 1 19920202 1.56 89 88 wangwu 2 19910303 1.6 89 90�س�
�����
C_average:87�س�
C_max:89�س�
lisi 1 19920202 1.56 89 88�س�
wangwu 2 19910303 1.60 89 90�س�
C_min:85�س�
Calculus_average:89�س�
Calculus_max:90�س�
zhangsan 1 19910101 1.85 85 90�س�
wangwu 2 19910303 1.60 89 90�س�
Calculus_min:88�س�
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