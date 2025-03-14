#include <stdio.h>

int main()
{
    int arr[10];
    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter a position to change content of and a number: ");
    int pos, num;
    scanf("%d %d", &pos, &num);
    
    arr[pos] = num;

    printf("The new array is: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}