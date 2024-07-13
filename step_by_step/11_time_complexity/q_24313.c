#include <stdio.h>

int main()
{
    int a1, a0, c, n0;

    scanf("%d %d", &a1, &a0); // -100~100
    scanf("%d", &c); // 1~100
    scanf("%d", &n0); // 1~100

    // {P}--- a0가 음수면 n이 커져가며 만족 가능 -> 조건문으로 처리

    if (a1 * n0 + a0 <= c * n0 && a1 <= c) // a0이 음수이면 초항에선 정의 만족 아닐 수 있지만, 결국 계수가 커짐에 따라 만족
        printf("1");
    
    else
        printf("0");

    return 0;
}