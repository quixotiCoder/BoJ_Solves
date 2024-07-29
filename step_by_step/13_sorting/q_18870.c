// BoJ 18870
// theme : sorting

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int coord;
} coordinate;

int compare_coord(const void *a, const void *b){
    coordinate *A = (coordinate*) a;
    coordinate *B = (coordinate*) b;

    if(A->coord > B->coord)
        return 1;
    else
        return 0;
}

int compare_index(const void *a, const void *b){
    coordinate *A = (coordinate*) a;
    coordinate *B = (coordinate*) b;

    if(A->index > B->index)
        return 1;
    else
        return 0;
}

int main(){
    int N;
    scanf("%d", &N);

    coordinate* co = (coordinate*)malloc(sizeof(coordinate) * N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &co[i].coord);
        co[i].index = i;
    }

    qsort(co, N, sizeof(coordinate), compare_coord);


    int order = 0;

    for(int i = 0; i < N; i++)
    {
        int cnt = 1;
        int temp_i = i;
        while(co[i].coord == co[i + 1].coord)
        {
            cnt++;
            i++;
        }
        for(int j = 0; j < cnt; j++)
            co[temp_i + j].coord = order;

        order++;
    }

    qsort(co, N, sizeof(coordinate), compare_index);

    for(int i = 0; i < N; i++)
        printf("%d ", co[i].coord);

    free(co);
    return 0;
}