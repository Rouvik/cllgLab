
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int p;
    p = fork();

    if (p == 0)
    {
        sleep(5);
        printf("Child Process\n");
        printf("Orphan Process\n");
    }
    else if (p > 0)
    {
        printf("Parent Process\n");
        exit(0);
    }

    return 0;
}
