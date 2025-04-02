#include <stdio.h>

void line(int len, char ch)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", ch);
    }
    printf("\n");
}

int main()
{
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    line(n, '*');
    printf("Done\n");
    return 0;
}