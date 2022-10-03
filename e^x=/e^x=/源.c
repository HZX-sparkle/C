#include <stdio.h>
int main()
{
    double ret = 0, x = 0, n = 0;
    scanf("%lf %lf", &x, &n);

    if (n < 0)
    {
        printf("error");
        return 0;
    }

    double i = 1, j = 1, k = 1;
    for (i = 1; i <= n; i++) {
        j *= x;
        k *= i;
        ret += j / k;
    }

    printf("%.6f", ret + 1);

    return 0;
}