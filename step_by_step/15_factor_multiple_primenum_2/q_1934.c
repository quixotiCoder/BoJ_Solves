// Boj 1934
// theme : factor_multiple_primenum_2

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num1;
    int num2;
} NumSet;

// by Euclidean algorithm
int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    int T;
    scanf("%d", &T);

    NumSet* numSet = (NumSet*)malloc(sizeof(NumSet) * T);

    for(int i = 0; i < T; i++)
        scanf("%d %d", &numSet[i].num1, &numSet[i].num2);

    for(int i = 0; i < T; i++) {
        int result = lcm(numSet[i].num1, numSet[i].num2);
        printf("%d\n", result);
    }

    free(numSet);
    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// lcm == a * b / GCD
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
