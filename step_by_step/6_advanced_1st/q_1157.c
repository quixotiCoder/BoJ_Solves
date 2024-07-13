#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
int main()
{
    char str[1000001];
    int alphabet[26] = {0, }; // A[65 - 65] ~ Z[90 - 65]
    int count = 0, most_used_time = 0, most_alphabet = 0;

    scanf("%s", &str);

    while (str[count])
    {
        if (islower(str[count])){ // exchange all small letters to CAPITAL
            str[count] = toupper(str[count]);
        } 
        count ++;
    }
    
    for(int i = 0; i < strlen(str); i++)
    {
        int temp = str[i]; // letter -> int [ASCII]
        alphabet[temp - 'A'] += 1; // ASCII code -> alphabet array indexing
    }

    for(int j = 0; j < 26; j++) // find 1. which alphabet most used 2. couunt how many times it used
    {
        if(alphabet[j] > most_used_time)
            {
                most_alphabet = j;
                most_used_time = alphabet[j];
            }
    }

    for (int k = 0; k < 26; k++)
    {
        if(k != most_alphabet)
        {
            if (alphabet[k] == most_used_time)
            {
                printf("?");
                return 0;
            }            
        }
    }

    most_alphabet += 65;
    printf("%c", &most_alphabet);

    return 0;    
}
*/

char a[1000005];
int arr[26];

int main(){
    int max = 0;
    int size;
    char ans;

    scanf("%s",a);
    size = strlen(a);

    for(int i=0;i<size;i++)
        if(a[i]>='a') arr[a[i]-'a']++;
        else arr[a[i]-'A']++;

    for(int i=0;i<26;i++)
        if(arr[i]==max){
            ans = '?';
        }
        else if(arr[i]>max){
            max = arr[i];
            ans = 'A'+i;
        }

    printf("%c",ans);

    return 0;
}