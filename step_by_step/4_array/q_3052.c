#include <stdio.h>

int main()
{
    int arr[42] = {0, }, input, count = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &input);
        arr[input % 42] = 1;
    }
    
    for(int j = 0; j < 42; j++)
    {
        if(arr[j] == 1)
            count++;

        else
            continue;
    }
    printf("%d", count);

    return 0;
}