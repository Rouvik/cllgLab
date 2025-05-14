#include <stdio.h>

int main()
{
    int n[10] = {0};
    FILE *input = fopen("./input.txt", "r");
    if(!input)
    {
        perror("Failed to open input file");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        fscanf(input, "%d", &n[i]);
        int j = i - 1, t = n[i];
        while (j >= 0 && n[j] > t)
        {
            n[j + 1] = n[j];
            j--;
        }
        n[j + 1] = t;
    }
    
    fclose(input);

    FILE *output = fopen("./output.txt", "w");
    if (!output)
    {
        perror("Failed to open file to write");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        fprintf(output, "%d ", n[i]);
    }
    
    fclose(output);

    puts("Sorted successfully!");
    return 0;
}