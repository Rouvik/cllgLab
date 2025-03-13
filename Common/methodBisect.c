#include <stdio.h>
#include <float.h>
#include <stdlib.h>

double func(double x)
{
	return x * x - 5.0;
}

double bisectSolve(double a, double b, double prev)
{
	double t = (a + b) / 2.0;
	double out = func(t);
	if(abs(out - prev) < 0.0001)
	{
		return t;
	}
	else if(func(a) * func(t) < 0)
	{
		return bisectSolve(a, t, out);
	}
	else if(func(b) * func(t) < 0)
	{
		return bisectSolve(t, b, out);
	}

	return FLT_MIN; // error case
}

int main()
{
	printf("%lf\n", bisectSolve(0, 5, func(5.0)));
	return 0;
}
