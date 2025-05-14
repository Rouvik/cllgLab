#include <stdio.h>
#include <math.h>

static int prec = 6;

double func(double x)
{
    return x * x * x - 8 * x - 4;
}

void regulaFalsi(double a, double b)
{
    while (1)
    {
        double c = b - func(b) * (b - a) / (func(b) - func(a));

        double fc = func(c);

        if (fabs(fc) < 0.001)
        {
            printf("Solution: %.*lf\n", prec, c);
            return;
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
            puts("Failed to find root");
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

    regulaFalsi(a, b);
    return 0;
}