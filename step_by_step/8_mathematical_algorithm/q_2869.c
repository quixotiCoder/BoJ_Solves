#include <stdio.h>

// 시간 복잡도 짧게 만드는 것이 point

int main()
{
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);

    int day = (V - B - 1) / (A - B) + 1;

    printf("%d", day);

    return 0;    
}