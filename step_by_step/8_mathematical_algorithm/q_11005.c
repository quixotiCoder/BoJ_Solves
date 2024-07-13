#include <stdio.h>
#include <string.h>

int main()
{
    int N, B; // int = 4 byte = 2^32 = 2^31(양수만) = 2,147,483,647 > 10억
    scanf("%d %d", &N, &B);

    char conversion_result[31] = {0, };
    int index = 0;

    if(N == 0)
        conversion_result[0] = '0';

    while(N > 0)
    {
        int quotient, remainder;

        quotient = N / B;
        remainder = N % B;

        if (0 <= remainder && remainder <= 9)
            conversion_result[index++] = remainder + 48;
        
        else if (10 <= remainder && remainder <= 35)
            conversion_result[index++] = remainder + 55;
        
        N = quotient;
    }

    conversion_result[index] = '\0';

    int len = strlen(conversion_result);

    for(int j = len - 1; j >= 0 ; j--)
        printf("%c", conversion_result[j]);

    return 0;
}