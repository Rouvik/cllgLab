#include <stdio.h>

int factorial(int n)
{
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        x *= i;
    }
    return x;
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

int main()
{
    printf("Enter the value of n and r: ");
    int n, r;
    scanf("%d %d", &n, &r);
    printf("The value of nCr is %d\nThe value of nPr is %d\n", combination(n, r), permutation(n, r));
    return 0;
}