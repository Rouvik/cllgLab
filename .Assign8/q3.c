#include <stdio.h>

int mypow(int a, int b)
{
    int result = 1;
    while(b > 0)
    {
        if((b & 1) == 1)
        {
            result *= a;
        }

        b >>= 1;
        a *= a;
    }

    return result;
}

int main()
{
    printf("Enter base and radix: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d ^ %d = %d\n", a, b, mypow(a, b));
    return 0;
}