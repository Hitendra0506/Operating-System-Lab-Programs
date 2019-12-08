// Program to demonstrate Zombie and Orphan Process

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

int pid = fork();

if(pid != 0)
{
printf("\nI am parent process, and I am going to die.\n\n");
}
else 
{
sleep(10);
printf("\nI am the child process.\nMy parent died 10 seconds ago :( , but i was busy executing.\nSo, I am an orphan since a few seconds.\nWaiting for Adoption :|\n");
exit(0);
}

return 0;

}

 
