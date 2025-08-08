#include <stdio.h>

int main()
{
	puts("Enter temperature:");
	double temp;
	scanf("%lf", &temp);

	printf("Celcius: %lf\nFarenheit: %lf\n", (temp * 9.0 / 5) + 32, (temp - 32.0) * 5.0 / 9);
	return 0;
}
