#include <stdio.h>

int main()
{
    long long n; // bc of 'input size' {P}---double을 사용하기보다 큰 정수형은 이거 사용 
    scanf("%llu", &n);

    printf("%llu\n3", n*n*n); // n번 loop 3회 반복 

    return 0;
}