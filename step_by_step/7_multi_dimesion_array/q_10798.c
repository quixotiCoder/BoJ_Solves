#include <stdio.h>

int main()
{
    char letter[5][16] = {0, }; // 초기화 필수 == UB(Undefined Behavior) 방지!
    
    for(int i = 0; i < 5; i++)
        scanf("%s", letter[i]);

    for(int j = 0; j < 16; j++)
    {
        for(int k = 0; k < 5; k++)
        {
            if(letter[k][j])
               printf("%c", letter[k][j]);
        }
    }

    return 0;
}