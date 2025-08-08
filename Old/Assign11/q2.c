#include <stdio.h>

#define SEGMENTS (400.0)

double func(double x)
{
	return 1.0 / (1 + x * x);
}

int main()
{
	printf("Enter bounds: ");
	int a, b;
	scanf("%d %d", &a, &b);

	double integral = 0.0;

	double delta = (b - a) / SEGMENTS;
	
	for(double i = 1; i < SEGMENTS; i += 2)
	{
		integral += func(a + i * delta);
	}

	integral *= 4;

	double part2 = 0.0;
	
	for(double i = 2; i < SEGMENTS - 1; i += 2)
	{
		part2 += func(a + i * delta);
	}

	part2 *= 2;

	integral = (delta / 3.0) * (func(a) + func(b) + integral + part2);

	printf("Solution: %lf\n", integral);
	return 0;
}
