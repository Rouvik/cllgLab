#include <stdio.h>
#include <string.h>

ssize_t getline(char *str, int streamsize, FILE *stream)
{
    char c;
    int i = 0;
    while ((c = fgetc(stream)) != '\n' && c != EOF && i < streamsize - 1)
    {
        str[i++] = c;
    }
    str[i] = '\0';
    return i;
}

int main()
{
    printf("Enter the pattern to search for: ");
    char pattern[16];
    scanf("%16s", pattern);
    while (getchar() != '\n');

    printf("Enter the string to search within: ");
    char str[64];
    getline(str, 64, stdin);

    int patLen = strlen(pattern);

    for (int i = 0; i < strlen(str) - patLen + 1; i++)
    {
        if (strncmp(str + i, pattern, patLen) == 0)
        {
            printf("Match found at index %d\n", i);
        }
    }

    return 0;
}