/*编写一个程序，找出1~N中的所有素数,其中1<N,N为整数。

输入输出格式要求：
	1.要求每个数后面都要输出逗号，
	  请不要输出其他字符

        2.遇到异常情况，输出error
例如：
输入：5
输出：2,3,5,

输入：a
输出：error

提醒：数据最多不超过200*/

#include <time.h>
#include <stdio.h>
#include <math.h>

int sqrt_low(int j);

int isPrime(int n) {

    
    if (n % 6 != 1 && n % 6 != 5) {
        return 0;
    }
    
    int s = sqrt_low(n);
    for (int i = 5; i <= s; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}


int sqrt_low(int j) {
    for (int i = 2; i <= 11; i++) {
         if (i * i > j)
            return i;
    }
}


int main()
{
    int n;
    int cnt = 0;
    if (scanf("%d", &n) != 1 || getchar() != '\n' || n <= 1)
    {
        printf("error");
        return 0;
    }
    
    int j = sqrt_low(n);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i)) {
            printf("%d,", i);
        }
    }
}