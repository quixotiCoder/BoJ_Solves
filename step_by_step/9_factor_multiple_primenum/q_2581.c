#include <stdio.h>

int main()
{
    int M, N;
    scanf("%d", &M);
    scanf("%d", &N);

    int sum = 0, min = 10001;

    for (int i = M; i <= N; i++)
    {
        int is_prime = 1;

        for(int j = 2; j <= i/2; j++)
        {
            if((i % j) == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if(i == 1)
            is_prime = 0;            

        if(is_prime)
        {
            sum += i;
            if(i < min)
                min = i;
        }
    }

    if(sum == 0)
        printf("-1");
    
    else
        printf("%d\n%d", sum, min);
    
    return 0;
}