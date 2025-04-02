#include <stdio.h>
#include <math.h>

float discriminant(float a, float b, float c)
{
    return (b * b) - (4 * a * c);
}

int main()
{
    printf("Enter coefficients of quadratic equation (a, b, c): ");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    float d = discriminant(a, b, c);

    if (d >= 0)
    {
        float r1 = (-b + sqrt(d)) / (2 * a);
        float r2 = (-b - sqrt(d)) / (2 * a);
        printf("Root 1 = %f Root 2 = %f\n", r1, r2);
    }
    else
    {
        printf("Roots are imaginary\n");
    }

    return 0;
}