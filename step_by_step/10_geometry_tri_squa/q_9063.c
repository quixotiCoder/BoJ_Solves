#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int x_min = 10001, y_min = 10001;
    int x_max = -10001, y_max = -10001;

    for (int i = 0; i < N; i++)
    {
        int x_temp, y_temp;
        scanf("%d %d", &x_temp, &y_temp);

        if(x_temp < x_min)
            x_min = x_temp;
        if(x_temp > x_max)
            x_max = x_temp;

        if(y_temp < y_min)
            y_min = y_temp;
        if(y_temp > y_max)
            y_max = y_temp;
    }

    printf("%d", (x_max - x_min) * (y_max - y_min));

    return 0;
}