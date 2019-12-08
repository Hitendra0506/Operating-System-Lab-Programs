// Program to demonstrate Zombie and Orphan Process

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

int pid = fork();

if(pid == 0)
{
printf("\nI am child process, and I am going to die.\nI am a zombie now ! \n");
exit(1); 
}
else 
{
sleep(10);
printf("\nI am the parent process.\nI have completed the execution.\nNow i will reap out the child process.\nUntill now...\nIT WAS A ZOMBIE !!! \n");

}

return 0;

}

 
