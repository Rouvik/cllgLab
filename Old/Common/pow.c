#include <stdio.h>

/*double mypow_double(int a, int b)
{
	char isNeg = 0;
	if(b < 0)
	{
		b = -b;
		isNeg = 1;
	}

	int out = 1;
	while( b > 0)
	{
		if((b & 1) == 1)
		{
			out *= a;
		}

		b >>= 1;
		a *= a;
	}
	return isNeg ? 1.0 / out : out;
}
*/

unsigned long long mypow(unsigned long long a, int b)
{
	long out = 1;
	while( b > 0)
	{
		if((b & 1) == 1)
		{
			out *= a;
		}

		b >>= 1;
		a *= a;
	}
	return out;
}


int main()
{
	printf("Pow: %llu\n", mypow(2, 63));
	return 0;
}
