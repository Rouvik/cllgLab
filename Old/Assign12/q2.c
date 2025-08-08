#include <stdio.h>

struct Compute
{
    float y, x;
    union
    {
        int i;
        float f;
    };
};

int main()
{
    struct Compute c;
    printf("Enter x: ");
    scanf("%f", &c.x);
    printf("Enter type of n (0 = int, 1 = float): ");
    int ch;
    scanf("%d", &ch);
    if (ch == 0)
    {
        printf("Enter int: ");
        scanf("%d", &c.i);

        c.y = c.x * c.i;
    }
    else
    {
        printf("Enter float: ");
        scanf("%f", &c.f);

        c.y = c.x * c.f;
    }

    printf("Output: %f\n", c.y);
    return 0;
}