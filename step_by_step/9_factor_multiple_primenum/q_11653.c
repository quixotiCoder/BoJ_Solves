#include <stdio.h>

int main()
{
    int N, factor = 2;
    scanf("%d", &N);

    while (N > 1)
    {
        if(N % factor == 0)
        {
            printf("%d\n", factor);
            N /= factor;
            factor = 2;
            continue;
        }

        factor++;
    }

    return 0;
}