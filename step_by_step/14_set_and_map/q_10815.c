// BoJ 10815
// theme : SetAndMap

#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return 1;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // input1
    int N;
    scanf("%d", &N);

    int *cards = (int *)malloc(sizeof(int) * N);  
    for (int i = 0; i < N; i++)
        scanf("%d", &cards[i]);

    qsort(cards, N, sizeof(int), compare);

    // input2
    int M; 
    scanf("%d", &M);
    
    int *compares = (int *)malloc(sizeof(int) * M);  
    for (int i = 0; i < M; i++)
        scanf("%d", &compares[i]); 

    for (int i = 0; i < M; i++) {
        if (binary_search(cards, N, compares[i]))
            printf("1 ");
        else
            printf("0 ");
    }

    free(cards);
    free(compares);

    return 0;
}
