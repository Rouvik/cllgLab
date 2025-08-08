#include <stdio.h>

int main()
{
	printf("Enter range: ");
	int n;
	scanf("%d", &n);
	
	double sum = 0.0;
	int prevMult = 1;
	for(int i = 1; i <= n; i++)
	{
		int mult = 2 * (i + 1) - 1;
		sum += (double)(i * 2) / (prevMult * mult);
		prevMult = mult;
	}

	printf("Sum: %lf\n", sum);
	return 0;
}
