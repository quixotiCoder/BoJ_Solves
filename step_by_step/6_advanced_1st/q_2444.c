#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    for(int i = 1; i <= num; i++)
    {
        for(int j = num - i; j > 0; j--)
            printf(" "); // ... 4 3 2 1 0
        
        for(int k = 2*i - 1; k >0; k--)
            printf("*"); // 1 3 5 7 ... 

        printf("\n");
    }
    
    for(int l = num -1; l > 0; l--) // ... 4 3 2 1
    {
        for(int m = num - l; m > 0; m--)
            printf(" ");

        for(int n = 2*l - 1; n > 0; n--)
            printf("*");

        printf("\n");   
    }

    return 0;
}
