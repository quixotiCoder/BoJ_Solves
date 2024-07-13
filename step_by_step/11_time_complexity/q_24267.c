#include <stdio.h>

// {P}---input Max = 500,000 -> fibonacci 식 재귀로 가면 시간복잡도 기하급수적
// while 문에 따른 시그마 합으로 계산

int main()
{
    long long n;
    scanf("%lld", &n);

    // 1 ~ n-2
    // i+1 ~ n-1
    // j+1 ~ n

    // 안쪽부터 시그마 공식 사용후 식 정리 시 : (n-2)(n-1)(n) / 6 (= 시간 복잡도는 n^3)

    printf("%lld\n3", (n-2)*(n-1)*(n) / 6);

    return 0;
}