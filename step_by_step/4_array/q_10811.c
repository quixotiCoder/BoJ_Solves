#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j; // declare variables given by question
    scanf("%d %d", &N, &M); // 1st row input

    int* basket = (int*)malloc(sizeof(int) * (N + 1)); // make array whose size is made by "N"

    for (int index = 0; index < N+1; index++)
        basket[index] = index; // fill the array with its index
    
    for(int reverse = 0; reverse < M; reverse++)
    {
        scanf("%d %d", &i, &j); // take "i", "j" by "M" times
        
        for(i; i < j; i++) // reversing array from "i" to "j"
        {
            int temp; // to save 'i'th index element "temporarily"
            temp = basket[i]; // store 'i'th one
            basket[i] = basket[j]; // store 'j' in 'i' (last -> first)
            basket[j] = temp; // store 'i' in 'j' (last <- first)
            j--; // to change (i++) <-> (j--) 
        }
    }
  

    for(int print = 1; print <= N; print++)
        printf("%d ", basket[print]);
    
    return 0;
}