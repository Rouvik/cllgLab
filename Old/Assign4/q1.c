#include <stdio.h>

int main()
{
        printf("Enter a, d, n: "); int a, d, n;
        scanf("%d %d %d", &a, &d, &n);

	int s = a;
        for(int i = 0; i < n; i++)
        {
                printf("%d ", s);
                s += d;
        }
        printf("\n");

        return 0;
}
