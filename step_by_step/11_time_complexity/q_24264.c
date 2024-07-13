#include <stdio.h>

int main()
{
    double n; // {P}--- int(X) double(O ; bc 500000*500000 범위 커버)
    scanf("%lf", &n);

    printf("%.0lf\n2", n*n); // n번 loop 2번

    return 0;
}