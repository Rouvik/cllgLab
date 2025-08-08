#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 9999

static int prec = 6;

double func(double x)
{
    return x * x * x - 8 * x - 4;
}

double fprime(double x)
{
    return 3 * x * x - 8;
}

void newtonRhapson(double a)
{
    int i = 0;
    while (i++ < MAX_ITERATIONS)
    {
        if(fabs(func(a)) < 0.001)
        {
            printf("Solution: %.*lf", prec, a);
            return;
        }

        a = a - func(a) / fprime(a);
    }

    puts("Failed to find a solution");
}

int main()
{
    fputs("Enter precision: ", stdout);
    scanf("%d", &prec);

    fputs("Enter starting x: ", stdout);
    int x = 10;
    scanf("%d", &x);

    newtonRhapson(x);

    return 0;
}