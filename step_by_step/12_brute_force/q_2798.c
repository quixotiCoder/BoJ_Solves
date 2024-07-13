#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    int* cards = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
        scanf("%d", &cards[i]);

    int sum = 0, max = 0;
    
    for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				sum = cards[i] + cards[j] + cards[k];
				if (sum > max && sum <= M)
					max = sum;
			}
		}
	}
	printf("%d\n", max);
    
    free(cards);
    
    return 0;
}