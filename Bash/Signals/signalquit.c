#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void oh(int sig)
{
printf("OH!-I got signal %d\n",sig);
signal(SIGINT,oh);
signal(SIGQUIT,SIG_DFL);
}
int main() 
{
signal(SIGQUIT,oh);
while(1)
{
printf("Hello World!\n");
sleep(1);
}
}

