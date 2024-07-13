#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K, num_of_factor = 0;
    scanf("%d %d", &N, &K);

    int* arr = (int*)malloc(sizeof(int) * (N + 1));

    for(int i = 0; i <= N; i++)
        arr[i] = 0;

    for(int j = 1; j <= N; j++)
    {
        if(N % j == 0)
            arr[++num_of_factor] = j;
    }

    printf("%d", arr[K]);

    return 0;
}