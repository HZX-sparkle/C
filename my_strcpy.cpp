/*
实现字符串的拷贝。

void my_strcpy(char * destination,char * source);
将source指向的字符串拷贝到destination指向的位置。

注意：使用空格字符来表示字符串的结束。
例如source指向位置，依次保存了字符'a'，字符'b'，字符空格' '，字符'c'，则source指向的字符串为"ab"。


遇到异常情况，输出"error"；否则不要随意输出，会视为错误。

33	提醒：
(1) 拷贝结束后，source的字符串不能被修改；destination字符串只有source第一个空格之前的串被替换，其余的字符都不能被修改。
	比如source: ab xy z; destination: tkf m。则拷贝结束后，source不变，destination：ab  m(ab和m之间是2个空格)
(2)字符串虽然是’\0’作为结束符，本题的字符串是一定会包含空格的。本题是通过空格作为字符串拷贝的结束标记。
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