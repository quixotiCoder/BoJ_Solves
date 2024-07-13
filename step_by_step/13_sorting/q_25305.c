#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, k;   // [N : 1~1,000] [k : 1~N]

    scanf("%d %d", &N, &k);
    
    int* score = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
        scanf("%d", &score[i]);     // [score : 1~10,000] 
    
    // Insertion sort
    for (int i = 1; i < N; i++) {
        int key = score[i];
        int j = i - 1;

        while (j >= 0 && score[j] > key) {
            score[j + 1] = score[j];
            j--;
        }
        score[j + 1] = key;
    }

    printf("%d", score[N - k]);

    return 0;
}