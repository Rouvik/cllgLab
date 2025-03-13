#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	puts("Enter the coefficients of quadratic equation (ax^2 + bx + c):");
	scanf("%d  %d %d", &a, &b, &c);
	
	double d = b * b - 4 * a * c;
	
	if(d < 0)
	{
		d = sqrt(-d);
		double realPart = -b / (2 * a);
		double imagPart =  d / (2 * a);
		printf("root1 = %lf + %lfi root2 = %lf - %lfi\n", realPart, imagPart, realPart, imagPart);
	}
	else
	{
		d = sqrt(d);
		printf("root1 = %lf root2 = %lf\n", (-b + d) / (2 * a), (-b - d) / (2 * a));
	}
	return 0;
}
