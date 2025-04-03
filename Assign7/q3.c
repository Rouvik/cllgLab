#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter a string: ");
    char str[32];
    scanf("%32s", str);

    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            printf("Not a palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");

    return 0;
}