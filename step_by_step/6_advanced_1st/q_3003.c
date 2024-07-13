#include <stdio.h>

int main(){
    int original_Set[6] = {1, 1, 2, 2, 2, 8};
    int input_set[6];

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &input_set[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", original_Set[i] - input_set[i]);
    }

    return 0;
}