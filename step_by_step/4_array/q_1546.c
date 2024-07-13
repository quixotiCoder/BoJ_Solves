#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M = 0;
    double avg;

    scanf("%d", &N);

    int* score = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &score[i]);
        if(score[i] > M)
            M = score[i];
    }
    
    for(int j = 0; j < N; j++)
        avg += (double)(score[j]) / M * 100;
    
    printf("%lf", avg / N);

    return 0;
}