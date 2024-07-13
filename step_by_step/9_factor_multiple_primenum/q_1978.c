#include <stdio.h>

int main()
{
    int N, cnt = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int temp, is_prime = 1;
        scanf("%d", &temp);

        if(temp == 1)
            continue;

        for(int i = 2; i < temp; i++)
        {
            if((temp % i) == 0)
                is_prime = 0;
        }
        if(is_prime)
            cnt++;
    }

    printf("%d", cnt);
    
    return 0;
}