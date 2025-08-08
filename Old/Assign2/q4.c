#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	puts("Enter 2 number a and b:");
	scanf("%d %d", &a, &b);

	printf("Is a > b ? %s\n", a > b ? "Yes" : "No");
	printf("Is a < b ? %s\n", a < b ? "Yes" : "No");
	printf("Is a == b ? %s\n", a == b ? "Yes" : "No");
	printf("Is a != b ? %s\n", a != b ? "Yes" : "No");

	int t1 = b;
	t1 *= a;
	int t2 = b;
	t2 /= a;
	int t3 = b;
	t3 += a;
	int t4 = b;
	t4 -= a;

	printf("t is b\nNow we perform\nt *= a -- %d\nt /= a -- %d\nt += a -- %d\nt -= a -- %d\n",
		t1, t2, t3, t4);
	if(a > 3 && b > 5)
	{
		puts("a > 3 AND b > 5");
	}

	if(a > 0 || b > 0)
	{
		puts("a > 0 OR b > 0");
	}
	
	if(!(a > 3 && b > 5))
	{
		puts("NOT (a > 3 AND b > 5)");
	}

	t1 = a & b;
	t2 = a | b;
	t3 = ~a;
	t4 = a ^ b;
	int t5 = a << 2;
	int t6 = a >> 2;

	printf("a & b = %d\na | b = %d\n~a = %d\na ^ b = %d\na << 2 = %d\na >> 2 = %d\n",
		t1, t2, t3, t4, t5, t6);
	return 0;
}	
