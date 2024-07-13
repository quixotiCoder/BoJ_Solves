#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N; // 1~1000
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
        scanf("%d", arr + i);

    for (int i = 0; i < N; i++) // bubble sort
    {
		for (int j = 0; j < N-1; j++) 
        {
			if (arr[j + 1] < arr[j]) 
            {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return 0;
}