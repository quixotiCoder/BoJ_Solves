#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];

    scanf("%s", &str);

    for(int i = 0; i < strlen(str) / 2; i++)
    {
        if(str[i] != str[strlen(str) - 1 - i]) // {0, 4} / {1, 3} / {2, 2}
        {
            printf("0");
            return 0;
        }
    }

    printf("1");
    
    return 0;
}