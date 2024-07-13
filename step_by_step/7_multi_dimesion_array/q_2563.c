// It's too complex to "subtract overlapping areas from the total area."
// fill 1*1 size for drwan area

#include <stdio.h>

int main()
{
    int N, total_area[101][101] = {0, }, scale = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                if(total_area[x+j][y+k] == 0)
                {
                    total_area[x+j][y+k] = 1;
                    scale++;
                }
            }
        }
    }

    printf("%d", scale);

    return 0;
}