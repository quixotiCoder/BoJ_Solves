#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    // input1
    //
    int N; // 숫자 카드 수 [1 ~ 500,000] 
    scanf("%d", &N);

    int *cards = (int *)malloc(sizeof(int) * N);  // 가진 숫자 카드
    for (int i = 0; i < N; i++)
        scanf("%d", &cards[i]); // [-10^7 ~ 10^7]

    // input2
    //
    int M; // 비교할 숫자 카드 수 [1 ~ 500,000]
    scanf("%d", &M);

}