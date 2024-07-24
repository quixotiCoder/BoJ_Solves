// BoJ q_11650
// theme : sorting

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} coordinate;

int compare(const void *a, const void *b)
{
    coordinate A = *(coordinate*) a;
    coordinate B = *(coordinate*) b;

    if(A.y > B.y)
        return 1;

    else if (A.y == B.y)
    {
        if (A.x > B.x)
            return 1;
        else
            return -1;
    }

    return -1;
}



int main(){
    int N;
    scanf("%d", &N);

    coordinate* input = (coordinate*)malloc(N * sizeof(coordinate));

    for(int i = 0; i < N; i++)
        scanf("%d %d", &input[i].x, &input[i].y);

    qsort(input, N, sizeof(coordinate), compare);

    for(int i = 0; i < N; i++)
        printf("%d %d\n", input[i].x, input[i].y);

    return 0;
}