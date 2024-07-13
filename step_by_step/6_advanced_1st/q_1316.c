#include <stdio.h>
#include <string.h>

int main()
{
    int N, count = 0;
    scanf("%d", &N);  // get 'N'

    for(int i = 0; i < N; i++) // 'N' times repeat
    {
        char str[101];
        scanf("%s", &str); // get 'str'
        int len = strlen(str); // check length 

        int is_group_word = 1;

        for(int j = 0; j < len; j++)
        {
            char comparison_letter = str[j];

            if (j + 1 < len && comparison_letter != str[j + 1])
            {
                for(int k = j + 2; k < len; k++)
                {
                    if(str[k] == comparison_letter) {
                        is_group_word = 0; 
                        break;
                    }
                }
            }
        }
       
        if (is_group_word)
            count++;
    }
    printf("%d", count);

    return 0;
}