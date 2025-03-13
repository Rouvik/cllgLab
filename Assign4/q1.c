#include <stdio.h>

int main()
{
	printf("Enter a, d, n: "); int a, d, n;
	scanf("%d %d %d", &a, &d, &n);

	for(int i = 0; i < n; i++)
	{
		printf("%d ", a + i * d);
	}
	puts("");

	return 0;
}
