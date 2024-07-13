#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    int Quarter = 25, Dime = 10, Nickel = 5, Penny = 1;
    
    for (int i = 0; i < T; i++)
    {
        int change;
        scanf("%d", &change);

        int coin[4] = {0, }; // [0] : Quarter / [1] : Dime ..

        while (change > 0)
        {
            if ((change / Quarter) > 0)
            {
                coin[0] = change / Quarter;
                change %= Quarter;
                continue;
            }
            else if ((change / Dime) > 0)
            {
                coin[1] = change / Dime;
                change %= Dime;
                continue;
            }
            else if ((change / Nickel) > 0)
            {
                coin[2] = change / Nickel;
                change %= Nickel;
                continue;
            }
            else if ((change / Penny) > 0)
            {
                coin[3] = change / Penny;
                change %= Penny;
                continue;
            }
        }

        printf("%d %d %d %d\n", coin[0], coin[1], coin[2], coin[3]);
    }
    
    return 0;
}