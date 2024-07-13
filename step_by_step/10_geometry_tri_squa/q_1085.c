#include <stdio.h>

int main()
{
    int x, y, w, h, min_distance = 1001;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int w_x = w - x;
    int h_y = h - y;
    int arr[4] = {x, y, w_x, h_y};

    for(int i = 0; i < 4; i++)
    {
        if(arr[i] < min_distance)
            min_distance = arr[i];
    }

    printf("%d", min_distance);

    return 0;
}