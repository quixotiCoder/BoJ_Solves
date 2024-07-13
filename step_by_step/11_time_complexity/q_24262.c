#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    printf("1\n0"); // 재귀 함수 X. 그냥 배열 index에 대한 접근 O(1)

    return 0;
}