/*��дһ�������ҳ�1~N�е���������,����1<N,NΪ������

���������ʽҪ��
	1.Ҫ��ÿ�������涼Ҫ������ţ�
	  �벻Ҫ��������ַ�

        2.�����쳣��������error
���磺
���룺5
�����2,3,5,

���룺a
�����error

���ѣ�������಻����200*/

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