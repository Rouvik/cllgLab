#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

int tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int main()
{
    char str[64];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
    
    printf("Capitalised: %s\n", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }

    printf("Smallised: %s\n", str);

    return 0;
}