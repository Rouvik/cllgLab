#include <stdio.h>

int main()
{
    FILE *fp = fopen("./input.txt", "w");
    if (!fp)
    {
        perror("Failed to open file");
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        int x;
        scanf("%d", &x);

        fprintf(fp, "%d ", x);
    }

    fclose(fp);

    printf("All numbers written successfully");
    return 0;
}