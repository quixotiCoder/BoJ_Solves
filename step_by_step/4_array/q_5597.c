#include <stdio.h>

int main()
{
    int arr[31]= {0, };
    int digit;

    for (int i = 0; i < 28; i++)
    {
        scanf("%d", &digit);
        arr[digit] = 1;
    }

    for (int i = 1; i <= 30; i++)
    {
        if(arr[i] != 1)
            printf("%d\n", i);
    }

    return 0;
}
