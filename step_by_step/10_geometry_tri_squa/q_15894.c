#include <stdio.h>

int main()
{
    double n; // input 범위 check
    scanf("%lf", &n);

    printf("%.0lf", n * 4);

    return 0;
}