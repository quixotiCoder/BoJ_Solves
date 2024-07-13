#include <stdio.h> 
#include <stdlib.h>

void merge_sort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

void merge_sort(int* arr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right){
    int i = left, j = mid + 1, k = left;
    int* sorted = (int*)malloc(sizeof(int) * (right + 1));

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    if(i > mid)
    {
        for(int l = j; l <= right; l++)
            sorted[k++] = arr[l];
    }
    else
    {
        for(int l = i; l <= mid; l++)
            sorted[k++] = arr[l];
    }

    for(int l = left; l <= right; l++)
        arr[l] = sorted[l];

    free(sorted);
}

int main(){
    int N;  // [N : 1~1,000,000]
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);   // N만큼 input 받기 

    merge_sort(arr, 0, N - 1);
    
    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return 0;
}