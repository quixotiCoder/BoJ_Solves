#include <stdio.h>

int main()
{
    int number;
    scanf("%d", &number);

    for(int i = 0; i < number; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }

    return 0;
}