#include <stdio.h>

int main()
{
    int X;
    scanf("%d", &X);
    int times = X;

    int index = 1, threshhold = 1;

    while (X > 0)
        X -= index++;
    
    for(int i = 1; i < index - 1; i++)
        threshhold += i;

    times -= threshhold;

    int numerator; // 분자
    int denominator; // 분모

    if((index % 2) == 0)
    {
        numerator = index -1;
        denominator = 1;

        for(int j = 0; j < times; j++)
        {
            numerator--;
            denominator++;
        }

        printf("%d/%d", numerator, denominator);
    }

    else
    {
        numerator = 1;
        denominator = index -1;

        for(int j = 0; j < times; j++)
        {
            numerator++;
            denominator--;
        }

        printf("%d/%d", numerator, denominator);
    }

    return 0;
}