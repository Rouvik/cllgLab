#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void) {
pid_t ppid, pid, cpid;
ppid = getpid();
pid = fork();
if(ppid == getpid())
printf("parent");
else if (cpid == getpid())
printf("child");
if(pid>0)
{
int i = 0;
while(i++ <5){
printf("In the parent process.\n");
sleep(1);
}
}
else if(pid==0)
{
int i=0;
while (i++ < 10){
printf("In the child process.\n");
sleep(1);
if(i==3)
{
kill(pid, SIGKILL);
printf("The Parent is killed. I'm Orphan !!!");
}
}
}
else{
printf("Something bad happened");
exit(EXIT_FAILURE);
}
return 0;
}
