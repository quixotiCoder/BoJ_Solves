// BoJ q_1427
// theme : sorting

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[11]; // 1 ~ 1,000,000,000
    scanf("%s", str);

    int length = strlen(str);

    int *arr = (int *)malloc(sizeof(int) * length); // 문자열 길이만큼 int형 배열
    for(int i = 0; i < length; i++)
        arr[i] = str[i] - '0'; // char -> int 변환 by ASCII code

    // bubble sort
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < length; i++)
        printf("%d", arr[i]);
    
    free(arr);  // 동적할당 해제!
    return 0;   
}