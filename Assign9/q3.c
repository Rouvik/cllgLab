#include <stdio.h>

void hanoi(int n, char from, char aux, char to)
{
    if(n > 0)
    {
        hanoi(n - 1, from, to, aux);
        printf("%c -> %c, ", from, to);
        hanoi(n - 1, aux, from, to);
    }
}

int main()
{
    int n;
    fputs("Enter a number: ", stdout);
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}