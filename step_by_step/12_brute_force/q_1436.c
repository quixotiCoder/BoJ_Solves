// BoJ 1436
// theme : brute force

#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int count = 0;
    int standardNum = 666;

    while(1)
    {
        int consecutiveSix = 0;
        int cur = standardNum;
        while(cur > 0)
        {
            int digit = cur % 10;

            if(digit==6)
                consecutiveSix ++;
            else
                consecutiveSix = 0;
            
            if(consecutiveSix == 3)
            {
                count++;
                break;
            }
            cur = cur/10;
        }

        if(count==N)
            break;

        standardNum++;
    }
    
    printf("%d", standardNum);

    return 0;
}