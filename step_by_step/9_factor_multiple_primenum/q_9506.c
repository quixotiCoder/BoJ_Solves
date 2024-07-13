#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        int n;
        scanf("%d", &n);

        if(n == -1)
            return 0;

        int* arr = (int*)calloc(n, sizeof(int));  // calloc은 자동으로 NULL 초기화
        int sum = 0;

        for(int i = 1; i <= n/2; i++) 
        {
            if(n % i == 0)
            {
                arr[i] = i;
                sum += i;
            }
        }
        if (sum == n)
        {
            printf("%d = %d ", n, arr[1]);

            for(int j = 2; j <= n/2; j++)
            {
                if(arr[j])
                    printf("+ %d ", arr[j]);
            }

        }
        else if(sum != n)
            printf("%d is NOT perfect.", n); // -------- '.' 안썼다....
        
        printf("\n");
    }
    
}