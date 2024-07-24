#include <stdio.h>

int main(){
    int deafult_value = 666;
    int result = 0;

    int N;
    scanf("%d", &N);
    N = N - 1;

    int first_order = N / 19;
    int second_order = N % 19;

    first_order *= 10000;
    
    if(6 < second_order && second_order < 17)
    {
        second_order = second_order;
        deafult_value *= 10;
    }
    
    else
        second_order *= 1000;

    result = first_order + second_order + deafult_value;
    
    printf("%d", result);

    return 0;
}