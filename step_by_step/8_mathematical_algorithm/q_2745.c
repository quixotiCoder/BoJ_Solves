#include <stdio.h>
#include <string.h>

int main()
{
    int B, result = 0;
    char N[10000];

    scanf("%s %d", N, &B);

    int len = strlen(N);

    for(int i = 0; i < len; i++)
    {
        int temp;      

        if(N[i] >= '0' && N[i] <= '9') 
            temp = N[i] - '0';

        else if(N[i] >= 'A' && N[i] <= 'Z')
            temp = N[i] - 'A' + 10;

        result += result * B + temp;
    }

    printf("%d", result);

    return 0;
}
