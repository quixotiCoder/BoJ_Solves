#include <stdio.h>

int main()
{
    int arr[5];
    int sum = 0;

    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }    
    
    for (int i = 0; i < 5; i++) // bubble sort
    {
		for (int j = 0; j < 4; j++) 
        {
			if (arr[j + 1] < arr[j]) 
            {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

    printf("%d\n%d", sum / 5, arr[2]);

    return 0;
}