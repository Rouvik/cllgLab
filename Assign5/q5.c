#include <stdio.h>

int main()
{
    for (int i = 100; i <= 1000; i++)
    {
        int t = i, s = 0;
        while (t > 0)
        {
            int d = t % 10;
            s += d * d * d;
            t /= 10;
        }
        
        if (s == i)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    
    return 0;
}
