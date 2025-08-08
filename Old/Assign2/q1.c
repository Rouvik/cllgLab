#include <stdio.h>
#include <math.h>

int main()
{
	puts("Enter the radius:");
	double radius = 0.0;
	scanf("%lf", &radius);

	printf("Area: %lf\n", M_PI * radius * radius);
	return 0;
}
