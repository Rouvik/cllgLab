#include <stdio.h>
#include <math.h>

int main()
{
    printf("Enter 10 integers: ");
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    float mean = 0.0f;
    for (int i = 0; i < 10; i++)
    {
        mean += arr[i];
    }
    mean /= 10.0f;

    float sd = 0.0f;
    for (int i = 0; i < 10; i++)
    {
        sd += (arr[i] - mean) * (arr[i] - mean);
    }
    sd = sqrt(sd / 9.0f);
    
    printf("Mean: %f Standard Deviation: %f\n", mean, sd);
    return 0;
}