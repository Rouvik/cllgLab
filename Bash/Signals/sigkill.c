// 1 

#include <stdio.h>
#include <signal.h>

int main()
{
    printf("Enter PID: ");
    int pid;
    scanf("%d", &pid);

    if(kill(pid, SIGKILL) == -1)
    {
        perror("Failed to kill process");
        return 1;
    }

    printf("Killed process %d", pid);
    return 0;
}