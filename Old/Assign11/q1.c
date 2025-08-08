#include <stdio.h>

#define DELTA_X 0.001

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

	for(double i = a + DELTA_X; i < b - DELTA_X; i += DELTA_X)
	{
		integral += func(i);
	}

	integral = (DELTA_X / 2.0) * (func(a) + func(b) + 2 * integral);

	printf("Solution: %lf\n", integral);
	return 0;
}
