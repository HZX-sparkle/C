#include <stdio.h>
#include <math.h>

int  isPrime(int n) {
    
    // ֻ��6x-1��6x+1�������п���������
    if (n % 6 != 1 && n % 6 != 5) {
        return 0;
    }
    // �ж���Щ���ܷ�С��sqrt(n)����������
    int s = (int) sqrt(1.0*n);
    for (int i = 5; i <= s; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
};

int main()
{
    int n = 0, ret=1;
    scanf("%d", &n);
    if (n <= 3) {
        printf("error");
        return 0;
    }

    if (isPrime(n))
        printf("yes");
    else printf("no");

    return 0;
    
}
