#include <stdio.h>

double sum(int n)
{
    return n == 0 ? 0 : n * 2.0 / ((2 * n - 1) * (2 * n + 1)) + sum(n - 1);
}

int main()
{
    int n, prec;
    printf("Enter the number of terms and precision: ");
    scanf("%d %d", &n, &prec);

    printf("Sum: %.*lf\n", prec, sum(n));
    return 0;
}