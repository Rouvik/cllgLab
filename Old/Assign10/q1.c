#include <stdio.h>
#include <math.h>

static int prec = 6;

double func(double x)
{
    return x * x * x - 8 * x - 4;
}

void bisection(double a, double b)
{
    while (1)
    {
        double c = (a + b) / 2.0;
        double fc = func(c);

        if (fabs(fc) < 0.001)
        {
            printf("Solution: %.*lf\n", prec, c);
            break;
        }

        if (func(a) * fc < 0)
        {
            b = c;
        }
        else if (func(b) * fc < 0)
        {
            a = c;
        }
        else
        {
            puts("Failed to find roots");
            return;
        }
    }
}

int main()
{
    fputs("Enter precision: ", stdout);
    scanf("%d", &prec);

    fputs("Enter the bounds: ", stdout);
    int a, b;
    scanf("%d %d", &a, &b);

    if (func(a) * func(b) > 0)
    {
        puts("Error, both f(a) and f(b) must be of opposite signs");
    }

    bisection(a, b);

    return 0;
}