/*
ʵ���ַ����Ŀ�����

void my_strcpy(char * destination,char * source);
��sourceָ����ַ���������destinationָ���λ�á�

ע�⣺ʹ�ÿո��ַ�����ʾ�ַ����Ľ�����
����sourceָ��λ�ã����α������ַ�'a'���ַ�'b'���ַ��ո�' '���ַ�'c'����sourceָ����ַ���Ϊ"ab"��


�����쳣��������"error"������Ҫ�������������Ϊ����

33	���ѣ�
(1) ����������source���ַ������ܱ��޸ģ�destination�ַ���ֻ��source��һ���ո�֮ǰ�Ĵ����滻��������ַ������ܱ��޸ġ�
	����source: ab xy z; destination: tkf m���򿽱�������source���䣬destination��ab  m(ab��m֮����2���ո�)
(2)�ַ�����Ȼ�ǡ�\0����Ϊ��������������ַ�����һ��������ո�ġ�������ͨ���ո���Ϊ�ַ��������Ľ�����ǡ�
*/
#include <stdio.h>
void my_strcpy(char *dest, char* sour)
{
	if (dest == NULL || sour == NULL)
	{
		printf("error");
		return;
	}
	int i = 0;
	for (i = 0; sour[i] != ' '; i++)
	{
		*(dest + i) = sour[i];
	}
	*(dest + i) = ' ';
}
int main()
{
	char* sour = new char[100];
	char* dest = new char[100];
	if (fgets(sour, 100, stdin) == NULL)
	{
		printf("error");
		return 0;
	}
	my_strcpy(dest, sour);
}