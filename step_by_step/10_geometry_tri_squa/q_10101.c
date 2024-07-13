#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int total = a + b + c;

    if (a == 60 && b == 60 && c == 60)
        printf("Equilateral");

    else if (total == 180) // --- 등호 1개 빼먹기...
    {
        if(a != b && b != c && a !=c)
            printf("Scalene");

        else
            printf("Isosceles");    
    }

    else
        printf("Error");

    return 0;
}