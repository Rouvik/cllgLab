#include <stdio.h>
#include <stdlib.h>

double n = 0;

double func(double x)
{
	return x * x - n;
}

double funcDiff(double x)
{
	return 2.0 * x;
}

double newtonRhapson(double n)
{
	double x = n;
	while(abs(func(x)) > 0.0001)
	{
		x = x - func(x) / funcDiff(x);
	}
	return x;
}

int main()
{
	fputs("Enter number to find root of: ", stdout);
	scanf("%lf", &n);
	printf("Root: %lf\n", newtonRhapson(5));
	return 0;
}
