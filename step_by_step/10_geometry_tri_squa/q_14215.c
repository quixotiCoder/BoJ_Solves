#include <stdio.h>

int main()
{
    int arr[3];
    scanf("%d %d %d", arr, arr + 1, arr + 2);

    int temp;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1]= temp;
            }
        }
    }

    if((arr[0] + arr[1]) <= arr[2])
        printf("%d", arr[0] + arr[1] + (arr[0] + arr[1] - 1));

    else
        printf("%d", arr[0] + arr[1] + arr[2]);
    
    return 0;
}