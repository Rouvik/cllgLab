#include <stdio.h>

int leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    printf("%d is a %s year\n", year, leap(year) ? "leap" : "non-leap");
    return 0;
}