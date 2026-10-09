#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void oh(int sig)
{
printf("OH!-I got signal %d\n",sig);
signal(SIGINT,oh);
//signal(SIGINT,SIG_DFL);
}
int main() 
{
signal(SIGINT,oh);
while(1)
{
printf("Hello World!\n");
sleep(1);
}
}

