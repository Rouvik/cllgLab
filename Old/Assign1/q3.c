#include <stdio.h>
#include <math.h>

int main()
{
	puts("Enter 3 sides:");
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	double s = (a + b + c) / 2.0;
	printf("Perimeter: %d\nArea: %lf\n", a + b + c, sqrt(s * (s - a) * (s - b) * (s - c)));
	return 0;
}
