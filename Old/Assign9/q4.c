#include <stdio.h>
#include <string.h>

void revprnt(char *str, int i)
{
    if (i == 0)
    {
        return;
    }
    
    printf("%c", str[i - 1]);
    revprnt(str, i - 1);
}

int main()
{
    char buf[32];
    printf("Enter a string: ");
    fgets(buf, 32, stdin);

    printf("Reversed string: ");
    revprnt(buf, strlen(buf));

    return 0;
}