#include <stdio.h>

/*
    1 : 1   [1]
    2~7 : 2 [6]
    8~19 : 3    [12]
    20 ~ 37 : 4     [18]
*/

int main()
{
    int N;
    scanf("%d", &N);

    int multiply_six = 0, sum = 0;

    if(N > 0)
    {
        N -= 1;
        multiply_six++;
        sum++;
    }

    while (N > 0)
    {
        N -= multiply_six * 6;
        multiply_six++;
        sum++;
    }
    
    printf("%d", sum);

    return 0;
}