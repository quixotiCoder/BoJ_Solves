#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int min = 10000001, max = -1;
    int* count;
    int temp; 
    
    count = (int*)calloc(10001, sizeof(int)); 

    for(int i = 0; i < N; i++) 
    {
        scanf("%d", &temp);
        count[temp]++;

        if(temp < min) 
            min = temp;
        if(temp > max) 
            max = temp;
    }

    for(int i = min; i <= max; i++) 
    {
        for(int j = 0; j < count[i]; j++)
            printf("%d\n", i);
    }

    free(count);

    return 0;
}