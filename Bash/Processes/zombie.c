#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
int p;
p = fork();
if(p == 0)
{
printf("Child Process");
exit(0);
}
else 
{
sleep(5);
printf("Parent process\n");
printf("Zombie process\n");
}

return 0;
}
