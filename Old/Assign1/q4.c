#include <stdio.h>
#include <math.h>

int main()
{
	puts("Enter (x, y) of 1st point:");
	int x1 = 0, y1 = 0;
	scanf("%d %d", &x1, &y1);
	
	puts("Enter (x, y) of 2nd point:");
	int x2 = 0, y2 = 0;
	scanf("%d %d", &x2, &x2);

	float slope = (float)(y2 - y1) / (x2 - x1);
	float dist = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));

	printf("Slope: %f\nDistance: %f\n", slope, dist);
	return 0;
}
